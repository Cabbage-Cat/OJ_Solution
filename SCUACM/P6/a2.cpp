#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#define MAX_N 200005

using namespace std;
void solve();

int book[MAX_N];
int cost[MAX_N];
int q;
int main()
{
    freopen("F:\\github\\OJ_Solution\\SCUACM\\P6\\file.in","r",stdin);
    freopen("F:\\github\\OJ_Solution\\SCUACM\\P6\\file.out","w",stdout);
    scanf("%d",&q);
    char c;
    int id;
    list<int> l;
    list<int>::iterator iter;
    for (int i=0;i<q;i++)
    {
        getchar();
        scanf("%c",&c);
        scanf("%d",&id);
        getchar();
        if (c=='L')
            l.push_front(id);
        else if(c=='R')
            l.push_back(id);
        else
        {
            iter=find(l.begin(),l.end(),id);
            
        }
    }

    return 0;
}

void solve()
{
	
}