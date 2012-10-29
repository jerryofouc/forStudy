#include<iostream>
using namespace std;
const int MAX = 10001;
int a[501][501];
int d[501];
void printD(int N){
	cout << "D::::"<<endl;
	for(int i=0;i<N;i++){
		cout << d[i]<<" ";
	}
	cout << endl;

}
bool bellmanFord(int s,int N){
	for(int i=1;i<=N;i++){
		d[i] = MAX;
	}
	d[s] = 0;
	for(int i=0;i<N-1;i++){
		for(int j=1;j<=N;j++){
			for(int k=1;k<=N;k++){
				if(j!=k&&a[j][k]<MAX){
					if(d[k]>a[j][k]+d[j]){
						d[k] = a[j][k] + d[j];
					}
				}
			}
		}
	}
	for(int j=1;j<=N;j++){
		for(int k=1;k<=N;k++){
			if(j!=k&&a[j][k]<MAX){
				if(d[k]>a[j][k]+d[j]){
					return false;
				}
			}
		}
	}
	return true;
}
void initA(int N){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(i==j){
				a[i][j] = 0;
			}else{
				a[i][j] = MAX;
			}
		}
	}
}
void printA(int N){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout << a[i][j]<<" ";
		}
		cout << endl;
	}
}
int main(){
	int num;
	int N,M,W; 
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>N>>M>>W;
		int s,e,t;	
		initA(N);
		for(int j=0;j<M;j++){
			cin>>s>>e>>t;	
			if(t<a[s][e]){
				a[s][e] = t;
			}
			if(t<a[e][s]){
				a[e][s] = t;
			}
		}
		for(int j=0;j<W;j++){
			cin>>s>>e>>t;
			a[s][e] = -t;
		}
		bool isYes = false;
		for(int j=1;j<=N;j++){
			if(!bellmanFord(j,N)){
				cout<<"YES"<<endl;;
				isYes = true;
				break;
			}
		}
		if(!isYes){
			cout <<"NO"<< endl;
		}
	}
}
