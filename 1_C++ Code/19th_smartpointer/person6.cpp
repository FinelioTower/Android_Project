#include <iostream>

using namespace std;

class Person{
public:
	void  incStrong(){
		count++;
	}

	void decStrong(){
		count--;
	}

	int getStrongCount(){
		return count;
	}
	
	Person() : count(0){
		cout<<"Person()"<<endl;
	}

	~Person(){
 		cout<<"~Person()"<<endl;
	}

	void printInfo(){
		cout<<"printInfo()"<<endl;
	}
	
private:
	int count;
};

class sp{
public:
	sp(){
		cout<<"sp()"<<endl;
	}

	sp(Person *other){
		cout<<"sp(Persion *other)"<<endl;
		p = other;
		p->incStrong();
	}

	sp(const sp &other){
		cout<<"sp(const sp &other)"<<endl;
		p = other.p;
		p->incStrong();
	}

	~sp(){
		cout<<"~sp()"<<endl;
		if(p){
			p->decStrong();
			if(p->getStrongCount() == 0)
				delete p;	
				p = NULL;
		}
	}

	Person *operator->(){
		return p;
	}
	
private:
	Person *p;
	
};

void test_func(sp &other)
{
	sp s = other;

	cout<<"IN cell test_func :"<<other->getStrongCount()<<endl;

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

	cout<<"Before cell test_func :"<<other->getStrongCount()<<endl;

	for(i=0; i<2; i++){
		test_func(other);
		cout<<"After cell test_func :"<<other->getStrongCount()<<endl;
	}
	return 0;
}
