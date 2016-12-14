#include <iostream>
#include <string>
using std::string;

int main(int argc, char** argv)
{
	string sCol2="",
	       sFilter="dirty";

	int  iRowCount=0,
             iCol1=0,
	     iDirtySum=0;

	// row 1	
	std::cin >> iRowCount;

	// file scan
	while (iRowCount--) {

		std::cin >> iCol1;
		std::cin >> sCol2;

		if (sCol2 == sFilter) {
			// compute dirty
			iDirtySum += iCol1;
		}

	} // while file scan

	// set out
	if (iDirtySum) {
		std::cout << "There are " << iDirtySum << " dirty bills." << std::endl;
	} else {
		std::cout << "There are no dirty bills." << std::endl;
	}

	return 0;

}
