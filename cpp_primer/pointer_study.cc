#include<iostream>
using namespace std;
int main(){
	char c = 'a';
	char *pc = &c;
	char *p[3],*p1[3][3],**p2[3],*(*p4)[4],(**p5)[3],(**p6)[3][3],
		(*(*p7))[3];
	p[0] = pc;	
	p1[0][0] = pc;
	p2[0] = &pc;
	(*p4)[0] = pc;
	cout << *((*p4)[0])<<endl;
//	(**p5)[0] = *pc;
//	cout <<((**p5)[0]);	
}
