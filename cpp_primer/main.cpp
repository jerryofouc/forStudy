#include<iostream>
using namespace std;
enum Points {
    aa,
    bb,
    cc,
};
int main(){
    const int ii = 5;
    int const &ref = ii;
    std::cout << ref <<std::endl;
    double dval = 3.14;
    const double &ri = dval;
    dval = 4.3;
    cout << "dval:" << dval << "ri:" <<ri <<endl;
    int const &dd = 54;
    Points abc = bb;
    cout << abc <<endl;
}
