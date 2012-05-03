#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<limits>
using namespace std;
map<vector<int>,int> global_map;
void print_initalNum(const vector<int>& intialNums);
float find_min_fee(const vector<int>& book_list);
float const discount[5] = {0,0.05,0.10,0.20,0.25};
int main(){
    cout << "please the number of each books(can not larger than 10):" << endl;
    int num ;
    int size = 0;
    vector<int> initalNums;
    while(size < 5&&cin>>num){
        initalNums.push_back(num);
        ++size;
    }
    
    vector<int> zero_list(5,0); 
    sort(initalNums.rbegin(),initalNums.rend());
    global_map[vector<int>(5,0)] = 0;
    cout << "the minum fee is: " find_min_fee(initalNums)<<endl;
    return 0;
}
float find_min_fee(const vector<int>& book_list){
    map<vector<int>,int >::iterator current=global_map.find(book_list) ;
    if(current != global_map.end()){//find
        return current->second;
    }
    //if not find
    float  min = numeric_limits<float>::max();
    vector<int> temp;
    float fee;
    int i = 0;
    for(i=0;i<5;i++){
        temp = book_list;
        if(book_list[i] <= 0) continue;
        int j;
        for(j=0;j<=i;j++){
            temp[j]-=1;
        }
        sort(temp.rbegin(),temp.rend());
        fee = (i+1)*8*(1-discount[i]) + find_min_fee(temp);
        if(fee < min){
            min = fee;
        }
    }
    global_map[book_list] = min;
    return min;
 }
void print_initalNum(const vector<int>& intialNums){
    for(vector<int>::const_iterator it = intialNums.begin();it != intialNums.end();++it){
        cout << *(it) <<" ";
    }
    cout <<endl;
}
