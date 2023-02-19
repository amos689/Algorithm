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
    vector的赋值操作
    vector& operator = const vector &vec; //重载等号操作符
    assign(beg, end); //前开后闭
    assign(n, elem); //将n个elem拷贝给本身
*/
void test01()
{
    vector<int> v1;
    for (int i = 0; i < 6; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    // 赋值
    vector<int> v2 = v1;
    v2.push_back(6);
    printVector(v2);
    printVector(v1);

    // assign
    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);

    // n个elements
    vector<int> v4;
    v4.assign(3, 6);
    printVector(v4);
}

int main()
{
    test01();
    system("pause");
    return 0;
}