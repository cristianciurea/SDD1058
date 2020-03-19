#include <stdio.h>
#include <iostream>
using namespace std;

struct student
{
	int varsta;
	char *nume;
	float medie;
};

struct nodLS
{
	student inf;
	nodLS *next;
};

struct nodLP
{
	nodLS *inf;
	nodLP *next;
};

void inserareLS(nodLS **cap, student s)
{
	nodLS *nou = (nodLS*)malloc(sizeof(nodLS));
	nou->inf.varsta = s.varsta;
	nou->inf.nume = (char*)malloc((strlen(s.nume)+1)*sizeof(char));
	strcpy(nou->inf.nume, s.nume);
	nou->inf.medie = s.medie;
	nou->next = NULL;
	if(*cap==NULL)
		*cap = nou;
	else
	{
		nodLS *temp = *cap;
		while (temp->next)
			temp = temp->next;
		temp->next = nou;
	}
}

void inserareLP(nodLP **capLP, nodLS *capLS)
{
	nodLP *nou = (nodLP*)malloc(sizeof(nodLP));
	nou->inf = capLS;
	nou->next = NULL;
	if(*capLP==NULL)
		*capLP = nou;
	else
	{
		nodLP *temp = *capLP;
		while(temp->next)
			temp = temp->next;
		temp->next = nou;
	}
}