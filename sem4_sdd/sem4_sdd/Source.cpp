#include <iostream>
#include <stdio.h>
using namespace std;

//Structura stiva este un caz particular de lista simpla care respecta principiul LIFO (Last In First Out)
//informatie utila nod stiva
struct carte
{
	int cod;
	char *titlu;
	float pret;
	//int nrAutori;
	//char **numeAutori;
};

//definire structura nod stiva (informatie utila de tip carte si pointer de legatura next)
struct nodStiva
{
	carte inf;
	nodStiva *next; //la fel ca la lista simpla
};

//definire structura nod lista simpla pentru conversie stiva-lista
struct nodLista
{
	carte inf;
	nodLista *next;
};

//functie folosita pentru inserarea unui nod in stiva
//adresa de inceput (primul element al stivei) se numeste "varf" (echivalent cu "cap" de la lista)
//varful se trimite cu doua ** din cauza ca metoda returneaza void si este nevoie de returnarea varfului modificat
//inserarea se face inaintea primului element, adica varful se actualizeaza dupa fiecare inserare
void push(nodStiva **varf, carte c)
{
	nodStiva* nou = (nodStiva*)malloc(sizeof(nodStiva));
	nou->inf.cod = c.cod;
	nou->inf.titlu = (char*)malloc((strlen(c.titlu)+1)*sizeof(char));
	strcpy(nou->inf.titlu, c.titlu);
	nou->inf.pret = c.pret;
	nou->next = NULL;
	if (*varf == NULL)
	{
		*varf = nou;
	}
	else
	{
		nou->next = *varf;
		*varf = nou;
	}
}

//functie de extragere a unui nod din stiva
//returneaza int cu valoare 0 daca extragerea se face cu succes si -1 in caz contrar
//varful se actualizeaza la fiecare extragere deoarece se extrage mereu primul element
//se pastreaza in pointerul "val" informatia utila din nodul extras
//extragerea se face cu stergerea nodului din structura
int pop(nodStiva **varf, carte *val)
{
	if (*varf==NULL) return -1;
	else
	{
		(*val).cod = (*varf)->inf.cod;
		(*val).titlu = (char*)malloc((strlen((*varf)->inf.titlu)+1)*sizeof(char));
		strcpy((*val).titlu, (*varf)->inf.titlu);
		(*val).pret = (*varf)->inf.pret;
		nodStiva *temp = *varf;
		*varf = (*varf)->next;
		free(temp->inf.titlu);
		free(temp);
		return 0;
	}
}

//functie de afisare a structurii stiva
void traversare(nodStiva *varf)
{
	nodStiva *temp = varf;
	while(temp)
	{
		printf("\nCod = %d, Titlu = %s, Pret = %5.2f", temp->inf.cod, temp->inf.titlu, temp->inf.pret);
		temp = temp->next;
	}
}

//functie de afisare a structurii lista simpla
void traversareLista(nodLista *cap)
{
	nodLista *temp = cap;
	while(temp)
	{
		printf("\nCod = %d, Titlu = %s, Pret = %5.2f", temp->inf.cod, temp->inf.titlu, temp->inf.pret);
		temp = temp->next;
	}
}

//functie de conversie din stiva de carti in vector de carti
void conversieStivaVector(nodStiva **varf, carte *vect, int *nr)
{
	carte val;
	while(pop(varf, &val)==0) //atat timp cat se extrage cu succes din stiva se insereaza in vector
	{
		vect[*nr] = val;
		(*nr)++;
	}
}

//functie de inserare nod in lista simpla
void inserareLista(nodLista** cap, carte val)
{
	nodLista* nou = (nodLista*)malloc(sizeof(nodLista));
	nou->inf.cod = val.cod;
	nou->inf.titlu = (char*)malloc((strlen(val.titlu)+1)*sizeof(char));
	strcpy(nou->inf.titlu, val.titlu);
	nou->inf.pret = val.pret;
	nou->next = NULL;
	if (*cap==NULL)
		*cap = nou;
	else
	{
		nodLista* temp = *cap;
		while(temp->next) temp = temp->next;
		temp->next = nou;
	}
}

//functie de conversie stiva in lista simpla
void conversieStivaListaSimpla(nodStiva** varf, nodLista**cap)
{
	carte val;
	while(pop(varf, &val)==0)
	{
		inserareLista(cap, val);
	}
}

void main()
{
	nodStiva *varf = NULL;
	int n;
	carte c;
	printf("Nr. carti=");
	scanf("%d", &n);
	char buffer[20];
	for (int i=0;i<n;i++)
	{
		printf("\nCod=");
		scanf("%d", &c.cod);
		printf("\nTitlu=");
		cin.getline(buffer, 20, ';');
		c.titlu = (char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(c.titlu, buffer);
		printf("\nPret=");
		scanf("%f", &c.pret);
		push(&varf, c);
	}
	traversare(varf);

	carte val;
	pop(&varf, &val);
	printf("\nCartea extrasa are codul %d si titlul %s", val.cod, val.titlu);

	printf("\n----------------\n");
	/*carte *vect = (carte*)malloc(n*sizeof(carte));
	int nr = 0;
	conversieStivaVector(&varf, vect, &nr);
	for(int i=0;i<nr;i++)
		printf("\nCod = %d, Titlu = %s, Pret = %5.2f", vect[i].cod, vect[i].titlu, vect[i].pret);
	free(vect);*/

	nodLista* cap = NULL;
	conversieStivaListaSimpla(&varf, &cap);
	traversareLista(cap);
	
}