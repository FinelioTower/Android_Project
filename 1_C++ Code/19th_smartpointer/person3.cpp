#include <iostream>

using namespace std;

class Person{
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

class sp{
public:
	sp(Person *other){
		cout<<"sp(const Persion *other)"<<endl;
		p = other;
	}

	~sp(){
		cout<<"~sp()"<<endl;
		if(p){
			delete p;
		}
	}

	Person *operator->(){
		return p;
	}
	
private:
	Person *p;
	
};

void test_func(void)
{
	sp s = new Person;

	s->printInfo();
}

int main(int argc, char **argv)
{
	int i;

	for(i=0; i<2; i++){
		test_func();
	}	
	return 0;
}
