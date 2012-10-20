#include<iostream>
using namespace std;
void findMinMax(int a[],int start,int end,int &max,int &min){
	if(start==end){
		max = min = a[start];
		return ;
	}else if(end-start == 1){
		if(a[start]>a[end]){
			max = a[start];
			min = a[end];
		}else{
			min = a[start];
			max = a[end];
		}
	}
	else{
		int min1,max1,min2,max2;			
		int m = (start+end)/2;
		findMinMax(a,start,m-1,max1,min1);
		findMinMax(a,m,end,max2,min2);
		max = max1>max2?max1:max2;
		min = min1<min2?min1:min2;
	}
	
}
int main(){
	int a[9] = {1,23,44,52,2,5,6,7,5};
	int max ,min;
	findMinMax(a,0,8,max,min);
	cout << max <<":"<<min<<endl;
}
