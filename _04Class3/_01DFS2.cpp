#include<bits/stdc++.h>

using namespace std;

// 因为对角线条数为n * 2 - 1, 所以要开20
const int N = 20;

int n;
// 模拟棋盘
char q[N][N];
// 遍历行时对照的列, 正对角线, 反对角线
bool col[N], dg[N], udg[N];

void dfs(int x)
{
    if(x == n)
    {
        for(int i = 0; i < n; i++) cout << q[i] << endl;
        cout << endl;
        return;
    }
    
    // DFS搜索(这里遍历的是行, 所以不用设置行的判定)
    for(int i = 0; i < n; i++)
    {
        // 按照一次函数的解析式, b1 = x + y, b2 = y - x(因为b2要非负, 加偏移量n)
        if(!col[i] && !dg[x + i] && !udg[n - x + i])
        {
            q[x][i] = 'Q';
            col[i] = dg[x + i] = udg[n - x + i] = true;
            dfs(x + 1);
            col[i] = dg[x + i] = udg[n - x + i] = false;
            q[x][i] = '.';
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            q[i][j] = '.';
        }
    }
    
    dfs(0);
    
    return 0;
}