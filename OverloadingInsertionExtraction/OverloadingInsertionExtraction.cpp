#include<iostream>

using namespace std;

class Point
{
    int x,y,z;

public:

	friend istream& operator >> (istream& in, Point& p);
	friend ostream& operator << (ostream& out, Point& p);
};

class Rectangle
{
    int length,breadth;

public:

	friend istream& operator >> (istream& in, Rectangle& r);
	friend ostream& operator << (ostream& out, Rectangle& r);
};

class Triangle
{
    int base,height;

public:

	friend istream& operator >> (istream& in, Triangle& t);
	friend ostream& operator << (ostream& out, Triangle& t);
};

int main(){
    Point p;
    Triangle t;
    Rectangle r;

    std::cin >> p >> t >> r;
    std::cout << p << " " << t << " " << r << std::endl;

    std::cin >> p >> r >> t;
    std::cout << p << " " << r << " " << t << std::endl;

    std::cin >> r >> t >> p;
    std::cout << r << " " << t << " " << p << std::endl;

    std::cin >> r >> p >> t;
    std::cout << r << " " << p << " " << t << std::endl;

    std::cin >> t >> r >> p;
    std::cout << t << " " << r << " " << p << std::endl;

    std::cin >> t >> p >> r;
    std::cout << t << " " << p << " " << r << std::endl;

}

istream& operator>>(istream& in, Point& p)
{
	in >> p.x >> p.y >> p.z;
}

ostream& operator<<(ostream& out, Point& p)
{
	out << p.x << " " << p.y << " " << p.z;
}

istream& operator>>(istream& in, Rectangle& r)
{
	in >> r.length >> r.breadth;
	return in;
}

ostream& operator<<(ostream& out, Rectangle& r)
{
	out << r.length << " " << r.breadth;
	return out;
}

istream& operator>>(istream& in, Triangle& t)
{
	in >> t.base >> t.height;
	return in;
}

ostream& operator<<(ostream& out, Triangle& t)
{
	out << t.base << " " << t.height;
	return out;
}
