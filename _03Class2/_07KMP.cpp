#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int n, m;
char p[N], s[M];
int ne[N];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n >> p + 1 >> m >> s + 1;
    
    // 让比较链永远比被比较链长1
    // 从2开始, 因为ne[1] = 0
    for(int i = 2, j = 0; i <= n; i++)
    {
        while(j && p[i] != p[j + 1]) j = ne[j]; //如果跟下一个不匹配, 使用下一个j的地方的值继续匹配
        if(p[i] == p[j + 1]) j++; //知道能匹配到了, 那就让这个值加一, 如果是while中j == 0下来的, 如果头对应就是1, 对应不了就是0
        ne[i] = j; //记录当前字符对应的前缀长度
    }
    
    for(int i = 1, j = 0; i <= m; i++)
    {
        // 完全和上文同理
        while (j && s[i] != p[j + 1]) j = ne[j];
        if(s[i] == p[j + 1]) j++;
        if(j == n)
        {
            cout << i - n << " "; //输出
            j = ne[j]; //让j继续往下走
        }
    }
    return 0;
}