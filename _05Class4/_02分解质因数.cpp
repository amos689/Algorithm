/*
    分解质因数: 试除法(O(sqrt(n)))
    n中最多只包含一个大于sqrt(n)的质因子
*/

#include<bits/stdc++.h>

using namespace std;

void divide(int x)
{
    for(int i = 2; i <= x / i; i++)
    {
        if(!(x % i))
        {
            int s = 0;
            while(!(x % i)) x /= i, s++;
            cout << i << ' ' << s << endl;
        }
    }
    // n中最多只包含一个大于sqrt(n)的质因子, 单独输出
    if(x > 1) cout << x << ' ' << 1 << endl;
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
        divide(x);
        cout << endl;
    }
    
    return 0;
}