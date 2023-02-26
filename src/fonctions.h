/*!
\file fonctions.h
\author Alexandre Pauly <alexandre.pauly@cy-tech.fr>
\version 0.1 Premier jet
\date 12 décembre 2022
\brief TP8 - Chaînes de caractères
*/

#ifndef __TP8_H_
#define __TP8_H_

/*!
\fn int SaisieEntier()
\author Alexandre Pauly <alexandre.pauly@cy-tech.fr>
\version 0.1 Premier jet
\date 12 décembre 2022
\brief Vérification de saisie
\return int_nb si tout s'est bien passé
*/

int SaisieEntier(void);

/*!
\fn void VerifAllocation(char* pstr_texte)
\author Alexandre Pauly <alexandre.pauly@cy-tech.fr>
\version 0.1 Premier jet
\date 17 décembre 2022
\brief Vérification de l'allocation de mémoire
\param pstr_texte = Chaîne de caractère
*/

void VerifAllocation(char* pstr_texte);

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

char* codageCesar(char* pstr_texte, int int_decalage);

/*!
\fn void Cesar(int argc, char** argv)
\author Alexandre Pauly <alexandre.pauly@cy-tech.fr>
\version 0.1 Premier jet
\date 17 décembre 2022
\brief Code de César
\param argc = nombre d'arguments en entrée
\param argv = valeur des arguments en entrée
*/

void Cesar(int argc, char** argv);

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

char* codageVigenere(char* pstr_texte, char* pstr_mot);

/*!
\fn void Vigenere(int argc, char** argv)
\author Alexandre Pauly <alexandre.pauly@cy-tech.fr>
\version 0.1 Premier jet
\date 19 décembre 2022
\brief Code de Vigénère
\param argc = nombre d'arguments en entrée
\param argv = valeur des arguments en entrée
*/

void Vigenere(int argc, char** argv);

/*!
\fn char* codageScytale(char* pstr_texte);
\author Alexandre Pauly <alexandre.pauly@cy-tech.fr>
\version 0.1 Premier jet
\date 20 décembre 2022
\brief Codage par la méthode de Scytale
\param pstr_texte = Message à chiffrer
\return pstr_texte si tout s'est bien passé
*/

char* codageScytale(char* pstr_texte);

/*!
\fn void Scytale(int argc, char** argv);
\author Alexandre Pauly <alexandre.pauly@cy-tech.fr>
\version 0.1 Premier jet
\date 20 décembre 2022
\brief Code de Scytale
\param argc = nombre d'arguments en entrée
\param argv = valeur des arguments en entrée
*/

void Scytale(int argc, char** argv);

#endif
