#include <iostream>
#include <algorithm>
#include <string>

#define OK 0
#define MAX_WORD 80

char *rowScan (char *s1, char *s2);
void strSort (char *s1, char *s2, int nSize);
void setMsg (char *s1, char *s2, int isNotAnagram);
void x_strcat (char *dest, char *orig, int size);

int main(int argc, char** argv)
{
	char sRow1[MAX_WORD],
             sRow2[MAX_WORD],
             *sReturn;
	int  nRows = 0,
	     nActualRow = 0;
	
	// open file ok
	std::cin >> sRow1;
	// row 1
	try {
		nRows = atoi(sRow1);
	} catch (int e) {
		// Erro na leitura do nro de linhas
		return e;
	}

	// file scan
	while ((nActualRow < nRows)) {
		// row scan
		std::cin >> sRow1;
		std::cin >> sRow2;
		nActualRow++;

		// row rules
		sReturn = rowScan(sRow1,sRow2);

		// set output
		std::cout << sReturn << std::endl;								
		}

	return OK;
}

char *rowScan (char *s1, char *s2) {
	// vars
	int  idCmp;
	char sTmp1[MAX_WORD]="",
             sTmp2[MAX_WORD]="";

	if (strlen(s1) == strlen(s2)) {
		// same words size
		x_strcat(sTmp1,s1,MAX_WORD);
		x_strcat(sTmp2,s2,MAX_WORD);

		// sort words
		strSort(sTmp1,sTmp2,(int) strlen(sTmp1));
		
		// singular word check
		idCmp = strcmp(sTmp1,sTmp2);
		
	} else {
		// negative anagram
		idCmp = 1;
	}

	setMsg(s1,s2,idCmp);
	return s1;
}

void strSort (char *s1, char *s2, int nSize) {
	// vars
	int nChange = 0;
	char c;

	do {
		nChange = 0;
		// word1 and word2 scan
		for (int i=0;i<nSize-1;i++) {

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

}

void setMsg (char *s1, char *s2, int isNotAnagram) {
	char sNotAnagram[MAX_WORD]=" is not an anagram of ",
             sAnagram[MAX_WORD]=" is an anagram of ";

	if (isNotAnagram) {
		x_strcat(s1,sNotAnagram,MAX_WORD);
	} else {
		x_strcat(s1,sAnagram,MAX_WORD);
	}

	x_strcat(s1,s2,MAX_WORD);

}

void x_strcat (char *dest, char *orig, int size) {
	int iDestIndex=0,
            iOrigIndex=0;

	while ((iDestIndex < size) && (dest[iDestIndex] != NULL)) {
		iDestIndex++;
	}

	while ((iDestIndex < size) && (orig[iOrigIndex] != NULL)) {
		dest[iDestIndex] = orig[iOrigIndex];
		iDestIndex++;
		iOrigIndex++;
	}

	dest[iDestIndex] = NULL;

}