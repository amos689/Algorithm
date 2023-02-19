/*
用一个队列保存当前获得的序列
用一个哈希表保存各个序列与对应额交换次数
从队列中取出队头这个序列，计算出这个序列通过交换能得到的序列
如果能到得的序列是个新序列（哈希表中没有这个序列），就把这个新序列放入队尾，哈希表中记录新序列对应的交换次数
如果在上述过程中得到了结果序列，则输出交换次数，结束
如果最终没有得到结果序列, 输出-1
0123456789
*/
#include<bits/stdc++.h>

using namespace std;

string start;
// 保存序列的队列
queue<string> q;
// 保存序列和对应的交换次数
unordered_map<string, int> d;

void bfs()
{
    string end = "12345678x";
    q.push(start);
    d[start] = 0;
    
    // 四个方向的单位向量
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        int distance = d[t];
        
        if(t == end)
        {
            cout << d[end] << endl;
            return;
        }
        
        int k = t.find('x');
        int x = k / 3, y = k % 3;
        for(int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if(a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                // string也支持swap方法
                swap(t[a * 3 + b], t[k]);
                if(!d.count(t))
                {
                    // 距离累加
                    d[t] = distance + 1;
                    q.push(t);
                }
                swap(t[a * 3 + b], t[k]);
            }
        }
    }
    
    cout << -1 << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    char c;
    for(int i = 0; i < 9; i++)
    {
        cin >> c;
        start += c;
    }
    
    bfs();
    
    return 0;
}