#include <iostream>

using namespace std;

class RefBase{
private:
	int count;
public:
	RefBase() : count(0){

	}
		
	void  incStrong(){
		count++;
	}

	void decStrong(){
		count--;
	}

	int getStrongCount(){
		return count;
	}
};

class Person : public RefBase{
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
class sp{
public:
	sp() : p(0){
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

	T *operator->(){
		return p;
	}

	T &operator*(){
		return *p;
	}
	
private:
	T *p;
	
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
