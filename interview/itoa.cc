#include<iostream>
using namespace std;
void swap(char* buffer,int a,int b){
	int temp = buffer[a];
	buffer[a] = buffer[b];
	buffer[b] = temp;
}
char* atoi(int n){	
	bool negative = false;
	char* buffer = new char[30];
	int index = 0;
	if(n<0){
		negative = true;
		buffer[0] = '-';
		index++;
		n=-n;
	}
	while(n){
		buffer[index++] = '0' + n%10;
		n /= 10;
	}
	buffer[index] = '\0';
	int start = 0,end = index-1;
	if(negative){
		start++;
	}
	while(start<end){
		swap(buffer,start,end);
		start++;
		end--;
	}
	return buffer;
}
int main(){
	cout << atoi(-1132323)<<endl;
}
