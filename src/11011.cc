#include <iostream>
#include <iomanip>
using namespace std;

class MyComplex
{
private:
  double x,y;
public:
  /* Implementation of MyComplex */
  friend istream& operator >> (istream& is, MyComplex& c) {
    is >> c.x >> c.y;
    return is;
  }

  friend ostream& operator << (ostream& os, const MyComplex& c) {
    os << fixed << setprecision(2) << c.x << ' ' << c.y;
    return os;
  }

  MyComplex(double x=0, double y=0): x(x), y(y) {}

  MyComplex operator + (const MyComplex& other) {
    return MyComplex(this->x + other.x, this->y + other.y);
  }

  MyComplex operator - (const MyComplex& other) {
    return MyComplex(this->x - other.x, this->y - other.y);
  }

  MyComplex operator * (const MyComplex& other) {
    double x1 = this->x, x2 = other.x, y1 = this->y, y2 = other.y;
    return MyComplex(x1 * x2 - y1 * y2, x1 * y2 + x2 * y1);
  }

  MyComplex operator / (const MyComplex& other) {
    double x1 = this->x, x2 = other.x, y1 = this->y, y2 = other.y;
    double d = x2 * x2 + y2 * y2;
    return MyComplex((x1 * x2 + y1 * y2) / d, (x2 * y1 - x1 * y2) / d);
  }

  MyComplex& operator += (const MyComplex& other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
  }

  MyComplex& operator -= (const MyComplex& other) {
    this->x -= other.x;
    this->y -= other.y;
    return *this;
  }
  
  MyComplex& operator *= (const MyComplex& other) {
    double x1 = this->x, x2 = other.x, y1 = this->y, y2 = other.y;
    this->x = x1 * x2 - y1 * y2;
    this->y = x1 * y2 + x2 * y1;
    return *this;
  }
  
  MyComplex& operator /= (const MyComplex& other) {
    double x1 = this->x, x2 = other.x, y1 = this->y, y2 = other.y;
    double d = x2 * x2 + y2 * y2;
    this->x = (x1 * x2 + y1 * y2) / d;
    this->y = (x2 * y1 - x1 * y2) / d;
    return *this;
  }
};

int main()
{
  MyComplex z1;
  MyComplex z2;

  cin >> z1 >> z2;

  cout << z1 + z2 <<endl;
  cout << z1 - z2 <<endl;
  cout << z1 * z2 <<endl;
  cout << z1 / z2 <<endl;
  cout << (z1 += z2) <<endl;
  cout << (z1 -= z2) <<endl;
  cout << (z1 *= z2) <<endl;
  cout << (z1 /= z2) <<endl;

  return 0;
}