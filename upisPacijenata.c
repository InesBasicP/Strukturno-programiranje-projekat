#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool bJmbgValidacija(long long int iPrimljeniJmbg);
bool iDuzinaJmbg(long long int iPrimljeniJmbg);

int main()
{
    // deklarisanje promenljivih
    char cImePrezime[50];
    int iDan, iMesec, iGodina;
    long long int JMBG; 
    char cAdresa[50];
    char cGrad[20];
    char cLekar[50];
    FILE *fPacijenti;
    int iBrojUpisanih;
    // bool bJmbgValidacija(int);

    // inicijalizacija pokazivacke promenljive (na fajl koji se otvara)
    fPacijenti = fopen("C:/Pacijenti/Lista.csv", "a");

    if(fPacijenti == NULL)
    {
        printf("Otvaranje neuspesno.");
        return (-1);
    }
    else
    {
        // UNOS IMENA I PREZIMENA
        printf("Unesite ime i prezime: ");
        fflush(stdin);
        gets(cImePrezime);

        // UNOS DATUMA RODJENJA
        printf("Unesite datum rodjenja u formatu dan.mesec.godina: "); 
        fflush(stdin);
        scanf("%d.%d.%d", &iDan, &iMesec, &iGodina);

        // UNOS JMBG
        while (true)
        {
            printf("Unesite JMBG: "); 
            fflush(stdin);
            scanf("%lld", &JMBG);
            
            // izvrsavanje validacije unetog jmbg-a
            // ukoliko je utvrdjeno da uneti jmbg vec postoji, ispisati dati tekst u konzolu, nakon cega se korisniku ponovo omogucava unos jmbg-a
            if (bJmbgValidacija(JMBG) == true)
            {
                printf("Pacijent sa unesenim JMBG-om vec postoji ili je JMBG unet pogresno. Unesite JMBG ponovo");
            }
            // ukoliko ne postoji, zavrsiti petlju i nastaviti dalje sa izvrsavanjem main-a
            else 
            {
                break;
            }
        }

        // UNOS adrese
        printf("Unesite adresu: ");
        fflush(stdin);
        gets(cAdresa);

        // UNOS grada
        printf("Unesite grad: ");
        fflush(stdin);
        gets(cGrad);

        // UNOS lekara
        printf("Unesite izabranog lekara: ");
        fflush(stdin);
        gets(cLekar);

        // vracanje broja uspesno upisanih podataka o pacijentu u listu
        iBrojUpisanih = fprintf(fPacijenti, "%s, %d.%d.%d,%lld, %s, %s, %s\n", cImePrezime, iDan, iMesec, iGodina, JMBG, cAdresa, cGrad, cLekar);

        // ukoliko podaci nisu upisani, broj uspesno upisanih podataka je manji od 0 sto znaci da podaci nisu ni dodati
        if (iBrojUpisanih < 0)
        {
            printf("Podaci nisu dodati");
            return -1;
        }
        // ukoliko su podaci upisani, ispisati odgovarajuci tekst u konzolu
        else
        {
            printf("Podaci uspesno dodati.");
        }
    }
    
    // zatvaranje fajla
    fclose(fPacijenti);
    fPacijenti = NULL;

    return 0;
}

// funkcija za validaciju unetog jmbg-a
bool bJmbgValidacija(long long int iPrimljeniJmbg)
{   
    char cImePrezime[50];
    int iDan, iMesec, iGodina;
    long long int JMBG; 
	FILE* pFajl=NULL;
	int iJmbgUcitan;
	bool bPostoji = false;
    // bool iDuzinaJmbg(int);
	
    // otvaranje postojeceg fajla sa pacijentima
	pFajl = fopen("C:/Pacijenti/Lista.csv" , "r");
	
	if (pFajl==NULL)
    {
		return (false);
	}
	
    // dok nisu svi redovi u csv fajlu ocitani, ocitavati ih i proveravati da li je uneti jmbg za datog pacijenta jednak nekom
    // od vec postojecih pacijenata
	while(fscanf(pFajl, "%[^','], %d.%d.%d, %lld, %*[^\n]", &cImePrezime, &iDan, &iMesec, &iGodina, &iJmbgUcitan)  != EOF  )
    {

        // ukoliko jeste, promeniti boolean varijablu sa pretpostavljenom false vrednoscu, na true
		if(iPrimljeniJmbg == iJmbgUcitan)
        {
			bPostoji=true;
			break;
		}
	}
	
    // zatvaranje fajla
	fclose(pFajl);
	pFajl = NULL;
	
    // vracanje boolean vrednosti
	return (bPostoji);
}