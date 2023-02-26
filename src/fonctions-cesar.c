/*!
\file fonctions-cesar.c
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
\fn char* codageCesar(char* pstr_texte, int int_decalage)
\author Alexandre Pauly <alexandre.pauly@cy-tech.fr>
\version 0.1 Premier jet
\date 17 décembre 2022
\brief Codage par la méthode de Cesar
\param pstr_texte = Message à chiffrer
\param int_decalage = Valeur du décalage
\return pstr_texte si tout s'est bien passé
*/

char* codageCesar(char* pstr_texte, int int_decalage)
{
    int i; //Variable de boucle
    int int_tailleTexte; //Taille du texte

    //Initialisationd de variable
    int_tailleTexte = strlen(pstr_texte);

    //Itération du cryptage du message
    for(i=0 ; i<int_tailleTexte; i++)
    {
        //Vérification de conditons par rapport aux majuscules
        if (pstr_texte[i] >= 'A' && pstr_texte[i]<= 'Z') 
        {
            pstr_texte[i] = ((pstr_texte[i] - 'A' + int_decalage) % 26) + 'A';
        }
        //Vérification de conditons par rapport aux minuscules
        else if (pstr_texte[i] >= 'a' && pstr_texte[i]<= 'z') 
        {
            pstr_texte[i] = ((pstr_texte[i] - 'a' + int_decalage) % 26) + 'a';
        }
    }

    //Retourne pstr_texte quand tout s'est bien passé
    return(pstr_texte);
}

/*!
\fn void Cesar(int argc, char** argv)
\author Alexandre Pauly <alexandre.pauly@cy-tech.fr>
\version 0.1 Premier jet
\date 17 décembre 2022
\brief Code de César
\param argc = nombre d'arguments en entrée
\param argv = valeur des arguments en entrée
*/

void Cesar(int argc, char** argv)
{
 	int int_decalage; //Valeur du décalage
    int int_tailleMessage; //Taille du message à chiffrer
    char* pstr_texte; //Message à chiffrer
    int i; //Variable de boucle
    int j; //Variable de boucle
    int k; //Variable de boucle
    int int_break; //Variable pour vérifier si l'on est sorti d'une boucle sur un break

    //Initialisation de variable (prends 1 lorsque l'on a fait un break)
    int_break = 0;
    
    //Si l'utilisateur utilise au moins une option
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
                    //Si la seconde option saisie est -d
                    if (strcmp(argv[j],"-d") == 0)
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
                                int_tailleMessage = strlen(argv[k+1]);

                                //Réservation de l'espace mémoire
                                pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));
                            
                                //Appel de fonction
                                VerifAllocation(pstr_texte);

                                //Initialisation des variables
                                int_decalage = atoi(argv[j+1]);
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
                            //Initlisation de la taille de la chaîne à 100 pour allouer l'espace mémoire
                            int_tailleMessage = 100;

                            //Réservation de l'espace mémoire
                            pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));

                            //Appel de fonction
                            VerifAllocation(pstr_texte);

                            //Initialisation de variable
                            int_decalage = atoi(argv[j+1]);

                            //Demande et lecture des paramètres
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
                            //Si la troisième option saisie est -d
                            if (strcmp(argv[k],"-d") == 0)
                            {
                                //Initlisation de la taille de la chaîne pour allouer l'espace mémoire
                                int_tailleMessage = strlen(argv[j+1]);

                                //Réservation de l'espace mémoire
                                pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));
                            
                                //Appel de fonction
                                VerifAllocation(pstr_texte);

                                //Initialisation des variables
                                int_decalage = atoi(argv[k+1]);
                                strcpy(pstr_texte, argv[j+1]);

                                //On modifie la valeur de int_break
                                int_break = 1;

                                break;
                            }

                            //Incrémentation d'une variable de boucle
                            k++;
                        }

                        //Si l'option -d n'est pas saisie
                        if (argv[k] == NULL && int_break == 0)
                        {
                            //Initlisation de la taille de la chaîne à 100 pour allouer l'espace mémoire
                            int_tailleMessage = 100;

                            //Réservation de l'espace mémoire
                            pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));

                            //Appel de fonction
                            VerifAllocation(pstr_texte);

                            //Initialisation de variable
                            strcpy(pstr_texte, argv[j+1]);

                            //Demande et lecture des paramètres
                            printf("Quel décalage ? ");
                            int_decalage = SaisieEntier();

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

                    //Réservation de l'espace mémoire
                    pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));

                    //Appel de fonction
                    VerifAllocation(pstr_texte);

                    //Demande et lecture des paramètres
                    printf("Entrez le message : ");
                    scanf("%[^\n]", pstr_texte);
                    printf("Quel décalage ? ");
                    int_decalage = SaisieEntier();

                    //On modifie la valeur de int_break
                    int_break = 1;

                    break;
                }
            }
            //Sinon si la première option saisie est -d
            else if (strcmp(argv[i],"-d") == 0)
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
                        int_tailleMessage = strlen(argv[j+1]);

                        //Réservation de l'espace mémoire
                        pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));
                    
                        //Appel de fonction
                        VerifAllocation(pstr_texte);

                        //Initialisation des variables
                        int_decalage = atoi(argv[i+1]);
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
                    //Initlisation de la taille de la chaîne à 100 pour allouer l'espace mémoire
                    int_tailleMessage = 100;

                    //Réservation de l'espace mémoire
                    pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));

                    //Appel de fonction
                    VerifAllocation(pstr_texte);

                    //Initialisation de variable
                    int_decalage = atoi(argv[i+1]);

                    //Demande et lecture des paramètres
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
                    //Si l'utilisateur a saisi l'option -d
                    if (strcmp(argv[j],"-d") == 0)
                    {
                        //Initlisation de la taille de la chaîne pour allouer l'espace mémoire
                        int_tailleMessage = strlen(argv[i+1]);

                        //Réservation de l'espace mémoire
                        pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));
                    
                        //Appel de fonction
                        VerifAllocation(pstr_texte);

                        //Initialisation des variables
                        int_decalage = atoi(argv[j+1]);
                        strcpy(pstr_texte, argv[i+1]);

                        //On modifie la valeur de int_break
                        int_break = 1;

                        break;
                    }

                    //Incrémentation d'une variable de boucle
			        j++;
                }
                
                //Si l'option -d n'est pas saisie
                if (argv[j] == NULL && int_break == 0) 
                {
                    //Initlisation de la taille de la chaîne à 100 pour allouer l'espace mémoire
                    int_tailleMessage = 100;

                    //Réservation de l'espace mémoire
                    pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));

                    //Appel de fonction
                    VerifAllocation(pstr_texte);

                    //Initialisation de variable
                    strcpy(pstr_texte, argv[i+1]);

                    //Demande et lecture des paramètres
                    printf("Quel décalage ? ");
                    int_decalage = SaisieEntier();

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

            //Réservation de l'espace mémoire
            pstr_texte = (char*)malloc(int_tailleMessage*sizeof(char));

            //Appel de fonction
            VerifAllocation(pstr_texte);

            //Demande et lecture des paramètres
            printf("Entrez le message : ");
            scanf("%s", pstr_texte);
            printf("Quel décalage ? ");
            int_decalage = SaisieEntier();
        }
    }
    //Sinon s'il n'utilise pas d'options
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
        printf("Quel décalage ? ");
        int_decalage = SaisieEntier();
    }

    //Affichage du mot avant chiffrement
    printf("\nAvant codage : %s",pstr_texte);

    //pstr_texte devient le message chiffré
    pstr_texte = codageCesar(pstr_texte, int_decalage);

    //Affichage du mot après chiffrement
    printf("\nAprès codage : %s",pstr_texte);

    //libération de l'espace mémoire
	free(pstr_texte);
}
