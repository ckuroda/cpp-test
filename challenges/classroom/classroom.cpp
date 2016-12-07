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
	char str[80],
	     str1[40],
             str2[40];
	char *posSpace;
	int  qtQuestion = 0,
	     nrQuestion = 0,
	     nrTamStr = 0,
	     nrTamStr1 = 0,
	     nrTamStr2 = 0,
	     idOk = 1;
	
	if (argc == 2) {
		// parametros ok
		if ((fp=fopen(argv[1],"r")) == NULL) {
			// abre arquivo ok
			fgets(str);
			try {
				qtQuestion = atoi(str);
			} catch (int e) {
				cout << "Erro na linha 1: qtde de questionamentos. Exception nr. " << e << '\n';
				return -1;
			}
			while (!feof(fp) && (nrQuestion < qtQuestion) && idOk) {
				// novo questionamento
				fgets(str);
				posSpace = strchr(str,' ');
				nrTamStr = strlen(str);
				nrTamStr2 = strlen(posSpace) - 1;
				nrTamStr1 = nrTamStr - nrTamStr2 - 1;
				if ((nrTamStr1 > 0) && (nrTamStr2 > 0)) {
					// dois valores ok
					try {
						idQuestion = atoi(nrStr1);
						idQuestionQtde = atoi(nrStr2);
					} catch (int e) {
						cout << "Linha de questionamento invalido. Exception nr. " << e << '\n';
					}
				} else {
					// questionamento invalido
					printf("Questionamento invalido.");
					idOk = 0;
				}
			}
			// valida questionamentos invalidos
			if (idOk) { 
				return 0;
			} else {
				return -1;
			}
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
