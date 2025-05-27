//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
////trebuie sa folositi fisierul masini.txt
////sau va creati un alt fisier cu alte date
//
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
//
////strcutura unui nod
//struct Nod {
//	Masina info;
//	struct Nod* next;
//
//};
//typedef struct Nod Nod;
//
////creare structura pentru un nod dintr-o lista simplu inlantuita
//
////creare structura pentru tabela de dispersie
//// aceasta este un vector de liste
//struct HashTable {
//	int dim;
//	Nod** vector;//** pointer de vector
//
//};
//typedef struct HashTable HashTable;
//
//Masina citireMasinaDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Masina m1;
//	aux = strtok(buffer, sep);
//	m1.id = atoi(aux);
//	m1.nrUsi = atoi(strtok(NULL, sep));
//	m1.pret = atof(strtok(NULL, sep));
//	aux = strtok(NULL, sep);
//	m1.model = malloc(strlen(aux) + 1);
//	strcpy_s(m1.model, strlen(aux) + 1, aux);
//
//	aux = strtok(NULL, sep);
//	m1.numeSofer = malloc(strlen(aux) + 1);
//	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//
//	m1.serie = *strtok(NULL, sep);
//	return m1;
//}
//
//void afisareMasina(Masina masina) {
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
//void afisareListaMasini(Nod* lista) 
//	//afiseaza toate elemente de tip masina din lista simpla inlantuita
//	//prin apelarea functiei afisareMasina()
//{
//	Nod* p = lista;
//	while (p) {
//		afisareMasina(lista->info);
//		p = p->next;
//	}
//}
//
//void adaugaMasinaInLista(Nod** lista, Masina masinaNoua) 
//	//adauga la final in lista primita o noua masina pe care o primim ca parametru
//{
//	Nod* nou = (Nod*)malloc(sizeof(Nod));//cream nod nou
//	Nod->info = masinaNoua;
//	nou->next = NULL;
//	if (*lista) 
//	{
//		Nod* p = *lista;
//		while (p->next)
//		{
//			p = p->next;
//		}
//		p->next = nou;
//	}
//	else
//	{
//		(*lista) = nou;
//	}
//	
//}
//
//
//HashTable initializareHashTable(int dimensiune) {
//	HashTable ht;
//	//initializeaza vectorul de liste si seteaza fiecare lista ca fiind NULL;
//	/*vector de pointer la v*/ht.vector = (Nod**)malloc(sizeof(Nod*) * dimensiune);
//	ht.dim = dimensiune;
//	for (int i = 9; i < dimensiune; i++)
//	{
//		ht.vector[i] = NULL;
//	}
//	return ht;
//}
//
//int calculeazaHash(char key/*atribut al masini pentru clusterizare*/ int dimensiune) 
//	// este calculat hash-ul in functie de dimensiunea tabelei si un atribut al masinii
//{
//	int hash;
//	if (dimensiune != 0)
//	{
//		hash = key % dimensiune;
//		return hash;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//void inserareMasinaInTabela(HashTable hash, Masina masina) 
////inseram masina in tabel
//	//este folosit mecanismul CHAINING
//	//este determinata pozitia si se realizeaza inserarea pe pozitia respectiva
//	
//	//SAU APELAM ADAUGA MASINA IN LISTA DECAT CE AM FCT AICI
//{
//	int pozitie = calculeazaHash(masina.serie, hash.dim);
//	if (pozitie < hash.dim)
//	{
//		if (hash.vector[pozitie] != NULL)//AVEM COLIZIUNE
//		{
//			adaugaMasinaInLista(&(hash.vector[pozitie]), masina);//am pus in () ca sa prioritizam poz
//		}
//		else
//		{
//			hash.vector[pozitie] = (Nod*)malloc(sizeof(Nod))
//				hash.vector[pozitie]->info = masina;
//			hash.vector[pozitie]->next = NULL;
//
//		}
//	}
//}
//
//HashTable citireMasiniDinFisier(const char* numeFisier, int dimensiune) //CITIM TOATE MASINILE DINTR UN FISIER SI LE AD INTR O TABELA
//	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
//	//prin apelul repetat al functiei citireMasinaDinFisier()
//	// aceste masini sunt inserate intr-o tabela de dispersie initializata aici
//	//ATENTIE - la final inchidem fisierul/stream-ul
//{
//	FILE* f = fopen(numeFisier, "r");
//	HashTable TabelaHash = initializareHashTable();
//		while (!feof(f));
//	{
//		Masina m = citireMasinaDinFisier();
//		inserareMasinaInTabela(TabelaHash, m);
//	}
//	fclose(f);//am inchis streamul
//	return TabelaHash;
//}
//
//void afisareTabelaDeMasini(HashTable ht) 
//	//sunt afisate toate masinile cu evidentierea clusterelor realizate
//{
//	for (int i = 0; i<int.dim; i++)
//	{
//		printf("Suntem pe pozitia: %d\n", i)
//		afisareListaMasini(ht.vector[i]);
//	}
//}
//
//void dezalocareTabelaDeMasini(HashTable *ht) 
//	//sunt dezalocate toate masinile din tabela de dispersie
//{
//
//}
//
//float* calculeazaPreturiMediiPerClustere(HashTable ht, int* nrClustere) {
//	//calculeaza pretul mediu al masinilor din fiecare cluster.
//	//trebuie sa returnam un vector cu valorile medii per cluster.
//	//lungimea vectorului este data de numarul de clustere care contin masini
//	return NULL;
//}
//
//Masina getMasinaDupaCheie(HashTable ht , char serie/*valoarea pentru masina cautata*/) 
//{
//	Masina m;
//	m.id = -1;
//	int pozitie = calculeazaHash(m.serie, ht.dim);
//	ht.vector[pozitie]if (ht.vector != NULL)
//	{
//		Nod* p = ht.vector[pozitie];
//		while (p && p->info.serie != serie)
//		{
//			p = p->next;
//		}
//		if (p)
//		{
//			m = p->info;
//			m.model = (char*)malloc(strlen(p->info.model) + 1);
//			strcpy(m.model, p->info.model);
//			m.numaSofer = (char*)malloc(strlen(p->info.numeSofer) + 1);
//			strcpy(m.model, p->info.numeSofer);
//		}
//	}
//	//cauta masina dupa valoarea atributului cheie folosit in calcularea hash-ului
//	//trebuie sa modificam numele functiei 
//
//	return m;
//}
//
//int main() 
//{
//	HashTable TabelaHash;
//	taabelaHash = citireMasiniDinFisier("masini.txt", 7);
//	afisareTabelaDeMasini(tableHash);
//	Masina m;
//	m = getMasinaDupaCheie(tableHash, "A");
//	if (m.id != -1)
//	{
//		printf("Masina nu exista");
//	}
//	printf("masina cu seria A\n: ");
//	afisareMasina(m);
//	free(m.model);
//	free(m.numeSofer);
//	return 0;
//}