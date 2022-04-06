#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"TP_PENDU.h"
#include <time.h>


int main()
{
    char mot_devoile[100] = "";
    char etoile[1] = "*";

    int i = 0;
    int rejouer = 1;

    int bonne_lettre = 0;
    int partie_finie = 0;
    char relancer[1] = "1";
    

    while (relancer[0] != '0')
    {

        rejouer = 0;
        relancer[0] = '0';
        int coups_a_jouer = 10;
        int comparaison =0;
        partie_finie = 0;

        
    // on definit le mot aleatoire :


        int nombre_ligne = 0;
        char mot_secret[100] = "";


        FILE* fichier = NULL;

        fichier = fopen("dictionnaire_a_mot","r");


    // on determine le nombre de lignes

        if (fichier != NULL)
        {

            char c[100] = "";

            while(fgets(c,100, fichier) != NULL)
            {
                nombre_ligne++;
            }


            rewind(fichier);
            fclose(fichier);

        }
        else
        {
            printf("erreur sur l'ouverture du fichier\n");
        }
    
    // on tire au hasard entre 1 et le nombre de ligne:


        int MIN = 1;
        int MAX = nombre_ligne;
        int i = 0;
        int ligne_a_tirer = 0;
        

        srand(time(NULL));
        ligne_a_tirer = (rand() % (MAX - MIN + 1)) + MIN;


    // on recupere le mot à la ligne tirée au hasard:


        fichier = fopen("dictionnaire_a_mot","r");

        if(fichier != NULL)
        {

            for( i = 0; i<ligne_a_tirer; i++)
            {
                (fgets(mot_secret,1000,fichier));
        
            }
            
            char *p;                                                  // si il y a un \n a la fin de la ligne on le remplace par \0

            if ((p = strchr(mot_secret, '\n')) != NULL)
            *p = '\0';


            fclose(fichier);     

        }
        else
        {

            printf("erreur 2 le fichier ne s'ouvre pas\n");
        
        }

        // on affiche les regles :


        printf("Bienvenu dans le jeu du pendu !\n\nVoici les regles :\n1.ecrire seulement des lettres\n2.ecrire des lettres sans accents\nEt c'est tout! bonne partie!\n\n");
        

        // on mesure la longueur du mot secret : 


        int longueur = strlen(mot_secret);

    


        // on fait le mot etoilé


        for(i=0 ; i<longueur ; i++)
        {

            mot_devoile[i] = *etoile;
        
        }
    

        // on commence la boucle pour jouer

        // printf("test avant le while( partie finie == 0)");


        while(partie_finie == 0)
        {


            printf("\nil vous reste %d coups a jouer !\nquel est le mot secret ? : %s \nProposez une lettre : ", coups_a_jouer, mot_devoile);            
            
            char ma_lettre = lireCaractere();

            bonne_lettre = 0;

            for(i=0 ; i<longueur ; i++)
            {

                if(mot_secret[i] ==  ma_lettre)
                {

                    mot_devoile[i] = ma_lettre;
                    bonne_lettre = 1;
                
                }

            }
            if(bonne_lettre == 0)
            {
                
                coups_a_jouer--;
            
            }

            
            // Si le mot est découvert, alors c'est gagné


            int comparaison = strcmp(mot_secret, mot_devoile);

            if (comparaison == 0)
            {

            
                printf("\n\nGAGNE ! le mot etait bien : %s\nVoulez vous relancer une partie ? (oui = 1 ; non = 0) ", mot_secret);


                // relancer ?   


                char vide[1] = "";                          // pour reinitialiser mot_devoilé a "";

                for(i=0 ; i<longueur ; i++)
                {

                    mot_devoile[i] = *vide;

                }


                relancer[0] = lireCaractere();

                if(*relancer == '0')
                {
                    
                    printf("A bientot !\n");
                
                }

                partie_finie = 1;
                
            }

            
            // S'il ne reste plus de coup à jouer, alors c'est perdu


            if (coups_a_jouer <= 0)
            {

                printf("\n\nvous avez perdu\nle mot etait : %s\nVoulez vous relancer une partie ? (oui = 1 ; non = 0) ", mot_secret);


                // rejouer ?


                char vide[1] = "";                          // pour reinitialiser mot_devoilé a "";

                for(i=0 ; i<longueur ; i++)
                {

                    mot_devoile[i] = *vide;

                }

                relancer[0] = lireCaractere();

                if(*relancer == '0')
                {
                    
                    printf("A bientot !\n");
                
                }

                partie_finie = 1;

            }

        }    

    }

    return 0;
}
        





char lireCaractere() 
{ 
    char caractere = 0;

    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà
 
    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer) e
    while (getchar() != '\n') ;
 
    return caractere; // On retourne le premier caractère qu'on a lu 
}

