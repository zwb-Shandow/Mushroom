#pragma once
#include <boost/shared_ptr.hpp>

class CTest
{
public:
    CTest();
    ~CTest();
    void DoSomething();
private:
    class CTestImpl;
    boost::shared_ptr<CTestImpl> pimpl;
};

