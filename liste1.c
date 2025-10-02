#include<stdio.h>
#include<stdlib.h>
 typedef struct liste1
{
    int val;
    struct liste1*suiv;
}liste1;

struct liste1*createliste(int val){
    liste1*v1=(liste1*)malloc(sizeof(liste1));
    v1->val=val;
    v1->suiv=NULL;
    return v1;
}
void insert(liste1**tete, int val1){
    liste1*v1 =(liste1*)malloc(sizeof(liste1));
    v1->val=val1;
    v1->suiv=*tete;
    *tete=v1;

}
void delete(liste1**tete,int x){
if (*tete==NULL)
{
    printf("Liste vide");
    return;
}
liste1*temp=NULL;
while (*tete!=NULL && (*tete)->val==x)
{
    temp=*tete;
    *tete=(*tete)->suiv;
    free(temp);
}
liste1*cur=*tete;
while (cur!=NULL && cur->suiv!=NULL)
{
    if (cur->suiv->val==x)
    {
        temp=cur->suiv;
        cur->suiv=cur->suiv->suiv;
        free(temp);
    }else
    {
        cur=cur->suiv;
    }
    
    
}
}
void afficher(liste1*tete){
    if (tete==NULL)
    {
       printf("Liste vide\n");
       return;
    }
    
while (tete!=NULL){
    printf("%d->",tete->val);
    tete=tete->suiv;
}
printf("NULL\n");
}
int main(){
    int a,n;
    liste1 *liste=NULL;
    printf("Combien de valeur faut-il inserer dans la liste:");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Inserer l'element %d:",i);
        scanf("%d",&a);
        insert(&liste, a);
        printf("\n");
    }
    afficher(liste);
    int d;
    printf("\n");
    printf("Entrer l'element a supprimer:");
    scanf("%d",&d);
    printf("\n");
    delete(&liste,d);
    afficher(liste);
    return 0;
}