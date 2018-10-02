#include <cstdio>
#include <cstring>

char s[2100];
int n;
void solve();
int main()
{
    while(~scanf("%d",&n))
    {
        memset(s,'\0',sizeof(s));
        for (int i=0;i<n;i++)
            scanf(" %c",&s[i]); //让我们可以刨除回车的读入问题。
        solve();
    }
}

void solve()
{
    int a=0,b=n-1;
    int left_flag=0,count=0;
    while (a<=b)
    {
        for (int i=0;a+i<b;i++) //处理每次首尾字符相同的情况,如果相同处理下个字符。
        {
            if (s[a+i] < s[b-i])
            {
                left_flag = 1;
                break;
            }
            else if(s[a+i]>s[b-i])
            {
                left_flag = 0;
                break;
            }
        }
        
        if (left_flag)
            putchar(s[a++]);

        else
            putchar(s[b--]);
        count++;

        if (count == 80)
        {
            count = 0;
            putchar('\n');
        }
    }
    putchar('\n');
}