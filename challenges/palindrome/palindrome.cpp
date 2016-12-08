#include <iostream>
#include <string>

int isPalindrome (char *s);
char *setMessage (char *s);

int main(int argc, char** argv)
{
	// variaveis
	FILE *fp,
	     *fout;
	char str[80];
	int  nrLinhas,
	     idLinha=0;
	
	if (argc != 3) {
		// argumentos invalidos
		cout << "Argumentos invalidos.";
		return -1;
	} else {
		if ((fp=fopen(argv[1],"r"))==NULL || (fout=fopen(argv[2],"w"))==NULL) {
			// abre arq erro
			cout << "Erro na abertura de arquivos.";
			return -1;
		} else {
			fgets(str,80,fp);
			try {
				nrLinhas = atoi(str);
			} catch (int e) {
				cout << "Erro na linha 1. Exception nr. " << e << '\n';
				return -1;
			}
			// varre arquivo
			while ((!feof(fp)) && (idLinha < nrLinhas)) {
				fgets(str,80,fp);
				if (isPalindrome(str)) {
					fputs(setMessage(str),fout);
				}
				idLinha++;
			}
			return 0;
			fclose(fp);
			fclose(fout);
		}
}

int isPalindrome (char *s) {
	char sAux[80];
	int  nrTamS=0;
	
	nrTamS = strlen(s);
	//sAux recebe inverso de s
	for (i=nrTamS-1;i>=0;i--) {
		strcat(sAux,s[i]);
	}
	return (!strcmp(s,sAux));
}
	
char *setMessage (char *s) {
	char sAux[80];
	
	strcat(sAux,s);
	strcat(sAux," is a palindrome");
	return sAux;
}
