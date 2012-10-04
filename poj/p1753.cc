#include<iostream>
#include<queue>
using namespace std;
bool visited[65536];
int  step[65536];
bool isFinished(int state){
	if(state == 0||state == 65535){
		return true;	
	}
	return false;
}
int flip(int state,int pos){
	state ^= (1<<(15-pos));
	if(pos%4-1>=0){
		state ^= (1<<(15-(pos-1)));
	}
    if(pos%4+1<4){
		state ^= (1<<(15-(pos+1)));
	}
    if(pos-4>=0){
		state ^= (1<<(15-(pos-4)));
	}
    if(pos+4<16){
		state ^= (1<<(15-(pos+4)));
	}
	return state;
}
int main(){
	int initState = 0;
	string row;
	int lineNum = 4;

	while((lineNum--)>0&&cin>>row){
		for(int i=0;i<row.size();i++){
			switch(row[i]){
				case 'w':
					initState = initState*2;
					break;
				case 'b':
					initState = initState*2 + 1;
					break;
			}	
		}
	}

	for(int i=0;i<65536;i++){
		visited[i] = false;	
	}
	step[initState] = 0;	
	queue<int> q;
	q.push(initState);
	while(!q.empty()){
		int	currentState = q.front();		
		visited[currentState] = true;
		q.pop();
		if(isFinished(currentState)){
			cout <<step[currentState]<<endl;
			return 0;
		}

		for(int pos = 0;pos<16;pos++){
			int nextState = flip(currentState,pos);
			if(!visited[nextState]){
				step[nextState] = step[currentState] + 1;
				q.push(nextState);
			}
		}

	}
	cout << "Impossible" << endl;
}
