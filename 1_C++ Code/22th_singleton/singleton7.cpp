#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

class Singleton;

class Singleton{
private:
	static Singleton *gInstance;

	/*mutex*/
	static pthread_mutex_t g_tMutex;

	Singleton(){
		cout<<"Singleton()"<<endl;
	}

public:
	static Singleton *getInstance(){
		return gInstance;
	}

	void printInfo(){
		cout<<"this is singleton"<<endl;
	}
	
};

/*懒汉模式: 你先给我做好*/
Singleton *Singleton::gInstance = new Singleton();

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

//	Singleton *s4 = new Singleton();

//	Singleton s5;

	/*创建线程*/
	pthread_t thread1_ID;
	pthread_t thread2_ID;

	pthread_create(&thread1_ID, NULL, start_routine_thread1, NULL);
	pthread_create(&thread2_ID, NULL, start_routine_thread2, NULL);

	sleep(3);
	
	return 0;
}
