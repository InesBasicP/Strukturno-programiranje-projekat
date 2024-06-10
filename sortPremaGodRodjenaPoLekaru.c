#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct Ppacijent
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
    char cTrazeniLekar[50];
    FILE *fPacijenti;
    PACIJENT* auPacijenti;
    PACIJENT uPacijenti;
    PACIJENT uTemp;
    int iBrojPacijenata = 0;
    bool bIzmenaRedosleda;

    printf("Unesie trazenog lekara: ");
    gets(cTrazeniLekar);

    fPacijenti = fopen("C:/Pacijenti/Lista.csv", "r");

    if(fPacijenti == NULL)
    {
        printf("Otvaranje neuspesno.");
        return (-1);
    }
    else
    {
        while (fscanf(fPacijenti, "%[^','], %d.%d.%d, %lld, %[^','], %[^','], %[^'\n']\n", &uPacijenti.cImePrezime, &uPacijenti.iDan, &uPacijenti.iMesec, &uPacijenti.iGodina, &uPacijenti.JMBG, &uPacijenti.cAdresa, &uPacijenti.cGrad, &uPacijenti.cLekar) != EOF)
        {
            if (strcmpi(cTrazeniLekar, uPacijenti.cLekar) == 0)
            {
                // printf("%s, %d.%d.%d, %lld, %s, %s, %s\n", cImePrezime, iDan, iMesec, iGodina, JMBG, cAdresa,cGrad, cLekar);

                if (iBrojPacijenata == 0)
                {
                    auPacijenti = malloc(sizeof(PACIJENT));
                }
                else 
                {
                    auPacijenti = realloc(auPacijenti, sizeof(PACIJENT)*(iBrojPacijenata+1));
                }
                auPacijenti[iBrojPacijenata] = uPacijenti;
                iBrojPacijenata++;
            }
        }
    }
    
    fclose(fPacijenti);
    fPacijenti = NULL;

    do{
		bIzmenaRedosleda = false;
		for (int iIndex=0; iIndex<iBrojPacijenata-1; iIndex++)
        {
			if(auPacijenti[iIndex].iGodina > auPacijenti[iIndex+1].iGodina)
            {
				uTemp = auPacijenti[iIndex];
				auPacijenti[iIndex]=auPacijenti[iIndex+1];
				auPacijenti[iIndex+1]=uTemp;
				bIzmenaRedosleda = true;
			}
		}
	
	} while(bIzmenaRedosleda);


	for(int iIndex=0; iIndex < iBrojPacijenata; iIndex++)
    {
		printf("%s, %d.%d.%d, %lld, %s, %s, %s\n", auPacijenti[iIndex].cImePrezime, auPacijenti[iIndex].iDan, auPacijenti[iIndex].iMesec, auPacijenti[iIndex].iGodina, auPacijenti[iIndex].JMBG, auPacijenti[iIndex].cAdresa, auPacijenti[iIndex].cGrad, auPacijenti[iIndex].cLekar);
	}


    return 0;
}
