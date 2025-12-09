#include <iostream>
#include <string>
#include <limits>

#include "CFraction.h"
#include "Compare.h"
#include "CDynamicArray.cpp"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

std::string CFraction::SEPERATOR = "/";

void clearCin() {
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// DEMO CFraction.h/CFraction.cpp
	std::cout << "DEMO CFraction Class\n";

    CFraction f1, f2;
	std::cout << "Nhap phan so thu nhat:\n";
	std::cin >> f1;
	std::cout << "Nhap phan so thu hai:\n";
	std::cin >> f2;

	CFraction sum = f1 + f2;
	std::cout << "Tong hai phan so: " << sum << std::endl;
	CFraction diff = f1 - f2;
	std::cout << "Hieu hai phan so: " << diff << std::endl;
	CFraction prod = f1 * f2;
	std::cout << "Tich hai phan so: " << prod << std::endl;
	CFraction quot = f1 / f2;
	std::cout << "Thuong hai phan so: " << quot << std::endl;

	std::cout << "Phan so thu nhat ban dau: " << f1 << std::endl;
	std::cout << "++f1: " << ++f1 << std::endl;
	std::cout << "f1++: " << f1++ << std::endl;
	std::cout << "Phan so thu nhat luc sau: " << f1 << std::endl;

	std::cout << "Phan so thu hai ban dau: " << f2 << std::endl;
	std::cout << "--f2: " << --f2 << std::endl;
	std::cout << "f2--: " << f2-- << std::endl;
	std::cout << "Phan so thu hai luc sau: " << f2 << std::endl;

	CFraction f3 = f1;
	std::cout << "Phan so thu ba (f3 = f1): " << f3 << std::endl;

	// DEMO Compare.cpp
	std::cout << "\nDEMO Min Function\n";

	std::cout << Min(3, 4) << std::endl;
	std::cout << Min(3.14, 5.76) << std::endl;
	std::cout << Min('A', 'C') << std::endl;


	// DEMO CDynamicArray.h/CDynamicArray.cpp
	std::cout << "\nDEMO CDynamicArray Class\n";
	std::cout << "CDynamicArray<int>.\n";
    CDynamicArray<int>* array = new CDynamicArray<int>;
    bool isRunning = true;
    while (isRunning) {
        std::cout << "\n______________________________" << std::endl;
        std::cout << "1. Nhan phim 1 de them phan tu vao cuoi mang." << std::endl;
        std::cout << "2. Nhan phim 2 de lay phan tu tai index i." << std::endl;
        std::cout << "3. Nhan phim 3 de nhap mang." << std::endl;
        std::cout << "4. Nhan phim 4 de xuat mang." << std::endl;
        std::cout << "5. Nhan phim 5 de lay phan tu lon nhat." << std::endl;
		std::cout << "6. Nhan phim 6 de sap xep mang tang dan." << std::endl;
        std::cout << "*Nhan phim bat ki khac de thoat chuong trinh.*" << std::endl;
        std::cout << "______________________________" << std::endl;

        std::cout << "Moi thay nhap chuc nang: ";
        int option;
        std::cin >> option;
        if (std::cin.fail()) {
            clearCin();
            option = -1;
        }
        switch (option) {
        case 1: {
            std::cout << "Moi thay nhap gia tri can them vao cuoi mang: ";
            int value;
            std::cin >> value;
            array->pushBack(value);
            break;
        }
        case 2: {
            std::cout << "Moi thay nhap index can truy xuat: ";
            int index;
            std::cin >> index;
            std::cout << "Ket qua la: " << array->getAt(index) << std::endl;
            break;
        }
        case 3:
            std::cin >> *array;
            break;
        case 4:
            std::cout << *array;
            break;
        case 5:
            std::cout << "Phan tu lon nhat: " << array->MaxElement() << std::endl;
            break;
        case 6:
            array->sort();
            std::cout << "Mang da duoc sap xep tang dan.\n";
			std::cout << *array;   
            break;
        default:
            isRunning = false;
            std::cout << "Ket thuc chuong trinh!!!\n";
            break;
        }
    }
    delete array;

    std::cout << "\nCDynamicArray<CFraction>.\n";
    CDynamicArray<CFraction>* array1 = new CDynamicArray<CFraction>;
    isRunning = true;
    while (isRunning) {
        std::cout << "\n______________________________" << std::endl;
        std::cout << "1. Nhan phim 1 de them phan tu vao cuoi mang." << std::endl;
        std::cout << "2. Nhan phim 2 de lay phan tu tai index i." << std::endl;
        std::cout << "3. Nhan phim 3 de nhap mang." << std::endl;
        std::cout << "4. Nhan phim 4 de xuat mang." << std::endl;
        std::cout << "5. Nhan phim 5 de lay phan tu lon nhat." << std::endl;
        std::cout << "6. Nhan phim 6 de sap xep mang tang dan." << std::endl;
        std::cout << "*Nhan phim bat ki khac de thoat chuong trinh.*" << std::endl;
        std::cout << "______________________________" << std::endl;

        std::cout << "Moi thay nhap chuc nang: ";
        int option;
        std::cin >> option;
        if (std::cin.fail()) {
            clearCin();
            option = -1;
        }
        switch (option) {
        case 1: {
            std::cout << "Moi thay nhap gia tri can them vao cuoi mang: ";
            CFraction value;
            std::cin >> value;
            array1->pushBack(value);
            break;
        }
        case 2: {
            std::cout << "Moi thay nhap index can truy xuat: ";
            int index;
            std::cin >> index;
            std::cout << "Ket qua la: " << array1->getAt(index) << std::endl;
            break;
		}
        case 3:
            std::cin >> *array1;
            break;
        case 4:
            std::cout << *array1;
            break;
        case 5:
            std::cout << "Phan tu lon nhat: " << array1->MaxElement() << std::endl;
            break;
        case 6:
            array1->sort();
            std::cout << "Mang da duoc sap xep tang dan.\n";
            std::cout << *array1;
            break;
        default:
            isRunning = false;
            std::cout << "Ket thuc chuong trinh!!!\n";
            break;
        }
    }
    delete array1;

    return 0;
}

