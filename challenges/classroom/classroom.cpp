#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <vector>

int main(int argc, char** argv)
{
	// declaracao de variaveis
	FILE *fp;
	char str[80];
	int  qtQuestion = 0,
	     nrQuestion = 0;
	
	if (argc == 2) {
		// parametros ok
		if ((fp=fopen(argv[1],"r")) == NULL) {
			// abre arquivo ok
			fgets(str);
			try {
				qtQuestion = atoi(str);
			} catch (int e) {
			}
			while (!feof(fp) && (nrQuestion < qtQuestion)) {
				// novo questionamento
			}
			return 0;
		} else {
			// falha em abertura de arquivo
			return -1;
		}
	} else {
		// parametros invalidos
		printf("Parametros invalidos.");
		return -1;
	}
}
