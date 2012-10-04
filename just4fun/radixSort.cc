#include<iostream>
using namespace std;
void print(int data[],int n){
	for(int i=0;i<n;i++){
		cout << data[i] << " ";
	}
	cout << endl;
}
void radixSort1(int data[]){
	int temp[10];
	int order[10] = {0};
	for(int i=0;i<2;i++){
		int ra = 1;
		for(int k=0;k<i;k++){
			ra*=10;
		}
		for(int j=0;j<10;j++){
			int m = (data[j]/ra)%10;
			order[m]++;
		}
		for(int k=1;k<10;k++){
			order[k] += order[k-1];
		}
		for(int k=9;k>=0;k--){
			int m = (data[k]/ra)%10;
			temp[order[m]-1] = data[k];
			order[m]--;
		}
		for(int k=0;k<10;k++){
			data[k] = temp[k];
		}
		for(int k=0;k<10;k++){
			order[k] = 0;
		}
	}
	
}
void radixSort(int data[]){
	int temp[10][10];
	int order[10] = {0,0,0,0,0,0,0,0,0,0};
	for(int i=0;i<2;i++){
		int ra = 1;
		for(int k=0;k<i;k++){
			ra *= 10;
		}
		for(int j=0;j<10;j++){
			int m = (data[j]/ra)%10;
			temp[m][order[m]] = data[j];
			order[m]++;
		}
		for(int j=0,k=0;k<10;k++){
			for(int p = 0;p<order[k];p++){
				data[j++] = temp[k][p];
			}
		}
		for(int i=0;i<10;i++){
			order[i] = 0;
		}
	}
}
int main(){
	int data[10] = {12,34,53,56,67,43,66,23,78,99};
	print(data,10);
	radixSort1(data);
	print(data,10);
}
