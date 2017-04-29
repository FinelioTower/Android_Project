
#include <jni.h>  /* /usr/lib/jvm/java-1.7.0-openjdk-amd64/include/ */
#include <stdio.h>

jint create_vm(JavaVM **jvm, JNIEnv **env)
{
	JavaVMInitArgs args;
	JavaVMOption options[1];
	args.version = JNI_VERSION_1_6;
	args.nOptions = 1;
	options[0].optionString = "-Djava.class.path=./";
	args.options = options;
	args.ignoreUnrecognized = JNI_FALSE;
	
	return JNI_CreateJavaVM(jvm, (void **)env, &args);
	
}

int main(int argc, char **argv)
{
	JavaVM *jvm;
	JNIEnv *env;
	jclass cls;
	jmethodID mid;
	jmethodID cid;
	jobject jobj;
	jstring jstr;
	jfieldID nameID;
	jfieldID ageID;
	int r = 0;
	int ret = 0;
	/*1.create java virtual machine*/
	if(create_vm(&jvm, &env)){
		printf("can not create jvm \n");
		return -1;
	}
	/*2.get class*/
	cls = (*env)->FindClass(env,"Hello");
	if(cls == NULL){
		ret = -1;
		goto destroy;
	}
	/*3.create object*/
	cid = (*env)->GetMethodID(env, cls, "<init>", "()V");	
	if(cid == NULL){
		ret = -1;
		printf("can not get construct method \n");
		goto destroy;
	}
	
	jobj = (*env)->NewObject(env, cls, cid);
	if(jobj == NULL){
		ret = -1;
		printf("can not create jobj \n");
		goto destroy;
	}
	
	nameID = (*env)->GetFieldID(env, cls, "name", "Ljava/lang/String;");
	if(nameID == NULL){
		ret = -1;
		printf("can not get field name");
		goto destroy;
	}
	
	jstr = (*env)->NewStringUTF(env, "Bill");
	(*env)->SetObjectField(env ,jobj, nameID, jstr);
	
	ageID = (*env)->GetFieldID(env, cls, "age", "I");
	if(nameID == NULL){
		ret = -1;
		printf("can not get field age");
		goto destroy;
	}
	
	(*env)->SetIntField(env ,jobj, ageID, 10);


	mid = (*env)->GetStaticMethodID(env, cls, "main", "([Ljava/lang/String;)V");
	if(mid == NULL){
		ret = -1;
		printf("can not get method\n");
		goto destroy;
	}
	
	(*env)->CallIntMethod(env, jobj, mid, NULL);

	
	mid = (*env)->GetMethodID(env, cls, "sayhello_to", "(Ljava/lang/String;)I");
	if(mid == NULL){
		ret = -1;
		printf("can not get method\n");
		goto destroy;
	}
	
	jstr = (*env)->NewStringUTF(env, "weidongshan");
	
	/*4.call method*/
	r = (*env)->CallIntMethod(env, jobj, mid, jstr);
	printf("ret = %d\n", r);
	
destroy:
	(*jvm)->DestroyJavaVM(jvm);
	return ret;
}

