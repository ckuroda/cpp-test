#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	// declaracao de variaveis
	FILE *fp,
	     *fout;
	char str[80],
	     sStr2[80],
	     sNewStr[40];
	int  qtLinhas = 0,
	     idLinha,
	     nrTamStr,
	     qtDirtyTotal=0;
	
	if (argc != 3) {
		// argumentos invalidos
		cout << "Argumentos de entrada invalidos.";
		return -1;
	} else {
		// qtde argumentos ok
		if ((fp=fopen(argv[1],"r"))==NULL || (fout=fopen(argv[2],"w"))==NULL) {
			// erro abertura de arq
			cout << "Erro na abertura de arquivos";
			return -1;
		} else {
			// abre arq ok
			fgets(str,80,fp);
			try {
				qtLinhas = atoi(str);
			} catch (int e) {
				cout << "Erro na linha 1.";
				return -1;
			}
			// leitura das notas
			while ((!feof(fp)) && (idLinha < qtLinhas)) {
				fgets(str,80,fp);
				sStr2 = strchr(str,' ');
				if (sStr2 == NULL) {
					// linha invalida
					cout << "Linha invalida. Linha nr. " << idLinha+1 << '\n';
				} else {
					// linha ok
					nrTamStr = strlen(str);
					nrTamStr2 = strlen(sStr2);
					strncpy(sNewStr,str,nrTamStr-nrTamStr2);
					try {
						if (strcmp(sStr2+1,"dirty")) {
							qtDirtyTotal += atoi(sNewStr);
						}
					} catch (int e) {
						cout << "Qtde de bills invalido. Exception nr. " << e << '\n';
					}
				}
				idLinha++;
			}
			// gera saida
			strcat(sOut,"x ");
			itoa(qtDirtyTotal,sTmp,10);
			strcat(sOut,sTmp);
			fputs();
			fclose(fp);
			fclose(fout);
			return 0;
		}
	}
}
