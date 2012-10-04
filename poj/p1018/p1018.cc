#include<iostream>
#include<iomanip>
#include<limits>
using namespace std;
struct BP{
	int brand;
	int price;
};
int d[100];
BP list[100][100];
int t = 0;		
int n=0;
double maxV = 0;
void maxBP(int n,int maxB,int maxP){
//	cout << "n:"<<n<<endl;
	if(n == 0){
//		cout << "maxB:"<<maxB<<endl;
//		cout << "maxP:"<<maxP<<endl;
//		cout << "result:"<<((double)maxB)/maxP<<endl;
		if(((double)maxB)/maxP>maxV){
			maxV = ((double)maxB)/maxP;
		}
	}
	int num = d[n-1];
	int newB = maxB;
	if(list[n-1][0].brand<maxB){
		newB = list[n-1][0].brand;
	}
	int curRowB = list[n-1][0].brand;
	int newP = maxP + list[n-1][0].price;
	if(((double)newB/newP)>=maxV){
		maxBP(n-1,newB,newP);
	}

	for(int i=1;i<num;i++){
			double newMax;
			newB = maxB;
			if(list[n-1][i].brand<maxB){
				newB = list[n-1][i].brand;
			}
			if(((double)newB/newP)>=maxV){
				maxBP(n-1,newB,maxP + list[n-1][i].price);
			}
	}
}
int main(){
	cin>>t;
	for(int i=0;i<t;i++){
		cin >>n;
		for(int j=0;j<n;j++){
			cin>>d[j];
			for(int k=0;k<d[j];k++){
				cin>>list[j][k].brand;
				cin>>list[j][k].price;
			}
		}
    	maxBP(n,std::numeric_limits<int>::max(),0);
		cout <<setprecision(3) <<maxV<<endl;
	}
}

