#include<iostream>
#include<string.h>
using namespace std;
int atoi(char a[]){
	int l = strlen(a);
	bool isNegative = false;
	int cur = 0;
	if(a[0] == '-'){
		isNegative = true;
		++cur;
	}
	int result = 0;
	while(a[cur]){
		result = result*10 + a[cur]-'0';
		++cur;
	}
	if(isNegative){
		result = -result;
	}
	return result;
}
int main(){
	char a[] = "12233123";
	char b[] = "-12233123";
	cout << atoi(a)<<endl;
	cout << atoi(b)<<endl;

}
