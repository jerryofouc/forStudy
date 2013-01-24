#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int halfProb(){
	int halfMax = RAND_MAX/2;
	if(rand()<halfMax){
		return 0;
	}else{
		return 1;
	}
}

int winPro(float pro){
	int half = RAND_MAX*pro;
	if(rand()<half){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	srand(time(NULL));
	int const EXP_COUNT = 10000;
	int const MAX_MONEY = 10000;
	int winCount = 0;
	bool islose = false;
	for(int i =0;i<EXP_COUNT;i++){
		int capital = MAX_MONEY;
		while(capital>0&&capital<2*MAX_MONEY&&!islose){
			int money = 1;
			bool isWin = false;
			while(!isWin){
				if(winPro(0.5)){
					isWin = true;
					capital += money;
				}else{
					capital -= money;
					if(capital<0||capital < money*2){//lose
						islose = true;
						break;
					}
					money *=2 ;
				}
			}
		}

		if(capital>=2*MAX_MONEY&&!islose){
			winCount++;
		}else{
			if(capital>0){
				cout << "left money:"<<capital<<endl;
			}
		}
	}
	cout<<"winCount="<<winCount<<endl;
}
