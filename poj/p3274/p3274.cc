#include<iostream>
using namespace std;
int const MAX = 100000;
int const K = 30;
int n,k;
int s[MAX][K];
struct Node{
	int index;
	Node* next;
};
Node* hashTable[1000000];
int hashCode(int index){
	long sum = 0;
	int base = 1;
	for(int i=0;i<k;i++){
		sum += s[index][i]*base;	
		base <<= 1;
	}
	return sum%1000000;
}
void printS(){
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			cout << s[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}
bool equal(int i,int j){
	for(int t = 0;t<k;t++){
		if(s[i][t] != s[j][t]){
			return false;
		}
	}
	return true;
}
int main(){
	cin>>n>>k;		
	for(int i=0;i<k;i++){
		s[0][i] = 0;
	}
	for(int i=1;i<=n;i++){
		int t;	
		cin>>t;
		int base = 1;
		int j=0;
		while(base<=t){
			if(t&base){
				s[i][j] = 1;	
			}
			++j;
			base<<=1;
		}
	}
//	printS();

	for(int i=0;i<k;i++){
		for(int j=1;j<=n;j++){
			s[j][i] += s[j-1][i];
		}
	}	
//	printS();
	for(int i=0;i<=n;i++){
		for(int j=k-1;j>=0;j--){
			s[i][j] -= s[i][0];	
		}	
	}
	for(int i=0;i<1000000;i++){
		hashTable[i] = NULL;
	}
//	printS();
	int max = 0;
	for(int i = 0;i<=n;i++){
		int hc = hashCode(i);
		//cout << hc<<endl;
		Node* cur = hashTable[hc];
		if(cur == NULL){
			Node* t = new Node();
			t->index = i;
			t->next = NULL;
			hashTable[hc] = t;
		//	cout <<"iiii:"<< i << endl;
		}else{
			Node* pre = cur;
			while(cur!=NULL&&!equal(cur->index,i)){
				pre = cur;
				cur = cur->next;
			}
			if(cur != NULL){//equals
			//	cout << "equals" <<endl;
				if(max <i- cur->index ){
					max =i- cur->index;
				}
			}else{
				Node* t = new Node();
				t->index = i;
				t->next = NULL;
				pre ->next = t;
			}
		}
	}
	cout << max<<endl;
}
