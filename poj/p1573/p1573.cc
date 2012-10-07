#include<iostream>
using namespace std;
int rows,cols,sj;
char instr[101][101];
int state[101][101];
bool isExitorLoop(int si,int sj,int steps){
	if(si==0||si==rows+1||sj==0||sj==cols+1){
		cout << steps-1<< " step(s) to exit"<<endl;
		return true;
	}else if(state[si][sj] != 0){
		cout << state[si][sj]-1<<" step(s) before a loop of "<<steps-state[si][sj]<<" step(s)"<<endl;
		return true;
	}
	return false;
}
int main(){
	while(cin>>rows>>cols>>sj){
		if(rows==0&&cols==0&&sj==0){
			return 0;
		}
		for(int i=1;i<=rows;i++){
			for(int j=1;j<=cols;j++){
				cin>>instr[i][j];
				state[i][j] = 0;
			}
		}
		int si=1;
		int steps = 1;
		while(!isExitorLoop(si,sj,steps)){
			state[si][sj]=steps++;
			switch(instr[si][sj]){
				case 'N':si--;break;
				case 'E':sj++;break;
				case 'S':si++;break;
				case 'W':sj--;break;
			}
		}
	}
}
