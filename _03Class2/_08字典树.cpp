/*
    注: 此题目中所注明的是所有输入的字符串的总和长度<=1e5, 所以N开1e5
    当插入n个字符串，每个字符串长度最大m等具有n, m这种两个变量时
    将N开到n * m, 即开到最大总和长度
    
    关于idx: 就是因为idx唯一所以p才不会重复 cnt[p]才能表示以当前字母结尾的单词数量
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int son[N][26], idx, cnt[N];
char str[N];

void ins()
{
    int p = 0;
    for(int i = 0; str[i]; i++)
    {
        int tmp = str[i] - 'a';
        if(!son[p][tmp]) son[p][tmp] = ++idx; // 给每个不是0的地方一个唯一确定的idx作为下标
        p = son[p][tmp]; // 指针移动到下一位
    }
    cnt[p]++;
}

void query()
{
    int p = 0;
    for(int i = 0; str[i]; i++)
    {
        int tmp = str[i] - 'a';
        if(!son[p][tmp])
        {
            cout << 0 << endl;
            return;
        }
        p = son[p][tmp];
    }
    cout << cnt[p] << endl;
}

int main()
{
    cin >> n;
    while(n--)
    {
        char op[2];
        cin >> op >> str;
        if(*op == 'I') ins();
        else query();
    }
    
    return 0;
}