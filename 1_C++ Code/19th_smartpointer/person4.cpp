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

	sp(sp &other){
		cout<<"sp(sp &other)"<<endl;
		p = other.p;
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

void test_func(sp &other2)
{
	sp s = other2;

	s->printInfo();
}

int main(int argc, char **argv)
{
	int i;

	/*相当于
	*	1.Person *p = new Person();
	*	2.sp tmp(p); --> sp(Person *other)
	*	3.
	*		3.1 sp other(tmp); -->sp(sp &other2)
	*			问题在于: sp &other2 = tmp; //错误的语法
	*						   const sp &other2 = tmp //ok
	*		或者
	*		3.2 sp other(tmp==>Person *);  -->sp(Person *other)	
	*/
	
	sp other = new Person();

	for(i=0; i<2; i++){
		test_func(other);
	}	
	return 0;
}
