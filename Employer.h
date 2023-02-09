#ifndef EMPLOYER_H_INCLUDED
#define EMPLOYER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Structure.h"

Employer Lire_Employer();
void Lire_Tab_Employer(Employer* Tab_Employer,int* N);
void Affiche_Employer(Employer e);
void Affiche_Tab_Employer(Employer* Tab_Employer, int N);
Fiche Lire_Fiche();
void Lire_Tab_Fiche(Fiche* Tab_Fiche,int*M);
void Affiche_Fiche(Fiche F);
void Affiche_Tab_Fiche(Fiche* Tab_Fiche,int M);
int Recherche_Fiche_NUM(Fiche* Tab_Fiche, int M);
int * Recherche_Fiche_CNSS(Fiche* Tab_Fiche, int M);
int recherche_employer(Employer* tab_employer,int N,int num);
void Modifie_Fiche(Fiche* F);
void Supprime_Fiche(Fiche* Tab_Fiche,int* M, int pos);
float Montant_totale(Fiche *tab_fiche,int M,int mois);
#endif // EMPLOYER_H_INCLUDED
