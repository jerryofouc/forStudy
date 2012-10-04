#include<iostream>
#include<string>
using namespace std;
void multSingle(string& s1,char a){
	int carry_bit = 0;
	string result;
	for(int i = s1.size()-1;i>=0;i--){
		int m_temp = (a-'0')*(s1[i]-'0')+carry_bit;
		int current_bit = m_temp%10;
		result.insert(0,1,current_bit+'0');
		carry_bit = m_temp/10;
	}
	if(carry_bit != 0){
		result.insert(0,1,carry_bit+'0');
	}
	s1 = result;
}
void add(string& s1,const string& s2){
	int carry_bit = 0;	
	string result;
	int i = s1.size()-1,j=s2.size()-1;
	for(;i>=0&&j>=0;i--,j--){
		int current = (s1[i]-'0') + (s2[j] - '0') + carry_bit;	
		carry_bit = current/10;
		result.insert(0,1,current%10+'0');	
	}
	while(i>=0){
		int current = (s1[i]-'0') + carry_bit;
		carry_bit = current/10;
		result.insert(0,1,current%10+'0');	
		i--;
	}
	while(j>=0){
		int current = (s2[j]-'0') + carry_bit;
		carry_bit = current/10;
		result.insert(0,1,current%10+'0');	
		j--;
	}
	s1 = result;
}
int main(){
	string s1("0");
	string s2("13212");
	add(s1,s2);
	cout << s1 <<endl;;
}
