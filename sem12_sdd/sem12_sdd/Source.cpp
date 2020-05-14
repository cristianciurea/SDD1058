#include <stdio.h>
#include <iostream>
using namespace std;

struct nodStiva
{
	int inf;
	nodStiva *next;
};

struct nodCoada
{
	int inf;
	nodCoada *next;
};

void push(nodStiva **varf, int val)
{
	nodStiva* nou = (nodStiva*)malloc(sizeof(nodStiva));
	nou->inf = val;
	nou->next = NULL;
	if(*varf==NULL)
		*varf = nou;
	else
	{
		nou->next = *varf;
		*varf = nou;
	}
}

void pop(nodStiva **varf, int *val)
{
	if(*varf==NULL)
		return;
	else
	{
		*val = (*varf)->inf;
		nodStiva* aux = *varf;
		*varf = (*varf)->next;
		free(aux);
	}
}

void put(nodCoada** prim, nodCoada**ultim, int val)
{
	nodCoada* nou = (nodCoada*)malloc(sizeof(nodCoada));
	nou->inf = val;
	nou->next = NULL;
	if(*prim==NULL && *ultim==NULL)
	{
		*prim = nou;
		*ultim = nou;
	}
	else
	{
		(*ultim)->next = nou;
		*ultim = nou;
	}
}

void get(nodCoada** prim, nodCoada**ultim, int *val)
{
	if(*prim!=NULL && *ultim!=NULL)
	{
		*val = (*prim)->inf;
		nodCoada *aux = *prim;
		*prim = (*prim)->next;
		free(aux);
	}
	if(*prim==NULL)
		*ultim=NULL;
}

void main()
{
	FILE* f = fopen("fisier.txt", "r");
	int nr;
	fscanf(f, "%d", &nr);

	int** mat = (int**)malloc(nr*sizeof(int*));
	for(int i=0;i<nr;i++)
		mat[i] = (int*)malloc(nr*sizeof(int));

	for(int i=0;i<nr;i++)
		for(int j=0;j<nr;j++)
			mat[i][j] = 0;

	int n, ii, jj;
	fscanf(f, "%d", &n);
	for(int i=0;i<n;i++)
	{
		fscanf(f, "%d", &ii);
		fscanf(f, "%d", &jj);
		if(ii<=n && jj<=n)
		{
			mat[ii-1][jj-1] = 1;
			mat[jj-1][ii-1] = 1;
		}
	}
	fclose(f);

	int *vizitat = (int*)malloc(nr*sizeof(int));
	for(int i=0;i<nr;i++)
		vizitat[i] = 0;

	int nod;
	printf("\nParcurgere in adancime de la nodul: ");
	scanf("%d", &nod);

	nodStiva* varf = NULL;

	push(&varf, nod);
	vizitat[nod] = 1;

	while(varf!=NULL)
	{
		pop(&varf, &nod);
		printf("%d-", nod+1);
		for(int k=0;k<nr;k++)
			if(mat[nod][k]==1 && vizitat[k]==0)
			{
				push(&varf, k);
				vizitat[k] = 1;
			}
	}

	for(int i=0;i<nr;i++)
		vizitat[i] = 0;

	printf("\nParcurgere in latime de la nodul: ");
	scanf("%d", &nod);

	nodCoada* prim=NULL, *ultim=NULL;

	put(&prim, &ultim, nod);
	vizitat[nod] = 1;
	while(prim!=NULL)
	{
		get(&prim, &ultim, &nod);
		printf("%d-", nod+1);
		for(int k=0;k<nr;k++)
			if(mat[nod][k]==1 && vizitat[k]==0)
			{
				put(&prim, &ultim, k);
				vizitat[k] = 1;
			}
	}
}