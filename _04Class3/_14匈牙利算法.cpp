/*
    匈牙利算法(成功匹配的最大数量)
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 500, M = 100010;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x)
{
    // 男生遍历自己喜欢的女生
    for(int i = h[x]; i != -1; i = ne[i])
    {
        int t = e[i];
        
        if(!st[t]) // 如果在这一轮模拟匹配中,这个女孩尚未被预定
        {
            st[t] = true; // 那就预订
            //如果女孩j没有男朋友, 或者她原来的男朋友能够找其它喜欢的女孩, 那就成功
            if(match[t] == 0 || find(match[t]))
            {
                match[t] = x;
                return true;
            }
        }
    }
    
    //自己中意的全部都被预定了, 配对失败
    return false;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    memset(h, -1, sizeof h);
    
    cin >> n1 >> n2 >> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        // 只用从一方看到另一方就行, 所以不需要反着再add一遍
        add(a, b);
    }
    
    int res = 0;
    for(int i = 1; i <= n1; i++)
    {
        // 因为每次模拟匹配的预定情况都是不一样的所以每轮模拟都要初始化
        memset(st, false, sizeof st);
        if(find(i)) res++; // 牵手成功
    }
    
    cout << res << endl;
    
    return 0;
}