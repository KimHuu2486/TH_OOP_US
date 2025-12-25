#include <iostream>
#include "CNode.h"
#include "CNumber.h"
#include "COperator.h"
#include <string>

int main()
{
    COperator op1("+");        
    op1.addLeft(CNumber(5));   
    op1.addRight(CNumber(3));  


    COperator op2("*");   
    op2.addLeft(op1);         
    op2.addRight(CNumber(2));  

    std::cout << op2.calculate();   
    return 0;
}

