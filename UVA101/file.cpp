#include <bits/stdc++.h>

#define MAX_N 30

using namespace std;

int n;
vector<int> pile[MAX_N];

void find_block(int a,int& p,int& h)
{
    for (p=0;p<n;p++)
        for (h=0;h<pile[p].size();h++)
            if(pile[p][h] == a)
                return;
}

void clear_above(int p,int h)
{
    int b;
    for (int i=h+1;i<pile[p].size();i++)
    {
        b = pile[p][i];
        pile[b].push_back(b);
    }
    pile[p].resize(h+1);
}

void pile_onto(int p,int h,int p2)
{
    int b;
    for (int i=h;i<pile[p].size();i++)
    {
        b = pile[p][i];
        pile[p2].push_back(b);
    }
    pile[p].resize(h);
}

void print()
{
    for (int i=0;i<n;i++)
    {
        printf("%d:",i);
        for (int j=0;j<pile[i].size();j++)
            printf(" %d",pile[i][j]);
        printf("\n");
    }
}

int main()
{
    int a,b;
    string s1,s2;
    cin >> n;
    for (int i=0;i<n;i++)
        pile[i].push_back(i);
    
    while (cin >> s1 >> a >> s2 >> b)
    {
        int pa,ha,pb,hb;
        find_block(a,pa,ha);
        find_block(b,pb,hb);
        if (pa==pb)
            continue;
        if (s2=="onto")
            clear_above(pb,hb);
        if (s1=="move")
            clear_above(pa,ha);
        pile_onto(pa,ha,pb);        
    }
    print();
    return 0;
}