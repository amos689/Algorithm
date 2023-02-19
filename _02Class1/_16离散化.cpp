/*
    离散化的本质是将数字本身key映射为它在数组中的索引index(1 based)。
    所以通过二分求索引建立映射的对应关系（value -> index)是离散化的本质
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 300010; //n个添加和m*2(因为包含l和r)个查询

int n, m;
int a[N], s[N]; //用来存放离散化后的数据和前缀和

vector<int> alls; //用来存放离散化前的下标使用情况
vector<pair<int, int>> add, query; //用来存放并记录添加和查询

// 二分查找, 通过查找函数实现了下标的压缩, 建立了从值到下标的映射关系
int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    // 因为最后要求区间和, 是从1开始的
    return l + 1;
}

int main()
{
    cin >> n >> m;
    // 保存加入数据
    for(int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        
        alls.push_back(x);
    }
    
    // 保存数据询问
    for(int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        
        alls.push_back(l);
        alls.push_back(r);
    }
    
    // 去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    
    // 处理插入
    for(auto item : add)
    {
        int x = find(item.first); //确定应该插入到第几个下标
        a[x] += item.second;
    }
    
    // 预处理前缀和
    for(int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];
    
    // 处理询问
    for(auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}