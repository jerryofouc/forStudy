#include <iostream>
using namespace std;

struct Edge{  
    int u,v;  
    double r,c;  
};  
int main(int argc, char* argv[])
{
    int N,M,S;
    double V;
     cin >> N >> M >> S >> V;


     Edge E[200];
     //memset(E, 0, sizeof(E));
	for(int i=0;i<200;i++){
    int a,b; 
    double rab,cab,rba,cba;
    for (int i = 0; i < M; ++i)
     {
         cin >> a >> b >> rab >> cab >> rba >> cba;
        int pos = i << 1;
         E[pos].u = a;
         E[pos].v = b;
         E[pos].r = rab;
         E[pos].c = cab;
         E[pos + 1].u = b;
         E[pos + 1].v = a;
         E[pos + 1].r = rba;
         E[pos + 1].c = cba;
     }

    double d[101];
	for(int i=0;i<101;i++){
		d[i] = 0;
	}
     memset(d, 0.0, sizeof(d));
    const double eps = 1e-8;  

     d[S] = V;  
    while(d[S] <= V + eps){  
        int f = 0;  
        for(int i = 0 ;i < 2 * M; ++i){  
            if(d[E[i].v] + eps < (d[E[i].u] - E[i].c) * E[i].r){  
                 d[E[i].v] = (d[E[i].u] - E[i].c) * E[i].r;  
                 f = 1;  
             }  
         }  
        if(!f) // can't relax
         {
            if (d[S] > V + eps) cout << "YES\n";
            else cout << "NO\n";
            return 0;  
         }
     }
    //find path
     cout << "YES\n";  
    return 0;
}
