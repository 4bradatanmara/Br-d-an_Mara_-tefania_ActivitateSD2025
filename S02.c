/*#include<stdio.h>
#include<malloc.h>


struct Masina 
{
	int id;
	int anFabricatie;
	char* sofer;
	float kilometriiParcursi;
	char initialaProducator;
};

struct Masina initializare(int id, int anFabricatie, const char* sofer, float kilometriiParcursi, char initialaProducator) 
{
	struct Masina m;
	m.id = id;
	m.anFabricatie = anFabricatie;
	if (sofer != NULL)
	{
		m.sofer = (char*)malloc(strlen(sofer) + 1);
		strcpy_s(m.sofer, strlen(sofer) + 1, sofer);
	}
	else
	{
		m.sofer = NULL;
	}
	m.kilometriiParcursi = kilometriiParcursi;
	m.initialaProducator = initialaProducator;
	return m;
}

void afisare(struct Masina m) 
{
	printf("ID: %d \n", m.id);
	printf("An fabricatie: %d \n", m.anFabricatie);
	printf("Sofer: %s \n", m.sofer);
	printf("Kilometrii Parcursi : %f \n", m.kilometriiParcursi);
	printf("Initiala producator: %c \n", m.initialaProducator);
}


void afisareVector(struct Masina* vector, int nrElemente) 
{
	if (vector != NULL && nrElemente > 0)
	{
		for (int i = 0; i < nrElemente; i++)
		{
			afisare(vector[i]);
			printf("\n");
		}
	}
	
}
//afisarea elementelor din vector apeland functia afisare



struct Masina* copiazaPrimeleNElemente(struct Masina* vector, int nrElemente, int nrElementeCopiate)
{
	
	struct Masina* vectorNou = NULL;
	if (vector != NULL && nrElementeCopiate <= nrElemente && nrElementeCopiate>0);
	{
		vectorNou = malloc(sizeof(struct Masina) * nrElementeCopiate);
		for (int i = 0; i < nrElementeCopiate; i++) {
			vectorNou[i] = initializare (vector[i].id, vector[i].anFabricatie, vector[i].sofer, vector[i].kilometriiParcursi, vector[i].initialaProducator);

		}


	}
	return vectorNou;
}
//copiem intr-un vector nou pe care il vom returna primele nrElementeCopiate



void dezalocare(struct Masina** vector, int* nrElemente) // **vectorul este transmis ca un pointer transmis prin adresa, deci trb sa dereferentiem sau prioritizam dereferentierea
{

	if ((*vector) != NULL && *nrElemente > 0)
	{
		for (int i = 0; i < *nrElemente; i++)
		{
			free ((*vector)[i].sofer);
		}
		free(*vector);
		(*vector) = NULL;
		(*nrElemente) = 0;
	}

}
//dezalocam elementele din vector si vectorul



void copiazaMasiniCuMultiKilometrii(struct Masina* vector, char nrElemente, float prag, struct Masina** vectorNou, int* dimensiune)
{
	if (vector != NULL && nrElemente > 0)
	{
		(*dimensiune) = 0;
		for (int i = 0; i < nrElemente; i++)
		{
			if (vector[i].kilometriiParcursi > prag)
			{
				(*dimensiune++);
			}
		}
		(*vectorNou) = malloc(sizeof(struct Masina) * (*dimensiune));
		int contor = 0;
		for (int i = 0; i < nrElemente; i++)
		{
			if (vector[i].kilometriiParcursi > prag)
			{
				(*vectorNou)[contor] = vector[i]; //vectorNou e pentru contor si vector pt i, unde vectorNou e transmis prin adresa
				(*vectorNou)[contor].sofer = malloc(sizeof(char) * (strlen(vector[i].sofer + 1)));//[contor] operatorul de index face deplasare + dereferentiere; -> face dereferentiere + accesare si noua ne trebuie DEREFERENTIERE(*vector) + DEPLASARE[contor]+ DEREFERENTIERE[contor] + ACCESARE(.)
				strcpy_s((*vectorNou)[contor].sofer, strlen(vector[i].sofer) + 1, vector[i].sofer);
				contor++;
			}
		}
	}

}
	//parametrul prag poate fi modificat in functie de 
	// tipul atributului ales pentru a indeplini o conditie
	//este creat un nou vector cu elementele care indeplinesc acea conditie


struct Masina getPrimaMasinaInFunctiedeSoferi(struct Masina* vector, int nrElemente, const char* soferCautat) 
{
	
	struct Masina m;
	for (int i = 0; i < nrElemente; i++)
	{
		if (strcmp(soferCautat, vector[i].sofer)== 0)// strcmp compara doua stringuri, daca avem AB si AC, din codul ascii a lui A scade A=0, apoi din B -C=-1, at primul sir este mai mic; dar daca avem D in loc de B ne da 1; daca avem rezultate pozitive sirurul e mai mare si daca avem C_C=0; trb sa comparam in asa mod incat sa fie egale
		{
			return vector[i];
		}
	}
	return initializare(-1,0,NULL,0,'-');
}
//trebuie cautat elementul care indeplineste o conditie
//dupa atributul de tip char*. Acesta este returnat.
//in vector avem mai multe masini cu Mara, vrem ca functia sa returneze prima masina condusa de Mara
//parcurgem pana cand gasim ce e necesar si o apelam



int main() 
{
	int nrElemente = 3;
	struct Masina* vector = malloc(sizeof(struct Masina) * nrElemente); //am alocat spatiu pentru acest vector
	vector[0] = initializare(1, 2010, "Mara", 4100, 'W');
	vector[1] = initializare(2, 2015, "Alex", 2101, 'M');
	vector[2] = initializare(3, 2020, "Mara", 6002, 'F');
	afisareVector(vector, nrElemente);

	int nrElementeCopiate = 2;
	struct Masina* vectorNou = copiazaPrimeleElemente(vector, nrElemente, nrElementeCopiate);
	printf("Masini copiate: \n");
	afisareVector(vectorNou, nrElementeCopiate);

	dezalocare(&vectorNou, &nrElementeCopiate);//le oferim adresa prin &

	float prag = 3500;
	copiazaMasiniCuMultiKilometrii(vector, nrElemente, prag,&vectorNou, &nrElementeCopiate);
	printf("Nr masini cu multi kilometrii:");
	afisareVector(vectorNou, nrElementeCopiate);
	dezalocare(&vectorNou, &nrElementeCopiate);

	struct Masina primaMasina = getPrimaMasinaInFunctiedeSoferi(vector, nrElemente, "Mara");
	afisare(primaMasina);

	dezalocare(&vector, &nrElemente);


	return 0;
}*/