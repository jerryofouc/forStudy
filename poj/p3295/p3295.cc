#include<iostream>
#include<stack>
#include<string>
using namespace std;
int K(int a,int b){
	return a&b;
}
int A(int a,int b){
	return a|b;
}
int N(int a){
	return !a;
}
int C(int a,int b){
	if(a==b)return 1;
	if(a==0&&b==1){
		return 1;
	}
	return 0;
}
int E(int a,int b){
	return !(a^b);
}
int dVal(char s,int var){
	switch(s){
		case 'p':
			return (16&var)!=0?1:0;
		case 'q':
			return (8&var)!=0?1:0;
		case 'r':
			return (4&var)!=0?1:0;
		case 's':
			return (2&var)!=0?1:0;
		case 't':
			return (1&var)!=0?1:0;
	}
}
bool isVar(char s){
	if(s>='a'&&s<='z'){
		return true;
	}
	return false;
}
bool isOpt(char s){
	if(s>='A' && s<='Z'){
		return true;
	}
	return false;
}
bool isDigit(char a){
	if(a == 0||a==1){
		return true;
	}
	return false;
}

void print(string s){
	for(int i =0;i<s.size();i++){
		if(s[i] == 0||s[i]==1){
			cout << (int)s[i];
		}
		else{
			cout << s[i];
		}
	}
	cout << endl;
}
int getValue(string s,int var){
	for(int i =0;i<s.size();i++){
		if(isVar(s[i])){
			s[i] = (char)dVal(s[i],var);
		}
	}
	//print(s);
	stack<int> stack;	
	int i = 0;
	stack.push(s[i++]);
	int cur ;
	while(!stack.empty()&&i<s.size()){
		if(isOpt(s[i])){
			stack.push(s[i]);	
			i++;
		}else if(isDigit(s[i])&&stack.top()=='N'){
			stack.pop();					
			s[i] = N(s[i]);	
			cur = s[i];
		}else if(isDigit(s[i])&&isDigit(stack.top())){
			int topDigit = stack.top();	
			stack.pop();
			int opter = stack.top();
			stack.pop();
			switch(opter){
				case 'K':
					s[i]=K(s[i],topDigit);
					cur = s[i];
					 break;
				case 'A':
					s[i]=A(s[i],topDigit);
					cur = s[i];
					break;
				case 'C':
					s[i]=C(s[i],topDigit);
					cur = s[i];
					break;
				case 'E':
					s[i]=E(s[i],topDigit);
					cur = s[i];
					break;
			}	
		}else{
			stack.push(s[i]);	
			i++;
		}	
	}
	return cur;
}
int main(){
	string s;
	while(cin>>s){
		if(s=="0"){
			break;
		}
		//cout <<"result:"<< result<<endl;
		bool isTau = true;
		for(int i=0;i<32;i++){
			int cur = getValue(s,i);
		//	cout <<i<<" cur:"<< cur<<endl;
			if(1 != cur){
				cout << "not"<<endl;
				isTau = false;
				break;
			}
		}	
		if(isTau){
			cout << "tautology"<<endl;
		}
	}
}
