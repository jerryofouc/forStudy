/**
**
*从一个长字符串中查找包含给定字符集合的最短子串。
*例如，长串为“aaaaaaaaaacbebbbbbdddddddcccccc”，字符集为{abcd}，
*那么最短子串是“acbebbbbbd”。
*如果将条件改为“包含且只包含给定字符集合”，
*你的算法和实现又将如何改动。
*思想是滑动窗口
*/

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
