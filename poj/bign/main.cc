#include"bign.h"
#include<iostream>
using namespace std;
int main(){
	string s1("1000000000000000");	
	string s2("999999999999999");	
	BigInteger bign1(s1); 
	BigInteger bign2(s2);
	BigInteger bign3 = bign1+bign2;
	cout << s1 <<endl;
	cout << s2 <<endl;
	printBigInteger(bign1-bign2);
}
