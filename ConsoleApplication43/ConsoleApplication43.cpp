#include <iostream>
using namespace std;

class Point {
    int x;
    int y;
public:
    Point() {
        cout << "Construct\n";
    
    }

    Point(int x1, int y1) {
        cout << "Construct by 2 param\n";
        x = x1;
        y = y1;
    }

    void Init() {
        x = rand() % 10;
        y = rand() % 10;
    }

    void Init(int x1, int y1) {
        x = x1;
        y = y1;
    }

    void Output() {
        cout << "X: " << x << "\tY: " << y << endl;
    }

    Point operator+(Point& b) {
        Point temp;
        temp.x = this->x + b.x;
        temp.y = this->y + b.y;
        return temp;
    }

    Point operator+(int a) {
        return Point(x + a, y + a);
    }

    Point operator-(int a) {
        return Point(x - a, y - a);
    }

    Point operator*(int a) {
        return Point(x * a, y * a);
    }

    Point operator/(int a) {
        if (a != 0) {
            return Point(x / a, y / a);
        }
        else {
            cout << "Error: Division by zero" << endl;
            return *this; 
        }
    }

    friend Point operator-(int a, const Point& p) {
        return Point(a - p.x, a - p.y);
    }

    int GetX() {
        return x;
    }

    int GetY() {
        return y;
    }

    void SetX(int a) {
        x = a;
    }

    void SetY(int a) {
        y = a;
    }
};

int main() {
    Point a(1, 2);
    Point b(3, 4);

    Point q = 100 - a; 
    q.Output();

    q = a * 10; 
    q.Output();

    q = a / 10; 
    q.Output();

    Point c = a + b; 
    c.Output();

}
