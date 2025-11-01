#include "CPoint.h"
#include "CLine.h"
#include "CRectangle.h"
#include "CDynamicArray.h"

#include <crtdbg.h>

int CPoint::InstanceCount = 0;
int CLine::InstanceCountLine = 0;
int CRectangle::InstanceCountRectangle = 0;

int main()
{
    // DEMO CPoint.h
    CPoint root(5, 6);
    CPoint copy(root);
    std::cout << "Nut copy: " << copy << " " << std::endl;

    CPoint* start = new CPoint(4, 3);
    CPoint* end = new CPoint(10, 9);
    float length = CPoint::CalcDistance(start, end);
    std::cout << "Khoang cach hai diem la: " << length << std::endl;

    CPoint* temp = start;
    CPoint* meet = new CPoint(*start);
    std::cout << "Dia diem gap: " << *meet << std::endl;

    std::cout << "So diem da tao ra: " << CPoint::InstanceCount << std::endl;

    delete meet;


    // DEMO CLine.h
    CLine line(start, end);
    CLine copyLine(line);
    std::cout << "\nDuong thang ban dau la: " << *line.start() << ", " << *line.end() << ", length = " << line.length() << std::endl;
    std::cout << "Duong thang copy la: " << *copyLine.start() << ", " << *copyLine.end() << ", length = " << copyLine.length() << std::endl;

    std::cout << "So duong thang da tao ra la: " << CLine::InstanceCountLine << std::endl;

    delete start;
    delete end;


    // DEMO CRectangle.h
    CRectangle* rec = new CRectangle;
    CRectangle copyRec(*rec);
    std::cout << "\nHinh chu nhat ban dau la: " << *rec->topLeft() << ", " << *rec->bottomRight() << std::endl;
    std::cout << "Hinh chu nhat copy la: " << *copyRec.topLeft() << ", " << *copyRec.bottomRight() << std::endl;

    std::cout << "So hinh chu nhat da tao ra la: " << CRectangle::InstanceCountRectangle << std::endl;

    delete rec;


    // DEMO CDynamicArray.h
    CDynamicArray* array = new CDynamicArray;
    bool isRunning = true;
    while (isRunning) {
        std::cout << "\n______________________________" << std::endl;
        std::cout << "1. Nhan phim 1 de them phan tu vao cuoi mang." << std::endl;
        std::cout << "2. Nhan phim 2 de lay phan tu tai index i." << std::endl;
        std::cout << "3. Nhan phim 3 de sao chep mang." << std::endl;
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
        case 3: {
            std::cout << "Mang da sao chep la: \n";
            CDynamicArray* copyArray = new CDynamicArray(*array);
            copyArray->print();
            delete copyArray;
            break;
        }
        default:
            isRunning = false;
            std::cout << "Ket thuc chuong trinh!!!\n";
            break;
        }
    }
    delete array;

    _CrtDumpMemoryLeaks();
    return 0;
}

