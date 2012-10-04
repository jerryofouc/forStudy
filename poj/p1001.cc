#include<iostream>
#include<string>
using namespace std;

void multSingle(string& result,const string& s1,char a){
	int carry_bit = 0;
	for(int i = s1.size()-1;i>=0;i--){
		int m_temp = (a-'0')*(s1[i]-'0')+carry_bit;
		int current_bit = m_temp%10;
		result.insert(0,1,current_bit+'0');
		carry_bit = m_temp/10;
	}
	if(carry_bit != 0){
		result.insert(0,1,carry_bit+'0');
	}
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

void multiply(string& s1, const string& s2){
	string result("0");
	for(int i=s2.size()-1;i>=0;i--){
		string temp = "";
		multSingle(temp,s1,s2[i]);
		for(int j = 0;j<s2.size()-1-i;j++){
			temp.push_back('0');
		}
		add(result,temp);
	}	
	s1 = result;
}
int main(){
	string s;
	string big_int;
	int  n = 0;
	int digit_num = 0;	
	string result;
	
	while(cin>>s>>n){
		int num = n;
		digit_num = s.size() - s.find_first_of('.') -1;	
		big_int += s.substr(0,s.find_first_of('.'));	
		big_int += s.substr(s.find_first_of('.')+1,digit_num);
		result = big_int;
		num--;
		while((num--) != 0){
			multiply(result,big_int);
		}
		digit_num *= n;	
		if(digit_num < result.size()){
			cout << result.substr(0,result.size()-digit_num)<<"."<<result.substr(result.size()-digit_num,digit_num)<<endl;	
		}
		big_int = "";
	}
}
