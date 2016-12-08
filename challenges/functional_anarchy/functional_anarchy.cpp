#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

int main(int argc, char** argv)
{
	// declara variaveis
	FILE *fp,
	     *fout;
	char str[80];
	int  nrLinhas=0,
	     idLinha=0,
	     idVetor=0,
	     nrAlterado=1,
	     nrTmp;
	int  vNumeros[80];
	
	if (argc != 3) {
		// argumentos invalidos
		cout << "Argumentos invalidos.";
		return -1;
	} else {
		// qtde de argumentos ok
		if ((fp=fopen(argv[1],"r"))==NULL || (fout=fopen(argv[2],"w"))==NULL) {
			// abre arq erro
			cout << "Erro na abertura de arquivos";
			return -1;
		} else {
			// abre arq ok
			fgets(str,80,fp);		
			try {
				nrLinhas = atoi(str);
			} catch (int e) {
				cout << "Qtde de linhas invalido." << e << '\n';
				return -1
			}
			// leitura de valores
			while ((!feof(fp)) && (idLinha < nrLinhas)) {
				fgets(str,80,fp);
				try {
					nrTmp = atoi(str);
					
					vNumeros[idVetor] = nrTmp;
					idVetor++;
				} catch (int e) {
					cout << "Valor invalido. Exception nr. " << e << '\n';
				}
				idLinha++;
			}
			// ordena
			while (nrAlterado) {
				nrAlterado = 0;
				for (i=0;i<idVetor;i++) {
					if (vNumeros[i] > vNumeros[i+1]) {
						// ordenar
						nrAlterado = 1
						nrTmp = vNumeros[i];
						vNumeros[i] = vNumeros[i+1];
						vNumeros[i+1] = nrTmp;
					}
				}
			}
			// grava saida
			for (i2=0;i2<=idVetor;i2++) {
				try {
					itoa(vNumeros[i2],str,10);
					
					fputs(str,fout);
				} catch (int e) {
					cout << "Valor invalido." << e << '\n';
				}
			}
			return 0;
		}
	}
}
