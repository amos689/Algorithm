#include <bits/stdc++.h>

using namespace std;

// 输出函数
void myPrint(int value)
{
    cout << value << endl;
}
// vector容器存放内置数据类型
void test01()
{
    // 创建一个vector容器
    vector<int> v;

    // 向容器中插入数据
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(50);

    // 通过迭代器访问容器中的数据
    vector<int>::iterator itBegin = v.begin(); // 起始迭代器, 指向容器中第一个元素
    vector<int>::iterator itEnd = v.end();     // 结束迭代器, 指向容器中最后一个元素的下一个位置

    // 第一种的遍历方式
    while (itBegin != itEnd)
    {
        cout << *itBegin << endl;
        itBegin++;
    }
    cout << "==========" << endl;

    // 第二种遍历方式
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    cout << "==========" << endl;

    // 利用STL提供的遍历算法
    for_each(v.begin(), v.end(), myPrint); // 函数回调机制
}

int main()
{
    test01();
    system("pause");
    return 0;
}