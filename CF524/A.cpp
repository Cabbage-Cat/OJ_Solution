#include <bits/stdc++.h>

#define MAX_N 10100
typedef long long i64;

using namespace std;
void solve();

int n,k;

int main()
{
    freopen("F:\\github\\OJ_Solution\\SCUACM\\file.in","r",stdin);
    freopen("F:\\github\\OJ_Solution\\SCUACM\\file.out","w",stdout);

    cin >> n >>k;
    int tmp;
    int res=0;
    tmp=2*n;
    tmp/=k;
    if (2*n%k != 0)
        tmp+=1;
    res+=tmp;
    
    tmp = 5*n;
    tmp/=k;
    if (5*n%k != 0)
        tmp+=1;
    res+=tmp;

    tmp = 8*n;
    tmp/=k;
    if (8*n%k != 0)
        tmp+=1;
    res+=tmp;
    cout << res << endl;
    fclose(stdin);fclose(stdout);
    return 0;
}

void solve()
{
	
}