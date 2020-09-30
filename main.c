#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct achat
{
    char nom_article[20];
    float montant;
    char date[10];
    int mois;

}achat;

struct achat remplir_list(int n)
{

        struct achat Achat;

        printf("\n-----------------------------------------------------------");
        printf("\nAchat n%i", n+1);
        printf("\nNom de Produit: ");
        scanf("%s", Achat.nom_article);
        printf("Prix: ");
        scanf("%f", &Achat.montant);
        printf("Date(JJ/MM/AAAA): ");
        scanf("%s", Achat.date);

    return Achat;
}

int main()
{


    int achA;
    int achB;

    printf("LISTE D'ACHATS ALGER");
    printf("\nENTRER LE NBRE D'ARTICLES ACHETES: ");
    scanf("%i", &achA);
    struct achat ListAchatAlger[achA];


    for(int i=0; i<achA; i++)
    {
        ListAchatAlger[i] = remplir_list(i);
    }



    printf("\nLISTE D'ACHATS BLIDA");

    printf("\nENTRER LE NBRE D'ARTICLES ACHETES: ");
    scanf("%i", &achB);
    struct achat ListAchatBlida[achB];


    for(int i=0; i<achB; i++)
    {
        ListAchatBlida[i] = remplir_list(i);
    }




    FILE * fptr1;
    fptr1 = fopen("FicheAchatAlger.txt", "w");
    for(int i=0; i<achA; i++)
    {
        fprintf(fptr1, "%s %.2f %s\n", ListAchatAlger[i].nom_article, ListAchatAlger[i].montant, ListAchatAlger[i].date);

    }

    fclose(fptr1);



    FILE * fptr2;
    fptr2 = fopen("FicheAchatBlida.txt", "w");
    for(int i=0; i<achB; i++)
    {
        fprintf(fptr2, "%s %.2f %s\n", ListAchatBlida[i].nom_article, ListAchatBlida[i].montant, ListAchatBlida[i].date);

    }

    fclose(fptr2);





    struct achat List_ach[20];

    const int achTOT = achB + achA;

    FILE * fp1;
    FILE * fp2;
    fp1 = fopen("FicheAchatAlger.txt", "r");
    fp2 = fopen("FicheAchatBlida.txt", "r");
    char blank[10];

    int i=0;

    while(!feof(fp2))
    {
        fscanf(fp2, "%s %f %s\n", List_ach[i].nom_article, &List_ach[i].montant, List_ach[i].date );

        strcpy(blank, List_ach[i].date);
        sprintf(blank, "%c%c", blank[3], blank[4]);

        List_ach[i].mois = atoi(blank);
        i++;
    }

    fclose(fp2);


    while(!feof(fp1))
    {
        fscanf(fp1, "%s %f %s\n", List_ach[i].nom_article, &List_ach[i].montant, List_ach[i].date);

        strcpy(blank, List_ach[i].date);
        sprintf(blank, "%c%c", blank[3], blank[4]);

        List_ach[i].mois = atoi(blank);
        i++;
    }

    fclose(fp1);


    float d[12]= {0,0,0,0,0,0,0,0,0,0,0,0};


    for(i=0; i < (achA + achB) ; i++)
    {
        d[ List_ach[i].mois - 1 ] += List_ach[i].montant;

    }



    printf("\n\n\n LES MOIS OU LES DEPENSES DEPASSENT 30000DA: ");

    char list_mois[12][20] = {"JANVIER","FEVRIER", "MARS", "AVRIL", "MAI", "JUIN", "JUILLET", "AOUT", "SEPTEMBRE", "OCTOBRE", "NOVEMBRE", "DECEMBRE"};

    for(i=0; i <12 ; i++)
    {
        if(d[i]>=30000)
        {
            printf("-%s ", list_mois[i]);

        }
    }


    return 0;
}
