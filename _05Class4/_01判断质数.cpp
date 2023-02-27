/*
    在大于1的整数中, 如果只包含1和本身这两个约数, 就被称为质数, 或者叫做素数
    判断质数: 试除法
*/
#include<bits/stdc++.h>

using namespace std;

int n;

// O(sqrt(n))
bool is_prime(int x)
{
    if(x < 2) return false;
    for(int i = 2; i <= x / i; i++)
    {
        if(!(x % i)) return false;
    }
    return true;
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
        if(is_prime(x)) cout << "Yes" << endl;
        else cout << "No" <<endl;
    }
    
    return 0;
}