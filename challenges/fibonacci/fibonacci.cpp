#include <iostream>

int main(int argc, char** argv)
{
	// declara variaveis
	FILE *fp,
	     *fout;
	char str[80];
	int  nr1=0,
	     nr2=1,
	     nrSwap,
	     nrSoma;
	
	if (argc != 3) {
		// argumentos invalidos
		cout << "Argumentos invalidos.";
		return -1;
	} else {
		// qtde arq ok
		if ((fp=fopen(argv[1],"r"))==NULL || (fout=fopen(argv[2],"w"))==NULL) {
			// abre arq erro
			cout << "Erro na abertura de arquivos.";
			return -1;
		} else {
			// abre arq ok
			try {
				fgets(str,80,fp);
			} catch (int e) {
				cout << "Erro no indice fibonacci. Exception nr. " << e << '\n';
				return -1;
			}
			try {
				nrIndice = atoi(str);
			} catch (int e) {
				cout << "Indice invalido. Exception nr. " << e << '\n';
				return -1;
			}
			switch (nrIndice) {
				case 1: nrSoma = 0;
					break;
				case 2: nrSoma = 1;
					break;
				default:
					// calcula fibonacci
					for (i=1;i<nrIndice;i++) {
						nrSoma = nr1+nr2;
						nr1 = nr2;
						nr2 = nrSoma;
					}
			}
			// gera saida
			try {
				itoa(nrSoma,nrTmp,10);
				
				fputs(nrTmp,fout);
			} catch (int e) {
				fputs("Erro no calculo.",fout);
			}
			return 0;
		}
	}
}
