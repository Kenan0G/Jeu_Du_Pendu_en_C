#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"TP_PENDU.h"
#include <time.h>


int main()
{

    char mot[1000] = "test";
    printf("-%s-  test mot 1\n", mot);

    //char *pointeur_sur_mot = &mot[1000];
    //printf("%s", &pointeur_sur_mot[1000]);

    testaleatoire(&mot);

    printf("-%s-  test mot 1\n", mot);
    // printf("%s test fonction\n", testaleatoire());
    // printf("%s", testaleatoire());
    // mot[1000] = testaleatoire();
    // printf("%s test mot", mot[1000]);

    return 0;
}
 



void testaleatoire(char *pointeur_sur_mot)
{
    FILE* fichier = NULL;

    fichier = fopen("dictionnaire_a_mot","r");
    int nombre_ligne = 0;
    char chaine[1000] = "";

    if (fichier != NULL)
    {
        while(fgets(chaine,1000, fichier) != NULL)
        {
            nombre_ligne++;
        }
        rewind(fichier);
        // printf("%d\n", nombre_ligne);
        // printf("%s\n", chaine);
        fclose(fichier);
    }
    else
    {
        printf("erreur sur l'ouverture du fichier\n");
    }

    int MIN = 1;
    int MAX = nombre_ligne;
    int i = 0;
    int ligne_a_tirer = 0;

    srand(time(NULL));
    ligne_a_tirer = (rand() % (MAX - MIN + 1)) + MIN;
    // printf("%d\n", ligne_a_tirer);

    fichier = fopen("dictionnaire_a_mot","r");

    if(fichier != NULL)
    {
        for( i = 0; i<ligne_a_tirer; i++)
        {
            (fgets(chaine,1000,fichier));
    
        }
        // printf("%s\n", chaine);

        fclose(fichier);
        // printf("%s\n", chaine);


    }
    else
    {
        printf("erreur 2 le fichier ne s'ouvre pas\n");
    }
    
    char chaineTest[] = "ABCD";

    //return *chaine;
    //char mot_secret[1000] = "test";
    //chaine[1000] = *pointeur_sur_mot;
    pointeur_sur_mot = &chaineTest;

    // printf("%s", pointeur_sur_mot);
    // printf("%s\n", chaine);
    

}


