#include <iostream>
#include "CFile.h"
#include "CFolder.h"
#include "CItem.h"

int main()
{
    CFolder fo1("Folder1");
    fo1.addLeft(CFile("File1", 5));
    fo1.addRight(CFile("File2", 6));
    long n1 = fo1.size();
    std::cout << n1 << std::endl;

    CFolder fo2("Folder 2");
    fo2.addLeft(CFile("File3", 7));
    fo2.addRight(fo1);
    long n2 = fo2.size();
    std::cout << n2 << std::endl;
    return 0;
}

