#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
void autor(void) {
	printf("\n");
	for (int i = 1; i <= 120; i++) printf("*");
	printf("Autor programu: Simon Dudek\n\n");
	for (int i = 1; i <= 120; i++) printf("*");
}
char zapis(char x[33], int y, char z[255]) {
	FILE* plik;
	errno_t err= fopen_s(&plik, z, "w");
	if ( plik != NULL) {
		for (int i = 0; i < y; i++) {
			fprintf(plik, "%s\n", x);
		}
		fclose(plik);
	}
	else
	{
		printf("Plik %s nie został otwarty!\n", z);
	}
		return 0;
}
char wypisz(char x[33], int y) {
	for (int i = 0; i < y; i++) {
		printf("%s\n", x);
	}
	return 0;
}
int main()
{
	char s[33], p[255];
	int r;
	autor();
	setlocale(LC_ALL, "");
	printf("Podaj dowolne słowo (Nie dłuższe niż 32 znaki): ");
	scanf_s("%s", s, 33);
	printf("Ile razy wyświetlić: ");
	scanf_s("%d", &r);
	printf("\nNazwa pliku: ");
	scanf_s("%s", p, 255);
	zapis(s, r, p);
	wypisz(s, r);
	system("pause");
	return 0;
}