#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

void solution();

int dis[1100];
int R,N;
int main()
{
    while (scanf("%d%d",&R,&N) == 2 && R!=-1 && N!=-1)
    {
        memset(dis,0,sizeof(dis));
        for (int i=0;i<N;i++)
            scanf("%d",&dis[i]);
        solution();
    }
    return 0;
}

void solution()
{
    sort(dis,dis+N);

    int left=0,ans=0;

    while (left<N)
    {
        int s = dis[left]; //First point not marked 's distance.

        while (left<N && dis[left]<=s+R)
            left++;
        
        int p = dis[left-1]; 

        while (left<N && dis[left]<=p+R)
            left++;

        ans++;
    }
    printf("%d\n",ans);
    
}
