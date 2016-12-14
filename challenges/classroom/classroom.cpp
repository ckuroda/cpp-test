#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#include <map>

#include <list>
#include <vector>

int main(int argc, char** argv)
{
	// vars
	vector<string> sNames;
	string sName1,
               sName2;
	int  iQuestionCount = 0,
	     iQuestionId = 0,
             iActualQuestion = 0,
             iQuestionLoopCount = 0,
	     iQuestionLoopId = 0,
	     iNameId = 0;
	
	// row 1
	std::cin >> iQuestionCount;

	while (iActualQuestion < iQuestionCount) {

		// question ID capture
		std::cin >> iQuestionId;

		// question count capture
		std::cin >> iQuestionLoopCount;		

		switch (iQuestionId) {
			case 1: // insert
				while (iQuestionLoopId < iQuestionLoopCount) {
					std::cin >> sName1;
					std::cin >> sName2;

					sName1 += " ";
					sName1 += sName2;
					
					// rec name
					sNames.push_back(sName1);

					// next name
					iQuestionLoopId++;
				}

				// sort people
				sort(sNames.begin(),sNames.end());

				break;
			case 2: // search
				while (iQuestionLoopId < iQuestionLoopCount) {
					std::cin >> iNameId;
					
					// rec name
					std::cout << sNames[iNameId-1] << std::endl;

					// next name
					iQuestionLoopId++;
				}
				break;
		} // switch
		
		iQuestionLoopId = 0;
		iActualQuestion++;

	} // while
}