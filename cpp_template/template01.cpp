// 编写一个函数来比较两个值，适用不同类型
// 模板程序应该尽量减少对实参类型的要求

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

// 可用于比较指针的compare函数
template <typename T>
int compare_1(const T &v1, const T &v2)
{
    if (less<T>()(v1, v2)) return -1; // less<T> 默认实现用的就是<
    if (less<T>()(v2, v1)) return 1;
    return 0;
}

int main()
{
    // 模板实例化成int型
    std::cout << compare(1, 0) << endl;
    // 模板实例化成vector<int>
    vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
    std::cout << compare(vec1, vec2) << endl;


}