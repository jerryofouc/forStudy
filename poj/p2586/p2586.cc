#include<iostream>
using namespace std;
int x[12];
int sum(){
	int sum = 0;
	for(int i=0;i<12;i++){
		sum+= x[i];
	}
	return sum;
}
void print(){
	for(int i=0;i<12;i++){
		cout<< x[i]<<" ";
	}
	cout << endl;
}
bool canSolve(int x5,int x6){
	x[5] = x5;x[6] = x6;
	int ss = 0;
	for(int j=1;j<=5;j++){
		ss+=x[j];
	}
	for(int i = 5;i<11;){
		if(ss>0){
			break;
		}else{
			ss -= x[i-4];
			ss += x[++i];
		}
	}		
	if(ss<0&&sum()>0){
		return true;	
	}
	return false;
}
int main(){
	int s,d;
	while(cin>>s>>d){
		int i = 1;
		for( i=1;i<=5;i++){
			if((5-i)*s-i*d<0){
				break;
			}
		}
		for(int j=0;j<5;j++){
			if(j<5-i){
				x[j] = s;
			}else{
				x[j] = -d;
			}
		}
		for(int j=0;j<5;j++){
			x[11-j] = x[j];
		} 
		int a[4][2] ={{s,s},{-d,s},{s,-d},{-d,-d}};
		int flag = 0;
		for(int j=0;j<4;j++){
			if(canSolve(a[j][0],a[j][1])){
				cout << sum()<<endl;		
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			cout<<"Deficit"<<endl;
		}
	}
}
