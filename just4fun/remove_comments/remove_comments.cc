#include<iostream>
#include<stdio.h>
using namespace std;
int const s_start = 0;
int const s_2 = 1;
int const s_3 = 2;
int const s_4 = 3;
int const s_5 = 4;
int const s_6 = 5;
int const s_7 = 6;
/**
 *
 *
 *dfsdfdsfdsfdsfdsfd
 *
 */
int main(){
	char a;//input char
	int state = s_start;
	char* ss = "/////*";
	while(scanf("%c",&a)!=EOF){
		if(state == s_start){
			if(a=='/'){
				state = s_2;
			}else if(a=='\''){
				state = s_6;	
				cout << a;
			}else if(a=='\"'){
				state = s_7;	
				cout << a;
			}else{
				cout << a;
			}
		}else if(state == s_2){
			if(a=='/'){
				state = s_3;
			}else if(a=='*'){
				state = s_4;
			}
		}else if(state == s_3){
			if(a=='\n'){
				state = s_start;
			}
		}else if(state == s_4){
			if(a == '*'){
				state = s_5;
			}
		}else if(state == s_5){
			if(a == '/'){
				state = s_start;
			}else{
				state = s_4;
			}
		}else if(state == s_6){
			if(a=='\''){
				state = s_start;
			}
			cout << a;
		}else if(state == s_7){
			if(a=='\"'){
				state = s_start;
			}
			cout << a;
		}
	}
}
