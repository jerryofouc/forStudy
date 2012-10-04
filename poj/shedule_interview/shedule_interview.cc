#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class TimeTable{
	public:
		TimeTable(int startTime,int endTime):startTime(startTime),endTime(endTime){
		}
		bool operator<(const TimeTable &rhs)const{
			return (this->startTime < rhs.startTime);
		}
		int getStartTime()const{
			return startTime;
		}
		int getEndTime()const{
			return endTime;
		}
	private:
		int startTime;
		int endTime;
};
void print(const vector<TimeTable> &times){
	for(vector<TimeTable>::const_iterator ite = times.begin();ite != times.end();++ite){
		cout << "begin:"<<(ite->getStartTime())<<" end:"<<(ite->getEndTime())<<endl;
	}

}
bool isOverLap(const vector<TimeTable>& times,int i,int j){
	if(times[i].getEndTime()>times[j].getStartTime()){
		return true;
	}else{
		return false;
	}
}
int main(){
	int startTime, endTime;
	vector<TimeTable> times;
	while(cin>>startTime>>endTime){
		TimeTable time(startTime,endTime);	
		times.push_back(time);
	}
	sort(times.begin(),times.end());
	vector<int> color(20);
	vector<bool> forbidden(20);
	int max_color = 0;
	for(int i=0;i<times.size();i++){
		for(int j=0;j<max_color;j++){
			forbidden[j] = false;	
		}

		for(int j = 0;j<i;j++){
			if(isOverLap(times,j,i)){
				forbidden[color[j]] = true;
			}
		}

		int k = 0;
		for(k=0;k<max_color;k++){
			if(!forbidden[k]){
				break;
			}	
		}
		if(k<max_color){
			color[i] = k;
		}else{
			color[i] = max_color++;
		}
	}
	cout << "max_color:" << max_color << endl;
}
