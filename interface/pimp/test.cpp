/*
 * @Author: zwb 
 * @Date: 2021-02-01 21:01:54 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-02 08:19:01
 */
#include "test.h"
#include <iostream>

class CTest::CTestImpl
{
private:
    CTestImpl(CTestImpl const &){}
    CTestImpl & operator=(CTestImpl const &){}
public:
    CTestImpl(){}
    void DoSomethind();
}