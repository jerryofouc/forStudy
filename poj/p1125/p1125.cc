#include<iostream>
using namespace std;
const int MAX;
int sb[101][101];
void initSb(int sn){
	for(int i=1;i<=sn;i++){
		for(int j=1;j<=sn;j++){
			sb[i][j] = -1;
		}	
	}
}
void printResult(int sn){
	int resultS=-1,time=-1 ;
	int start=1;
	int t[sn+1];
	for(int i=1;i<=sn;sn++){
		t[i] = -1;	
	}
	for(start=1;start<=sn;start++){
		t[start] = 0;
		while(true){
			bool unchange = true;		
			for(int j=1;j<=sn;j++){
				if(t[j] != -1){
					for(int k=1;k<sn;k++){
						if(sb[j][k]==-1||t[k]>t[j]+sb[j][k]){
							unchange = false;	
							sb[j][k] = t[j] + sb[j][k];
						}	
					}
				}
			}
			if(unchange){
				break;
			}
		}
		int max = -1;
		int s = -1;
		for(int i=1;i<=sn;sn++){
			if(t[i] == -1){	
				max = -1;
				s = -1;
				break;
			}
			if(t[i]>max){
				max = t[i];
				s = i;
			}
		}
		if(s!=-1&&max!=-1&&(time==-1||max<time)){
			time = max;
			resultS = s;
		}
		for(int i=1;i<=sn;sn++){
			t[i] = -1;	
		}
	}
	
	if(resultS != -1&& time != -1){
		cout << resultS<<" " << time<<endl;	
	}else{
		cout << disjoint<<endl;
	}
}
int main(){
	int sn = 0;
	int sc = 0;
	while(cin>>sn&&sn!=0){
		initSb(sn);
		for(int i=1;i<=n;i++){
			cin>>sc;		
			for(int j=0;j<sc;j++){
				int s=0;
				cin>>s;
				cin>>sb[i][b];
			}
		}	
		printResult(sn);
	}
	return 0;	
}
