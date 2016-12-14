#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define OK 0

int isAnagram (string s1, string s2);
int isSimilar (string s1, string s2);

int main(int argc, char** argv)
{
	string sRow1,
               sRow2,
	       sReturn;

	int  nRows = 0;
	
	// Row 1
	std::cin >> nRows;

	// file scan
	while (nRows--) {

		// row scan
		std::cin >> sRow1;
		std::cin >> sRow2;

		sReturn = sRow1;

		// anagram check
		if ( isAnagram(sRow1,sRow2) ) {
			sReturn += " is an anagram of ";
		} else {
			sReturn += " is not an anagram of ";
		}

		//set message
		sReturn += sRow2;

		// set output
		std::cout << sReturn << std::endl;								
		}

	return OK;
}

int isAnagram (string s1, string s2) {
	// vars
	string sTmp1,
               sTmp2;
	int    iResult = 0;

	if (s1.length() == s2.length()) {
		// same words size
		sTmp1 = s1;
		sTmp2 = s2;

		// sort words
		iResult = isSimilar(sTmp1,sTmp2);
		
		// singular word check
		return iResult;
		
	} else {
		// negative anagram
		return 0;
	}

}

int isSimilar (string s1, string s2) {
	// vars
	int nChange = 0;
        size_t nSize = 0;
	char c;

	nSize = s1.length();
	do {
		nChange = 0;
		// word scan
		for (size_t i=0;i<nSize-1;i++) {

			if (s1[i] > s1[i+1]) {
				c = s1[i];
				s1[i] = s1[i+1];
				s1[i+1] = c;
				nChange++;
			}

			if (s2[i] > s2[i+1]) {
				c = s2[i];
				s2[i] = s2[i+1];
				s2[i+1] = c;
				nChange++;
			}
		}
	} while (nChange > 0);

	return (s1 == s2);

}