#include <bits/stdc++.h>

#define MAX_N 10100
typedef long long i64;

using namespace std;

void print(string& s,int l,char c)
{
    int s_size = s.size();
    cout << s;
    for (int i=0;i<l-s_size;i++)
        cout << c;
}

int main()
{
    vector<string> code[1000];
    int s_length[200];

    fill(s_length,s_length+200,0);
    string s;

    int row=0,col=0;
    while (getline(cin,s))
    {
        col = 0;
        stringstream ss(s);
        string t;
        while (ss >> t)
        {
            code[row].push_back(t);
            s_length[col] = max(s_length[col],(int)t.size());
            col++;
        }
        row++;
    }

    for (int i=0;i<row;i++)
    {
        for (int j=0;j<code[i].size()-1;j++)
        {
            string s = code[i][j];
            print(s,s_length[j]+1,' ');
        }
        cout << code[i][code[i].size()-1];
        cout << '\n';
    }
    return 0;
}

