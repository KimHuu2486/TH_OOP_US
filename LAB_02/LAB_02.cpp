#include <iostream>
#include "CPoint.h"
#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CDynamicArray.h"

int main()
{
    CPoint* start = new CPoint(4, 3);
    CPoint* end = new CPoint(10, 9);
    float length = start->CalcDistanceTo(end);
    std::cout << "Khoang cach hai diem la: " << length << std::endl;
    delete start;
    delete end;
    std::cout << std::endl;

    //CPoint* p = new CPoint();
    //p->addressOfThis();
    //std::cout << std::hex << &p << std::endl;
    //std::cout << std::hex << p << std::endl;

    CPoint* center = new CPoint;
    CCircle* cir = new CCircle(center, 2);
    std::cout << "Duong kinh cua hinh tron la: " << cir->Diameter() << std::endl;
    std::cout << "Chu vi cua hinh tron la: " << cir->Perimeter() << std::endl;
    std::cout << "Dien tich cua hinh tron la: " << cir->Area() << std::endl;
    delete center;
    delete cir;
    std::cout << std::endl;

    CRectangle* rectangle = new CRectangle;
    std::cout << "Chu vi cua hinh chu nhat la: " << rectangle->Perimeter() << std::endl;
    std::cout << "Dien tich cua hinh chu nhat la: " << rectangle->Area() << std::endl;
    delete rectangle;
    std::cout << std::endl;


    CTriangle* triangle = new CTriangle;
    std::cout << "Chu vi cua hinh tam giac la: " << triangle->perimeter() << std::endl;
    std::cout << "Dien tich cua hinh tam giac la: " << triangle->area() << std::endl;
    delete triangle;
    std::cout << std::endl;


    CDynamicArray* array = new CDynamicArray;
    bool isRunning = true;
    while (isRunning) {
        std::cout << "\n______________________________" << std::endl;
        std::cout << "1. Nhan phim 1 de them phan tu vao cuoi mang." << std::endl;
        std::cout << "2. Nhan phim 2 de lay phan tu tai index i." << std::endl;
        std::cout << "*Nhan phim bat ki khac de thoat chuong trinh.*" << std::endl;
        std::cout << "______________________________" << std::endl;

        std::cout << "Moi thay nhap chuc nang: ";
        int option;
        std::cin >> option;

        switch (option) {
        case 1:
            std::cout << "Moi thay nhap gia tri can them vao cuoi mang: ";
            int value;
            std::cin >> value;
            array->pushBack(value);
            std::cout << "Ket qua la: \n";
            array->print();
            break;
        case 2:
            std::cout << "Moi thay nhap index can truy xuat: ";
            int index;
            std::cin >> index;
            std::cout << "Ket qua la: " << array->getAt(index) << std::endl;
            break;
        default:
            isRunning = false;
            std::cout << "Ket thuc chuong trinh!!!\n";
            break;
        }
    }
    delete array;

    return 0;
}