#include<iostream>
using namespace std;
const int MAX = 256*256;
int bits[16];
bool isPossible(int state,int f,int &k){
	int t=0;
	int i = 0;
	int f1 = f;
	while(f){
		if(f&1){
			state ^= bits[i];
			t++;
		}		
		f = f>>1;
		i++;
	}
	if(state == 0||state==65535){
		if(t < k){
			k = t;
		}
		return true;	
	}else{
		return false;
	}
}
int main(){
	for(int i=0,k = 1;i<16;i++,k*=2){
		bits[i] = 0;
		bits[i] += k;	
		if(i%4-1>=0){//left
			bits[i] += k/2;	
		}
		if(i%4+1<=3){//right
			bits[i] += k*2;	
		}
		if(i>=4){//top
			bits[i] += k/16;	
		}
		if(i<=11){//bottom
			bits[i] += k*16;
		}
	}
	int state = 0;
	int b = 1;
	for(int i=0;i<16;i++,b*=2){
		char k;
		cin>>k;
		if(k=='w'){
			state += b;
		}
	}	
	//cout <<"state:"<< state<<endl;
	int k = 17;
	if(state == 0||state==65535){
		cout << 0<<endl;
		return 0;
	}
	for(int i=0;i<MAX;i++){
		isPossible(state,i,k);
	}
	if(k==17){
		cout <<"Impossible"<<endl;
	}else{
		cout << k <<endl;
	}
}
