#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using std::string;
#include <vector>

#define MAX_FIELDS 5

int main(int argc, char** argv)
{

	string sRow = "",
               sField = "",
	       sNome = "",
               sAge = "",
               sCity = "",
               sState = "",
               sAux = "";

	int  idField,
	     nrLine=0,
             qtLines=0,
             iRowIndex=0;
		
	// lines count
	std::cin >> qtLines;

	// file scan
	while (nrLine < qtLines) {

		// set new line
		idField=0;
		iRowIndex=0;
		sNome = "";
		sState = "";
		sCity = "";
		sAge = "";
		sAux = "";

		// row scan
		while (idField < MAX_FIELDS) {

			std::cin >> sRow;

			if (sAux.length()) {
				// field part recovery
				sField = sAux;
				sField += " ";
				sAux = "";
			} else {
				sField = "";
			}

			// row scan 
			for (iRowIndex=0;iRowIndex<sRow.length();iRowIndex++) {

				if (sRow[iRowIndex] == ',') {

					// word break point
					switch (idField) {
						case 0: // name second part
							sNome = sField;

							// set next field
							sField = "";
							idField++;
							break;
						case 1: // state
							sState = sField;

							// set next field
							sField = "";
							idField++;
							break;
						case 2: // city
							sCity = sField;

							// set next field
							sField = "";
							idField++;
							break;
						case 3: // country - ignore
							// set next field
							sField = "";
							idField++;
							break;
					} // switch


				} else {
			
					if (idField != 3) {
						// word build
						sField += sRow[iRowIndex];

					}
				} // if-else
 

			} // for

			if (idField == 4) {
				// last field age
				sAge = sField;

				// set next field
				idField++;

				// set new line
				nrLine++;
			} else {
				// space break point - backup field part
				sAux = sField;
			}

		} // while row scan

		// set line out
		std::cout << sNome << " is " << sAge << " years old and lives in " << sCity << ", " << sState << "." << std::endl;

	} // while file scan

	return 0;
}