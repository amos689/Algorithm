#include <bits/stdc++.h>

using namespace std;

/*
    字符串创建
    -string(); //创建一个空的字符串, 例如string str;
     string(const char* s); //使用字符串s进行初始化
    -string(const string & str); //使用一个string对象初始化另一个string对象
    -string(int n, char c); //使用n个字符c初始化
*/
// string的构造函数
void test1()
{
    string s1; // 默认构造

    const char *str = "hello world";
    string s2(str);

    cout << "s2 = " << s2 << endl;

    string s3(s2);
    cout << "s3 = " << s3 << endl;

    string s4(10, 'a');
    cout << "s4 = " << s4 << endl;
}

/*
    string的赋值操作
    - string& operator = (const char* s);
    - string& operator = (const char &s);
    - string& operator = (char c);
    - string& assign(const char* s);
    - string& assign(const char* s, int n); //s的前n个字符
    - string& assign(const string& s);
    - string& assign(int n, char c); //n个c
*/
void test2()
{
    string str1;
    str1 = "hello world";
    cout << str1 << endl;

    string str2;
    str2 = str1;
    cout << str2 << endl;

    string str3;
    str3 = '3';
    cout << str3 << endl;

    string str4;
    str4.assign("hello cpp");
    cout << str4 << endl;

    string str5;
    str5.assign("hello cpp", 5);
    cout << str5 << endl;

    string str6;
    str6.assign(str5);
    cout << str6 << endl;

    string str7;
    str7.assign(10, 'a');
    cout << str7 << endl;
}

/*
    字符串增加
    - string& operator += const char* str;
    - string& operator += const char c;
    - string& operator += const string& str;
    - string& append(const char* s);
    - string& append(const char* s, int n); //前n个
    - string& append(const string &s);
    - string& append(const string &s, int pos, int n); //从哪开始截取几个
*/
void test3()
{
    string str1 = "我";
    str1 += "是好人";
    cout << str1 << endl;

    str1 += '!';
    cout << str1 << endl;

    string str2 = "lol dnf";
    str1 += str2;
    cout << str1 << endl;

    string str3 = "I";
    str3.append(" love ");
    str3.append("Amos_Liu", 4);
    cout << str3 << endl;

    str3.append("Amos_Liu", 5, 3);
    cout << str3 << endl;
}

int main()
{
    test1();
    test2();
    test3();
    system("pause");
    return 0;
}