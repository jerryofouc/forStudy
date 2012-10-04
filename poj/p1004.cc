#include<iostream>
using namespace std;
int main(){
	const int n = 12;
	double sum = 0;
	for(int i = 0;i<12;i++){
		double m;
		cin>>m;
		sum += m;
	}
	double mean = sum/12;
	cout << "$"<<mean<<endl;

}
