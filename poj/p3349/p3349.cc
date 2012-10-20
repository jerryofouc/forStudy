#include<iostream>
using namespace std;
const int MAX = 100003;
int table[MAX];
int array[100000][6];
bool equal(int a[6],int b[6]){
	for(int i=0;i<6;i++){
		if(a[0] == b[i]){
			int k=0;
			for(k=0;k<6;k++){
				if(a[k] != b[(k+i)%6]){
					break;
				}
			}
			if(k==6){
				return true;
			}
			for(k=0;k<6;k++){
				if(a[k] != b[(i-k+6)%6]){
					break;
				}
			}
			if(k==6){
				return true;
			}
		}
	}
	return false;
}
int hashCode(int a[6]){
	int sum =0;
	for(int i=0;i<6;i++){
		sum+=a[i];
	}
	return sum%MAX;
}
void put(int k){
	int h = hashCode(array[k]);
	while(table[h]!=-1){
		h = (h+1)/MAX;
	}
	table[h] = k;
}
//return -1 :not found
//return index
int get(int a[]){
	int h = hashCode(a);
	while(table[h]!=-1&&!equal(array[table[h]],a)){
		h++;
	}
	return table[h];
}
int main(){
	for(int i =0;i<MAX;i++){
		table[i] = -1;
	}
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<6;j++){
			cin>>array[i][j];
		}
	}
	for(int i=0;i<N;i++){
		if(get(array[i])==-1){
			put(i);	
		}else{
			cout << "Twin snowflakes found."<<endl;
			return 0;
		}
	}
	cout << "No two snowflakes are alike."<<endl;
}
