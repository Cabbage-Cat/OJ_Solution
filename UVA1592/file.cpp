#include <bits/stdc++.h>

#define MAX_N 10100
typedef long long i64;

using namespace std;

map<string,int> IDcache;
vector<string> Setcache;

int ID(string& s)
{
    if (IDcache.count(s))
        return IDcache[s];
    Setcache.push_back(s);
    return IDcache[s] = Setcache.size() - 1;
}


int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    int rows,cols;
    while (scanf("%d%d",&rows,&cols)==2)
    {
        getchar();
        IDcache.clear();Setcache.clear();
        string s;char c;
        vector<vector<int>> database;
        for (int i=0;i<rows;i++)
        {
            vector<int> row;
            for (int j=0;j<cols;j++)
            {
                s.clear();
                while ((c=getchar())!=EOF && c!=',' && c!='\n')
                    s+=c;
                row.push_back(ID(s));
                // database[i].push_back(ID(s));        
            }
            database.push_back(row);
        }
        // for (int i=0;i<rows;i++)
        // {
        //     for (int j=0;j<cols;j++)
        //     {
        //         printf("%d  ",database[i][j]);
        //     }
        //     printf("\n");
        // }
        map<pair<int,int>,int> searchmap;
        bool flag = false;
        for (int i=0;i<cols-1;i++)
        {
            for (int j=i+1;j<cols;j++)
            {
                searchmap.clear();
                for (int k=0;k<rows;k++)
                {
                    pair<int,int> tmp = make_pair(database[k][i],database[k][j]);
                    if (searchmap.count(tmp))
                    {
                        printf("NO\n");
                        printf("%d %d\n",searchmap[tmp]+1,k+1);
                        printf("%d %d\n",i+1,j+1);
                        flag = true;
                    }
                    else
                    {
                        searchmap[tmp] = k;
                    }
                    if (flag)
                        break;
                }
                if (flag)
                    break;
            }
            if (flag)
                break;
        }
        if (!flag)
            printf("YES\n");
    }

    return 0;
}

