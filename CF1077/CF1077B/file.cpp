#include <cstdio>
#define MAX_N 105
using namespace std;

int light[MAX_N];
int N;
int disturbed[MAX_N];
int counted[MAX_N];
int main()
{
    scanf("%d",&N);
    for (int i=0;i<N;i++)
        scanf("%d",&light[i]);
    int d=0;
    for (int i=1;i<N-1;i++)
        if (light[i]==0 && light[i-1]==1 && light[i+1]==1)
        {
            disturbed[i] = 1;
            counted[i-1]++;counted[i+1]++;
            d++;
        }
        
    int res=0;
    for (int i=0;i<N;i++)
    {
        if (counted[i]>1)
        {
            res++;
            disturbed[i-1]=0;disturbed[i+1]=0;counted[i]=0;
        }
    }
    for (int i=0;i<N;i++)
    {
        if (disturbed[i]==1)
            res++;
    }
    printf("%d\n",res);
    return 0;
}


