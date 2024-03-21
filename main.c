#include <stdio.h>

void Cotisation(char *nom, int montant, char *date)
{
    FILE *fichier;
    fichier = fopen("cotisation.txt", "a");

    fprintf(fichier, "%s a cotise %d le %s\n", nom, montant, date);

    fclose(fichier);
}

void Afficher()
{
    FILE *fichier;
    fichier = fopen("cotisation.txt", "r");

    if(fichier == NULL)
    {
        printf("Erreur : fichier inexistant \n");
        return;
    }

    char caractere;

    while((caractere = fgetc(fichier)) != EOF)
        printf("%c",caractere);

    fclose(fichier);
}

int main(void)
{
    int choix;

    printf("Veuillez choisir une option \n");
    printf("\t1. Enregistrer une cotisation \n");
    printf("\t2. Afficher l'historique des cotisations\n");
    printf("choix : ");
    scanf("%d",&choix);

    switch(choix)
    {
        case 1 : 
            char nom[50], date[11];
            int montant;

            printf("Entrez le nom de la personne qui cotise : ");
            scanf("%s",nom);
            printf("Entrez le montant a cotiser : ");
            scanf("%d",&montant);
            printf("Entrez la date du jour (sous le format jj/mm/aaaa) : ");
            scanf("%s",date);

            Cotisation(nom, montant, date);
            
            break;

        case 2 : 
            Afficher();
            break;

        default : 
            printf("Mauvaise valeur \n");
            break;
    }
}