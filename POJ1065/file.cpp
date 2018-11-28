#include <bits/stdc++.h>

#define MAX_N 5007
typedef long long i64;
typedef struct
{
    int length;
    int weight;
}S;

S stick[MAX_N];
int N;
using namespace std;
void solve();
bool cmp(S &s1,S &s2);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    freopen("F:\\github\\OJ_Solution\\POJ1065\\file.in","r",stdin);
    freopen("F:\\github\\OJ_Solution\\POJ1065\\file.out","w",stdout);
    int t;
    cin >> t;
    while (t-->0)
    {
        cin >> N;
        for (int i=0;i<N;i++)
            cin >> stick[i].length >> stick[i].weight;

        sort(stick,stick+N,cmp);
        // for (int i=0;i<N;i++)
        //     cout << "(" << stick[i].length << " " << stick[i].weight<<") "<< endl;
        solve();
        // cout << endl;
    }
    
    fclose(stdin);fclose(stdout);
    return 0;
}

void solve()
{
	int res=1;
    for (int i=1;i<N;i++)
    {
        if (stick[i].length<=stick[i-1].length && stick[i].weight<=stick[i-1].weight)
            continue;
        else
            res+=1;
    }
    cout << res << endl;
}

bool cmp(S &s1,S &s2)
{
    if (s1.length==s2.length)
        return s1.weight > s2.weight;
    return s1.length > s2.length;
}