### 类和对象

c++面向对象的三大特性：封装，继承，多态

c++认为万事万物皆对象，对象有其属性和行为

**1. 封装**

封装意义：

- 将属性和行为作为一个整体，表现生活中的事务
- 将属性和行为加以权限控制

**1.1 构造函数的分类及调用**

两种分类方式：

- 按参数分为：有参构造和无参构造（默认构造）
- 按类型分为：普通构造和拷贝构造

三种调用方式：

- 括号法
- 显示法
- 隐世转换法

注意：调用默认构造函数时，不要加（）

**1.2 构造函数调用规则**

创建一个类，c++编译器会给每个类添加至少3个函数：

- 无参构造
- 有参构造
- 拷贝构造

调用规则：

- 如果用户定义有参构造函数，c++不再提供默认无参构造，但是会提供默认拷贝构造
- 如果用户定义拷贝构造函数，c++不会再提供其他构造函数

**1.3 深拷贝与浅拷贝**

浅拷贝：简单的赋值拷贝操作，会带来堆区内存重复释放

深拷贝：在堆区重新申请空间，进行拷贝操作

**1.4 静态成员**

在成员变量和成员函数前加关键字static，称为静态成员

静态成员分为：

- 静态成员变量
  - 所有对象共享同一份数据
  - 在编译阶段分配内存
  - 类内声明，类外初始化
- 静态成员函数
  - 所有对象共享同一个函数
  - 静态成员函数只能访问静态成员变量
  - 每个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码

**1.5 this指针**

this指针指向被调用的成员函数所属的对象

this指针的用途：

- 当形参和成员变量同名时，可用this指针来区分
- 在类的非静态成员函数中返回对象本身，可使用return *this

**1.6 const修饰成员函数**

常函数：

- 成员函数后加const后即为常函数
- 常函数内不可以修改成员属性
- 成员属性声明时加关键字mutable后，在常函数中依然可以修改

常对象：

- 声明对象前加const称改对象为常对象
- 常对象只能调用常函数