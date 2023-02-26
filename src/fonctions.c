 /*!
\file fonctions.c
\author Alexandre Pauly <alexandre.pauly@cy-tech.fr>
\version 0.1 Premier jet
\date 12 décembre 2022
\brief Chiffrements de messages
*/ 

//Inclusion des en-têtes de librairie
#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
 
/*!
\def ERREUR_SAISIE Code d'erreur associé à la saisie
\def ERREUR_allocation Code d'erreur associé à l'allocation
*/

#define ERREUR_SAISIE -1
#define ERREUR_ALLOCATION -1

/*!
\fn int SaisieEntier()
\author Alexandre Pauly <alexandre.pauly@cy-tech.fr>
\version 0.1 Premier jet
\date 12 décembre 2022
\brief Vérification de saisie
\return int_nb si tout s'est bien passé
*/

int SaisieEntier()
{
	int int_nb; //Variable demandée à l'utilisateur
	int int_retour; //Variable de retour
	
	//Lecture de l'entrée
	int_retour = scanf("%d", &int_nb);
	
	//Vérification de l'entrée
	if (int_retour == 0)
	{
		printf("Vous n'avez pas saisi un entier.\n");
		exit(ERREUR_SAISIE);
	}
	
	//Retourne int_nb quand tout s'est bien passé
	return (int_nb);
}

/*!
\fn void VerifAllocation(char* pstr_texte)
\author Alexandre Pauly <alexandre.pauly@cy-tech.fr>
\version 0.1 Premier jet
\date 17 décembre 2022
\brief Vérification de l'allocation de mémoire
\param pstr_texte = Chaîne de caractère
*/

void VerifAllocation(char* tab)
{
	//Si l'allocation a échouée
	if(tab == NULL)
	{
		printf("L'allocation a échouée.\n");
		exit(ERREUR_ALLOCATION);
	}
}