#include<iostream>
#include<string.h>
using namespace std;
void swap(int *a,int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void swap(char *a,char *b){
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
int findMaxGCD(int a, int b){
	if(a<b){
		swap(&a,&b);
	}
	if(b == 0){
		return a;
	}
	return	findMaxGCD(b,a%b);
}
void shiftString(char *s, int shift){
	int n = strlen(s);
	int gcd = findMaxGCD(n,shift);
	for(int i=0;i<gcd;i++){
		char t = s[i];
		for(int j=i;(j-shift+n)%n!=i;j=(j-shift+n)%n){
			swap(&t,&s[(j-shift+n)%n]);
		}
		swap(&t,s+i);
	}
	
}
int main(){
	char s[] = {'a','b','c','d','e','f','g','h','\0'};
	cout <<s<<endl;
	shiftString(s,3);
	cout <<s<<endl;
	
	
}
