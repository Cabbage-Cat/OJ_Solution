#include <bits/stdc++.h>

#define MAX_N 10100
typedef long long i64;

using namespace std;

const int maxn = 100+5;
const int maxcol = 60;

string filenames[maxn];
void print(const string& s,int l,char extra)
{
    cout << s;
    int s_l = s.length();
    for (int i=0;i<l-s_l;i++)
        cout << extra;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    while (cin >> n)
    {
        int M=0;
        for (int i=0;i<n;i++)
        {
            cin >> filenames[i];
            M = max(M,(int)filenames[i].length());
        }

        int cols = (maxcol - M) / (M+2) + 1,rows = (n-1) / cols + 1;
        print("",maxcol,'-');
        cout << '\n';
        sort(filenames,filenames+n);

        for (int r=0;r<rows;r++)
        {
            for (int c=0;c<cols;c++)
            {
                int idx = c * rows + r;
                if (idx < n)
                    print(filenames[idx],c==cols-1?M:M+2,' '); 
            }

            cout << '\n';
        }
    }

    return 0;
}

