#include<iostream>
using namespace std;
const int MAX = 10001;
struct Edge{
	int v;
	int t;
	Edge* next;
};
Edge* edges[MAX];
int d[MAX];

void printD(int N){
	cout<<"dddd:::"<<endl;
	for(int i=1;i<=N;i++){
		cout << d[i]<<"  ";
	}
	cout <<endl;
	cout<<"dddd:::"<<endl;
}
bool bellmanFord(int s,int N){
	for(int i=1;i<=N;i++){
		d[i] = MAX;
	}
	d[s] = 0;
	//printD(N);
	for(int i=0;i<N-1;i++){
		for(int s=1;s<=N;s++){
			for(Edge* pe = edges[s]->next;pe!=NULL;pe=pe->next){
				int e = pe->v;
				if((d[s]+pe->t) < d[e]){
					d[e] = (d[s] + pe->t);
				}
			}
		}
	}
	//printD(N);
	for(int s=1;s<=N;s++){
		for(Edge* pe = edges[s]->next;pe!=NULL;pe=pe->next){
			int e = pe->v;
			if((d[s]+pe->t) < d[e]){
				return false;
			}
		}
	}
	return true;
}
void initA(int N){
	for(int i=1;i<=N;i++){
		edges[i] = new Edge();	
		edges[i]->v = i;
		edges[i]->next = NULL;
	}
}
void printA(int N){
	for(int s=1;s<=N;s++){
		for(Edge* pe = edges[s]->next;pe!=NULL;pe=pe->next){
			cout << s <<"  "<<(pe->v)<<"  "<<(pe->t)<<endl;
		}
	}
}
int main(){
	int num;
	int N,M,W; 
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>N>>M>>W;
		int s,e,t;	
		initA(N);
		for(int j=0;j<M;j++){
			cin>>s>>e>>t;	
			Edge* ed = new Edge();
			ed->v = e;
			ed->next = edges[s]->next;
			ed->t =t;
			edges[s]->next = ed;
			ed = new Edge();
			ed->v = s;
			ed->next = edges[e]->next;
			ed->t =t;
			edges[e]->next = ed;
		}
		for(int j=0;j<W;j++){
			cin>>s>>e>>t;
			Edge* ed = new Edge();
			ed->v = e;
			ed->next = edges[s]->next;
			ed->t =-t;
			edges[s]->next = ed;
		}
		//printA(N);
		bool isYes = false;
		for(int j=1;j<=N;j++){
			if(!bellmanFord(j,N)){
				cout<<"YES"<<endl;;
				isYes = true;
				break;
			}
		}
		if(!isYes){
			cout <<"NO"<< endl;
		}
	}
}
