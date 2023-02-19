#include <bits/stdc++.h>

using namespace std;

// 字符串比较
void test1()
{
    // 逐个对比, 相等返回0, 不相等返回ascii码差值
    string str1 = "hello";
    string str2 = "hello";
    if (str1.compare(str2) == 0)
    {
        cout << "str1 == str2" << endl;
    }
    else
    {
        cout << "str1 != str2" << endl;
    }
}

int main()
{
    test1();
    system("pause");
    return 0;
}