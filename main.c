#include <stdio.h>
#include <stdlib.h>
#include "employer.h"
#include "Structure.h"
#include <time.h>
int main()
{
    Employer Tab_Employer[30];
    time_t secondes;
    struct tm instant;
    time(&secondes);
    instant=*localtime(&secondes);
    int N=0,M=0,i,j=0;
    int* tab;
    Fiche F,Tab_Fiche[30];
    while(1)
    {
        printf("\n  ****** Menu Gestion Etudiant*********");
        printf("\n *****  %d/%d/%d   ***   %d:%d:%d ****\n",instant.tm_mday,instant.tm_mon+1,instant.tm_year+1900,instant.tm_hour,instant.tm_min,instant.tm_sec);
        printf("**************************************************\n\t\t\tMENU\n**************************************************\n");
        printf("1. Saisir un employer.\n2. Saisir Un Tabeau d'emplyers.\n3. Afficher l'ensemble des employers.\n");
        printf("4. Saisir une fiche.\n5. Saisir un ensemble de fiches.\n6. Afficher l'ensemble des fiches.\n");
        printf("7. Rechercher les fiches d'un employer.\n8. Modifier une fiche.\n9. Supprimer une fiche.\n");
        printf("10. Afficher Le Montant Totale D'un Mois.\n");
        printf("**************************************************\n");
        scanf("%d",&i);
        switch (i)
        {
            case 0:
            {
                exit(1);
            }
            case 1:{
                Tab_Employer[N]=Lire_Employer();
                N+=1;break;
            }
            case 2:{
                Lire_Tab_Employer(Tab_Employer,&N);break;
            }
            case 3:{
                Affiche_Tab_Employer(Tab_Employer,N);break;
            }
            case 4:
            {

               /* printf("Ajouter une fiche de paie:\n");
                F=Lire_Fiche();
                Tab_Fiche[M]=F;
                M++;*/
               printf("Donner le numero cnss de l'employer: ");
               int num_cnss;
               scanf("%d",&num_cnss);
               if (recherche_employer(Tab_Employer,N,num_cnss)!=-1){
                   printf("Donnez Le numero de la fiche: \n");
                   scanf("%d",&F.Numero);
                   printf("Donnez le montant de la fiche:\n");
                   scanf("%f",&F.Montant);
                   printf("Donnez le mois de la fiche:\n");
                   scanf("%d",&F.Mois);
                   printf("Donnez l'employer de la fiche:\n");
                   F.employer=Tab_Employer[recherche_employer(Tab_Employer,N,num_cnss)];
                   Tab_Fiche[M]=F;
                   M++;
               }
               else{
                   printf("L'employer ayant ce numero de cnss n'existe pas. Voulez vous l'ajouter? [0/1] ");
                   int choice;
                   scanf("%d",&choice);
                   if (choice==1){
                       F.employer=Lire_Employer();
                       Tab_Employer[N]=F.employer;
                       N++;
                       printf("Donnez Le numero de la fiche: \n");
                       scanf("%d",&F.Numero);
                       printf("Donnez le montant de la fiche:\n");
                       scanf("%f",&F.Montant);
                       printf("Donnez le mois de la fiche:\n");
                       scanf("%d",&F.Mois);
                       printf("Donnez l'employer de la fiche:\n");
                       Tab_Fiche[M]=F;
                       M++;
                   }
               }
                break;
            }
            case 5:
            {

                printf("Ajouter un ensemble de fiches:\n");
                Lire_Tab_Fiche(Tab_Fiche,&M);
                break;
            }
            case 6:
            {
                printf("Afficher les fiches:\n");
                Affiche_Tab_Fiche(Tab_Fiche,M);
                break;
            }
            case 7:
            {
                printf("Rechercher les fiches d'un employer:\n");
                tab=Recherche_Fiche_CNSS(Tab_Fiche,M);
                for(j=0;j<M;j++)
                {
                    if ((*tab+j)==1)
                    {
                        Affiche_Fiche(Tab_Fiche[j]);break;
                    }
                }
                break;

            }
            case 8:
            {
                printf("Modifier une fiche:\n");
                j=Recherche_Fiche_NUM(Tab_Fiche,M);
                if (j==-1)
                    printf("La fiche n'existe pas.\n");
                else
                    Modifie_Fiche(&Tab_Fiche[j]);
                break;

            }
            case 9:
            {
                printf("Supprimer une fiche:\n");
                j=Recherche_Fiche_NUM(Tab_Fiche,M);
                if (j==-1)
                    printf("La fiche n'existe pas.\n");
                else
                    Supprime_Fiche(Tab_Fiche,&M,j);
                break;
            }
            case 10:
            {
                printf("Donner Le Mois: ");
                int mois;
                scanf("%d",&mois);
                printf("%f", Montant_totale(Tab_Fiche,M,mois));break;
            }

        }
    }
    return 0;
}
