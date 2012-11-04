/***
*this method has too much complexity
*
**/

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const int MAX = 200;
struct Node{
	int x;
	int y;
};
struct Edge{
	int s;
	int e;
};
Node nodes[200];

double matrix[MAX][MAX];
double visited[MAX][MAX]; 
Edge findMin(int n){
	int minX,minY;
	double min = -1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if((min==-1&&!visited[i][j])||
				(min!=-1&&!visited[i][j]&&matrix[i][j]<min)){
				min = matrix[i][j];
				minX = i;
				minY = j;
			}			
		}
	}
	visited[minX][minY] = 1;
	Edge ret ;
	ret.s = minX;
	ret.e = minY;
	return ret;
}
double distance(int x1,int y1,int x2,int y2){
	return sqrt((double)(x1-x2)*(x1-x2) + (double)(y1-y2)*(y1-y2));
}
double getDistance(int s,int e){
	if(s>e){
		int t = s;
		s = e;
		e = t;
	}
	return matrix[s][e];
}
double setDistance(int s,int e,double d){
	if(s>e){
		int t = s;
		s = e;
		e = t;
	}
	matrix[s][e] = d;
}
void relax(const Edge& min,int n){
	for(int i=0;i<n;i++){
		if(i == min.s||i==min.e){
			continue;
		}
		double xl = getDistance(min.s,i);
		double yl = getDistance(min.e,i);
		double ml = getDistance(min.s,min.e);
		if(ml<yl&&xl<yl){
			if(ml>xl){
				setDistance(min.e,i,ml);
			}else{
				setDistance(min.e,i,xl);
			}
		}
		else if(ml<xl&&yl<xl){
			if(ml>yl){
				setDistance(min.s,i,ml);
			}else{
				setDistance(min.s,i,yl);
			}
		}
	}
}
int main(){	
	int n;
	int count = 1;
	while(cin>>n&&n!=0){
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			nodes[i].x = x;
			nodes[i].y = y;	
		}
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				matrix[i][j] = distance(nodes[i].x,nodes[i].y,nodes[j].x,nodes[j].y);
				visited[i][j] = 0;
				if(i==j){
					visited[i][j] = 1;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j = i+1;j<n;j++){
				Edge min = findMin(n);
				relax(min,n);
			}
		}
		cout << "Scenario #" <<count++<<endl;
		cout << "Frog Distance = "<<std::setiosflags(ios::fixed)<<std::setprecision(3)<<matrix[0][1]<<endl;
		cout <<endl;
	}
}
