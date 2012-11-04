#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const int inf = 0x7ffffff;
struct Node{
	int x;
	int y;
};
Node nodes[200];
double matrix[200][200];
double d[200];
int vis[200];
int findMin(int n){
	int ret = -1;
	int min = inf;
	for(int i=0;i<n;i++){
		if(!vis[i]&&d[i]<min){
			min = d[i];
			ret = i;
		}
	}
	return ret;
} 
double max(double x,double y){
	return x>y?x:y;
}
void relax(int min,int j){
	if(d[min]<d[j]&&matrix[min][j]<d[j]){
		d[j] = max(d[min],matrix[min][j]);
		//cout <<"d[j]"<<endl;
	}
}
void dijkstra(int n){
	d[0] = 0;
	vis[0] = 0;
	for(int i=1;i<n;i++){
		d[i] = matrix[0][i];		
		vis[i] = 0;
	}
	for(int i=0;i<n-1;i++){
		int min = findMin(n);
		//cout << "min:"<<min<<endl;
		for(int j=0;j<n;j++){
			if(!vis[j]&&j!=min){
				relax(min,j);
			}
		}
		vis[min] = 1;
	}
}
double distance(int x1,int y1,int x2,int y2){
	return sqrt((double)(x1-x2)*(x1-x2) + (double)(y1-y2)*(y1-y2));
}
void printM(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<matrix[i][j]<<" "<<endl;
		}
		cout <<endl;
	}
}
int main(){
	int n;
	int test = 1;
	while(cin>>n&&n!=0){
		for(int i=0;i<n;i++){
			cin>>nodes[i].x;
			cin>>nodes[i].y;
			for(int j=0;j<=i;j++){
				matrix[i][j] = distance(nodes[i].x,nodes[i].y,nodes[j].x,nodes[j].y);
				matrix[j][i] = matrix[i][j];
			}
		}	
		//printM(n);
		dijkstra(n);
		cout << "Scenario #" <<test++<<endl;
		cout << "Frog Distance = "<<std::setiosflags(ios::fixed)<<std::setprecision(3)<<d[1]<<endl;
		cout <<endl;
	}
}
