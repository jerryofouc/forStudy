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
int hashFun(int a[6]){
	int sum =0;
	for(int i=0;i<6;i++){
		sum+=a[i];
	}
	return sum%MAX;
}
void put(int k){
	int h = hashFun(array[k]);
	if(table[h] == -1){
		table[h] = k;
	}else{
		int j = h+1;
		while(table[j%MAX] != -1){
			j++;
		}
		table[j] = k;
	}
}
int get(int a[]){
	int h = hashFun(a);
	//cout << "h:"<<h<<endl;
	int index = table[h];
	//cout << "index "<<index<<endl;
	while(index!=-1){
		if(equal(array[index],a)){
			//cout << "equal"<<endl;
			return index;
		}
		h++;
		index = table[h];
	}
	return index;
}
int main(){
	int aa[] = {1,2,3,4,5,6};
	int bb[] = {6,5,4,3,2,1};
	if(equal(aa,bb)){
		//cout << "ddd"<<endl;
		}
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
			//cout <<"put: "<<i<<endl;
		}else{
			cout << "Twin snowflakes found."<<endl;
			return 0;
		}
	}
	cout << "No two snowflakes are alike."<<endl;
}
