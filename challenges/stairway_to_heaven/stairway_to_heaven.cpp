#include <iostream>
#include <string>
#include <iomanip>

int main(int argc, char** argv)
{
	// declara variaveis
	FILE *fp,
	     *fout;
	char str[80],
	     sAux[80];
	int  nrIteracoes=0;
	
	if (argc != 3) {
		// argumentos invalidos
		cout << "Argumentos invalidos";
		return -1;
	} else {
		if ((fp=fopen(argv[1],"r"))==NULL || (fout=fopen(argv[2],"w"))==NULL) {
			// abre arq erro
			cout << "Erro na abertura de arquivos.";
			return -1;
		} else {
			fgets(str,80,fp);
			try {
				nrIteracoes = atoi(str);
			} catch (int e) {
				cout << "Erro na linha 1. Exception nr. " << e << '\n';
				return -1;
			}
			if (nrIteracoes < 1) {
				fputs("Erro",fout);
			} else {
				for (i=0;i<nrIteracoes;i++) {
					strcat(sAux,"#");
					fputs(sAux,fout);
				}
			}
			fclose(fp);
			fclose(fout);
			return 0;
		}
	}
}
