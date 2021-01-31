/*
 * @Author: zwb 
 * @Date: 2021-01-04 21:41:03 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-04 23:04:53
 */

#include <iostream>
#include <string>

using namespace std;

// 直接初始化
string s1("value");
// 拷贝初始化
string s2 = s1;

// empty() & size()
void usage()
{
    cout << s1 << " " << s2 << endl;
    cout << "empty用法: " << s1.empty() << endl;
    cout << "size用法: " << s1.size() << endl; // 使用了size()函数就要避免再使用int
}

// 统计字符串中的标点符号
void stat_symbol()
{
    string s("Hello World!");
    decltype(s.size()) punct_cnt = 0;  // 使用decltype关键字声明变量类型，只在c++11引入
    for (auto c : s)
        if (ispunct(c))
            ++punct_cnt;
    cout << punct_cnt << " punctuation charachers in " << s << endl;
}

// 字符串转换为大写
void translate()
{
    string s("Hello World!");
    for (auto &c : s)
        c = toupper(c);
    cout << s << endl;
}


// 字符串下标
void index()
{
    string s("some thing!");
    for (decltype(s.size()) index=0; index!=s.size() && !isspace(s[index]); ++index)
        s[index] = toupper(s[index]);
    cout << s << endl;
}

int main(){
    // usage();

    // stat_symbol();

    // translate();

    index();

    return 0;
}

