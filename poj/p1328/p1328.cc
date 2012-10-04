#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

struct Pos{
	int x;
	int y;
};
bool isLegal(const Pos& pos,int d){
	if(pos.y > d){
		return false;
	}	
	return true;
}
class Section{
public:
	double begin;
	double end;
	double getBegin()const{
		return begin;
	}
	double getEnd()const{
		return end;
	}
};
inline bool operator<(const Section& a,const Section& b){
	return a.getEnd() < b.getEnd();
}

void printVector(const vector<Section>& sections){
	for(vector<Section>::const_iterator ite = sections.begin();ite!= sections.end();++ite){
		cout<<"begin:"<<ite->getBegin()<<" end"<<ite->getEnd();
	}	
	cout << endl;
}
int main(){
	int islandCount = 0;
	int d =0;
	int caseCount = 0;
	int x[100];
	Pos	pos[1000];
	vector<Section> sections;
	double include[1000];
	while(cin>>islandCount&&cin>>d){
		int solutionCount = 0;
		if(islandCount == 0&& d==0){
			break;
		}
		bool hasSolution = true;
		for(int i =0;i<islandCount;i++){
			include[i] = false;
			cin>>pos[i].x>>pos[i].y;	
			if(!isLegal(pos[i],d)){
				hasSolution = false;
			}
			Section section;
			section.begin = (double)pos[i].x - sqrt((double)(d*d-pos[i].y*pos[i].y));
			section.end = (double)pos[i].x + sqrt((double)(d*d-pos[i].y*pos[i].y));
			sections.push_back(section);
		}

		if(!hasSolution){
			cout << "Case " << (++caseCount) <<": " << -1<<endl;
			sections.clear();
			continue;
		}else{
			std::sort(sections.begin(),sections.end());	
			for(int i = 0;i<islandCount;i++){
				if(!include[i]){
					include[i] = true;
					solutionCount++;	
					for(int j=i+1;j<islandCount;j++){
						if(sections[i].end>=sections[j].begin){
							include[j] = true;	
							i = j;
						}		
					}
				}
			}
		}	
		cout << "Case " << (++caseCount) <<": " << solutionCount<<endl;
		sections.clear();
	}
}
