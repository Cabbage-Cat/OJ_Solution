#include <bits/stdc++.h>

#define MAX_N 10100
typedef long long i64;

using namespace std;

// typedef struct 
// {
    
// }
void input_prize(double *total,double *d)
{
    scanf("%lf",total);
    for (int i=0;i<70;i++)
        scanf("%lf",&d[i]);
}

int main()
{
    int n;
    scanf("%d",&n);

    double total,d[70];
    for (int i=0;i<n;i++)
    {
        input_prize(&total,d);

    }    

    return 0;
}

