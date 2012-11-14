#include<iostream>
using namespace std;
void countingSort(int a[],int n,int k){
	int *pk = new int[k];	
	for(int i=0;i<k;i++){
		pk[i] = 0;	
	}
	for(int i=0;i<n;i++){
		pk[a[i]]++;	
	}
	for(int i=1;i<k;i++){
		pk[i] += pk[i-1];	
	}
	int* temp = new int[n];
	for(int i=n-1;i>=0;i--){
		temp[--pk[a[i]]] = a[i];
	}
	for(int i=0;i<n;i++){
		a[i] = temp[i];
	}
	delete[] pk;
	delete[] temp;
}
void printArray(int a[],int n){
	for(int i=0;i<n;i++){
		cout <<a[i]<<" ";
	}
	cout << endl;

}
int main(){
	int a[20] = {1,2,4,5,3,3,4,5,6,3,2,6,7,8,9,0,3,3,5,6};
	printArray(a,20);
	countingSort(a,20,10);
	printArray(a,20);
	
}
