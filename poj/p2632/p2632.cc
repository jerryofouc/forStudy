#include<iostream>
using namespace std;
int A,B;
int turnR(int di,int repeat){
	return (di+repeat)%4;
}
int turnL(int di,int repeat){
	return (di-repeat+repeat*4)%4;
}
struct state{
	int i;
	int j;
	int di;
};
state s[101];
int board[101][101];
struct intr{
	int i;	
	char action;
	int repeat;
};
intr ii[101];
bool forward(state &ss,int r){
	board[ss.i][ss.j] = 0;
	if(ss.di == 0){
		ss.j++;	
	}else if(ss.di==1){
		ss.i--;
	}else if(ss.di==2){
		ss.j--;
	}else if(ss.di==3){
		ss.i++;
	}
	if(ss.i==0||ss.i==B+1||ss.j==0||ss.j==A+1){
	//	cout << "ss.i:"<<ss.i<<"ss.j"<<ss.j<<endl;
		cout << "Robot "<<r<<" crashes into the wall"<<endl;
		return false;
	}
	if(board[ss.i][ss.j]!=0){
		//cout << "dddd"<<endl;
		cout << "Robot "<<r<<" crashes into robot "<<board[ss.i][ss.j]<<endl;
		return false;
	}
	board[ss.i][ss.j] = r;
	return true;
}
void print(){
	for(int j=1;j<=B;j++){
		for(int k=1;k<=A;k++){
			cout << board[j][k]<<" ";
		}
		cout <<endl;
	}

}
bool step(int r,char action,int repeat){
	//cout << "step::"<<s[r].i<<" "<<s[r].j<<endl;
	if(action == 'F'){
		for(int i=0;i<repeat;i++){
			//cout << "FFF"<<endl;
			if(!forward(s[r],r)){
				return false;
			}
		}
	}else if(action == 'L'){
		s[r].di = turnL(s[r].di,repeat);		
	}else{
		s[r].di = turnR(s[r].di,repeat);		
	}
	return true;

}
int main(){
	int tn;
	cin>>tn;
	for(int i=0;i<tn;i++){
		cin>>A>>B;
		//cout<<"A:"<<A<<"B:"<<B<<endl;
		for(int j=1;j<=B;j++){
			for(int k=1;k<=A;k++){
				board[j][k] = 0;
			}
		}
		int rn,in;
		cin>>rn>>in;
	//	cout << "rn:"<<rn<<" in:"<<in<<endl;
		for(int j=1;j<=rn;j++){
			int t1,t2;
			cin>>t1;	
			cin>>t2;	
			s[j].i=t2;
			s[j].j=t1;
			//cout << " t1:"<<t1<<" t2:"<<t2<<endl;
			//cout << "kkkk::"<<s[j].i<<" "<<s[j].j<<endl;
			char dir;
			cin>>dir;
		//	cout <<"dir:"<< dir<<endl;
			if(dir=='E'){
				s[j].di = 0;
			}else if(dir=='S'){
				s[j].di = 1;
			}else if(dir=='W'){
				s[j].di = 2;
			}else if(dir=='N'){
				s[j].di = 3;
			}
			board[s[j].i][s[j].j] = j;
		}
		bool ok = true;

		for(int j=1;j<=in;j++){
			cin>>ii[j].i;
			cin>>ii[j].action;
			cin>>ii[j].repeat;
		}

		for(int j=1;j<=in;j++){
			if(!step(ii[j].i,ii[j].action,ii[j].repeat)){
				ok = false;
				break;
			}
		}
		if(ok){
			cout << "OK"<<endl;
		}
	}
}
