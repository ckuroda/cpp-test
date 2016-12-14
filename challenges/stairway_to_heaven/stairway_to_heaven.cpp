#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char** argv)
{
	int  iIterationCount=0;

	string sAux="";
	
	std::cin >> iIterationCount;

	// set file out
	for (int i=0;i<iIterationCount;i++) {

		sAux += "#";

		// set out		
		std::cout << setw(iIterationCount);
		std::cout << sAux << std::endl;

	}

	if (!sAux.size()) {
		std::cout << "Error." << std::endl;
	}

	return 0;

}
