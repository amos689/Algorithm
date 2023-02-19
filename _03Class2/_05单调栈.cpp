// 单调xx核心思想: 将永远都用不到(不会是答案)的数据扔掉
#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int stk[N], stt;

void find(int x)
{
    // 当栈不为空, 且栈顶元素不是比x小时, 一直出栈
    while(stt && stk[stt] >= x) stt--;
    if(stt) cout << stk[stt] << " ";
    else cout << -1 << " ";
    stk[++stt] = x;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        find(x);
    }
    
    return 0;
}