#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
}

/*
    vector的构造函数
    vector<T> v; //采用模板数显, 默认构造函数
    vector(v.begin(), v.end()); //将v前闭后开地拷贝给新的v
    vector(n, elem); //构造函数将n个elem拷贝给本身
    vector(const vector& vec); //拷贝构造函数
*/
void test01()
{
    vector<int> v1; // 默认无参构造

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    printVector(v1);

    // 通过区间分方式进行构造
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    // n个elem
    vector<int> v3(3, 6);
    printVector(v3);

    // 拷贝构造
    vector<int> v4(v3);
    printVector(v4);
}

int main()
{
    test01();
    system("pause");
    return 0;
}