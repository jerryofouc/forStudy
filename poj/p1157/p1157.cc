#include<iostream>
using namespace std;
int map[100][100];
int state[100][100];//status
int main(){	
	int F,V;
	cin>>F>>V;
	for(int i=0;i<F;i++){
		for(int j=0;j<V;j++){
			cin>>map[i][j];
		}	
	}
	state[0][0] = map[0][0];

	for(int i=1;i<V;i++){//init state
		if(map[0][i]>state[0][i]){
			state[0][i] = map[0][i];
		}else{
			state[0][i] = state[0][i-1];
		}	
	}

	for(int i=1;i<F;i++){
		state[i][i] = state[i-1][i-1]+map[i][i];
		for(int j=i+1;j<V;j++){
			if(state[i-1][j-1]+map[i][j]>state[i][j-1]){
				state[i][j] = state[i-1][j-1]+map[i][j] ;
			}else{
				state[i][j] = state[i][j-1];
			}
		}	
	}
	cout << state[F-1][V-1]<<endl;
}
