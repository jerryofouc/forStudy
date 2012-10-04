#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void print(const vector<char>& par){
	for(vector<char>::const_iterator ite = par.begin();ite != par.end();++ite){
		cout << *ite;
	}
	cout << endl;
}
int main(){
	int caseCount = 0;
	vector<char> par;
	vector<int> s;
	cin >> caseCount;
	for(int i=0;i<caseCount ;i++){
		int charCount = 0;
		int num=0;	
		int curNum = 0;
		cin >> charCount;
		for(int j = 0;j<charCount;j++){
			cin>>num;
			for(int k=0;k<num-curNum;k++){
				par.push_back('(');	
			}	
			par.push_back(')');
			curNum = num;
		}
		for(vector<char>::const_iterator ite = par.begin();ite != par.end();++ite){
			if(*ite == '('){
				s.push_back(1);
			}else{
				cout << s.back();
				s.pop_back();
				if(ite != par.end()-1){
					cout << " ";
				}
				for(vector<int>::iterator ite=s.begin();ite != s.end();++ite){
					++(*ite);	
				}
			}
		}	
		cout << endl;
		par.clear();
		s.clear();
	}
}
