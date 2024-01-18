# C++ STL补充

> 这部分内容仅是补充C++ STL容器概念
> 只适用于算法比赛中加快速度
> 不适用于考研数据结构和所有算法类考试中

## 1. Vector

```C++
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
```

```c++
#include <bits/stdc++.h>

using namespace std;

// vector中存放自定义数据类型
class Person
{
public:
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_Age = age;
    }
    string m_name;
    int m_Age;
};

void test01()
{
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("ccc", 30);
    Person p3("bbb", 20);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    // 向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    // 遍历程序中的数据
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名: " << (*it).m_name << "  年龄: " << (*it).m_Age << endl;
    }
    cout << "============" << endl;
}

// 存放自定义数据类型的指针
void test02()
{
    vector<Person *> v;
    Person p1("aaa", 10);
    Person p2("ccc", 30);
    Person p3("bbb", 20);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    // 向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    // 遍历容器
    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*it)->m_name << "   " << (*it)->m_Age << endl;
    }
}

int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
```

```c++
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

// 容器中嵌套容器
void test1()
{
    vector<vector<int>> v;
    // 创建小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    // 向小容器中添加数据
    for (int i = 0; i < 4; i++)
    {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    // 将小容器插入到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    // 通过大容器将所有数据遍历一遍
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        // (*it) -------- 就是一个容器, 是一个vector<int>
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << *vit << endl;
        }
        cout << endl;
    }
}

int main()
{

    system("pause");
    return 0;
}
```

```c++
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
```

```c++
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
```

```c++
#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
}

/*
    vector容量和大小
    - empty(); 判断容器是否为空
    - capacity(); 返回容器的容量(capacity >= size)容量大于等于大小
    - size(); 返回容器中元素的个数
    - resize(int num); 重新指定容器的长度为num, 若容器变长, 则默认值填充新的位置
      若容器变短, 则末尾超出容器的长度的元素将被删除
    - resize(int num, elem); 重新指定容器的长度为num, 若容器变长, 则以elem值填充新的位置
      如果容器变短, 则末尾超出容器长度的元素会被删除
*/
void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    if (v1.empty())
    {
        cout << "v1为空" << endl;
    }
    else
    {
        cout << "v1不为空" << endl;
        cout << "v1的容量是: " << v1.capacity() << endl;
    }

    // 重新指定大小
    v1.resize(15, 100);
    printVector(v1); // 如果重新指定的比原来长, 以默认值/参数值代替
    v1.resize(5);
    printVector(v1); // 重新指定的比以前短了, 超出的部分会删除
}

int main()
{
    test01();
    system("pause");
    return 0;
}
```

```c++
#include <bits/stdc++.h>

using namespace std;

/*
    vector的插入和删除
    - push_back(elem); 尾部插入元素elem
    - pop_back(); 删除最后一个元素
    - insert(const_iterator pos, elem); 迭代器指向位置pos插入元素elem
    - insert(const_iterator pos, int count, elem); 迭代器指向位置pos插入count个元素elem
    - erase(const_iterator pos); 删除迭代器指向的元素
    - erase(const_iterator start, const_iterator end); 删除迭代器从start到end之间的元素
    - claer(); 删除容器中所有的元素
*/

int main()
{

    system("pause");
    return 0;
}
```



## 2. String

```c++
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
```

```c++
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
```

```c++
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
```

```c++
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
```

```c++
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
```

```c++
#include <bits/stdc++.h>

using namespace std;

// string子串
// string substr(int pos, int n) //从哪开始截取几个
void test01()
{
    string str = "abcdef";
    string sub = str.substr(1, 3);
    cout << sub << endl;

    // 从邮件中获取字符串信息
    string email = "amos@gmail.com";
    int pos = email.find("@");
    cout << email.substr(0, pos) << endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}
```

