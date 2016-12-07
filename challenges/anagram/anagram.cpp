#include <iostream>
#include <algorithm>
#include <string>

int main(int argc, char** argv)
{
	// declaracao de variaveis
	FILE *fp;
	char str[80],
	     str1[40],
	     str2[40],
	     c;
	char *posSpace;
	int  qtLinhas = 0,
	     nrLinhaAtual = 0,
	     idStatus = 1,
             nrTamStr,
	     nrTamStr1,
	     nrTamStr2,
	     nrAlteracao = 0;
	
	// valida parametros main
	if (argc == 2) {
		// trata arquivo
		if ((fp=fopen(argv[1],"r")) == NULL) {
			// problemas no arquivo
			printf("Erro na abertura do arquivo.");
		} else {
			// arquivo aberto ok - leitura de linha
			fgets(str);
			// leitura do nro de linhas
			try {
				qtLinhas = atoi(str);
			} catch (int e) {
				cout << "Erro na leitura do nro de linhas. Exception Nr. " << e << '\n';
				return e;
			}
			// leitura do arquivo
			while (!feof(fp) and (nrLinhaAtual < qtLinhas) and idStatus) {
				// leitura de linha
				fgets(str);
				nrLinhaAtual++;
				// localiza divisao de palavras
				posSpace = strchr(str,' ');
				if (posSpace == NULL) {
					// erro na linha
					printf("Conteudo invalido no arquivo.");
					idStatus = 0;
				} else {
					// trata linha
					nrTamStr = strlen(str);
					nrTamStr2 = strlen(posSpace) - 1;
					nrTamStr1 = nrTamStr - nrTamStr2 - 1;
					strncpy(str1,str,nrTamStr1);
					if (nrTamStr2 > 0) {
						// duas palavras na linha
						strncpy(str1,str,nrTamStr1);
						strncpy(str2,posSpace+1,nrTamStr2);
						if (nrTamStr1 == nrTamStr2) {
							// possivel anagrama
							do {
								for (i=0;i<nrTamStr1-1;i++) {
									if (str1[i] > str1[i+1]) {
										c = str1[i];
										str1[i] = str1[i+1];
										str1[i+1] = c;
										nrAlteracao++;
									}
									if (str2[i] > str2[i+1]) {
										c = str2[i];
										str2[i] = str2[i+1];
										str2[i+1] = c;
										nrAlteracao++;
									}
								}
							} while (nrAlteracao > 0);
							if (strcmp(str1,str2) == 0) {
								// anagrama ok
								printf("%s is an anagram of %s",str1,str2);
							} else {
								// nao eh anagrama
								printf("%s is an anagram of $s",str1,str2);
							}
								
						} else {
							// nao eh anagrama
							printf("%s is not an anagram of %s",str1,str2);
						}
					} else {
						// nao ha duas palavras na linha
						printf("Conteudo invalido no arquivo");
						idStatus = 0;
					}
				}
			}
			// fecha arquivo
			fclose(fp);
			return 0;
		}
	} else {
		// erro de parametro main
		printf("Favor digitar o nome do arquivo de entrada.");
		return -1;
	}
}
