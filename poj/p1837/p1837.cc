#include<iostream>
using namespace std;
int d[21][15001];
int h[21];
int w[21];
int main(){
	int c,g;
	cin>>c>>g;
	for(int i=1;i<=c;i++){
		cin>>h[i];
	}
	for(int i=1;i<=g;i++){
		cin>>w[i];
	}
	for(int i=1;i<=c;i++){
		d[1][7500+w[1]*h[i]] += 1;	
	}
	for(int i=2;i<=g;i++){
		for(int j=-7500;j<=7500;j++){
			d[i][j+7500] = 0;
			for(int k=1;k<=c;k++){
				if(j-w[i]*h[k]<=7500&&j-w[i]*h[k]>=-7500){
					d[i][j+7500] += d[i-1][7500+j-w[i]*h[k]];
				}
			}
		
		}
	}
	cout << d[g][7500]<<endl;;
}
