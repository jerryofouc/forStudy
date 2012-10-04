#include<iostream>
using namespace std;
void print(int array[],int n);
int parent(int i){
	return (i-1)/2;
}

int leftChild(int i){
	return 2*i+1;
}

int rightChild(int i){
	return 2*i+2;
}

void maxHeapfy(int array[],int n,int i){
	int left = leftChild(i);	
	int right = rightChild(i);
	int max = i;

	if(left<n&&array[max] < array[left]){	
		max = left;
	}
	if(right <n&&array[max]<array[right]){
		max = right;
	}
	
	if(max != i){
		int temp = array[i];
		array[i] = array[max];
		array[max] = temp;
		maxHeapfy(array,n,max);
	}
}

void buildHeap(int array[],int n){
	for(int i = parent(n-1);i>=0;i--){
		maxHeapfy(array,n,i);	
	}	
}

void heapSort(int array[],int n){
	buildHeap(array,n);
	print(array,10);
	for(int i=n-1;i>=1;i--){
		int temp = array[0]	;
		array[0] = array[i];
		array[i] = temp;
		maxHeapfy(array,i,0);	
	}
}
void print(int array[],int n){
	for(int i = 0;i<n;i++){
		cout << array[i]<< " ";
	}
	cout << endl;
}
int main(){
	int array[11] = {3,5,2,4,5,1,2323,3,5,3,1};
	print(array,11);
	heapSort(array,11);
	print(array,11);
	
}
