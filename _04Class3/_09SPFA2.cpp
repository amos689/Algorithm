/*
    根据抽屉原理, 如果有n个点, 当没有负环时, 只有n - 1个边
    当边数大于等于n时, 则存在负权回路
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 2010, M = 10010;

int n, m;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa()
{
    // 可以不初始化dist, 因为边的长度不是关键, 边的个数是关键
    queue<int> q;
    
    // 不一定是从节点1才开始, 所以开局将每个节点都入队
    for(int i = 1; i <= n; i++)
    {
        st[i] = true;
        q.push(i);
    }
    
    while(q.size())
    {
        int t = q.front();
        q.pop();
        
        st[t] = false;
        
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
                
                // 如果变长大于等于n, 那么就存在负权回路
                if(cnt[j] >= n)
                {
                    puts("Yes");
                    return;
                }
            }
        }
    }
    puts("No");
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    memset(h, -1, sizeof h);
    
    cin >> n >> m;
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    
    spfa();
    
    return 0;
}