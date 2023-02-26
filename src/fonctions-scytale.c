 /*!
\file fonctions-scytale.c
\author Alexandre Pauly <alexandre.pauly@cy-tech.fr>
\version 0.1 Premier jet
\date 12 décembre 2022
\brief Chiffrements de messages
*/ 

//Inclusion des en-têtes de librairie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "fonctions.h"

/*!
\fn char* codageScytale(char* pstr_texte);
\author Alexandre Pauly <alexandre.pauly@cy-tech.fr>
\version 0.1 Premier jet
\date 20 décembre 2022
\brief Codage par la méthode de Scytale
\param pstr_texte = Message à chiffrer
\return pstr_texte si tout s'est bien passé
*/

char* codageScytale(char* pstr_texte)
{
    int int_tailleMessage; //Taille du message à chiffrer
    int int_tailleGrille; //Taille du tableau de chiffrement
    int i; //Variable de boucle
    int j; //Variable de boucle
    int k; //Variable de boucle

    //Initialisation de variables
    int_tailleMessage = strlen(pstr_texte);
    int_tailleGrille = sqrt(int_tailleMessage);

    char str_crypte[int_tailleGrille][int_tailleGrille]; //Message encrypté

    //On initialise par défaut la grille avec des espaces
    for(i=0 ; i<int_tailleGrille ; i++)
    {
        for(j=0 ; j<int_tailleGrille ; j++)
        {
            str_crypte[i][j] = ' ';
        }
    }

    //Initialisationd de variable de boucle
    k = 0;

    //Remplissage de la grille avec le message
    for(i=0 ; i<int_tailleGrille ; i++)
    {
        for(j=0 ; j<int_tailleGrille ; j++)
        {
            if(k < int_tailleMessage)
            {
                str_crypte[i][j] = pstr_texte[k];    
            }
            k++;
        }
    }

    //Initialisationd de variable de boucle
    k = 0;

    //Lecture de la grille colonne par colonne 
    for(j=0 ; j<int_tailleGrille ; j++)
    {
        for(i=0 ; i<int_tailleGrille ; i++)
        {
            pstr_texte[k] = str_crypte[i][j];
            k++;
        }
    }    

    //Retourne pstr_texte quand tout s'est bien passé
    return(pstr_texte);
}

/*!
\fn void Scytale(int argc, char** argv);
\author Alexandre Pauly <alexandre.pauly@cy-tech.fr>
\version 0.1 Premier jet
\date 20 décembre 2022
\brief Code de Scytale
\param argc = nombre d'arguments en entrée
\param argv = valeur des arguments en entrée
*/

void Scytale(int argc, char** argv)
{
    int int_tailleMessage; //Taille du message à chiffrer
    char* pstr_texte; //Pointeur vers message à coder
    int i; //Variable de boucle
    int j; //Variable de boucle

    //Si l'utilisateur utilise l'option -c
    if (argv[1] != NULL)
    {
        //Initialisation de variables
        i = 1;

        //Affichage en fonction des options saisies
        while(argv[i] != NULL)
        {
            //Si la première option saisie est -c
            if (strcmp(argv[i],"-c") == 0)
            {
                //Initialisation de variables
                j = 1;

                //Affichage en fonction des options saisies
                while (argv[j] != NULL)
                {
                    //Si la seconde option saisie est -m
                    if (strcmp(argv[j],"-m") == 0)
                    {
                        //Initlisation de la taille de la chaîne pour allouer l'espace mémoire
                        int_tailleMessage = strlen(argv[j+1]);

                        //Réservation de l'espace mémoire
                        pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));
                    
                        //Appel de fonction
                        VerifAllocation(pstr_texte);
                        strcpy(pstr_texte, argv[j+1]);

                        break;
                    }

                    //Incrémentation d'une variable de boucle
			        j++;
                }
                
                //Si l'option -m n'est pas saisie
                if (argv[j] == NULL)
                {
                    //Initlisation de la taille de la chaîne à 100 pour allouer l'espace mémoire
                    int_tailleMessage = 100;

                    //Réservation de l'espace mémoire
                    pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));

                    //Appel de fonction
                    VerifAllocation(pstr_texte);

                    //Demande et lecture des paramètres
                    printf("Entrez le message : ");
                    scanf("%[^\n]", pstr_texte);

                    break;
                }
            }
            //Sinon si la première option saisie est -m
            else if (strcmp(argv[i],"-m") == 0)
            {
                //Initlisation de la taille de la chaîne pour allouer l'espace mémoire
                int_tailleMessage = strlen(argv[i+1]);

                //Réservation de l'espace mémoire
                pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));
            
                //Appel de fonction
                VerifAllocation(pstr_texte);
                strcpy(pstr_texte, argv[i+1]);

                break;
            }

            //Incrémentation d'une variable de boucle
			i++;
        }
    }
    //Si l'utilisateur n'utilise pas l'option -c
    else
    {
        //Initlisation de la taille de la chaîne à 100 pour allouer l'espace mémoire
        int_tailleMessage = 100;

        //Réservation de l'espace mémoire
        pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));

        //Appel de fonction
		VerifAllocation(pstr_texte);

        //Demande et lecture des paramètres
        printf("Entrez le message : ");
        scanf("%s", pstr_texte);
    }

    //Affichage du mot après chiffrement
    printf("\nAvant codage : %s", pstr_texte);

    //pstr_texte devient le message chiffré
    pstr_texte = codageScytale(pstr_texte);

    //Affichage du mot après chiffrement
    printf("\nAprès codage : %s", pstr_texte);

    //libération de l'espace mémoire
    free(pstr_texte);
}