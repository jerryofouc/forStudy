#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


vector<string> vs;
struct Element;
string getStr(const vector<string> &vs,const Element &e);
struct Element{
	Element(int ii,int jj,int kk):i(ii),j(jj),k(kk){}
	int i;
	int j;
	int k;
	bool operator==(const Element& rhs)const{
		return getStr(vs,*this)==getStr(vs,rhs);
	}
};
string getStr(const vector<string> &vs,const Element &e){
	return vs[e.i].substr(e.j,e.k-e.j+1);
}

bool isExit(const vector<string> &vs,const vector<Element> &ve,const Element &e,int start,int end){
	if(start<=end){
		int mid = start+(end-start)/2;
		if(getStr(vs,e)<getStr(vs,ve[mid])){
			return isExit(vs,ve,e,start,mid-1);
		}else if(getStr(vs,e)>getStr(vs,ve[mid])){
			return isExit(vs,ve,e,mid+1,end);
		}else{
			return true;
		}
	}else{
		return false; }
}

void insert_sort(const vector<string> &vs,vector<Element> &ve){
	Element last = ve[ve.size()-1];
	for(int i=ve.size()-2;i>=0;i--){
		Element temp = ve[i];
		if(getStr(vs,last)<getStr(vs,temp)){
			Element e = ve[i];
			ve[i] = ve[i+1];
			ve[i+1] = e;
		}else{
			break;
		}
	}
}

void print(const vector<string> &vs,const vector<Element> ve){
	for(vector<Element>::const_iterator ite = ve.begin();ite!=ve.end();++ite){
		cout << getStr(vs,*ite)<<" ";
	}
	cout << endl;
}
class compare{
	public:
		bool operator()(const Element& e1,const Element &e2){
			return getStr(vs,e1)<getStr(vs,e2);	
		}
};
int main(){
	int wn ;
	cin>> wn;
	vector<Element> ve;
	for(int i=0;i<wn;i++){
		string s;
		cin>>s;
		vs.push_back(s);
	}

	set<Element,compare> elem_set;

	for(int i=0;i<wn;i++){
		for(int j=0;j<vs[i].size();j++){
			for(int k=j;k<vs[i].size();k++){
				Element e(i,j,k);
				elem_set.insert(e);
			}
		}
	}

	for(set<Element,compare>::iterator ite=elem_set.begin();ite!=elem_set.end();++ite){
		ve.push_back(*ite);
	}
	int num_query;
	cin>>num_query;
	for(int i=0;i<num_query;i++){
		int query;
		cin>>query;
		if(query<=ve.size()){
			Element e = ve[query-1];
			cout <<getStr(vs,e)<<endl;
		}else{
			cout <<"INVALID"<<endl;;	
		}
	}
}
