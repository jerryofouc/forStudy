#include<iostream>
#include<map>
using namespace std;
int main(){
	double sum = 0;
	double hash[278];
	for(int i =1;i< 278;i++){
		sum += 1.0/(i+1);
		hash[i] = sum;
	}	
	double input;
	while(cin>>input){
		if(input == 0){
			break;
		}
		
		int low = 1,high = 277;
		while(low <= high){
			int mid = low + (high-low)/2;
			if(input < hash[mid]){
				high = mid-1;
			}else if(input > hash[mid]){
				low = mid +1;
			}else{
				low = mid;
				break;
			}
		}
		
		cout<<low << " card(s)"<<endl;
	}
}
