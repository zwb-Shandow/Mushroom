/*
 * @Author: zwb 
 * @Date: 2021-01-30 14:21:20 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-30 14:26:35
 * @Desc: bind一个引用参数
 */
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std::placeholders;
using namespace std;

ostream& print(ostream &os, const string& s, char c)
{
    os << s << c;
    return os;
}

int main()
{
    vector<string> words{"hello","world","this","is","C++11"};
    ostringstream os;
    char c = ' ';
    for_each(words.begin(), words.end(),) 
}