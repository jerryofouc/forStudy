#include<iostream>
using namespace std;
/**
*implement a search function for a sorted rotated array. Duplacates are allowed
*Returning any one of the duplicates is acceptive
*for example, an example input array would be
*[8,9,10,3,4,5,6,7]
*which is a sorted array that has been sorted (or shifted) to the right by 3 
*positions
*/
/**
*if found return the index of the key
*if not found return -1
*
*/
int bSearch(int array[],int s ,int e, int key){
	if(s<e-1){
		int m = s + (e-s)/2;	
		if(array[m] == key){
			return m;
		}
		if(array[s]<=array[m]){
			if(key>=array[s]&&key<array[m]){
				return bSearch(array,s,m-1,key);	
			}else{
				return bSearch(array,m+1,e,key);
			}
		}else{
			if(key>array[m]&&key<=array[e]){
				return bSearch(array,m+1,e,key);
			}else{
				return bSearch(array,s,m-1,key);
			}
		}
	}else{
		if(array[s] == key){
			return s;
		}else if(array[e] == key){
			return e;
		}else{
			return -1;
		}	
	}	
}
void printArray(int array[],int n){
	for(int i=0;i<n;i++){
		cout <<array[i]<<" ";
	}
	cout <<endl;
}
int main(){
	int a1[1] = {1};	
	cout <<"case 1:"<<endl;
	printArray(a1,1);
	cout <<"found case index:"<< bSearch(a1,0,0,1)<<endl;
	cout <<"nost found case index:"<< bSearch(a1,0,0,0)<<endl;
	cout <<"case 2:"<<endl;
	int a2[2] = {1,2};	
	printArray(a2,2);
	cout <<"found case index:"<< bSearch(a2,0,1,1)<<endl;
	cout <<"nost found case index:"<< bSearch(a2,0,1,3)<<endl;
	cout <<"case 3:"<<endl;
	int a3[2] = {2,1};	
	printArray(a3,2);
	cout <<"found case index:"<< bSearch(a3,0,1,1)<<endl;
	cout <<"nost found case index:"<< bSearch(a3,0,1,3)<<endl;
	cout <<"case 4:"<<endl;
	int a4[9] = {5,6,7,8,9,1,2,3,4};	
	printArray(a4,9);
	cout <<"found case index:"<< bSearch(a4,0,8,1)<<endl;
	cout <<"nost found case index:"<< bSearch(a4,0,8,10)<<endl;
}
