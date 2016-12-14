#include <iostream>
#include <string>

using namespace std;

int isPalindrome (string s);

int main(int argc, char** argv)
{
	string sWord,
	       sMessage;

	int  iRowCount,
	     iActualRow=0;

	// row 1 - row count	
	std::cin >> iRowCount;

	// file scan
	while (iActualRow < iRowCount) {

		std::cin >> sWord;

		if (isPalindrome(sWord)) {
			sMessage = " is palindrome";
		} else {
			sMessage = " is not palindrome";
		}

		// set out
		std::cout << sWord << sMessage << std::endl;

		iActualRow++;

	} // while file scan

	return 0;

}

int isPalindrome (string s) {
	string sAux="";
	
	//sAux recebe inverso de s
	for (size_t i=s.length();i>0;i--) {
		sAux += s[i-1];
	}

	return (s == sAux);

}