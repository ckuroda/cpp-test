#include <iostream>
#include <algorithm>
#include <string>
#include <map>

#include <list>
#include <vector>

int main(int argc, char** argv)
{
	// declaracao de variaveis
	FILE *fp,
	     *fout;
	char str[80],
	     str1[40],
             str2[40],
	     posSpace[40],
             sPeople[100][80],
	     strTmp[80];
	int  qtQuestion = 0,
	     nrQuestion = 0,
	     nrTamStr = 0,
	     nrTamStr1 = 0,
	     nrTamStr2 = 0,
	     idPeople = -1,
	     idOk = 1,
	     nrAlteracao = 0,
	     ind = 0;
	
	if (argc == 2) {
		// parametros ok
		if ((fp=fopen(argv[1],"r")) != NULL && (fout=fopen("saida.txt","w")) != NULL) {
			// abre arquivo ok
			fgets(str,80,fp);
			try {
				qtQuestion = atoi(str);
			} catch (int e) {
				cout << "Erro na linha 1: qtde de questionamentos. Exception nr. " << e << '\n';
				return -1;
			}
			while (!feof(fp) && (nrQuestion < qtQuestion) && idOk) {
				// novo questionamento
				fgets(str,80,fp);
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
					switch (idQuestion) {
						case 1:
							// insert pessoas
							for (i=0;i<idQuestionQtde;i++) {
								fgets(str,80,fp);
								idPeople++;
								strcat(sPeople[idPeople],str);
								;
							}
							// ordenar strings
							do {
								nrAlteracao = 0;
								for (i2=0;i2<idPeople;i2++) {
									// compara duas pessoas
									ind = 0;
									nrTamStr1 = strlen(sPeople[i2]);
									nrTamStr2 = strlen(sPeople[i2+1]);
									while (!nrAlteracao && (ind < nrTamStr1) && (ind < nrTamStr2)) {
										if (sPeople[i2][ind] > sPeople[i2][ind+1]) {
											// ordena
											strTmp = sPeople[i2];
											sPeople[i2] = sPeople[i2+1];
											sPeople[i2+1] = strTmp;
											nrAlteracao++;
										} else {
											// prox caractere
											ind++;
										}
									}
								}
							} while (nrAlteracao);
							break;
						case 2:
							// pesquisa n posicoes
							for (i3=0;i3<idQuestionQtde;i3++) {
								fgets(str,80,fp);
								try {
									ind = atoi(str);
								} catch (int e) {
									cout << "Indice invalido. Exception nr. " << e << '\n';
								}
								// pesquisa em sPeople
								if (ind > (idPeople+1)) {
									printf("Indice nao encontrado.");
								} else {
									// grava pessoa localizada em arq out
									fputs(sPeople[ind],fout);
								}
							}
							break;
						default:
							printf("Tipo de questionamento invalido.");
							idOk = 0;
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
			fclose(fp);
			fclose(fout);
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
