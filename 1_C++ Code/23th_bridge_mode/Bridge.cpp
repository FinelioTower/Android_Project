#include <iostream>

using namespace std;

class OS{
private:
	virtual void Install() = 0;
public:
};

class LinuxOS : public OS{
public:
	virtual void Install(){
		cout<<"Install LinxuOS"<<endl;
	}
};

class WindowOS: public OS{
public:
	virtual void Install(){
		cout<<"Install WindowOS"<<endl;
	}
};

class Computer{
public:
	virtual void printInfo() = 0;
};

class MAC : public Computer{
public:
	virtual void printInfo(){
		cout<<"this is MAC, ";
	}
};

class MacWithLinux : public LinuxOS, public MAC{
public:
	void InstallOS(){
		cout<<"This is MAC, ";
		Install();
	}
};

class MacWithWindow : public WindowOS, public MAC{
public:
	void InstallOS(){
		cout<<"This is MAc, ";
		Install();
	}
};


class Lenovo : public Computer{
public:
	virtual void printInfo(){
		cout<<"this is Lenovo, ";
	}
};

class LenovoWithLinux : public LinuxOS, public Lenovo{
public:
	void InstallOS(){
		cout<<"This is Lenovo, ";
		Install();
	}
};

class LenovoWithWindow : public WindowOS, public Lenovo{
public:
	void InstallOS(){
		cout<<"This is Lenovo,";
		Install();
	}
};

int main(int argc, char **argv)
{
	MacWithLinux a;
	a.InstallOS();

	LenovoWithWindow a1;
	a1.InstallOS();
}