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
        // 先找到当前这一列，绝对值最大的一个数字所在的行号
        int t = r; // 初始化t，t表示当前列中绝对值最大的数在哪一行
        for(int i = r; i < n; i++) // 从未定型的第0行开始搜
            if(fabs(a[i][c]) > fabs(a[t][c]))
                t = i;
        
        // 如果这一列的每一个数都是0，那就没有必要做后面的操作了        
        if(fabs(a[t][c]) < eps) continue;
        
        // 将这一行换到第r行上，形成倒三角
        for(int i = c; i < n + 1; i++) swap(a[t][i], a[r][i]);
        
        // 将这一行从后往前，将所有数都除以第c列的数，目标是将第c列的数变为1
        for(int i = n; i >= c; i--) a[r][i] /= a[r][c];
        
        // 把当前行(r)下面的所有第c列的数都消成0
        for(int i = r + 1; i < n; i++)
            if(fabs(a[i][c]) > eps)
                for(int j = n; j >= c; j--)
                    // 这里的操作是, 将第i行第j列的数减去, 第r行第c列与第i行第c列相差的倍数 * 第r行第j列的数
                    a[i][j] -= a[r][j] * a[i][c];
        
        // 做完一行定型一行            
        r++;
    }
    
    if(r < n)
    {
        for(int i = r; i < n; i++)
            // 因为已经是阶梯型，所以r ~ n-1的末位应该都是0
            if(fabs(a[i][n]) > eps)
                // 如果不是, 那就是无解
                return 2;
        // 如果是, 那就是有无数解
        return 1;
    }
    
    // 如果r不小于n，说明方程有唯一解，我们需要把方程的每一项答案整合
    // 从下往上减
    for(int i = n - 1; i >= 0; i--)
        for(int j = i + 1; j < n; j++)
            // 每n行最后一个值表示第n个未知数的解
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