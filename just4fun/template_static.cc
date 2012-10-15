#include<iostream>
using namespace std;
int g = 0;
template<typename T>
class B{
	public:
		int static fun(){
			static int value = ++g;
			return value;
		}
};
int main(){
	cout << B<int>::fun()<<endl;	
	cout << B<char>::fun()<<endl;	
	cout << B<int>::fun()<<endl;	
	cout << B<long>::fun()<<endl;	
	return 0;
}
