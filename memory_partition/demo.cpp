/***********************************************************  
* File name: demo.cpp                                        *
* Time: 2020/12/12                                           
* Author: trunk    
* Description: 堆区，栈区，全局区，代码区，文字常量区
***********************************************************/
#include <malloc.h>
#include <string.h>

int a = 0;  // 全局初始化区

char *p1;  // 全局未初始化区

int main()
{
    int b;  // 栈区
    char s[] = "abc";  // 栈区
    char *p2;  // 栈区
    char *p3 = "123456";  // "123456"在文字常量区，p3在栈区

    static int c = 0;  // 全局（静态）初始化区
    p1 = (char *)malloc(10);  // malloc在堆区分配内存
    p2 = (char *)malloc(20);  //
    strcpy(p3, "123456");  // "123456"在文字常量区，编译器会将它与p3所指向的"123456"，优化成一个地方

    return 0;

}