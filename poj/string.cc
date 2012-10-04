#include<iostream>
using namespace std;
int main(){
	char str1[]= "hello world";
	char str2[] = "hello world";
	if(str1 == str2 ){
		cout <<"equal" << endl;
	}else{
		cout << "not equal"<<endl;
	}
	char* str3 = "hello world";
	char* str4 = "hello world";
	if(str3 == str4 ){
		cout << "equal" << endl;
	}else{
		cout << "not equal"<<endl;
	}
}
