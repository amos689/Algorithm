#include <bits/stdc++.h>

using namespace std;

// 字符串查找和替换

// 1. 查找
void test1()
{
    string str1 = "abcdefg";
    int pos = str1.find("de"); // 从零开始第一次出现的位置, 如果要返回最后一次, 用rfind
    cout << pos << endl;
    pos = str1.find("yz"); // 未找到返回-1
    cout << pos << endl;
}

// 2. 替换
void test2()
{
    string str1 = "abcdefg";
    str1.replace(0, 1, "Amos"); // 从哪个位置起多少个字符替换为传入字符串
    cout << str1 << endl;
}

int main()
{
    test1();
    test2();
    system("pause");
    return 0;
}