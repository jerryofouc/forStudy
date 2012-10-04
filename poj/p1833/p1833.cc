#include<iostream>
using namespace std;
int a[1025];
void swap(int *a,int *b){
	*a = (*a)^(*b);
	*b = (*a)^(*b);
	*a = (*a)^(*b);
}
void nextPermulation(int n){
	if(n<=1){
		return ;
	}	
	int m = n-2;
	while(m>=0&&a[m]>a[m+1]){
		m--;
	}
	if(m<0){
		int s=0;
		int e=n-1;
		while(s<e){
			swap(&a[s],&a[e]);
			s++;
			e--;
		}
		return ;
	}
	int i = n-1;
	while(i>m&&a[i]<a[m]){
		i--;	
	}
	swap(a+m,a+i);
	int p=m+1;
	int q=n-1;
	while(p<q){
		swap(&a[p],&a[q]);
		p++;
		q--;
	}
}
int main(){
	int caseN;	
	cin>>caseN;
	int n,k;
	for(int i=0;i<caseN;i++){
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<k;i++){
			nextPermulation(n);
		}
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout << endl;
	}
}
