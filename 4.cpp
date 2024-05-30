// Базовий клас "Фігури": віртуальні функції обчислення площі і периметра.
// Похідний клас "Трапеції": координати вершин, конструктор з параметрами, віртуальні функції обчислення площі і периметра.
// Похідний клас "Коло": радіус, конструктор з параметром, віртуальні функції обчислення площі і периметра

// Описати класи, об’єкти цих класів; обчислити і вивести площу та периметр об’єктів, використовуючи поліморфізм (вказівну/посилання базового класу)

#include <iostream>

class Figure{
    public:
        virtual double getArea() = 0;
        virtual double getPerimeter() = 0;
};

/*
    *  x1,y1 _________ x2,y2
    *       |       |
    *       |       |
    *  x4,y4|_______| x3,y3
    
    area = a+b/2 * h
    perimeter = a + b + c + d

    a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))
    b = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2))
    c = sqrt(pow(x4 - x1, 2) + pow(y4 - y1, 2))
    d = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2))
    h = y1 - y4
*/
class Trapezoid : public Figure{
    private:
        double x1, y1, x2, y2, x3, y3, x4, y4;
        double a, b, c, d, h;
        double sideLength(double x1, double y1, double x2, double y2){
            return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        }
    public:
        Trapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) :
            x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4){
                a = sideLength(x1, y1, x2, y2);
                b = sideLength(x4, y4, x3, y3);
                c = sideLength(x4, y4, x1, y1);
                d = sideLength(x3, y3, x2, y2);
                h = y1 - y4;
        }
        double getArea(){
            return ((a + b) / 2) * h;
        }
        double getPerimeter(){
            return a + b + c + d;
        }
};

/*
    area = pi * r^2
    perimeter = 2 * pi * r

    r - radius
    pi = 3.14

*/
class Circle : public Figure{
    private:
        double radius;
        double pi = 3.14;
    public:
        Circle(double radius){
            this->radius = radius;
        }
        double getArea(){
            return pi * radius * radius;
        }
        double getPerimeter(){
            return 2 * pi * radius;
        }
};

int main(){
    Figure *trapezoid = (Figure *) new Trapezoid(0, 1, 1, 1, 2, 0, 0, 0);
    Figure *circle = (Figure *) new Circle(5);
    std::cout << "Trapezoid area: " << trapezoid->getArea() << std::endl;
    std::cout << "Trapezoid perimeter: " << trapezoid->getPerimeter() << std::endl;
    std::cout << "Circle area: " << circle->getArea() << std::endl;
    std::cout << "Circle perimeter: " << circle->getPerimeter() << std::endl;
    return 0;
}