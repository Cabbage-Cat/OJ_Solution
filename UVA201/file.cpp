#include <bits/stdc++.h>

#define MAX_N 11
typedef long long i64;

using namespace std;


int H[MAX_N][MAX_N];
int V[MAX_N][MAX_N];
int n,m;
int t=0;

int get_square(int size);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    while (scanf("%d%d",&n,&m)==2)
    {
        if (t!=0)
            cout <<endl<< "**********************************" << endl << endl ;
        t++;
        char ch;
        int x,y;
        fill(H[0],H[0]+MAX_N*MAX_N,0);
        fill(V[0],V[0]+MAX_N*MAX_N,0);
        for (int i=0;i<m;i++)
        {
            getchar();
            scanf("%c",&ch);
            scanf("%d%d",&x,&y);
            if (ch=='H')
                H[x-1][y-1] = 1;
            else
                V[y-1][x-1] = 1;
        }
        
        cout << "Problem #"<< t << endl << endl;
        bool have_square=0;
        for (int i=1;i<=n;i++)
        {
            if(get_square(i)>0)
            {
                cout << get_square(i)<<" square (s) of size "<<i << endl;;
                have_square = true;
            }
        }
        if (!have_square)
            cout << "No completed squares can be found." << endl;
        
    }

    return 0;
}

int get_square(int size)
{
    int res=0;

    for (int i=0;i<n-size;i++)
        for (int j=0;j<n-size;j++)
        {
            int flag = 1;
            for (int m=0;m<size;m++)
            {
                if (!H[i][j+m] || !H[i+size][j+m] || !V[i+m][j] || !V[i+m][j+size])
                {
                    flag = 0;
                    break;
                }
            }

            if (flag)
                res++;
        }
    return res;
    // if (res > 0)
    //     cout << res<<" square (s) of size "<<size << endl;
    // else 
    //     cout << "No completed squares can be found." << endl;
}