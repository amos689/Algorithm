/*
    异或运算是不进位的加法
    方法: 
        1. 消成上三角矩阵
        2. 判断形状
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 110;

int n;
int a[N][N];

int gauss()
{
    int r, c;
    for(r = 0, c = 0; c < n; c++)
    {
        int t = r;
        for(int i = r + 1; i < n; i++)
        {
            if(a[i][c])
            {
                t = i;
                break;
            }
        }
        
        if(!a[t][c]) continue;
        
        for(int i = c; i < n + 1; i++) swap(a[r][i], a[t][i]);
        
        for(int i = r + 1; i < n; i++)
            if(a[i][c])
                for(int j = c; j < n + 1; j++)
                    a[i][j] ^= a[r][j];
        
        r++;
    }
    
    if(r < n)
    {
        for(int i = r; i < n; i++)
            if(a[i][n])
                return 2;
        return 1;
    }
    
    for(int i = n - 1; i >= 0; i--)
        for(int j = i + 1; j < n; j++)
            // 如果是0 就不用下面的a[j][j] 来^a[i][j]了
            if(a[i][j])
                a[i][n] ^= a[j][n];
    
    return 0;
    
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n + 1; j++)
            cin >> a[i][j];
    
    int res = gauss();
    
    if(res == 0)
    {
        for(int i = 0; i < n; i++) cout << a[i][n] << endl;
    }
    else if(res == 1) puts("Multiple sets of solutions");
    else puts("No solution");
    
    return 0;
}