#include "CPoint.h"
#include "CLine.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "CFraction.h"
#include "CDynamicArray.h"

#include <crtdbg.h>

int CPoint::InstanceCount = 0;
int CLine::InstanceCountLine = 0;
int CRectangle::InstanceCountRectangle = 0;
int CCircle::InstanceCountCircle = 0;
int CFraction::InstanceCountFraction = 0;

int main()
{
    // DEMO CPoint.h
    CPoint* meet = new CPoint(4, 3);
    std::cout << "Dia diem gap mat: " << meet->ToString() << std::endl;
    delete meet;

    CPoint* start = new CPoint();
    std::cin >> *start;
    std::cout << "Diem bat dau: " << *start << std::endl;




    // DEMO CLine.h
    CLine* line = new CLine();
    std::cout << "\nDuong thang khoi tao la: " << line->ToString() << std::endl;
    
    std::cin >> *line;
    std::cout << "Duong thang sau khi nhap la: " << line->ToString() << std::endl;
    delete line;



    // DEMO CRectangle.h
    CRectangle* rec = new CRectangle ();
    std::cout << "\nHinh chu nhat khoi tao la: " << rec->ToString() << std::endl;

    std::cin >> *rec;
    std::cout << "Hinh chu nhat sau khi nhap la: " << rec->ToString() << std::endl;

    delete rec;


    // DEMO CCircle.h
    CCircle* cir = new CCircle ();
    std::cout << "\nHinh tron khoi tao la: " << cir->ToString() << std::endl;

    std::cin >> *cir;
    std::cout << "Hinh tron sau khi nhap la: " << cir->ToString() << std::endl;

    delete cir;

    // DEMO CFraction.h
    CFraction* f = new CFraction();
    std::cout << "\nPhan so khoi tao la: " << f->ToString() << std::endl;

    std::cin >> *f;
    std::cout << "Phan so sau khi nhap la: " << f->ToString() << std::endl;

    delete f;

    // DEMO CDynamicArray.h
    CDynamicArray* array = new CDynamicArray;
    bool isRunning = true;
    while (isRunning) {
        std::cout << "\n______________________________" << std::endl;
        std::cout << "1. Nhan phim 1 de them phan tu vao cuoi mang." << std::endl;
        std::cout << "2. Nhan phim 2 de lay phan tu tai index i." << std::endl;
        std::cout << "3. Nhan phim 3 de nhap mang." << std::endl;
        std::cout << "4. Nhan phim 4 de xuat mang." << std::endl;
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
            break;
        case 2:
            std::cout << "Moi thay nhap index can truy xuat: ";
            int index;
            std::cin >> index;
            std::cout << "Ket qua la: " << array->getAt(index) << std::endl;
            break;
        case 3: 
            std::cin >> *array;
            break;
        case 4:
            std::cout << *array;
            break;
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