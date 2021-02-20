/*
 * @Author: zwb 
 * @Date: 2021-02-01 15:49:08 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-01 15:56:52
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>

class PersonImpl;  //实现类的声明，此处无需暴露实现细节

class Person
{
public:
    Person(std::string& name);
    virtual ~Person();
    std::string& getName();  //要暴露的功能接口
private:
    PersonImpl* m_personImpl;  //指向实现类的对象
};

#endif