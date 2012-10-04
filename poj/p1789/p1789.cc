#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int INFINIT_D = 10; 
int map[2000][2000];
int key[2000];

int computeD(const string& s1,const string& s2){
	int d = 0;
	for(int i=0;i<s1.size();i++){
		if(s1[i] != s2[i]){
			d++;
		}
	}
	return d;
}
int sum;
int main(){
	int count = 0;
	vector<string> vec;	
	bool visited[2000];
	while((cin>>count)&&count != 0){
		for(int i =0;i<count;i++){
			visited[i] = false;
		}
		for(int i=0;i<count;i++){
			string s;	
			cin>>s;
			vec.push_back(s);
		}	
		for(int i=0;i<vec.size();i++){
			for(int j=i+1;j<vec.size();j++){
				map[i][j]=map[j][i] = computeD(vec[i],vec[j]);
			}
		}
		for(int i=0;i<count;i++){
			key[i] = INFINIT_D;
		}
		key[0] = 0;
		for(int i=0;i<count;i++){
			int min = INFINIT_D;
			int min_i = -1;
			for(int j=0;j<count;j++){
				if(!visited[j]&&min > key[j]){
					min = key[j];
					min_i = j;
				}
			}
			visited[min_i] = true;
			for(int k = 0;k<count;k++){
				if(!visited[k]&&map[min_i][k]<key[k]){
					key[k] = map[min_i][k];
				}
			}
		}		
		sum = 0;
		for(int i=0;i<count;i++){
			sum+=key[i];
		}
		cout << "The highest possible quality is 1/"<<sum <<"." <<endl;
		vec.clear();
	}
}
