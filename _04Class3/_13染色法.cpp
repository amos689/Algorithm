/*
    一个图是二分图当且仅当这个图中不含奇数环
    二染色时出现矛盾就不是二分图, 反之就是二分图
    实现思路
        开始对任意一未染色的顶点染色
        判断其相邻的顶点中，若未染色则将其染上和相邻顶点不同的颜色
        若已经染色且颜色和相邻顶点的颜色相同则说明不是二分图，若颜色不同则继续判断
    实现操作
        for(int i = 1; i <= n; i++)
            if(i未染色) dfs(i, 1)
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 100010, M = 200010;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u, int c)
{
    color[u] = c; // 将u染成c色
    
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int t = e[i];
        
        // 如果下面的还没有被染色, 就进行染色
        if(!color[t])
        {
            // 如果染色失败, 就返回false
            if(!dfs(t, 3 - c)) return false;
        }
        // 如果这个节点的下一个节点跟它颜色一样, 是不对的, 返回false
        else if(color[t] == c) return false;
    }
    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    memset(h, -1, sizeof h);
    
    cin >> n >> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    
    bool flag = true;
    // 遍历每个没有染色的点
    for(int i = 1; i <= n; i++)
    {
        if(!color[i])
        {
            if(!dfs(i, 1)) // 染色, 并递归处理相邻的点
            {
                flag = false;
                break;
            }
        }
    }
    
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}