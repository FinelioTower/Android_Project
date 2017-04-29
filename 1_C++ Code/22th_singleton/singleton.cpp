#include <iostream>

using namespace std;

class Singleton;

Singleton *gInstance;

class Singleton{
private:

public:
	static Singleton *getInstance(){
		if(NULL == gInstance){
			gInstance = new Singleton;
		}
		return gInstance;
	}

	Singleton(){
		cout<<"Singleton()"<<endl;
	}

	void printInfo(){
		cout<<"this is singleton"<<endl;
	}
};

int main(int argc, char **argv)
{
	Singleton *s = Singleton::getInstance();
	s->printInfo();

	Singleton *s1 = Singleton::getInstance();
	s->printInfo();

	Singleton *s2 = Singleton::getInstance();
	s->printInfo();
	return 0;
}
