#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
int main(int argc, char** argv)
{
	// declaracao de variaveis
	FILE *fp,
	     *fout;
	char str[255],
	     nextStr[255],
	     fields[100][10][255],
	     sOut[255];
	int  idField,
	     nrTamStr,	     nrTamNextStr,
	     nrLine;
	
	if (argc != 3) {
		// parametros invalidos
		printf("Erro de parametros.");
		return -1;
	} else {
		// parametros ok
		if ((fp=fopen(argv[1],"r"))==NULL || (fout=fopen(argv[2],"w"))==NULL) {
			printf("Erro na abertura de arquivos.");
			return -1;
		} else {
			// abre arquivo ok - le novo registro
			fgets(str,255,fp);
			try {
				qtLines = atoi(str);
			} catch (int e) {
				cout << "Linha 1 invalida. Exception nr. " << e << '\n';
				return -1;
			}
			nrLine=0;
			// le registro a registro
			while (!feof(fp) && (nrLine < qtLines)) {
				fgets(str,255,fp);
				idField=0;
				// grava campos do registro em fields
				do {
					nextStr = strchr(str,',');
					if (nextStr == NULL) {
						fields[nrLine][idField] = str;
					} else {
						nrTamStr = strlen(str);
						nrTamNextStr = strlen(nextStr);
						strncpy(fields[nrLine][idField],str,nrTamStr-nrTamNextStr);
						str=nextStr+1;
						idField++;
					}
				} while (nextStr != NULL);
				nrLine++;
			}		
			// gera saida registro a registro
			for (i=0;i<nrLine;i++) {
				// monta saida
				strcat(sOut,fields[i][0]);
				strcat(sOut," is ");
				strcat(sOut,fields[i][4]);
				strcat(sOut," years old and lives in ");
				strcat(sOut,fields[i][2]);
				strcat(sOut,", ");
				strcat(sOut,fields[i][1]);
				// grava saida
				fputs(sOut,fout);
			}
			fclose(fp);
			fclose(fout);
			return 0;
		}
		
	}
}
