#include<stdio.h>
#include<stdlib.h>

typedef struct liste
{
   struct liste*suiv;
   struct liste*prec;
    int val;
}liste;

void insertinqueue(liste**tete,int x){
    liste*v1=(liste*)malloc(sizeof(liste));
    v1->suiv=NULL;
    v1->prec=NULL;
    v1->val=x;
    if(*tete==NULL){
        v1->suiv=*tete;
        *tete=v1;
        return;
    }
    liste*cur=*tete;
    while (cur->suiv!=NULL)
    {
        cur=cur->suiv;
    }
    cur->suiv=v1;
    v1->prec=cur;
}
void insertete(liste**tete,int x){
    liste*v1=(liste*)malloc(sizeof(liste));
    v1->suiv=*tete;
    v1->prec=NULL;
    v1->val=x;
    if (*tete!=NULL)
    {
        (*tete)->prec=v1;
    }
    
    *tete=v1;
}
void afficher(liste*tete){
    if (tete==NULL)
    {
        printf("Liste vide\n");
    }
    liste*cur=tete;
    do
    {
        printf("<-%d->",cur->val);
        cur=cur->suiv;
    } while (cur!=NULL);
}
int main(){
    int a,n;
    liste *liste1=NULL;
    printf("Combien de valeur faut-il inserer dans la liste:");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Inserer l'element %d:",i);
        scanf("%d",&a);
        insertete(&liste1, a);
        printf("\n");
    }
    afficher(liste1);
    int d;
    printf("\n");
    printf("Entrer l'element a inserer:");
    scanf("%d",&d);
    printf("\n");
    insertinqueue(&liste1,d);
    afficher(liste1);
    return 0;
}