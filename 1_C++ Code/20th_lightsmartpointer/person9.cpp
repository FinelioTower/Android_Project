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

	/* ����"Person *"; ��"sp"������"Person *"
	*	Person *per;
	*	�����ֲ���:	per->xxx, (*per).xxx
	*	spҲӦ���������ֲ���
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
