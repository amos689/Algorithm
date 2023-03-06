/*
    当n为质数时, 可以用快速幂求逆元
        a / b ≡ a * x (mod n)
        两边同乘b可得 a ≡ a * b * x (mod n)
        即 1 ≡ b * x (mod n)
        同 b * x ≡ 1 (mod n)
        由费马小定理可知，当n为质数时
        b ^ (n - 1) ≡ 1 (mod n)
        x * b = b ^ (n - 1)
        x = b ^ (n - 2)
        拆一个b出来可得 b * b ^ (n - 2) ≡ 1 (mod n)
        故当n为质数时，b的乘法逆元 x = b ^ (n - 2)
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

LL qmi(int a, int b, int p)
{
    LL res = 1;
    while(b)
    {
        if(b & 1) res = res * a % p;
        b >>= 1;
        a = (LL)a * a % p;
    }
    
    return res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    while(n--)
    {
        int a, p;
        cin >> a >> p;
        if(a % p) cout << qmi(a, p - 2, p) << endl;
        else cout << "impossible" << endl;
    }
    
    return 0;
}