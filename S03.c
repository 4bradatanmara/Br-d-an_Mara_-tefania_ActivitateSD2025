#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//trebuie sa folositi fisierul masini.txt
//sau va creati un alt fisier cu alte date

struct StructuraMasina 
{
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;

//afiseaza toate atributele unei masini
void afisareMasina(Masina masina) 
{
	printf("ID: %d\n", masina.id);
	printf("Nr. usi: %d", masina.nrUsi);
	printf("Pret: %2f", masina.pret);
	printf("Model %s", masina.model);
	printf("Nume soferi: %s", masina.numeSofer);
	printf("Serie: %c", masina.serie);

}

//afiseaza toate elemente de tip masina din vector
//prin apelarea functiei afisareMasina()
void afisareVectorMasini(Masina* masini, int nrMasini)
{
	int i;
	for (i = 0; i < nrMasini; i++) {
		afisareMasina(masini[i]);
	}
}

//adauga in vectorul primit o noua masina pe care o primim ca parametru
//ATENTIE - se modifica numarul de masini din vector;
void adaugaMasinaInVector(Masina** masini, int* nrMasini, Masina masinaNoua) 
{
	Masina* aux;//aux retine o adresa; aux este adresa noii masini
	aux = (Masina*)malloc(sizeof(Masina) * (*nrMasini)+1);//am alocat 
	for (int i = 0; i < (*masini); i++)
	{
		aux[i] = (*masini)[i];//asa prioritizam diferentierea
		//trb un shallow copy-doar pointerii la structura Masina sunt copia?i, dar nu ?i datele din interiorul fiec?rei structuri
	}
	aux[(*nrMasini)] = masinaNoua;//mutam pe ultima pozitie
	free((*masini));//stergem 
	(*masini) = aux;
	(*nrMasini) = (*nrMasini) + 1;
	

}

//functia citeste o masina dintr-un strceam deja deschis-masini.txt
//masina citita este returnata;
Masina citireMasinaFisier(FILE* file) //citire masina fisier-citeste o singura masina, nu e nevoie de while for...
{
	Masina m;
	//fscanf-citeste o valoare dintr un fisier; fgets
	char buffer[100];
	char delim[4] = ",;\n";//"" pentru ca avem \0 si de aia alocam 2; daca adaugam si \n punem 3 s.a.m.d
	fgets(buffer, 100, file);
	char* aux;
	aux =strtok(buffer, delim);

	m.id =atoi(aux);// a TO i
	m.nrUsi = atoi(strtok(NULL, delim));
	m.pret = atof(strtok(NULL, delim));//a TO f- de tip float
	//char*
	aux = strtok(NULL, delim);
	m.model = malloc(strlen(aux) + 1);
	strcpy_s(m.model, strlen(aux) + 1, aux);
	aux = strtok(NULL, delim);
	m.numeSofer = malloc(strlen(aux) + 1);
	strcpy_s(m.numeSofer, strlen(aux) + 1, aux);
	aux = strtok(NULL, delim);
	m.serie = aux[0];

	return m;
}

//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
//prin apelul repetat al functiei citireMasinaFisier()
//numarul de masini este determinat prin numarul de citiri din fisier
//ATENTIE - la final inchidem fisierul/stream-ul
Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitite) 
{
	FILE* f = fopen("masini.txt", "r");//w+ pentru a adauga, r pt citire

	Masina* masini = NULL;

	while (!feof(f))
	{
		Masina m = citireMasinaFisier(f);
		adaugaMasinaInVector(&masini, nrMasiniCitite, m);//& adresa masinii

	}
	fclose(f);
	return masini;
}

//este dezalocat intreg vectorul de masini
void dezalocareVectorMasini(Masina** vector, int* nrMasini) {
	for (int i = 0; i < (*nrMasini); i++)
	{
		free((*vector)[i].model);
		free((*vector)[i].numeSofer);
	}
	free(*vector);
	(*vector) = NULL;
	(*nrMasini) = 0;
}

int main() {
	Masina* masini = NULL;
	int nrMasini = 0;
	masini=citireVectorMasiniFisier("masini.txt", &nrMasini);
	afisareVectorMasini(masini, nrMasini);
	dezalocareVectorMasini(&masini, &nrMasini);

	return 0;
}