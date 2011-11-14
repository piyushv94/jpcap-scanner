#ifndef _myException
#define _myException
#include<string>
using std::string;
class myException{
protected:
	string info;
public:
	string& toString(){
		return info;
	}
	myException(const string& _s){
		info=_s;
	}
};
#endif