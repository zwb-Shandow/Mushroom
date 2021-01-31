/*
 * @Author: zwb 
 * @Date: 2021-01-19 21:10:20 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-19 21:27:11
 * @Description: 类层次
 */

class Shape {
public:
    virtual Point center() const = 0;
    virtual void move(Point to) = 0;

    virtual void draw() const = 0;
    virtual void rotate(int angle) = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    Circle(Point p, int rad);

    Point center() const override
    {
        return x;
    }
    void move(Point to) const override
    {
        x = to;
    }

    void draw() const override;
    void rotate(int) override {}
private:
    Point x;  // 圆心
    int r;  // 半径
};

class Smiley : public Circle {
public:
    Smiley(Point p, int rad) : Circle{p,r}, mouth{nullptr} {}

    ~Smiley()
    {
        delete mouth;
        for (auto p : eyes)
            delete p;
    }

    void move(Point to) override;

    void draw() const override;
    void rotate(int) override;

    void add_eye(Shape* s)
    {
        eyes.push_back(s);
    }
    void set_mouth(Shape* s);
    virtual void wink(int i);
private:
    vector<Shape*> eyes;
    Shape* mouth;
};