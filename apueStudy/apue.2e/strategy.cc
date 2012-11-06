#include<iostream>
using namespace std;
typedef int (*opStrategy)(int a,int b);
int add(int a,int b){
	return a+b;
}
int mutiply(int a,int b){
	return a*b;
}

int getValue(int a,int b,opStrategy strategy){
	return strategy(a,b);
}

int main(){
	cout << getValue(1,2,add)<<endl;	
}
