/*
 * @Author: zwb 
 * @Date: 2021-01-12 08:53:56 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-12 09:34:36
 * @Description: 类不变式
 */
#include <assert.h>
// 提供接口函数增加秒数，更新类成员变量；保持一个使用者的指针
class CDayTime
{
public:
    int AddTime(int iSeconds);
    bool IsValid();
private:
    void* m_pUser;
    int m_iHour;
    int m_iMinute;
    int m_iSecond;
};


int CDayTime::AddTime(int iSeconds)
{
    // ...
}

bool CDayTime::IsValid()
{
    if (m_iHour < 0 || m_iHour > 23)
        return false;
    if (m_iMinute < 0 || m_iMinute > 59)
        return false;
    if (m_iSecond < 0 || m_iSecond > 59)
        return false;
    return true;
}

// 基于RAII的自动化检查
class Checkinvariant
{
public:
    Checkinvariant(CDayTime* pTime)
        :m_pTime(pTime)
    {
        assert(m_pTime->IsValid());
    }
    ~Checkinvariant()
    {
        assert(m_pTime->IsValid());
    }
private:
    CDayTime* m_pTime;
}

int CDayTime::AddTime(int iSeconds)
{
    Checkinvariant oCheck(this);
    int iRet 
    
}