#include<iostream>
using namespace std;
class Test{
	char ddd;
	int a;
	virtual void test(){}
};
int main(){
	cout << sizeof(Test);
}
