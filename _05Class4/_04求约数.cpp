// 试除法求一个数的所有约数
#include<bits/stdc++.h>

using namespace std;

vector<int> get_divisors(int x)
{
    vector<int> ans;
    
    for(int i = 1; i <= x / i; i++)
    {
        if(x % i == 0)
        {
            ans.push_back(i);
            // 如果不是根号x, 就增加一个大于根号x的那个对应的数
            if(i != x / i) ans.push_back(x / i);
        }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    while(n--)
    {
        int x;
        cin >> x;
        auto ans = get_divisors(x);
        for(auto t : ans) cout << t << " ";
        cout << endl;
    }
    
    return 0;
}