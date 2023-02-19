#include <bits/stdc++.h>

using namespace std;

/*
    字符串的插入与删除
*/
void test01()
{
    string str = "hello";

    // 插入
    str.insert(1, "1111");
    cout << str << endl;

    // 删除
    str.erase(1, 3); // 从哪起, 删几个
}

int main()
{
    test01();
    system("pause");
    return 0;
}