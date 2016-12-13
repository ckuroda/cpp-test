#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

int main(int argc, char** argv)
{
	// vars
	int  iRowCount=0,
	     iListMax=0,
	     iChangeCount=0,
	     iRowValue=0,
	     iAux=0;
	int  lNumbers[92000];
	
	std::cin >> iRowCount;

	// file scan
	while (iListMax < iRowCount) {

		std::cin >> iRowValue;
			
		lNumbers[iListMax] = iRowValue;
		iListMax++;


	} // while file scan

	// sort
	do { 

		// no change
		iChangeCount = 0;

		for (int i=1;i<iListMax;i++) {

			if (lNumbers[i-1] > lNumbers[i]) {

				// sort
				iAux = lNumbers[i-1];
				lNumbers[i-1] = lNumbers[i];
				lNumbers[i] = iAux;

				// flag change
				iChangeCount++;

			} // if

		} // for

	} while (iChangeCount);

	// set out
	for (int x=0;x<iListMax;x++) {
	
		std::cout << lNumbers[x] << std::endl;	
	}

	return 0;
}
