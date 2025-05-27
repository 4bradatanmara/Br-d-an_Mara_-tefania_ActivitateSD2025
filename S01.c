/*#include <stdio.h>

int main() {
	printf("Hello");
	
}*/
/*
#include<stdio.h>
#include<stdlib.h>

struct Masina {
	int id;
	int an;
	char* sofer;//const-nu mai permite modificarea parametrului
	float kilometriiParcursi;
	char initialaProducator;
};

struct Masina initializare(int id, int an, const char* sofer, float kilometriiParcursi, char initialaProducator) {
	struct Masina m;
	m.id = id;
	m.an = an;
	m.sofer = (char*)malloc(strlen(sofer) + 1);//malloc=o functie; calculam dimensiunea 
	strcpy_s(m.sofer, strlen(sofer) + 1, sofer);//strcpy_s copie maximul, pe cand strcpy se duce mai departe cu masurarea
	m.kilometriiParcursi = kilometriiParcursi;
	m.initialaProducator = initialaProducator;

	return m;
}

void afisare(struct Masina m) {
	printf("ID: %d\n", m.id);
	printf("An fabricatie: %d\n", m.an);//%=urmeaza sa afisam ceva int-%d, float %f, char-%s
	printf("Sofer: %s\n", m.sofer);
	printf("Kilometrii parcursi: %f\n", m.kilometriiParcursi);
	printf("Initiala Producatorului: %c\n", m.initialaProducator);
}

void modifica_sofer(struct Masina* m, const char* nouSofer) {
	if (strlen(nouSofer) > 2)
	{
		if (m->sofer != NULL)
		{
			free(m->sofer);//
		}
		m->sofer = (char*)malloc(strlen(nouSofer) + 1);
		strcpy_s(m->sofer, strlen(nouSofer) + 1, nouSofer);
	}
	//modificarea soferului
}

void dezalocare(struct Masina* m) {
	if (m->sofer != NULL)
	{
		free(m->sofer);
		m->sofer = NULL;
	}

	//dezalocare campuri alocate dinamic
}

int main() {
	struct Masina masina;
	masina = initializare(1, 2004, "Mara", 2000, 'M');//"M"ocupa 2 octeti, 'M' ocupa unul
	afisare(masina);
	modifica_sofer(&masina, "Ioana");
	afisare(masina);
	dezalocare()
		return 0;

}
*/