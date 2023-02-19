#include <bits/stdc++.h>

using namespace std;

/*
    string字符存取
    char& operator[](int n); //通过[]方式取字符
    char& at(int n); //通过at方法获取字符
*/
void test1()
{
    string str = "hello";
    cout << str << endl;

    // 1. 通过[]的方式来访问
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;

    // 2. 通过at的方式来访问
    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << " ";
    }
    cout << endl;

    // 修改单个字符
    str[0] = 'x';
    cout << str << endl;
    str.at(1) = 'x';
    cout << str << endl;
}

int main()
{
    test1();
    system("pause");
    return 0;
}