/*
    中国剩余定理
    m1, m2, m3 ... mk两两互质
    x ≡ a1(mod m1), x ≡ a2(mod m2) ... x ≡ ak(mod mk)
    令M = m1 * m2 * ... * mk, Mi = M / mi, M^-1表示Mi mod mi的逆
    则x = a1 * M1 * M1^-1 + a2 * M2 * M2^-1 + ... + ak * Mk * Mk^-1

    扩展中国剩余定理
    拿出上面其中两个式子, 化为x = k1 * a1 + m1, x = k2 * a2 + m2
    联立可得k1 * a1 - k2 * a2 = m2 - m1, 用扩展欧几里得算法可以求得k1, k2
    进而, k1, k2解集是k1 = k1 + k * a2 / d, k2 = k2 + k * a1 / d. (k是任意正整数)
    将k1代入式子中, x = k1 * a1 + m1 + k * a1 * a2 / d
    其中可将k1 * a1 + m1看做是新的m, k[a1, a2]是k * a, 用这个式子继续和下面的式子进行合并
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if(!b)
    {
        x = 1, y = 0;
        return a;
    }
    
    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    bool has_ans = true;
    LL a1, m1;
    cin >> a1 >> m1;
    
    for(int i = 1; i <= n - 1; i++)
    {
        LL a2, m2;
        cin >> a2 >> m2;
        
        LL k1, k2;
        LL d = exgcd(a1, a2, k1, k2);
        
        if((m2 - m1) % d)
        {
            has_ans = false;
            break;
        }
        
        // 因为此时k1是k1 * a1 + k2 * a2 = d的解,所以要乘上(m2 - m1) / d的倍数大小
        k1 *= (m2 - m1) / d;
        // 当k1是一个解时, k1 + k * a2 / d也是一个解(k为任意正数)
        LL t = a2 / d;
        // 将k1变成方程的最小正整数解
        k1 = (k1 % t + t) % t;
        
        // m1在被赋值之后的值为当前"x"的值, 此时赋值是为了方便下一轮的继续使用
        m1 = a1 * k1 + m1;
        // 循环结束时a1的值为当前所有的a1, a2, ... , an中的最小公倍数
        // 最小公倍数 = 两数相乘 / 两数的大公因数
        a1 = abs(a1 * a2 / d);
    }
    
    if(has_ans) cout << (m1 % a1 + a1) % a1 << endl;
    else cout << "-1" << endl;
    
    return 0;
}