#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

// deklarisanje strukture
typedef struct Pacijent
{
    char cImePrezime[50];
    int iDan, iMesec, iGodina;
    long long int JMBG; 
    char cAdresa[50];
    char cGrad[20];
    char cLekar[50];
} PACIJENT;


int main()
{
    // deklaracija promenljivih
    char cTrazeniLekar[50];
    FILE *fPacijenti;
    PACIJENT* auPacijenti;
    PACIJENT uPacijenti;
    PACIJENT uTemp;
    int iBrojPacijenata = 0;
    bool bIzmenaRedosleda;

    // unos trazenog lekara 
    printf("Unesite trazenog lekara: ");
    gets(cTrazeniLekar);

    // inicijalizacija pokazivacke promenljive (na fajl koji se otvara)
    fPacijenti = fopen("C:/Pacijenti/Lista.csv", "r");

    if(fPacijenti == NULL)
    {
        printf("Otvaranje neuspesno.");
        return (-1);
    }
    else
    {   
        // dok nisu svi redovi u csv fajlu ocitani, ocitavati ih i smestati u niz struktura auPacijenti...
        while (fscanf(fPacijenti, "%[^','], %d.%d.%d, %lld, %[^','], %[^','], %[^'\n']\n", &uPacijenti.cImePrezime, &uPacijenti.iDan, &uPacijenti.iMesec, &uPacijenti.iGodina, &uPacijenti.JMBG, &uPacijenti.cAdresa, &uPacijenti.cGrad, &uPacijenti.cLekar) != EOF)
        {   
            // ...ukoliko je izabrani lekar pacijenta isti onaj cije je ime korisnik uneo
            if (strcmpi(cTrazeniLekar, uPacijenti.cLekar) == 0)
            {
                // ukoliko je niz struktura prazan, alocirati inicijalnu memoriju
                if (iBrojPacijenata == 0)
                {
                    auPacijenti = malloc(sizeof(PACIJENT));
                }
                // ukoliko nije prazan, prosiriti ga novim clanovima koji ispunjavaju trazeni uslov
                else 
                {
                    auPacijenti = realloc(auPacijenti, sizeof(PACIJENT)*(iBrojPacijenata+1));
                }
                // upis adekvatnog clana u niz i inkrementiranje brojaca clanova
                auPacijenti[iBrojPacijenata] = uPacijenti;
                iBrojPacijenata++;
            }
        }
    }
    
    // zatvaranje fajla
    fclose(fPacijenti);
    fPacijenti = NULL;

    // sortiranje pacijenata prema godini rodjenja
    do{
		bIzmenaRedosleda = false;
		for (int iIndex=0; iIndex < iBrojPacijenata-1; iIndex++)
        {
            // provera da li je godina rodjenja i-tog veca od godine rodjenja i+1-og pacijenta
			if(auPacijenti[iIndex].iGodina > auPacijenti[iIndex+1].iGodina)
            {   
                // ukoliko jeste, zameniti im redosled
				uTemp = auPacijenti[iIndex];
				auPacijenti[iIndex]=auPacijenti[iIndex+1];
				auPacijenti[iIndex+1]=uTemp;
				bIzmenaRedosleda = true;
			}
		}
	
	} while(bIzmenaRedosleda);

    // sortirani prikaz svih prikupljenih clanova niza
	for(int iIndex=0; iIndex < iBrojPacijenata; iIndex++)
    {
		printf("%s, %d.%d.%d, %lld, %s, %s, %s\n", auPacijenti[iIndex].cImePrezime, auPacijenti[iIndex].iDan, auPacijenti[iIndex].iMesec, auPacijenti[iIndex].iGodina, auPacijenti[iIndex].JMBG, auPacijenti[iIndex].cAdresa, auPacijenti[iIndex].cGrad, auPacijenti[iIndex].cLekar);
	}

    return 0; // main()
}
