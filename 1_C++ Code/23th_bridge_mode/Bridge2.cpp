#include <iostream>

using namespace std;

class OS{
private:

public:
	virtual void InstallOS_impl() = 0;
};

class LinuxOS : public OS{
public:
	virtual void InstallOS_impl(){
		cout<<"Install LinxuOS"<<endl;
	}
};

class WindowsOS: public OS{
public:
	virtual void InstallOS_impl(){
		cout<<"Install WindowOS"<<endl;
	}
};

class UnixOS: public OS{
public:
	virtual void InstallOS_impl(){
		cout<<"Install UnixOS"<<endl;
	}
};

class Computer{
public:
	virtual void printInfo() = 0;
	virtual void InstallOS() = 0;
};

class MAC : public Computer{
public:
	virtual void printInfo(){
		cout<<"this is MAC, ";
	}

	MAC(OS *impl){
		this->impl = impl;
	}

	virtual void InstallOS(){
		printInfo();
		impl->InstallOS_impl();
	}
	
private:
	OS *impl;
};

class Lenovo : public Computer{
public:
	virtual void printInfo(){
		cout<<"this is Lenovo, ";
	}

	Lenovo(OS *impl){
		this->impl = impl;
	}

	virtual void InstallOS(){
		printInfo();
		impl->InstallOS_impl();
	}

private:
	OS *impl;
};

int main(int argc, char **argv)
{
	OS *os1 = new LinuxOS();
	OS *os2 = new WindowsOS();
	OS *os3 = new UnixOS();

	Computer *c1 = new MAC(os1);
	Computer *c2 = new Lenovo(os2);
	Computer *c3 = new Lenovo(os3);

	c1->InstallOS();
	c2->InstallOS();
	c3->InstallOS();
}