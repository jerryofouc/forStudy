#include<iostream>
using namespace std;

int main(){
	const double pi = 3.14159265;
	int num;
	cin>> num;
	int i=1;
	while((num--)>0){
		double a,b;
		cin >> a>>b;
		double erea = pi*(a*a+b*b)/2;
		int year = (int)(erea/50) + 1;
		cout << "Property "<<i++<<": This property will begin eroding in year "<<year<<"."<<endl;
	}
	cout << "END OF OUTPUT."<<endl;
}
