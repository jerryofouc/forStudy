#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
struct trip{
	int cost;
	int preference;
};
/**
int temp[5001][100];
int costs[5001][100];
int findMax(int total, int &cost,const trip trips[],int n){
	int max = 0;
	for(int i=0;i<=n;i++){
		temp[0][i] = 0;
		costs[0][i]= 0;
	}
	for(int i=0;i<=total;i++){
		temp[i][0] = 0;
		costs[i][0]= 0;
	}

	for(int i=1;i<=total;i++){
		for(int j=1;j<=n;j++){
			if(i<trips[j].cost){
				temp[i][j] = temp[i][j-1];
				costs[i][j] = costs[i][j-1];
			}else{
				if(temp[i][j-1]<trips[j].preference+temp[i-trips[j].cost][j]){
					temp[i][j] = trips[j].preference+temp[i-trips[j].cost][j-1];
					costs[i][j] = trips[j].cost + costs[i-trips[j].cost][j-1];
					if(max < temp[i][j]){
						max = temp[i][j];
						cost = costs[i][j];
					}
				}else{
					temp[i][j] = temp[i][j-1];
					costs[i][j] = costs[i][j-1];
				}
			}
		
		}
	}
	return max;
}
*/
int f[5001];
int c[5001];

int findMax2(int total, int &cost,const trip trips[],int n){
	for(int i=0;i<=total;i++){
		f[i] = 0;	
		c[i] = 0;	
	}	

	for(int i=1;i<n;i++){
		for(int j=total;j>0;j--){
			if((j>trips[i].cost)&&( f[j]<(f[(j-trips[i].cost)]+trips[i].preference))){
				f[j] = f[j-trips[i].cost]+trips[i].preference;
				c[j] = c[j-trips[i].cost]+trips[i].cost;
			}
		}
	}

	cost = c[total];
	return f[total];

}
int main(){
	int testNum = 0;	
	cin>>testNum;//total test case
	int total = 0;
	int nd = 0;//number destination 
	int nt = 0;//number trip per destination
	trip trips[91];
	for(int i = 0;i<testNum;i++){
		string temp;
		cin>>total;	
		cin>>temp;
		cin>>nd;
		int t = 0;//numtrips
		for(int j = 0;j<nd;j++){
			cin>>temp;
			cin>>nt;
			for(int k=0;k<nt;k++){
				cin>>temp;
				cin>>temp;
				cin>>trips[++t].cost;	
				cin>>temp;
			}
		}

		for(int j=1;j<=t;j++){
			cin>>trips[j].preference;
		}
		int cost = 0;
		int max = findMax2(total,cost,trips,t);
		cout << cost<<" "<<max<<endl;;
	}
}
