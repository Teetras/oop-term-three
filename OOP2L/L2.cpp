#include<iostream>
#include<fstream>
using namespace std;

class Point3D {
 
public:
   int x, y, z;
    Point3D()
    {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }
    Point3D(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Point3D(Point3D& point)
    {
        this->x = point.x;
        this->y = point.y;
        this->z = point.z;
    }
    Point3D& operator +(int a);
    Point3D& operator -(int a);
    Point3D& operator *(int a);
    Point3D& operator/ (int a);// +,  -,*,/
    friend ostream& operator<<(ostream& out,const Point3D&);//write in potok
    friend istream& operator>>(istream& in, Point3D&);//read from potok
};
Point3D& Point3D::operator/ (int a)
{
    this->x = this->x / a;
    this->y = this->y / a;
    this->z = this->z / a;
    return *this;
}
Point3D& Point3D::operator *(int a)
{
    this->x = this->x *a;
    this->y = this->y*a;
    this->z = this->z *a;
    return *this;
}
Point3D& Point3D::operator -(int a)
{
    this->x = this->x -a;
    this->y = this->y -a;
    this->z = this->z -a;
    return *this;
}
Point3D& Point3D::operator +(int a)
{
    this->x = this->x +a;
    this->y = this->y +a;
    this->z = this->z +a;
    return *this;
}
ostream& operator <<(ostream& out,const Point3D& point2)
{
    out << point2.x << "  " << point2.y << "  " << point2.z << endl;
    return out;
}
istream& operator >>(istream& in, Point3D& point) {
    cout << "X:" << endl;
    in >> point.x;
    cout << "Y:" << endl;
    in >> point.y;
    cout << "Z:" << endl;
    in >> point.z;
    return in;
}
int main()
{
    int change;
    int  a;
    cout << "Vvedite koof dlya operacii" << endl;
    cin >> a;
    cout << "\tVibereti deistvie" << endl;
    cout << "1. Slogenie" << endl;
    cout << "2. Otnimanie" << endl;
    cout << "3. Mnogenie" << endl;
    cout << "4. Delenie" << endl;
    cout << "4. Exit" << endl;
    cin >> change;

    Point3D point;
    Point3D point4(point);

    switch (change)
    {
    case 1:cin >> point;
        point + a;
 cout << "Itog";
        cout << point;
       
        break;
    case 2:cin >> point;
        point - a;
        cout << "itog" << endl;  cout << point;
        
       break;

    case 3:cin>> point;
        point* a;
      cout << "itog"<<endl;  cout << point;
        
        cout << "mnoget";
    	break;
    case 4:cin>> point;
        point / a;  cout << "itog" << endl;
        cout << point;
        cout << "dell";break;
    case 5:return 0;
    default:
        printf("Invalid choice.\n");
        break;

    }
};