#include<iostream>
using namespace std;
void countingSort(int a[],int n,int base);
void radixSort(int a[],int n,int bn){
	int base = 1;
	for(int i=0;i<bn;i++){
		countingSort(a,n,base);
		base *= 10;
	}
}
int getBitValue(int v,int base){
	return (v/base)%10;
}
void countingSort(int a[],int n,int base){
	int *pk = new int[10];	
	for(int i=0;i<10;i++){
		pk[i] = 0;	
	}
	for(int i=0;i<n;i++){
		pk[getBitValue(a[i],base)]++;	
	}
	for(int i=1;i<10;i++){
		pk[i] += pk[i-1];	
	}
	int* temp = new int[n];
	for(int i=n-1;i>=0;i--){
		temp[--pk[getBitValue(a[i],base)]] = a[i];
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
	int a[20] = {1222,232,433,533,333,32,44,54,336,323,52,96,87,28,39,0,333,33,45,61};
	printArray(a,20);
	radixSort(a,20,4);
	printArray(a,20);
	
}
