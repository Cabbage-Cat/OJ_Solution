#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX_N 5500

typedef std::pair<int,int> P;
P stick[MAX_N];
int t,N;
bool cmp(P p1,P p2);
int main()
{
    scanf("%d ",&t);
    while (t-->0)
    {
        scanf("%d",&N);
        for (int i=0;i<N;i++)
        {
            scanf("%d",&stick[i].first);
            scanf("%d",&stick[i].second);
        }
        std::sort(stick,stick+N,cmp);

        
    }
    return 0;
}

bool cmp(P p1,P p2)
{
    int tmp = p1.second - p2.second;
    if (tmp == 0)
    {
        return p1.first - p2.first > 0;
    }
    else
        return tmp>0;
}

