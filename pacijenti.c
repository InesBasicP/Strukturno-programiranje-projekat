#include<stdio.h>
#include<stdlib.h>
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

    fPacijenti = fopen("C:/Zadaci/Pacijenti.csv", "a");

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
        scanf("%d.%d.%d.", &iDan, &iMesec, &iGodina);

        printf("Unesite JMBG: "); //UNOS JMBG//
        fflush(stdin);
        scanf("%lld", &JMBG);

        printf("Unesite adresu: "); //UNOS adrese//
        fflush(stdin);
        gets(cAdresa);

        printf("Unesite grad: "); //UNOS grada//
        fflush(stdin);
        gets(cGrad);

        iBrojUpisanih = fprintf(fPacijenti, "%s, %d.%d.%d,%lld, %s, %s\n", cImePrezime, iDan, iMesec, iGodina, JMBG, cAdresa, cGrad);

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