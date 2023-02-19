/*
    归并排序 -- 分治
        1. 确定分界点mid: (l + r) / 2
        2. 递归排序left ~ right
        3. 归并, 合二为一(重点)
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n;
int q[N], tmp[N];

void merge_sort(int *q, int l, int r)
{
    // 递归出口
    if (l >= r)
        return;

    // 确定分界点
    int mid = l + r >> 1;

    // 递归左边和右边
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);

    // 归并
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];
    }
    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];

    for (int i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    merge_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
}