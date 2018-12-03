#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char s[15],a[7];
bool vis[3];
int cnt;

int main()
{
    while(~scanf("%s",s))
    {
        memset(vis,0,sizeof(vis));
        cnt = 0;
        strcpy(a,s+6);
        s[6] = '\0';
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(!vis[j] && ((s[i]==a[j] && s[5-i]==a[5-j]) || (s[i]==a[5-j] && s[5-i]==a[j])))
                {
                    vis[j] = true;
                    cnt++;
                    break;
                }
            }
        }
        cnt==3?puts("TRUE"):puts("FALSE");
    }
    return 0;
}