#include<iostream>
#include<string.h>
using namespace std;
/**
*Inverse words of a sentence:such as input "Jack likes Mary"
*output:"Mary likes Jack"
*
*
*/
bool isAlpha(char c){
	if(c<='z'&&c>='a'||c<='Z'&&c>='A'){
		return true;
	}
	return false;
}
void swap(char* c1,char* c2){
	char temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}
void reverse(char* sentence){
	int l = strlen(sentence);
	for(int s =0,e=l-1;s<e;s++,e--){
		swap(sentence[s],sentence[e]);
	}
	bool lastIsBlank = true;
	int s,e;
	for(int i=0;i<=l;i++){
		if(isAlpha(sentence[i])&&lastIsBlank){
			s = i;	
			lastIsBlank = false;
		}else if(!isAlpha(sentence[i])&&!lastIsBlank){
			e = i-1;
			while(s<e){
				swap(sentence[s],sentence[e]);
				s++;
				e--;
			}
			lastIsBlank = true;
		}
	}
}
int main(){
	char buff[20] = "Jack love Mary";
	cout << buff<<endl;
	reverse(buff);
	cout << buff<<endl;
	char buff1[40] = "   J  love   M";
	cout << buff1<<endl;
	reverse(buff1);
	cout << buff1<<endl;
	char buff2[22] = "t";
	cout << buff2<<endl;
	reverse(buff2);
	cout << buff2<<endl;

}

