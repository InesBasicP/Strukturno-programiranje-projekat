#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{

    char cImePrezime[50];
    int iDan, iMesec, iGodina;
    long long int JMBG; 
    char cAdresa[50];
    char cGrad[20];
    char cLekar[50];
    FILE *fPacijenti;
    int iBrojUpisanih;
    bool bJmbgValidacija(int);

    fPacijenti = fopen("C:/Pacijenti/Lista.csv", "a");

    if(fPacijenti == NULL)
    {
        printf("Otvaranje neuspesno.");
        return (-1);
    }
    else
    {
        printf("Unesite ime i prezime: "); //UNOS IMENA I PREZIMENA//
        fflush(stdin);
        gets(cImePrezime);

        printf("Unesite datum rodjenja u formatu dan.mesec.godina: "); //UNOS DATUMA RODJENJA//
        fflush(stdin);
        scanf("%d.%d.%d", &iDan, &iMesec, &iGodina);

        while (true)
        {
            printf("Unesite JMBG: "); //UNOS JMBG//
            fflush(stdin);
            scanf("%lld", &JMBG);

            if (bJmbgValidacija(JMBG) == true)
            {
                printf("Pacijent sa unesenim JMBG-om vec postoji ili je JMBG unet pogresno. Unesite JMBG ponovo");
            }
            else 
            {
                break;
            }
        }

        printf("Unesite adresu: "); //UNOS adrese//
        fflush(stdin);
        gets(cAdresa);

        printf("Unesite grad: "); //UNOS grada//
        fflush(stdin);
        gets(cGrad);

        printf("Unesite izabranog lekara: "); //UNOS lekara//
        fflush(stdin);
        gets(cLekar);

        iBrojUpisanih = fprintf(fPacijenti, "%s, %d.%d.%d,%lld, %s, %s, %s\n", cImePrezime, iDan, iMesec, iGodina, JMBG, cAdresa, cGrad, cLekar);

        if(iBrojUpisanih < 0)
        {
            printf("Podaci nisu dodati");
            return -1;
        }
        else
        {
            printf("Podaci uspesno dodati.");
        }
    }
    
    fclose(fPacijenti);
    fPacijenti = NULL;

    return 0;
}


bool bJmbgValidacija(int iPrimljeniJmbg)
{
    char cImePrezime[50];
    int iDan, iMesec, iGodina;
    long long int JMBG; 
	FILE* pFajl=NULL;
	int iJmbgUcitan;
	bool bPostoji = false;
    bool iDuzinaJmbg(int);
	
	pFajl = fopen("C:/Pacijenti/Lista.csv" ,"r");
	
	if(pFajl==NULL){
		return (false);
	}
	
	while(fscanf(pFajl, "%[^','], %d.%d.%d, %lld, %*[^\n]", &cImePrezime, &iDan, &iMesec, &iGodina, &iJmbgUcitan)  != EOF  )
    {
        // int iBrojCifara;

        // iBrojCifara = iDuzinaJmbg(iPrimljeniJmbg);

		if(iPrimljeniJmbg==iJmbgUcitan){
			bPostoji=true;
			break;
		}
	}
	
	fclose(pFajl);
	pFajl = NULL;
	
	return(bPostoji);
}



// bool iDuzinaJmbg(int iPrimljeniJmbg)
// {
//     int iBrojac = 0;
//     bool okJmbg = true;

//     do {
//     iPrimljeniJmbg /= 10;
//     iBrojac++;
//     } while (iPrimljeniJmbg != 0);

//     if (iBrojac != 13) 
//     {
//         okJmbg = false;
//     }

//     return okJmbg;
// }