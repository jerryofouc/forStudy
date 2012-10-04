#include<iostream>
using namespace std;
int findMiddle(int a[],int starta,int na,int b[],int startb,int nb){
	if(na==1&&nb==1){
		return a[0]>b[0]?b[0]:a[0];
	}
	if(na==2&&nb==2){
		if(a[starta]<b[startb]){
			if(b[startb]<a[starta+1]){
				return b[startb];
			}else{
				return a[starta+1];
			}
		}else{
			if(a[starta]<b[startb+1]){
				return a[starta];
			}else{
				return b[startb+1];
			}
		}
	}	
	else{
		if(a[starta+na/2-1]<b[startb+nb/2-1]){
			starta = starta + na/2;	
			na = na - na/2;
			nb = nb - nb/2;
		}else{
			startb = startb + nb/2;	
			nb = nb - nb/2;
			na = na - na/2;
		}
		return findMiddle(a,starta,na,b,startb,nb);
	}
}


int main(){
	int a[] = {1,4,10,18,21,22};
	int b[] = {8,9,13,14,16,31};
	int middle = findMiddle(a,0,6,b,0,6);
	cout << middle <<endl;
}

