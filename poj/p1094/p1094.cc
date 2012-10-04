#include<iostream>
using namespace std;
int d[26][26];
void initD(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			d[i][j] = 0;
		}
	}
	
}
bool isConsistent(int first,int second){
	if(d[first][second] == 1 || d[second][first]== -1){
		return false;
	}
	return true;
}
bool isFinished(int n){
	for(int i=0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(d[i][j] == 0){
				false;
			}
		}
	}
	
}
void floyd(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(d[j][i]==-1&&d[i][k]==-1){
					d[j][k] = -1;
					d[k][j] = 1;
				}
				if(d[j][i]==1&&d[i][k]==1){
					d[j][k] = 1;
					d[k][j] = -1;
			}
		}	
	}
}
void outputOrder(int m,int n,int num){
	int *order = new int[m];
	for(int k=0;k<m;k++){
		for(int i=0;i<n;i++){
			bool flag = true;
			for(int j=0;j<n;j++){
				if(d[i][j] != -1){
					flag =false;
				}
			}	
			if(flag){
				oder[k] = i+'A';	
				for(int p=0;)
			}
		}
	}
	delete order[];
}
int main(){
	int n,m;
	while((cin>>n>>m)&&(n != 0||m != 0)){
		initD(n);	
		for(int i=0;i<m;i++){
			int first,second;
			cin>>first>>second;
			int firstIndex = first-'A';
			int secondIndex = second-'A';
			if(isConsistent(firstIndex,secondIndex)){
				d[firstIndex][secondIndex] = -1;
				d[secondIndex][firstIndex] = 1;
				floyd(n);	
			}else{
				cout << "Inconsistency found after "<<i+1<<" relations."<<endl;	
				break;
			}
			if(isFinished(n)){
				outputOrder(n);	
			}
		}	
		
	}
}
