
#include<iostream>
using namespace std;

bool isBlank(char a){
	return a==' '||a=='\n'||a=='\t';
}
/**splits the string p into splits 
*  example abc  cde    aaa  
*
*/
char** getChar(char* p){
	int start,cur,end;
	int num = 0;;
	bool lastBlank = true;
	for(cur=0;*(p+cur);cur++){
		if(lastBlank&&!isBlank(*(p+cur))){
			num++;
			lastBlank = false;
		}
		if(!lastBlank&&isBlank(*(p+cur))){
			lastBlank = true;
		}
	}
	if(num == 0){
		return NULL;
	}
	char** ret = new char*[num];
	lastBlank = true;
	int s = 0;
	for(cur=0;*(p+cur);cur++){
		if(lastBlank&&!isBlank(*(p+cur))){
			start = cur;	
			lastBlank = false;
		}
		if(!lastBlank&&isBlank(*(p+cur))){
			end = cur;	

			ret[s] = new char[end-start+1];		
			for(int i=0;i<end-start;i++){
				ret[s][i] = p[start+i];
			}

			ret[s][end-start] = '\0';
			s++;
			lastBlank = true;
		}
	}
	if(!lastBlank){
		end = cur;
		ret[s] = new char[end-start+1];		
		for(int i=0;i<end-start;i++){
			ret[s][i] = p[start+i];
		}
		ret[s][end-start] = '\0';
	}
	return ret;
}
int main(){
	char *ss = " abc dfsd dss sdsd ddd dd  sdssd  sdfd fdsdfdsfd";
	char** tt = getChar(ss);
	for(int i=0;i<9;i++){
		cout <<tt[i]<<endl;
	}
}
