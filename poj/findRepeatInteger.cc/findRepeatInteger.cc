#include<iostream>
using namespace std;
int findRepeatInt(int a[],int n){
	for(int i=0;i<n;i++){
		if(a[i]<0){
			continue;
		}

		int j=i;
		int start = i;

		while(a[j]>=0){
			int temp = a[j];
			a[j] = -1;
			j = temp;
		}

		if(a[j]<0&&j!=start){
			return j;
		}
	}

}
int main(){
	int a[] = {0,1,2,3,4,5,6,7,2};
	cout << findRepeatInt(a,9)<<endl;

}
