#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    int iTrazenaGodina;
    FILE *fPacijenti;
    char cImePrezime[50];
    int iDan, iMesec, iGodina;
    long long int JMBG; 
    char cAdresa[50];
    char cGrad[20];
    char cLekar[50];

    printf("Unesie trazenu godinu rodjenja: ");
    scanf("%d", &iTrazenaGodina);

    fPacijenti = fopen("C:/Pacijenti/Lista.csv", "r");

    if(fPacijenti == NULL)
    {
        printf("Otvaranje neuspesno.");
        return (-1);
    }
    else
    {
        while (fscanf(fPacijenti, "%[^','], %d.%d.%d, %lld, %[^','], %[^','], %[^'\n']\n", &cImePrezime, &iDan, &iMesec, &iGodina, &JMBG, &cAdresa, &cGrad, &cLekar) != EOF)
        {
            if (iGodina == iTrazenaGodina)
            printf("%s, %d.%d.%d, %lld, %s, %s, %s\n", cImePrezime, iDan, iMesec, iGodina, JMBG, cAdresa,cGrad, cLekar);
        }
    }
    fclose(fPacijenti);
    fPacijenti = NULL;

    return 0;
}
