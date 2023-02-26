/*!
\file main.c
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
#include <unistd.h>
#include "fonctions.h"

/*!
\def SORTIE_AFFICHAGE Sortie du programme pour n'afficher que les options
\def FIN_PROG Fin du programme
*/

#define SORTIE_AFFICHAGE -1
#define FIN_PROG -1

/*!
\fn int main(int argc, char** argv)
\author Alexandre Pauly <alexandre.pauly@cy-tech.fr>
\version 0.1 Premier jet
\date 12 décembre 2022
\brief Fonction principale
\param argc = nombre d'arguments en entrée
\param argv = valeur des arguments en entrée
\return 0 si tout s'est bien passé
*/

int main (int argc, char** argv)
{	
	int i; //Variable de boucle
	int int_fin; //ariable pour sortir d'un while

	//Initialisation de variable
	i = 1;
	int_fin = 0;

	//Recherche de l'option help
	while(argv[i] != NULL || int_fin != 0)
	{
		//Si argv[i] == --help
		if(strcmp(argv[i],"--help") == 0)
		{
			printf("\n  -- MENU des options --\n\n");
			printf("-c <nom_methode> : méthode de chiffrement\n");
			printf("-d <decalage> : valeur du décalage, uniquement pour le chiffrement de César\n");
			printf("-k <cle> : mot clé, uniquement pour le chiffrement de Vigenère\n");
			printf("-m <message> : message à chiffrer\n");
			exit(SORTIE_AFFICHAGE);
		}

		//Si argv[i] est vide, on modifie int_fin pour sortir du while
		if(argv[i] == NULL)
		{
			int_fin = 1;
		}

		//Incrémentation d'une variable de boucle
		i++;
	}

	//Si l'utilisateur n'utilise aucune option
	if(argv[1] == NULL)
	{
		int int_choix; //Variable demandée à l'utilisateur
		
		//Affichage du menu
		printf("\n   -- Menu -- \n\n");
		printf("1 - Code de Cesar\n");
		printf("2 - Code de Vigenère\n");
		printf("3 - Codage de scytale\n");

		//Demande du choix à l'utilisateur
		printf("\nQuel choix souhaitez vous faire ? ");
		int_choix = SaisieEntier();

		//On saute une ligne pour améliorer le visuel
		printf("\n"); 
		
		//Affichage en fonction du choix
		switch (int_choix)
		{ 
			case 1 : Cesar(argc, argv);
					break;
			case 2 : Vigenere(argc, argv);
					break;
			case 3 : Scytale(argc, argv);
					break;
			//Dans le cas par defaut, on ne fait rien
			default :
					break;
		}

		//On saute une ligne pour améliorer le visuel
		printf("\n\n");

		//On quitte le programme
		exit(FIN_PROG);
	}
	//Sinon si l'utilisateur utilise au moins l'option -c
	else
	{	
		//Initialisation de variable
		i = 1;

		//Affichage en fonction de la méthode de chiffrement demandée
		while(argv[i] != NULL)
		{
			//Si c'est celle de Cesar
			if ((strcmp(argv[i],"cesar") == 0) || (strcmp(argv[i],"Cesar") == 0) || (strcmp(argv[i],"CESAR") == 0))
			{
				Cesar(argc, argv);
				break;
			}
			//Sinon si c'estc elle de Vigenere
			else if ((strcmp(argv[i],"vigenere") == 0) || (strcmp(argv[i],"Vigenere") == 0) || (strcmp(argv[i],"VIGENERE") == 0))
			{
				Vigenere(argc, argv);
				break;
			}
			//Sinon si c'est celle de Scytale
			else if ((strcmp(argv[i],"scytale") == 0) || (strcmp(argv[i],"Scytale") == 0) || (strcmp(argv[i],"SCYTALE") == 0))
			{
				Scytale(argc, argv);
				break;
			}

			//Incrémentation d'une variable de boucle
			i++;
		}
	}

	//Si argv[i] est vide, on affiche un menu pour choisir la méthode de chiffrement
	if(argv[i] == 0)
	{
		int int_choix; //Variable demandée à l'utilisateur
		
		//Affichage du menu
		printf("\n   -- Menu -- \n\n");
		printf("1 - Code de Cesar\n");
		printf("2 - Code de Vigenère\n");
		printf("3 - Codage de scytale\n");
		printf("4 - Démineur\n");

		//Demande du choix à l'utilisateur
		printf("\nQuel choix souhaitez vous faire ? ");
		int_choix = SaisieEntier();

		//On saute une ligne pour améliorer le visuel
		printf("\n"); 
		
		//Affichage en fonction du choix
		switch (int_choix)
		{ 
			case 1 : Cesar(argc, argv);
					break;
			case 2 : Vigenere(argc, argv);
					break;
			case 3 : Scytale(argc, argv);
					break;
			//Dans le cas par defaut, on ne fait rien
			default :
					break;
		}
	}

	//On saute une ligne pour améliorer le visuel
	printf("\n\n");

	// Fin du programme, il se termine normalement, et donc retourne 0
	return (0);	
}
