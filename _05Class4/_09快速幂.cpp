/*
    快速幂(O(log(n)))
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int qmi(int a, int b, int p)
{
    LL res = 1;
    while(b)
    {
        // 看b的二进制位的第一位是否为1, 是则乘对应的a
        if(b & 1) res = res * a % p;
        b >>= 1;
        // 更新a,a依次为a^{2^0},a^{2^1},a^{2^2},....,a^{2^logb}, 一共log(b)个
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
        int a, b, p;
        cin >> a >> b >> p;
        
        cout << qmi(a, b, p) << endl;
    }
    
    return 0;
}