#include <stdio.h>
#include <iostream>
using namespace std;

struct produs
{
	int *cod;
	char *den;
	float pret;
	float cant;
};

void citireVectProd(produs *p, int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Cod=");
		p[i].cod = (int*)malloc(1*sizeof(int));
		scanf("%d", p[i].cod);
		printf("\nDenumire=");
		char buffer[20];
		scanf("%s", buffer);
		p[i].den= (char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(p[i].den, buffer);
		printf("\nPret=");
		scanf("%f", &p[i].pret);
		printf("\nCant=");
		scanf("%f", &p[i].cant);
	}
}

void afisareVectProd(produs *p, int n)
{
	for(int i=0;i<n;i++)
		printf("\nCod=%d, Denumire=%s, Pret=%5.2f, Cantitate=%5.2f",
		*(p[i].cod), p[i].den, p[i].pret, p[i].cant);
}

void dezalocareVectProd(produs *p, int n)
{
	for(int i=0;i<n;i++)
	{
		free(p[i].cod);
		free(p[i].den);
	}
	free(p);
}

void citire4Vectori(int *cod, char **den, float *pret, float *cant, int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Cod=");
		scanf("%d", &cod[i]);
		printf("\nDenumire=");
		char buffer[20];
		scanf("%s", buffer);
		den[i]= (char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(den[i], buffer);
		printf("\nPret=");
		scanf("%f", &pret[i]);
		printf("\nCant=");
		scanf("%f", &cant[i]);
	}
}

void afisare4Vectori(int *cod, char **den, float *pret, float *cant, int n)
{
	for(int i=0;i<n;i++)
		printf("\nCod=%d, Denumire=%s, Pret=%5.2f, Cantitate=%5.2f",
		cod[i], den[i], pret[i], cant[i]);
}

void dezalocare4Vectori(int *cod, char **den, float *pret, float *cant, int n)
{
	free(cod);
	for(int i=0;i<n;i++)
		free(den[i]);
	free(den);
	free(pret);
	free(cant);
}

void main()
{
	int n;
	printf("Nr. produse=");
	scanf("%d", &n);
	/*int *cod = (int*)malloc(n*sizeof(int));
	char** den = (char**)malloc(n*sizeof(char*));
	float* pret = (float*)malloc(n*sizeof(float));
	float *cant = (float*)malloc(n*sizeof(float));
	citire4Vectori(cod, den, pret, cant, n);
	afisare4Vectori(cod, den, pret, cant, n);
	dezalocare4Vectori(cod, den, pret, cant, n);*/

	produs *p = (produs*)malloc(n*sizeof(produs));
	citireVectProd(p, n);
	afisareVectProd(p, n);
	dezalocareVectProd(p, n);
}