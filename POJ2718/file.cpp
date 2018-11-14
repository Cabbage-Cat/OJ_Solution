#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define INF 999999
using namespace std;

int X[12];

int N;
void solve();

int main()
{
    // freopen("F:\\github\\OJ_Solution\\POJ2718\\file.in","r",stdin);
    // freopen("F:\\github\\OJ_Solution\\POJ2718\\file.out","w",stdout);
    int t;
    scanf("%d ",&t);
    
    while (t-->0)
    {
        char tmp[50];
        N=0;
        gets(tmp);
        for (int i=0;tmp[i]!='\0';i++)
        {
            if (tmp[i] >= '0' && tmp[i]<='9')
                X[N++] = tmp[i]-'0';
        }
        
        solve();
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}

void solve()
{
    int res=INF;
    
    sort(X,X+N);
    do
    {
        int a=0,b=0;
        for(int i=0;i<N/2;i++)
            if (X[N/2]!=0)
                a+=(int)(pow(10.0,i)+0.5)*X[i];
        
        for (int i=N/2;i<N;i++)
            if (X[N-1]!=0)
                b+=(int)(0.5+pow(10.0,i-N/2))*X[i];
        if (abs(a-b) < res)
            res=abs(a-b);
    }
    while(next_permutation(X,X+N));
    printf("%d\n",res);
}