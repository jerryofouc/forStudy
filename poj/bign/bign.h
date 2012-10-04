#ifndef BIG_N_H
#define BIG_N_H
#include<string>
#include<iostream>
using namespace std;
const int  base = 100000000;
const int digit_num = 8;
const int max_n = 1000;
struct BigInteger{		
	int s[max_n];
	int len;

	BigInteger(const string& str){
		*this = str;	
	}

	const BigInteger operator=(const string& str){
		int l = str.size()-1;
		len = l/digit_num + 1;	
		for(int i=0;i<=len;i++){
			s[i] = 0;
		}
		for(int i = 0;i<str.size();i++){
			int k = (l - i)/digit_num+1;	
			s[k] = s[k]*10 + str[i] - '0';
		}
		return *this;
	} 
};

void printBigInteger(const BigInteger& bigN){
	for(int i = bigN.len;i>= 1;i--){
		cout << bigN.s[i]<<"  ";
	}
	cout << endl;
}
int compare(const BigInteger& a,const BigInteger& b ){
	if(a.len < b.len){
		return -1;
	}else if(a.len > b.len){
		return 1;
	}
	int len = a.len;
	for(int i = len;i > 0;i--){
		if(a.s[i]>b.s[i]){
			return 1;
		}else if(a.s[i]<b.s[i]){
			return -1;
		}else{
			continue;
		}
	}
	return 0;
}

const BigInteger operator+(const BigInteger& a,const BigInteger& b){
	BigInteger c("");
	c.s[0] = 0;
	int carry = 0;
	int i = 1;

	for( i=1 ; i<= a.len && i<= b.len;i++){	
		c.s[i] = (a.s[i]+ b.s[i] + carry)%base;
		carry = (a.s[i] + b.s[i]+ carry)/base;		
	}
	
	while(i<=a.len){
		c.s[i] = (a.s[i]+carry)%base;
		carry = (a.s[i] + carry)/base;		
		i++;
	}

	while(i<=a.len){
		c.s[i] = (a.s[i]+carry)%base;
		carry = (a.s[i] + carry)/base;		
		i++;
	}
	if(carry != 0){
		c.s[i] = carry;
		c.len = i;
	}else{
		c.len = i-1;
	}
	return c;
}
const BigInteger operator-(const BigInteger& a,const BigInteger &b){
	BigInteger c("");
	int borrow = 0;
	int i =1;
	for(i = 1;i <= b.len;i++){
		int subResult = a.s[i] - borrow -b.s[i];
		if(subResult >= 0){
			c.s[i] = subResult;
			borrow = 0;
		}else{
			c.s[i] = subResult + base;	
			borrow = 1;
		}
	}

	while(i<a.len&&a.s[i] != 0){
		int subResult = a.s[i] - borrow;
		if(subResult >= 0){
			c.s[i] = subResult;
			borrow = 0;
		}else{
			c.s[i] = subResult + base;	
			borrow = 1;
		}
		i++;
	}

	c.len = i-1;	
	for(int j=i-1;j>=1;j--){
		if(c.s[j] == 0){
			--c.len;
		}else{
			break;
		}	
	}
	return c;
}
#endif
