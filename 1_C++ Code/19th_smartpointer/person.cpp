#include <iostream>

using namespace std;

class Person
{
public:
	Person(){
		cout<<"Person()"<<endl;
	}

	~Person(){
 		cout<<"~Person()"<<endl;
	}

	void printInfo(){
		cout<<"printInfo()"<<endl;
	}
	
private:

};


void test_func(void)
{
	Person *p = new Person();
	p->printInfo();
}

int main(int argc, char **argv)
{
	int i;

	for(i=0; i<2; i++){
		test_func();

	}	
	return 0;
}
