#include<iostream>
using namespace std;
void replaceBlank(char a[]){
	int numBlank = 0;
	int size = 0;
	int i = 0;
	for( i=0;a[i] != '\0';i++){
		if(a[i] == ' '){
			numBlank++;
		}
	}
	size = i;
	for(int k=size;k>=0&&numBlank>0;k--){
		int forword = numBlank*2;
		if(a[k] != ' '){
			a[k+forword] = a[k];
		}else{
			a[k+forword-2] = '%';
			a[k+forword-1] = '2';
			a[k+forword] = '0';
			numBlank--;
		}
	}

}
int main(){
	char a[30] = "I am a monster";	
	cout << a <<endl;
	replaceBlank(a);
	cout << a <<endl;
}
