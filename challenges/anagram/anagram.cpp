#include <iostream>
#include <algorithm>
#include <string>

int main(int argc, char** argv)
{
	// declaracao de variaveis
	FILE *fp;
	char str[80];
	int  qtLinhas = 0,
	     nrLinhaAtual = 0,
             posSpace = 0,
	     idStatus = 1;
	
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
				if (posSpace == 0) {
					// erro na linha
					printf("Conteudo invalido no arquivo.");
					idStatus = 0;
				} else {
					// trata linha
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
