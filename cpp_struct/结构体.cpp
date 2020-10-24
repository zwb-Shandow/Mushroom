#include <iostream>
#include <cstring>

using namespace std;

// 声明一个结构体类型
struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

int main()
{
    Books Book1;
    Books Book2;

    // Book1详述
    strcpy(Book1.title, "Cpp");
    strcpy(Book1.author, "Run");
    strcpy(Book1.subject, "编程");
    Book1.book_id = 123;

    // Book2详述
    strcpy(Book2.title, "python");
    strcpy(Book2.author, "Run");
    strcpy(Book2.subject, "编程");
    Book2.book_id = 1234;

    cout << Book1.title << endl;
    cout << Book1.author << endl;
    cout << Book1.subject << endl;
    cout << Book1.book_id << endl;

    cout << Book2.title << endl;
    cout << Book2.author << endl;
    cout << Book2.subject << endl;
    cout << Book2.book_id << endl;

    return 0;
}

