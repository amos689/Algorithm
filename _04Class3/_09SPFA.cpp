/*
    spfa优化自Bellman-Ford算法, 长得像dijkstra算法
    与B-F算法不同的是, spfa不会遍历所有的边, 只是在长度改变时才会被更改
    拿更新过的去更新下面的
    queue <- 1
    while(queue)
        1. t <- q.front; q.pop()
        2. 更新t的所有出边
        3. queue <- 出边
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int e[N], ne[N], h[N], w[N], idx;
int dist[N], st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa()
{
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    st[1] = true;
    
    while(q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        
        for(int i = h[t]; i != -1; i = ne[i]) // 遍历所有和t相邻的点
        {
            int j = e[i]; // 获得相邻的点的编号
            if(dist[j] > dist[t] + w[i]) // 如果可以让距离变得更短, 则更新距离
            {
                dist[j] = dist[t] + w[i]; // 更新距离
                if(!st[j]) // 如果没有在队列中, 则入队
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    
    if(dist[n] == 0x3f3f3f3f) puts("impossible");
    else cout << dist[n] << endl;
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