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