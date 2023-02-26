/*!
\file fonctions-vigenere.c
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
\fn char* codageVigenere(char* pstr_texte, char* pstr_mot)
\author Alexandre Pauly <alexandre.pauly@cy-tech.fr>
\version 0.1 Premier jet
\date 19 décembre 2022
\brief Codage par la méthode de Vigénère
\param pstr_texte = Message à chiffrer
\param pstr_mot = Mot clé de chiffrement
\return pstr_texte si tout s'est bien passé
*/

char* codageVigenere(char* pstr_texte, char* pstr_mot)
{
    int i; //Variable de boucle
    int j; //Variable de boucle
    int int_tailleMotCle; //Taille du mot clé
    int int_tailleMessage; //Taille du message

    //Initalisation de variables
    int_tailleMessage = strlen(pstr_texte);
    int_tailleMotCle = strlen(pstr_mot);
    j = 0;

    //Itération du cryptage du message
    for(i=0 ; i<int_tailleMessage ; i++)
    {
        //Vérification de conditons par rapport aux majuscules
        if (pstr_texte[i] >= 'A' && pstr_texte[i]<= 'Z') 
        {
            pstr_texte[i] = ((pstr_texte[i] - 'A' + toupper(pstr_mot[j % int_tailleMotCle]) - 'A') % 26) + 'A';
            j++;
        }
        //Vérification de conditons par rapport aux minuscules
        else if (pstr_texte[i] >= 'a' && pstr_texte[i]<= 'z') 
        {
            pstr_texte[i] = ((pstr_texte[i] - 'a' + tolower(pstr_mot[j % int_tailleMotCle]) - 'a') % 26) + 'a';
            j++;
        }
    }

    //Retourne pstr_texte quand tout s'est bien passé
    return(pstr_texte);
}

/*!
\fn void Vigenere(int argc, char** argv)
\author Alexandre Pauly <alexandre.pauly@cy-tech.fr>
\version 0.1 Premier jet
\date 19 décembre 2022
\brief Code de Vigénère
\param argc = nombre d'arguments en entrée
\param argv = valeur des arguments en entrée
*/

void Vigenere(int argc, char** argv)
{
    int int_tailleMessage; //Taille du message à chiffrer
    int int_tailleMotCle; //Taille du mot clé
    char* pstr_mot; //Pointeur vers mot clé
    char* pstr_texte; //Pointeur vers message à coder
    int i; //Variable de boucle
    int j; //Variable de boucle
    int k; //Variable de boucle
    int int_break; //Variable pour vérifier si l'on est sorti d'une boucle sur un break

    //Initialisation de variable (prends 1 lorsque l'on a fait un break)
    int_break = 0;

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
                    //Si la seconde option saisie est -k
                    if (strcmp(argv[j],"-k") == 0)
                    {
                        //Initialisation de variables
                        k = 1;

                        //Affichage en fonction des options saisies
                        while (argv[k] != NULL)
                        {
                            //Si la troisième option saisie est -m
                            if (strcmp(argv[k],"-m") == 0)
                            {
                                //Initlisation de la taille de la chaîne pour allouer l'espace mémoire
                                int_tailleMotCle = strlen(argv[j+1]);
                                int_tailleMessage = strlen(argv[k+1]);

                                //Réservation de l'espace mémoire
                                pstr_mot = (char*)malloc(int_tailleMotCle*sizeof(char));
                                pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));
                            
                                //Appel de fonction
                                VerifAllocation(pstr_mot);
                                VerifAllocation(pstr_texte);

                                //Initialisation des variables
                                strcpy(pstr_mot, argv[j+1]);
                                strcpy(pstr_texte, argv[k+1]);

                                //On modifie la valeur de int_break
                                int_break = 1;

                                break;
                            }

                            //Incrémentation d'une variable de boucle
			                k++;
                        }

                        //Si l'option -m n'est pas saisie
                        if (argv[k] == NULL && int_break == 0)
                        {
                            //Initlisation de la taille de la chaîne pour allouer l'espace mémoire
                            int_tailleMotCle = strlen(argv[j+1]);

                            //Initlisation de la taille de la chaîne à 100 pour allouer l'espace mémoire
                            int_tailleMessage = 100;

                            //Réservation de l'espace mémoire
                            pstr_mot = (char*)malloc(int_tailleMotCle*sizeof(char));
                            pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));
                        
                            //Appel de fonction
                            VerifAllocation(pstr_texte);

                            //Initialisation de variable
                            strcpy(pstr_mot, argv[j+1]);

                            //Demande et lecture de paramètres
                            printf("Entrez le message : ");
                            scanf("%[^\n]", pstr_texte);

                            //On modifie la valeur de int_break
                            int_break = 1;

                            break;
                        }
                    }
                    //Sinon si la seconde option saisie est -m
                    else if (strcmp(argv[j],"-m") == 0)
                    {
                        //Initialisation de variables
                        k = 1;

                        //Affichage en fonction des options saisies
                        while (argv[k] != NULL)
                        {
                            //Si la troisième option saisie est -k
                            if (strcmp(argv[k],"-k") == 0)
                            {
                                //Initlisation de la taille de la chaîne pour allouer l'espace mémoire
                                int_tailleMotCle = strlen(argv[k+1]);
                                int_tailleMessage = strlen(argv[j+1]);

                                //Réservation de l'espace mémoire
                                pstr_mot = (char*)malloc(int_tailleMotCle*sizeof(char));
                                pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));
                            
                                //Appel de fonction
                                VerifAllocation(pstr_mot);
                                VerifAllocation(pstr_texte);

                                //Initialisation des variables
                                strcpy(pstr_mot, argv[k+1]);
                                strcpy(pstr_texte, argv[j+1]);

                                //On modifie la valeur de int_break
                                int_break = 1;

                                break;
                            }

                            //Incrémentation d'une variable de boucle
                            k++;
                        }

                        //Si l'option -k n'est pas saisie
                        if (argv[k] == NULL && int_break == 0)
                        {
                            //Initlisation de la taille de la chaîne pour allouer l'espace mémoire
                            int_tailleMessage= strlen(argv[j+1]);

                            //Initlisation de la taille de la chaîne à 100 pour allouer l'espace mémoire
                            int_tailleMessage = 20;

                            //Réservation de l'espace mémoire
                            pstr_mot = (char*)malloc(int_tailleMotCle*sizeof(char));
                            pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));
                        
                            //Appel de fonction
                            VerifAllocation(pstr_texte);
                            VerifAllocation(pstr_mot);

                            //Initialisation de variable
                            strcpy(pstr_texte, argv[j+1]);

                            //Demande et lecture de paramètres
                            printf("Entrez le mot clé : ");
                            scanf("%s", pstr_mot);

                            //On modifie la valeur de int_break
                            int_break = 1;

                            break;
                        }
                    }
                
                    //Incrémentation d'une variable de boucle
			        j++;
                }

                //Si seulement l'option -c a été utilisée
                if (argv[j] == 0 && int_break == 0)
                {
                    //Initlisation de la taille de la chaîne à 100 pour allouer l'espace mémoire
                    int_tailleMessage = 100;
                    int_tailleMotCle = 20;

                    //Réservation de l'espace mémoire
                    pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));
                    pstr_mot = (char*)malloc(int_tailleMotCle*sizeof(char));

                    //Appel de fonction
                    VerifAllocation(pstr_texte);
                    VerifAllocation(pstr_mot);

                    //Demande et lecture de paramètres
                    printf("Entrez le message : ");
                    scanf("%s", pstr_texte);
                    printf("Entrez le mot clé : ");
                    scanf("%s", pstr_mot);

                    //On modifie la valeur de int_break
                    int_break = 1;

                    break;
                }
            }
            //Sinon si la première option saisie est -k
            else if (strcmp(argv[i],"-k") == 0)
            {
                //Initialisation de variables
                j = 1;

                //Affichage en fonction des options saisies
                while (argv[j] != NULL)
                {
                    //Si l'utilisateur a saisi l'option -m
                    if (strcmp(argv[j],"-m") == 0)
                    {
                        //Initlisation de la taille de la chaîne pour allouer l'espace mémoire
                        int_tailleMotCle = strlen(argv[i+1]);
                        int_tailleMessage = strlen(argv[j+1]);

                        //Réservation de l'espace mémoire
                        pstr_mot = (char*)malloc(int_tailleMotCle*sizeof(char));
                        pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));
                    
                        //Appel de fonction
                        VerifAllocation(pstr_mot);
                        VerifAllocation(pstr_texte);

                        //Initialisation des variables
                        strcpy(pstr_mot, argv[i+1]);
                        strcpy(pstr_texte, argv[j+1]);

                        //On modifie la valeur de int_break
                        int_break = 1;

                        break;
                    }

                    //Incrémentation d'une variable de boucle
			        j++;
                }

                //Si l'option -m n'est pas saisie
                if (argv[j] == NULL && int_break == 0)
                {
                    //Initlisation de la taille de la chaîne pour allouer l'espace mémoire
                    int_tailleMotCle = strlen(argv[i+1]);

                    //Initlisation de la taille de la chaîne à 100 pour allouer l'espace mémoire
                    int_tailleMessage = 100;

                    //Réservation de l'espace mémoire
                    pstr_mot = (char*)malloc(int_tailleMotCle*sizeof(char));
                    pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));
                
                    //Appel de fonction
                    VerifAllocation(pstr_texte);
                    VerifAllocation(pstr_mot);

                    //Initialisation de variable
                    strcpy(pstr_mot, argv[i+1]);

                    //Demande et lecture de paramètres
                    printf("Entrez le message : ");
                    scanf("%s", pstr_texte);

                    //On modifie la valeur de int_break
                    int_break = 1;

                    break;
                }                
            }
            //Sinon si la première option saisie est -m
            else if (strcmp(argv[i],"-m") == 0)
            {
                //Initialisation de variables
                j = 1;

                //Affichage en fonction des options saisies
                while (argv[j] != NULL)
                {
                    //Si l'utilisateur a saisi l'option -k
                    if (strcmp(argv[j],"-k") == 0)
                    {
                        //Initlisation de la taille de la chaîne pour allouer l'espace mémoire
                        int_tailleMotCle = strlen(argv[j+1]);
                        int_tailleMessage = strlen(argv[i+1]);

                        //Réservation de l'espace mémoire
                        pstr_mot = (char*)malloc(int_tailleMotCle*sizeof(char));
                        pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));
                    
                        //Appel de fonction
                        VerifAllocation(pstr_mot);
                        VerifAllocation(pstr_texte);

                        //Initialisation des variables
                        strcpy(pstr_mot, argv[j+1]);
                        strcpy(pstr_texte, argv[i+1]);

                        //On modifie la valeur de int_break
                        int_break = 1;

                        break;
                    }

                    //Incrémentation d'une variable de boucle
			        j++;
                }
                
                //Si l'option -k n'est pas saisie
                if (argv[j] == NULL && int_break == 0) 
                {
                    //Initlisation de la taille de la chaîne pour allouer l'espace mémoire
                    int_tailleMotCle = 20;

                    //Initlisation de la taille de la chaîne à 100 pour allouer l'espace mémoire
                    int_tailleMessage = strlen(argv[i+1]);

                    //Réservation de l'espace mémoire
                    pstr_mot = (char*)malloc(int_tailleMotCle*sizeof(char));
                    pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));
                    
                    //Appel de fonction
                    VerifAllocation(pstr_texte);
                    VerifAllocation(pstr_mot);

                    //Initialisation de variable
                    strcpy(pstr_texte, argv[i+1]);
                    
                    //Demande et lecture de paramètres
                    printf("Entrez le mot clé : ");
                    scanf("%s", pstr_mot);

                    //On modifie la valeur de int_break
                    int_break = 1;

                    break;
                }
            }

            //Incrémentation d'une variable de boucle
			i++;
        }

        if (argv[i] == NULL && int_break == 0)
        {
            //Initlisation de la taille de la chaîne à 100 pour allouer l'espace mémoire
            int_tailleMessage = 100;
            int_tailleMotCle = 20;

            //Réservation de l'espace mémoire
            pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));
            pstr_mot = (char*)malloc(int_tailleMotCle*sizeof(char));

            //Appel de fonction
            VerifAllocation(pstr_texte);
            VerifAllocation(pstr_mot);

            //Demande et lecture de paramètres
            printf("Entrez le message : ");
            scanf("%s", pstr_texte);
            printf("Entrez le mot clé : ");
            scanf("%s", pstr_mot);
        }
    }
    //Sinon s'il n'utilise pas l'option -c
    else
    {
        //Initlisation de la taille de la chaîne à 100 pour allouer l'espace mémoire
        int_tailleMessage = 100;
        int_tailleMotCle = 20;

        //Réservation de l'espace mémoire
        pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));
        pstr_mot = (char*)malloc(int_tailleMotCle*sizeof(char));

        //Appel de fonction
        VerifAllocation(pstr_texte);
        VerifAllocation(pstr_mot);

        //Demande et lecture de paramètres
        printf("Entrez le message : ");
        scanf("%s", pstr_texte);
        printf("Entrez le mot clé : ");
        scanf("%s", pstr_mot);
    }

    //Affichage du mot après chiffrement
    printf("\nAvant codage : %s",pstr_texte);

    ////pstr_texte devient le message chiffré
    pstr_texte = codageVigenere(pstr_texte, pstr_mot);

    //Affichage du mot après chiffrement
    printf("\nAprès codage : %s",pstr_texte);

    //libération de l'espace mémoire
    free(pstr_texte);
    free(pstr_mot);
}