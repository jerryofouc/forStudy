#include<iostream>
using namespace std;

struct Edge{
	int start;
	int end;
	double rate;
	double commission; 
};
Edge edges[201];
int d[101];
double esp = 1e-8;

int main(){
	int N,M,S;
	double V;
	cin>>N>>M>>S>>V;
	for(int i=0;i<2*M;){
		int start,end;
		cin>>start>>end;
		edges[i].start = start;
		edges[i].end = end;
		cin>>edges[i].rate;
		cin>>edges[i].commission;
		i++;
		edges[i].start = end;
		edges[i].end = start;
		cin>>edges[i].rate;
		cin>>edges[i].commission;
		i++;
	}
	for(int i=1;i<=N;i++){
		d[i] = 0;	
	}
	d[S] = V;	
	while(d[S]<= V+esp){
		bool flag = true;
		for(int k=0;k<2*M;k++){
			if(d[edges[k].end]+esp<(d[edges[k].start]-edges[k].commission)*edges[k].rate){
				d[edges[k].end] = (d[edges[k].start]-edges[k].commission)*edges[k].rate;
				flag = false;
			}
		}	
		if(flag){
			if(d[S]<=V+esp){
				cout << "NO"<<endl;
			}else{
				cout << "YES"<<endl;
			}
			return 0;
		}
	}		
	
		if(d[S]<=V+esp){
			cout << "NO"<<endl;
		}else{
			cout << "YES"<<endl;
		}
		return 0;
}

