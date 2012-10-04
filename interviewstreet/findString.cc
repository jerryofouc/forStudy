#include<iostream>
#include<strng>
#include<vector>
#include<set>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<string> v;
	set<string> string_set;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		v.push_back(s);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=j;k<v[i].size();k++){
				string temp = v[i].substr(j,k-j+1);
				string_set.insert(temp);		
			}
		}
	}
	v.clear();
	for(set<string>::const_iterator ite=string_set.begin();ite!=string_set.end();ite++){ v.push_back(*ite);		
	}

	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int k;
		cin>>k;
		if(k>v.size()){
			cout << "INVALID"<<endl;
		}else{
			cout << v[k-1]<<endl;
		}
	}
}
