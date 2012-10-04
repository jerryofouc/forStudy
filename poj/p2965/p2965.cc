#include<iostream>
using namespace std;
int MAX = 256*256;
int tm[16];
void initTm(){
	for(int i=0;i<16;i++){
		tm[i] = 0;
		for(int j=0;j<4;j++){
			tm[i] += 1<<((i/4)*4+j);
		}
		for(int j=0;j<4;j++){
			tm[i] += 1<<(j*4+i%4);
		}
		tm[i] -= 1<<((i/4)*4+i%4);
	}
}

int find(int t,int state){
	int k = 0;
	int time = 0;
	while(t){
		if(t&1){
			state ^= tm[k];
			time++;
		}
		k++;
		t>>=1;
	}
	return state==0?time:17;
}
int main(){
	initTm();
	int state = 0;
	for(int i=0;i<16;i++){
		char t;
		cin>>t;
		if(t == '+'){
			state+=(1<<i);
		}
	}
	int min = 17;
	int min_i;
	for(int i=0;i<MAX;i++){
		int t = find(i,state);
		if(min>t){
			min = t;
			min_i = i;
		}
	}
	cout<<min<<endl;
	int k=0;
	while(min_i){
		if(min_i&1){
			cout << (k/4+1)<<" ";
			cout << (k%4+1)<<endl;
		}		
		k++;
		min_i>>=1;
	}
}
