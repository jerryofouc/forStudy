#include<iostream>
using namespace std;
void print(int a[],int n){
	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
const int maxn = 100;
void da(int *r,int *sa,int n,int m){
	int wa[maxn],wb[maxn],wv[maxn],ws[maxn],*x = wa,*y=wb,*t;
	for(int i=0;i<m;i++){
		ws[i] = 0;
	}
	for(int i=0;i<n;i++){
		ws[x[i]=r[i]]++;
	}
	for(int i=1;i<m;i++){
		ws[i] += ws[i-1];
	}
	for(int i=n-1;i>=0;i--){
		sa[--ws[x[i]]] = i;
	}
	for(int j=1,p=1;p<n;j*=2,m=p){
		for(p=0,i=n-j;i<n;i++){
			y[p++] = i;
		}
		for(int i=0;i<n;i++){
			if(sa[i]>=j){
				y[p++] = sa[i]-j;
			}
		}
	}

}

int main(){
	int a[8] =  {'a','a','b','a','a','a','a','b'};
	int sa[8];
	da(a,sa,8,256);
}
