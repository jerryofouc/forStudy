#include<iostream>
#include<cstring>
using namespace std;
int const MAX_NUM = 16000005;
char s[MAX_NUM];
int ascii[256];
int hash[MAX_NUM];
int main(){
	int N =0,NC =0;	
	cin>>N>>NC;
	memset(hash,-1,sizeof(hash));
	memset(ascii,-1,sizeof(ascii));
	int i,j;
	cin>>s;
	int len = strlen(s);
	for(i=0,j=0;i<len;i++){
		if(ascii[s[i]] == -1){
			ascii[s[i]] = j++;
		}
		if(j==NC){
			break;
		}
	}
	int totalNum = 0;
	for(i=0;i<=len-N;i++){
		int sum =0 ;
		for(j=0;j<N;j++){
			sum = sum*NC+ascii[s[i+j]];
		}
		if(hash[sum] == -1){
			totalNum++;
			hash[sum] = 1;
		}
	}
	cout << totalNum<<endl;
}
