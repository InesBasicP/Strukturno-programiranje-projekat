#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
    int iTrazenaGodina;
    FILE *fPacijenti;
    int iBrojPacijenata = 0;
    PACIJENT* auPacijenti;
    PACIJENT uPacijenti;
    PACIJENT uTemp;
    bool bIzmenaRedosleda;

    // unos trazene godine 
    printf("Unesie trazenu godinu rodjenja: ");
    scanf("%d", &iTrazenaGodina);

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
            // ...ukoliko je godina rodjenja pacijenta jednaka trazenoj godini koju je korisnik uneo
            if (uPacijenti.iGodina == iTrazenaGodina)
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

    // sortiranje pacijenata prema datumu rodjenja
   do 
   {
    bIzmenaRedosleda = false;
    for (int iIndex = 0; iIndex < iBrojPacijenata - 1; iIndex++) 
    {
        // provera da li je mesec rodjenja i-tog veci od meseca rodjenja i+1-og pacijenta
        if (auPacijenti[iIndex].iMesec > auPacijenti[iIndex + 1].iMesec) 
        {
            // ukoliko jeste, zameniti im redosled
            uTemp = auPacijenti[iIndex];
            auPacijenti[iIndex] = auPacijenti[iIndex + 1];
            auPacijenti[iIndex + 1] = uTemp;
            bIzmenaRedosleda = true;
        }
        // zatim, provera da li je dan rodjenja i-tog veci od meseca rodjenja i+1-og pacijenta
        else if (auPacijenti[iIndex].iMesec == auPacijenti[iIndex + 1].iMesec && auPacijenti[iIndex].iDan > auPacijenti[iIndex + 1].iDan) 
        {
            // ukoliko jeste, zameniti im redosled
            uTemp = auPacijenti[iIndex];
            auPacijenti[iIndex] = auPacijenti[iIndex + 1];
            auPacijenti[iIndex + 1] = uTemp;
            bIzmenaRedosleda = true;
        }
    }
   } while (bIzmenaRedosleda);

    // sortirani prikaz svih prikupljenih clanova niza
    for(int iIndex=0; iIndex < iBrojPacijenata; iIndex++)
    {
		printf("%s, %d.%d.%d, %lld, %s, %s, %s\n", auPacijenti[iIndex].cImePrezime, auPacijenti[iIndex].iDan, auPacijenti[iIndex].iMesec, auPacijenti[iIndex].iGodina, auPacijenti[iIndex].JMBG, auPacijenti[iIndex].cAdresa, auPacijenti[iIndex].cGrad, auPacijenti[iIndex].cLekar);
	}

    return 0; // main()
}
