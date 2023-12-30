
class Vector;

class Point
{
public:
    int x;
    int y;

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void move(Vector& AB);
};

class Vector
{
public:
    int x;
    int y;

    Vector(const Point& A, const Point& B)
    {
        this->x = B.x - A.x;
        this->y = B.y - A.y;
    }
};

void Point::move(Vector& AB)
{
    this->x += AB.x;
    this->y += AB.y;
}
