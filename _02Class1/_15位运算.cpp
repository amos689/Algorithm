/*
根据计算机负数表示的特点，如一个数字原码是10001000，
他的负数表示形势是补码，就是反码+1，反码是01110111，加一则是01111000，二者按位与得到了1000，
这就是我们想要的lowbit操作
*/
#include<bits/stdc++.h>

using namespace std;

int n;

int lowbit(int i)
{
    return i & (- i);
}

int main()
{
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        
        int res = 0;
        while(x) x -= lowbit(x), res += 1;
        cout << res << ' ';
    }
    return 0;
}