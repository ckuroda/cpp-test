#include <iostream>

int main(int argc, char** argv)
{
	//vars
	int iQuestionNr=0,
	    iNum1=0,
	    iNum2=1,
	    iResult=0,
	    iIndex=1;

	// row 1
	std::cin >> iQuestionNr;

	// fibonacci compute
	while (iIndex < iQuestionNr) {

		// sum new value
		iResult = iNum1 + iNum2;

		// move values
		iNum1 = iNum2;
		iNum2 = iResult;	

		// next value
		iIndex++;

	} // while	

	// set out
	std::cout << iResult << std::endl;
}
