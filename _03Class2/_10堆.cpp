/*
    堆: 一棵完全二叉树, 小根堆: 从上往下看值一直减小(根小枝大)
        1. 插入一个数
            heap[++size] = x;
            up(size);
        2. 求这个集合当中的最小值
            heap[1];
        3. 删除最小值
            heap[1] = heap[size--];
            down(1);
        4. 删除任意一个元素
            heap[k] = heap[size--];
            down(k); up(k);
        5. 修改任意一个元素
            heap[k] = x;
            down(k); up(k);
    
    存储: 一个一维数组(从1开始)
        x的左儿子: 2x
        x的右儿子: 2x + 1
    
    核心操作: down(x), up(x)
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int h[N], ph[N], hp[N], idx, cnt; //idx对应了有几个插入的数, cnt对应了堆中有几个数

// 因为这里传递的a和b是在堆中的下标, 所以不仅要有ph[], 还要有hp[]
void heap_swap(int a, int b)
{
    // 这三个没有顺序限制, 因为这三个本质相互独立
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

// k是堆中下标
void down(int k)
{
    int min = k;
    if(k * 2 <= cnt && h[k * 2] < h[min]) min = k * 2;
    if(k * 2 + 1 <= cnt && h[k * 2 + 1] < h[min]) min = k * 2 + 1;
    if(min != k)
    {
        heap_swap(min, k); // 将小的放到上面, 此时min代表的就是原来大的k
        down(min); // 将换下来的大数继续down
    }
}

// k是堆中下标
void up(int k)
{
    while(k / 2 && h[k] < h[k / 2])
    {
        heap_swap(k, k / 2);
        k /= 2; // 将换上去的继续up
    }
}

int main()
{
    cin >> n;
    
    while(n--)
    {
        int k, x;
        char op[5];
        cin >> op;
        if(!strcmp(op, "I"))
        {
            cin >> x;
            // 在第一个的时候这里已经自增过了, 所以最小的下标是1而不是0
            idx++, cnt++;
            // 生成第几个插入与堆中下标的对应关系
            ph[idx] = cnt, hp[cnt] = idx;
            h[cnt] = x;
            up(cnt);
        }
        else if(!strcmp(op, "PM")) cout << h[1] << endl;
        else if(!strcmp(op, "DM"))
        {
            heap_swap(1, cnt);
            cnt--;
            down(1);
        }
        else if(!strcmp(op,"D"))
        {
            cin >> k;
            // 将"第k个数"转换堆中下标
            k = ph[k];
            heap_swap(k, cnt);
            cnt--;
            up(k);
            down(k);
        }
        else
        {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);
        }
    }
    
    return 0;
}