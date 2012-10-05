#include<iostream>
#include<queue>
using namespace std;
int answer = 0;
int w,h;
struct Node{
	int i;
	int j;
	int h;
};
int cover[300][300];
int board[300][300];
bool operator<(const Node &a,const Node &b){
	return a.h > b.h;
}
void dfs(int i,int j,priority_queue<Node> &que,int height){
	//top
	if(i-1>=0&&cover[i-1][j]==0){
		cover[i-1][j] = 1;
	//	cout<<"top"<<endl;
		if(board[i-1][j]<height){
			answer += height-board[i-1][j];		
			dfs(i-1,j,que,height);
		}else{
			Node a;
			a.i=i-1;
			a.j=j;
			a.h = board[i-1][j];
			que.push(a);		
		}
	}	
	//bottom
	if(i+1<h&&cover[i+1][j]==0){
		cover[i+1][j] = 1;
		//cout<<"bottom"<<endl;
		if(board[i+1][j]<height){
			answer += height-board[i+1][j];		
			dfs(i+1,j,que,height);
		}else{
			Node a;
			a.i=i+1;
			a.j=j;
			a.h = board[i+1][j];
			que.push(a);		
		}
	}	
	//left
	if(j-1>=0&&cover[i][j-1]==0){
		//cout<<"left"<<endl;
		cover[i][j-1] = 1;
		if(board[i][j-1]<height){
			answer += height-board[i][j-1];		
			dfs(i,j-1,que,height);
		}else{
			Node a;
			a.i=i;
			a.j=j-1;
			a.h = board[i][j-1];
			que.push(a);		
		}
	}	
	//right
	if(j+1<w&&cover[i][j+1]==0){
		cover[i][j+1] = 1;
		//cout<<"right"<<endl;
		if(board[i][j+1]<height){
			answer += height-board[i][j+1];		
			dfs(i,j+1,que,height);
		}else{
			Node a;
			a.i=i;
			a.j=j+1;
			a.h = board[i][j+1];
			que.push(a);		
		}
	}	
}
int main(){
	priority_queue<Node> que;
	cin>>w>>h;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>board[i][j];
		}
	}
	for(int i=0;i<w;i++){
		Node a,b;
		a.i = 0;
		b.i = h-1;
		a.j = i;
		b.j = i;
		a.h = board[0][i];
		b.h = board[h-1][i];
		cover[0][i] = 1;
		cover[h-1][i] = 1;
		que.push(a);
		que.push(b);
	}
	for(int i=0;i<h;i++){
		Node a,b;
		a.i = i;
		b.i = i;
		a.j = 0;
		b.j = w-1;
		a.h = board[i][0];
		b.h = board[i][w-1];
		cover[i][0] = 1;
		cover[i][w-1] = 1;
		que.push(a);
		que.push(b);
	}
	while(!que.empty()){
		Node min = que.top();
		//cout << min.i<<" " << min.j<<endl;
		que.pop();
		dfs(min.i,min.j,que,min.h);
	}
	cout << answer<<endl;

}
