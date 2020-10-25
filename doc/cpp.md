## 常用操作记录

**运算符**
 - 成员访问运算符： [.]
 - 范围解析运算符： [::]
 - 访问修饰符：
```
class Base
{
    public:  // 公有成员，类外可访问
    protected:  // 受保护成员
    private:  // 私有成员，类外不可访问
}
```
---

**类相关**
初始化列表的成员初始化顺序：
 - C++ 初始化类成员时，是按照声明的顺序初始化的，而不是按照出现在初始化列表中的顺序。
 
 深拷贝与浅拷贝
  - 如果一个类拥有资源，当这个类的对象发生复制过程的时候，资源重新分配，
  这个过程就是深拷贝，反之，没有重新分配资源，就是浅拷贝。