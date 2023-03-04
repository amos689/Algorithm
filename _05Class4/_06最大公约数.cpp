/*
    辗转相除法
    用(a, b)表示a和b的最大公因数, 有结论: (a, b)=(a, ka + b), 其中a、b、k都为自然数
    对(a, b)连续使用辗转相除, 直到小括号内右边数字为0, 小括号内左边的数就是两数最大公约数
*/
#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    while(n--)
    {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    
    return 0;
}