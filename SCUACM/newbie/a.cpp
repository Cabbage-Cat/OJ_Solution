#include <bits/stdc++.h>

#define MAX_N 1000005
typedef long long i64;

using namespace std;

int N,Q;
int T;
int num[MAX_N];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> T;
    while (T-- > 0)
    {
        fill(num,num+MAX_N,0);
        cin >> N >> Q;
        int l,r;
        int tmp;
        for (int i=0;i<N;i++)
        {
            cin >> l >> r;
            if (!num[l] && !num[r]){}
            else if (num[l] && !num[r])
            {
                while (num[l])
                    l++;
            }
            else if (!num[l] && num[r])
            {
                while (num[r])
                    r--;
            }
            else
                continue;
            cout << l << " " << r << endl;
            for (int j=l;j<=r;j++)
                num[j] = 1;
        }

        for (int i=0;i<Q;i++)
        {
            cin >> tmp;
            if (tmp < 0)
                cout << "No" << endl;
            else if (tmp >= MAX_N-1)
                cout << "No" << endl;
            else
            {
                if (num[tmp])
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
        }
    }

    return 0;
}

