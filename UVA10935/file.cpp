#include <bits/stdc++.h>

#define MAX_N 10100
typedef long long i64;

using namespace std;

void init_queue(queue<int>& q,int n)
{
    for (int i=1;i<=n;i++)
        q.push(i);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    int t = 0;
    while (cin >> n && n!=0)
    {
        queue<int> q;
        init_queue(q,n);
        if (t!=0)
            cout << '\n';
        cout << "Discarded cards: ";

        while(q.size()!=1)
        {
            int f = q.front();q.pop();
            int f2 = q.front();q.pop();q.push(f2);
            cout << f ;
            if (q.size()!=1)
                cout << ", ";
        }
        int res = q.front();
        cout << "\nRemaining card: " << res ;
        t++;
    }

    return 0;
}

