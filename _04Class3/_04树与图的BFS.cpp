#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N];
queue<int> q;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs()
{
    memset(d, -1, sizeof d);
    q.push(1);
    d[1] = 0;
    
    // 一直遍历到结束
    while(q.size())
    {
        int t = q.front();
        q.pop();
        
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(d[j] == -1)
            {
                d[j] = d[t] + 1;
                q.push(j);
            }
        }
    }
    
    // 先到的肯定是最短的
    return d[n];
}

int main()
{
    // 遍历链头
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    
    cout << bfs() << endl;
    
    return 0;
}