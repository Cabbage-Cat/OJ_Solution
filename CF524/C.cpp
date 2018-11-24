#include <bits/stdc++.h>

#define MAX_N 10100
typedef long long i64;

using namespace std;
void solve();

i64 t,n,m;
i64 x1_w,x2_w,y1_w,y2_w;
i64 x1_b,x2_b,y1_b,y2_b;
int main()
{
    freopen("F:\\github\\OJ_Solution\\SCUACM\\file.in","r",stdin);
    freopen("F:\\github\\OJ_Solution\\SCUACM\\file.out","w",stdout);

    cin >> t;
    while(t-->0)
    {
        cin >> n >> m;
        cin >> x1_w >> y1_w >> x2_w >> y2_w;
        cin >> x1_b >> y1_b >> x2_b >> y2_b;
        solve();
    }
    fclose(stdin);fclose(stdout);
    return 0;
}

void solve()
{
	i64 b_num = n*m/2;
    i64 w_num = n*m-b_num;
    int w_f_x,w_f_y,w_f;
    if (x1_w%2==1)
        w_f_x=1;
    else
        w_f_x=0;
    
    if (y1_w%2==1)
        w_f_y=1;
    else
        w_f_y=0;
    if(w_f_x)
    {
        if(w_f_y)
            w_f=1;
        else
            w_f=0;
    }
    else
    {
        if(w_f_y)
            w_f=0;
        else
            w_f=1;
    }

    i64 maxim_res=(x2_w-x1_w+1)*(y2_w-y1_w+1);
    i64 w_col;//colored black num.

    if (w_f)
        w_col=maxim_res/2;
    else
        w_col=maxim_res - maxim_res/2;

    b_num-=w_col;
    w_num+=w_col;

    int b_f_x,b_f_y,b_f;
    if (x1_b%2==1)
        b_f_x=0;
    else
        b_f_x=1;
    
    if (y1_w%2==1)
        b_f_y=0;
    else
        b_f_y=1;
    if(b_f_x)
    {
        if(b_f_y)
            b_f=1;
        else
            b_f=0;
    }
    else
    {
        if(b_f_y)
            b_f=0;
        else
            b_f=1;
    }


    i64 denis_res=(x2_b-x1_b+1)*(y2_b-y1_b+1);
    i64 b_col;//colored white num.

    if (b_f)
        b_col=denis_res/2;
    else
        b_col=denis_res - denis_res/2;

    b_num+=b_col;
    w_num-=b_col;

    i64 x_length = x2_w-x1_w + x2_b-x1_b;
    i64 x_l = max(x2_b,x2_w) - min(x1_b,x1_w);

    i64 y_length = y2_w-y1_w + y2_b-y1_b;
    i64 y_l = max(y2_b,y2_w) - min(y1_b,y1_w);


    if (x_l<=x_length && y_l<=y_length)
    {
        int x1;
        if (x1_w>x1_b)
            x1=x1_w;
        else
            x1=x1_b;
        
        int x2;
        if (x2_w>x2_b)
            x2=x2_b;
        else
            x2=x2_w;

        int y1;
        if (y1_w>y1_b)
            y1=y1_w;
        else
            y1=y1_b;
        
        int y2;
        if (y2_w>y2_b)
            y2=y2_b;
        else
            y2=y2_w;

        if (x1%2==1)
            b_f_x=0;
        else
            b_f_x=1;
        
        if (y1%2==1)
            b_f_y=0;
        else
            b_f_y=1;
        if(b_f_x)
        {
            if(b_f_y)
                b_f=1;
            else
                b_f=0;
        }
        else
        {
            if(b_f_y)
                b_f=0;
            else
                b_f=1;
        }
        int dleta;
        if(b_col)
            dleta = (x2-x1+1)*(y2-y1+1) - (x2-x1+1)*(y2-y1+1)/2;
        else
            dleta = (x2-x1+1)*(y2-y1+1)/2;
        b_num+=dleta;
        w_num-=dleta;
    }

    cout << w_num << " "<<b_num<<endl;

}