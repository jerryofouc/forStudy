#include<iostream>

#include<cstdio>

using namespace std;

const int N=120;

const int inf=(1<<28);

int b[N][N],p[N][N],m[N];

int min_b,max_b;

int main()

{

    int ci;scanf("%d",&ci);

    while(ci--)

    {

        int n;scanf("%d",&n);

        min_b=inf,max_b=0;

        for(int i=0;i<n;i++)

        {

            scanf("%d",&m[i]);

            for(int j=0;j<m[i];j++)

            {

                scanf("%d%d",&b[i][j],&p[i][j]);

                if(b[i][j]>max_b) max_b=b[i][j];

                if(b[i][j]<min_b) min_b=b[i][j];

            }

        }

        double cnt=0;

        for(int i=min_b;i<=max_b;i++)

        {

            int sum=0;

            for(int j=0;j<n;j++)

            {

                int min_p=inf;

                for(int k=0;k<m[j];k++)

                {

                    if(b[j][k]>=i&&p[j][k]<min_p)

                    {

                        min_p=p[j][k];

                    }

                }

                sum+=min_p;

            }

            if((i+0.0)/sum>cnt) cnt=(i+0.0)/sum;

        }

        printf("%.3lf/n",cnt);

    }

    return 0;

}
