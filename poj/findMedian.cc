#include<iostream>
using namespace std;

int find_median(int *a,int* b,int head_a,int rear_a,int head_b,int rear_b){
	int length_a = rear_a - head_a +1;
	int length_b = rear_b - head_b +1;

	if(1==length_a&&1==length_b){
		return a[rear_a] < b[rear_b]?a[rear_a]:b[rear_b];
	}

	int half = 0;
	if(length_a>length_b){
		half = length_b/2;
	}else{
		half = length_a/2;
	}

	if(a[(rear_a+head_a)/2]>b[(rear_b+head_b)/2]){
		if(half == 0){
			return 1==length_a?b[(rear_b+head_b-1)/2]:a[(rear_a+head_a+1)/2];
		}
		rear_a = rear_a-half;
		head_b = rear_b-half;
	}
	if(a[(rear_a+head_a)/2]<b[(rear_b+head_b)/2]){
		if(half == 0){
			return 1==length_b?b[(rear_b+head_b+1)/2]:a[(rear_a+head_a-1)/2];
		}
		head_a = head_a + half;
		rear_b = rear_b - half;
	}
	else return a[length_a/2];
	return find_median(a,b,head_a,rear_a,head_b,rear_b);
}

int main(){
	int a[] = {1};
	int b[] = {4,5};
	cout << find_median(a,b,0,1,0,1)<<endl;
}
