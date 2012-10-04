#include<iostream>
#include<string>
using namespace std;

int countSimilarity(const string &s1){
	int count = s1.size();;
	for(int i=1;i<s1.size();i++){
		for(int j=i;j<s1.size();j++){
			if(s1[j] == s1[j-i]){
				count++;	
			}else{
				break;
			}
		}
	}
	return count;
}
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		string s;
		cin>>s;
		cout<<countSimilarity(s)<<endl;
	}
}
