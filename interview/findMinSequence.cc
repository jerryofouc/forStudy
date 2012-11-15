#include<iostream>
using namespace std;
int hash[256];
void initHash(int hash[],int n) {
	for(int i=0;i<n;i++){
		hash[i] = 0;
	}
}
void findMinSequence(char *a,int &start,int &end){
	int n=0;
	for(int i=0;a[i];i++){
		n++;
	}
	int sn = 0;	
	int min = n;
	initHash(hash,256);
	for(int i=0;i<n;i++){
		if(!hash[a[i]]){
			hash[a[i]] = 1;	
			sn++;
		}
	}
	int e=0;
	for(int s=0;e<n;s++){
		initHash(hash,256);
		int num=0;
		e=s;
		for(;e<n&&num<sn;e++){
			hash[a[e]]++;
			if(hash[a[e]]==1){
				num++;
			}
		}
		while(hash[a[s]]>1){
			hash[a[s]]--;
			s++;
		}
		if(e-s<min){
			min = e-s;
			start=s;
			end = e-1;
		}
	}
}
int main(){
	char s[] = "aaaaaaaaaacbedbbbbbbbbddddddccccc";
	int start,end;
	findMinSequence(s,start,end);
	for(int i=start;i<=end;i++){
		cout << s[i];
	}
	cout <<endl;
}
