// 快速排序
/*
    快速排序 -- 分治
        1. 确定分界点x(假设从l到r)
          q[l]
          q[(l+r)/2]
          q[r]
        2. 调整区间, 使得小于等于x的在x的左边, 大于等于x的在x的右边(重点)
          (1)两指针相遇法
            让i指针永远指向x左边的数, j指针永远指向x右边的数
          (2)单开两个数组a, b
            如果q[i] <= x, 则放在a数组
            反之放在b数组
          将a, b放回到q
        3. 递归, 处理左右两端进行排序
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
    // 递归出口
    if (l >= r)
        return;

    // 确定分界点
    /*
        这里x必须等于q[l + r >> 1], 而不能是x = q + r >> 1
        因为在排序过程中交换过后的值是会变的
    */
    int x = q[l + r >> 1], i = l - 1, j = r + 1;

    // 两指针相遇法调整区间
    /*
        必须只能使用do while, 因为这是先自增后判断
        用while是先判断后自增, 当q[i] == x == q[j]时会发生死循环
    */
    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }

    // 递归处理左右两端
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
    /*
        注: 也可以写成:
        quick_sort(q, l, i - 1);
        quick_sort(q, i, r);
        其根本在于分治,[l, i - 1]的部分一定是交换过的, 是小于等于x的, 所以是分成[l, i - 1]和[i, r]两部分
        同理, [j + 1, r]的部分也一定是交换过的, 是大于等于x的, 所以分成[l, j]和[j + 1, r]两部分
    */
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
    return 0;
}