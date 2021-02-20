/*
 * @Author: zwb 
 * @Date: 2021-02-08 09:27:06 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-08 10:15:19
 * @Desc: 封装一个函数，利用冒泡排序，实现对整型数组的升序排序
 */
#include <iostream>
using namespace std;

void bubbleSort(int* arr, int len)
{
    for(int i=0; i<len-1; i++)
    {
        for(int j=0; j<len-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

void display(int* arr, int len)
{
    for (int i=0; i<len;i++)
    {
        cout << arr[i] << endl;
    }
}


int main()
{
    int arr[10] = {4,6,2,9,1,3,0,7,8,5};

    int len = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, len);

    display(arr, len);

    return 0;

}

