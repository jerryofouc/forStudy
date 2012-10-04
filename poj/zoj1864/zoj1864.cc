#include<iostream>
using namespace std;
struct bottle{
	int min;
	int max;
};
bottle bottles[101];

long amount;	
int num;
int find(int amount, int cur, int compliment){
	int min = -1;
	if(cur == num){
		return compliment > amount?0:amount-compliment;
	}
	int maxA = amount/bottles[cur].min;
	if(cur == num-1){
		return find(amount - maxA*bottles[cur].min,cur+1,compliment+maxA*(bottles[cur].max-bottles[cur].min));
	}
	for(int i=0;i<=maxA;i++){
		if(min == -1){
			min = find(amount - i*bottles[cur].min,cur+1,compliment+i*(bottles[cur].max-bottles[cur].min));
		}else {
			int ret = find(amount - i*bottles[cur].min,cur+1,compliment+i*(bottles[cur].max-bottles[cur].min));
			if(min > ret){
				min = ret;
			}
		}
	}
	return min;
}
int findAnswer(){
	return find(amount,0,0);
}
int main(){
	while(cin>>amount&&cin>>num){
		amount *= 1000;
		for(int i= 0;i<num;i++){
			cin>>bottles[i].min ;
			cin>>bottles[i].max;
		}
		cout << findAnswer()<<endl;
	}
}
