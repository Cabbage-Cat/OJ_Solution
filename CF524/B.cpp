#include <bits/stdc++.h>

#define MAX_N 10100
typedef long long i64;

using namespace std;
void solve();

int n,a1,an;

int main()
{
    freopen("F:\\github\\OJ_Solution\\SCUACM\\file.in","r",stdin);
    freopen("F:\\github\\OJ_Solution\\SCUACM\\file.out","w",stdout);

    cin >> n;

    for (int i=0;i<n;i++)
    {
        cin >> a1 >> an;
        int i1,i2;
        if (a1%2==0)
            i1=-1;
        else
            i1=1;
        
        if (an%2==0)
            i2=-1;
        else
            i2=1;
        
        if (a1%2 ==0)
            a1=a1;
        else
            a1=-a1;
        if (an%2 ==0)
            an=an;
        else
            an=-an;

        

        cout << (a1+an+(i1-i2)/2)/2 <<endl;
    }
    fclose(stdin);fclose(stdout);
    return 0;
}

void solve()
{
	
}