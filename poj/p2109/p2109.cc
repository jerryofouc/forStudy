#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	for(double a,b;std::cin>>a>>b;std::cout<<std::fixed<<std::setprecision(0)<<std::pow(b,1/a)<<std::endl);
	return 0;

}
