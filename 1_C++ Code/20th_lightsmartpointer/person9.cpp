#include <iostream>
#include "RefBase.h"
using namespace std;
using namespace android::RSC;

class Person : public LightRefBase<Person>{
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
	int count;
};

template<typename T>
void test_func(sp<T> &other)
{
	sp<T> s = other;

	cout<<"IN cell test_func :"<<other->getStrongCount()<<endl;

	s->printInfo();
}

int main(int argc, char **argv)
{
	int i;

	/* 少用"Person *"; 用"sp"来代替"Person *"
	*	Person *per;
	*	有两种操作:	per->xxx, (*per).xxx
	*	sp也应该有这两种操作
	*		sp->xxx,  (*sp).xxx
	*/	
	
	sp<Person> other = new Person();


	(*other).printInfo();
	cout<<"Before cell test_func :"<<other->getStrongCount()<<endl;

	for(i=0; i<2; i++){
		test_func(other);
		cout<<"After cell test_func :"<<other->getStrongCount()<<endl;
	}
	return 0;
}
