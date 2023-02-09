#include <stdio.h>
#include <stdlib.h>
#include "Employer.h"
Employer Lire_Employer()
{
    Employer E;
    printf("Donnez Le numero CNSS de l'employer: \n");
    scanf("%d",&E.CNSS);
    printf("Donnez le nom de l'employer:\n");
    scanf("%s",E.Nom);
    printf("Donnez le prenom de l'employer:\n");
    scanf("%s",E.Prenom);
    printf("Donnez la grade de l'employer:\n");
    scanf("%s",E.Grade);
    return E;
}
void Affiche_Employer(Employer e)
{
    printf("Le numero CNSS de l'employer est : %d \n",e.CNSS);
    printf("Le nom de l'employer est : %s \n",e.Nom);
    printf("Le prenom de l'employer est : %s \n",e.Prenom);
    printf("La grade de l'employer est : %s \n",e.Grade);
}
Liste Ajouter_Employer(Liste Liste_Employer)
{
    Employer E;
    E=Lire_Employer();
    struct cellule *current;
    current=(struct cellule*)malloc(sizeof(struct cellule));
    current->element=E;
    current->suivant=Liste_Employer;
    Liste_Employer=current;
    return Liste_Employer;
}

void Affiche_Liste_Employer(Liste Liste_Employer)
{
    struct cellule* current;
    current=Liste_Employer;
    while(current!=NULL)
    {
        Affiche_Employer(current->element);
        current=current->suivant;
    }
}
struct cellule* Recherche_Employer(Liste Liste_Employer,int Num)
{
    struct cellule *current;
    current=Liste_Employer;
    while(current!=NULL)
    {
        if (current->element.CNSS==Num)
        {
            break;
        }
        current=current->suivant;
    }
    return current;
}

