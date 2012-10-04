#include<iostream>
using namespace std;
int p[50001];
int pre[50001];
int next[50001]
int rank[50001];
int N =0;
int K = 0;
void makeSet(int x){
	p[x] = x;	
	rank[x] = 0;
}
int findSet(int x){
	int root = x,temp;
	while(root != p[root]){
		root = p[root];
	}
	while(x != root){
		temp = p[x];
		p[x] = root;	
		x = temp; 
	}
	return root;
}

void unionSet(int x,int y){
	x = findSet(x);
	y = findSet(y);
	if(rank[x] < rank[y]){
		p[x] = y;
	}else{
		p[y] = x;
		if(rank[x] == rank[y]){
			rank[x]++;	
		}
	}
}
bool isFalse(int say,int n1,int n2){
	bool flag = false;
	if(n1>N||n2>N||(say==2&&(n1==n2))){
		return true;
	}
	if(say==1){
		if(p[n1]!=-1&&p[n2]!=-1){
			if(findSet(n1)!=findSet(n2)){
				return true;
			}else{
				return false;
			}	
		}else{
			if(p[n1] = -1){
				makeSet(n1);	
			}
			if(p[n2] = -1){
				makeSet(n2);	
			}
			unionSet(n1,n2)	;
		}	
	}else{//say==2
		if(p[n1] != -1&&p[n2] != -1){
			if(findSet(n1) == findSet(n2)){
				return true;
			}if(next[n1]!=-1&&findSet(next[n1]) != find )	
		}
	}
}
int main(){

	cin>>N>>K;
	for(int i=1;i<=N;i++){
		p[i] = -1;	
		pre[i] = -1;	
		next[i] = -1;
	}	
	int say,n1,n2;
	int falseNum = 0;
	for(int i=0;i<K;i++){
		cin>>say>>n1>>n2;	
		if(isFalse(say,n1,n2)){
			falseNum++:
			continue;
		}else{
			
		}	
	}
}
