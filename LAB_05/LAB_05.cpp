#include "CPoint.h"
#include "CLine.h"
#include "CRectangle.h"
#include "CDynamicArray.h"
#include "Tokenizer.h"
#include "CCircle.h"
#include "CFraction.h"
#include "CTriangle.h"
#include "CDate.h"


int CPoint::InstanceCount = 0;
int CLine::InstanceCountLine = 0;
int CRectangle::InstanceCountRectangle = 0;
int CCircle::InstanceCountCircle = 0;

int main()
{

    //std::string line = "41, 817, 12, 9371, 154";
    //std::string seperator = ", ";
    //std::vector<std::string> tokens = Tokenizer::Parse(line, seperator);

    //std::vector<int>numbers;
    //
    //for (auto i = 0; i < tokens.size(); i++) {
    //    auto num = stoi(tokens[i]);
    //    numbers.push_back(num);
    //}

    //for (auto i = 0; i < numbers.size(); i++) {
    //    std::cout << numbers[i] << " ";
    //}


    // DEMO CPoint.h
    CPoint* point = CPoint::Parse("(1, 2)");
    std::cout << *point << std::endl;
    delete point;


    // DEMO CLine.h
    CLine* line = CLine::Parse("(3, 4), (5, 9)");
    std::cout << *line << std::endl;
    delete line;

    // DEMO CRectangle.h
    CRectangle* rec = CRectangle::Parse("(6, 15), (1, 20)");
    std::cout << *rec << std::endl;
    delete rec;


    //DEMO CTriangle.h
    CTriangle* tri = CTriangle::Parse("(6, 15), (1, 20), (61, 92)");
    std::cout << *tri << std::endl;
    delete tri;

    // DEMO CCircle.h
    CCircle* cir = CCircle::Parse("(4, 3), 1.8");
    std::cout << *cir << std::endl;
    delete cir;

    // DEMO CFraction.h
    CFraction* frac = CFraction::Parse("6/12");
    std::cout << *frac << std::endl;
    delete frac;


    // DEMO CDynamicArray.h
    CDynamicArray* array = CDynamicArray::Parse("5, 8, 12, 15, 612, 19");
    std::cout << *array << std::endl;
    delete array;

    // DEMO CDate.h
    CDate* date = CDate::Parse("14/11/2025");
    std::cout << *date << std::endl;
    delete date;

    return 0;
}

