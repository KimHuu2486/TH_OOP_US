#include "CPoint.h"
#include "CLine.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CCircle.h"
#include "CFraction.h"
#include "CStudent.h"

int main() {
	CPoint root;
	std::cout << "Root: " << root << std::endl;

	CPoint node(7, 12);
	std::cout << "Node: " << node << std::endl;

	CPoint* p = new CPoint(12, 198);
	std::cout << "Node: " << *p << std::endl;
	delete p;

	CLine* pLine = new CLine(CPoint(0, 0), CPoint(3, 3));
	std::cout << "\nLine: \n" << "start: " << pLine->start() << "; "
		<< "end: " << pLine->end() << std::endl;
	delete pLine;

	CRectangle* pRectangle = new CRectangle(CPoint(2, 4), CPoint(4, 3));
	std::cout << "\nRectangle: \n" << "top-left: " << pRectangle->topLeft() << "; "
		<< "bottom-right: " << pRectangle->bottomRight() << std::endl;
	delete pRectangle;

	CTriangle* pTriangle = new CTriangle(CPoint(2, 4), CPoint(0, 0), CPoint(4, 2));
	std::cout << "\nTriangle: \n" << "A" << pTriangle->A() << "; "
		<< "B" << pTriangle->B() << "; "
		<< "C" << pTriangle->C() << std::endl;
	delete pTriangle;

	CCircle* pCircle = new CCircle(CPoint(1, 2), 4);
	std::cout << "\nCircle: \n" << "center" << pCircle->center() << "; "
		<< "r = " << pCircle->radius() << std::endl;
	delete pCircle;

	CFraction* pFraction = new CFraction(2, 5);
	std::cout << "\nFraction: \n" << "numerator = " << pFraction->num() << "; "
		<< "denominator = " << pFraction->den() << std::endl;
	delete pFraction;

	CStudent* pStudent = new CStudent("Huu", "Kim", "Tran");
	std::cout << "\nStudent: \n" << *pStudent << std::endl;
	delete pStudent;

	return 0;
}
