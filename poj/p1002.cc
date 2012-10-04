#include<iostream>
#include<map>
using namespace std;
int main(){
	char a_map[26];
	int i=0;
	char j = '2';
	for(char a = 'A';a<='O';a++){
		if(i == 3){			
			j++;
			i = 0;
		}	
		i++;		
		a_map[a - 'A'] = j;
	}
	a_map['P' - 'A'] = '7';
	a_map['R' - 'A'] = '7';
	a_map['S' - 'A'] = '7';
	i = 0;
	j = '8';
	for(char a = 'T';a<='Y';a++){
		if(i == 3){			
			j++;
			i=0;
		}	
		i++;		
		a_map[a - 'A'] = j;
	}
	int n = 0;
	map<string,int> standardMap;
	cin >>n;		
	for(int i = 0;i<n;i++){
		string s;
		string t; 
		cin>>s;
		for(int i = 0,j=0;i<s.size();i++){
			if(j == 3){
				t.push_back('-');	
				j++;
			}
			if(s[i]<'Z' && s[i]>='A'){
				t.push_back(a_map[s[i]-'A']);	
				++j;
			}else if(s[i]<='9'&&s[i]>='0'){
				t.push_back(s[i]);
				++j;
			}
		}
		standardMap[t]++;
	}
	
	for(map<string,int>::const_iterator ite = standardMap.begin();ite != standardMap.end();++ite){
		if(ite->second > 1){
			cout << ite->first << " " << ite->second << endl;
		}
	}
}
