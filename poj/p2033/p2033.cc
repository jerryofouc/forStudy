#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> mem(1000000);
int countNum(const string &encode,int start){
	if(encode.size()==start){
		return 1;
	}
	int firstC = countNum(encode,start+1);
	int secondC = 0;
	if(start<encode.size()-1&&(((encode[start]-'0')*10+encode[start+1]-'0'))<27){
		secondC = countNum(encode,start+2);
	}
	return (firstC + secondC);
}

int countNum2(const string &encode){
	int start = 0;
	mem[0] = 1;
	mem[1] = 0;
	if(encode[start+1]!='0'){
		mem[1]++;
	}
	if((((encode[start]-'0')*10+encode[start+1]-'0'))<27){
		mem[1]++;	
	}
	if(mem[1] == 0)return 0;
	for(int i=2;i<encode.size();i++){
		int first = 0,second =0;
		first = mem[i-1];
		second=mem[i-2];
		if(encode[i]-'0' == 0){
			first = 0;
		}
		if((((encode[i-1]-'0')*10+encode[i]-'0'))>=27||encode[i-1]=='0'){
			second=0;
		}
		if(!first&&!second){
			return 0;
		}
		mem[i] = first + second;
	}
	return mem[encode.size()-1];
}

int main(){
	string encode;
	cin >>encode;
	while(encode != "0"){
		cout << countNum2(encode)<<endl;;
		cin >>encode;
	}
}
