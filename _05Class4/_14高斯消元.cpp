/*
    方法
        通过初等行变换
        如果产生一个完美的上三角的阶梯型 --> 唯一解
        如果出现 0 = !0 的情况 --> 无解
        如果出现几组0 = 0的情况 --> 有无数个解
    
    高斯消元
    在O(n ^ 3)时间内解出线性方程组的解
    算法步骤
        枚举每一列c
        1. 找到当前列绝对值最大的一行
        2. 把这一行换到最上面(未确定阶梯型的行的顶行, 并不一定是第一行)
        3. 将该行的第一个数变成1(其余的数跟着发生变化)
        4. 将下面所有行的当且列的值消成0
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 110;
const double eps = 1e-6;

int n;
double a[N][N];

int gauss()
{
    int c, r;
    for(c = 0, r = 0; c < n; c++)
    {
        int t = r;
        for(int i = r; i < n; i++)
            if(fabs(a[i][c]) > fabs(a[t][c]))
                t = i;
                
        if(fabs(a[t][c]) < eps) continue;
        
        for(int i = c; i < n + 1; i++) swap(a[t][i], a[r][i]);
        for(int i = n; i >= c; i--) a[r][i] /= a[r][c];
        for(int i = r + 1; i < n; i++)
            if(fabs(a[i][c]) > eps)
                for(int j = n; j >= c; j--)
                    a[i][j] -= a[r][j] * a[i][c];
                    
        r++;
    }
    
    if(r < n)
    {
        for(int i = r; i < n; i++)
            if(fabs(a[i][n]) > eps)
                return 2;
        return 1;
    }
    
    for(int i = n - 1; i >= 0; i--)
        for(int j = i + 1; j < n; j++)
            a[i][n] -= a[j][n] * a[i][j];
    
    return 0;
}

int main()
{
    cin >> n;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n + 1; j++)
            cin >> a[i][j];
            
    int t = gauss();
    
    if(t == 0)
    {
        for(int i = 0; i < n; i++)
        {
            if (fabs(a[i][n]) < eps) a[i][n] = 0;
            printf("%.2lf\n", a[i][n]);
        }
    }
    else if(t == 1) puts("Infinite group solutions");
    else puts("No solution");
    
    return 0;
}