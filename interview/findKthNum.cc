#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int getRnd(int low,int high){
	int range = high - low;
	return (low + int(range*(rand()/(RAND_MAX+1.0))+0.5));
}
void swap(int *a,int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int partition(int a[],int start, int end){
	int i=start,j=start-1;
	for(;i<end;i++){
		if(a[i]<a[end]){
			swap(a[i],a[++j]);
		}
	}
	swap(&a[++j],&a[end]);
	return j;
}

int findKthNum(int a[],int start,int end,int k){
	int m = partition(a,start,end);
	if(m == k){
		return a[m];
	}else if(k<m){
		return findKthNum(a,start,m-1,k);	
	}else{
		return findKthNum(a,m+1,end,k);
	}
		
}
int main(){
	srand((unsigned)time(0));
	int a[10] = {2,3,5,6,2,32,5,6,23,4};
	cout << findKthNum(a,0,9,9)<<endl;
}
