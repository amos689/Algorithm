#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> args, ans;

int main()
{
    // 读入
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        args.push_back({l, r});
    }
    
    // 排序, sort排序pair默认先按左边再按右边
    sort(args.begin(), args.end());
    
    int st = -2e9, ed = -2e9;
    for(auto item : args)
    {
        // 处理无法合并, 即找到了一个新的区间
        if(ed < item.first)
        {
            // 先看看是不是第一个, 如果是, 先不算
            if(st != -2e9) ans.push_back({st, ed});
            st = item.first, ed = item.second;
        }
        else
        {
            // 能合并, 判断末尾需不需要延长
            ed = max(ed, item.second);
        }
    }
    
    // 最后一个元素在for循环中无法被添加, 需要被加入, 同时防止空传入情况
    if(st != -2e9) ans.push_back({st, ed});
    
    cout << ans.size() << endl;
    return 0;
}