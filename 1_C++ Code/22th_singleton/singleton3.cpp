#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

class Singleton;

Singleton *gInstance;

/*mutex*/
static pthread_mutex_t g_tMutex = PTHREAD_MUTEX_INITIALIZER;

class Singleton{
private:

public:
	static Singleton *getInstance(){
		pthread_mutex_lock(&g_tMutex);
		if(NULL == gInstance){
			gInstance = new Singleton;
		}
		pthread_mutex_unlock(&g_tMutex);
		return gInstance;
	}

	Singleton(){
		cout<<"Singleton()"<<endl;
	}

	void printInfo(){
		cout<<"this is singleton"<<endl;
	}
};

void *start_routine_thread1(void *arg)
{
	cout<<"this is thread 1 ..."<<endl;

	Singleton *s = Singleton::getInstance();
	s->printInfo();

	return NULL;
}

void *start_routine_thread2(void *arg)
{
	cout<<"this is thread 2 ..."<<endl;

	Singleton *s = Singleton::getInstance();
	s->printInfo();

	return NULL;
}


int main(int argc, char **argv)
{
	Singleton *s = Singleton::getInstance();
	s->printInfo();

	Singleton *s1 = Singleton::getInstance();
	s->printInfo();

	Singleton *s2 = Singleton::getInstance();
	s->printInfo();

	/*创建线程*/
	pthread_t thread1_ID;
	pthread_t thread2_ID;

	pthread_create(&thread1_ID, NULL, start_routine_thread1, NULL);
	pthread_create(&thread2_ID, NULL, start_routine_thread2, NULL);

	sleep(3);
	
	return 0;
}
