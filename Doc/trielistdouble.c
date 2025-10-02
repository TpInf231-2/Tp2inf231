#include<stdio.h>
#include<stdlib.h>

typedef struct liste{
    struct liste*suiv;
    struct liste*prec;
    int val;
}liste;
void insert(liste**tete,int x){
    liste*v1=(liste*)malloc(sizeof(liste));
    v1->suiv=*tete;
    v1->prec=NULL;
    v1->val=x;
    if (*tete!=NULL){
        (*tete)->prec=v1; 
    }
    *tete=v1;
}

void trierliste(liste**tete){
    if (*tete==NULL || (*tete)->suiv==NULL)
    {
        return;
    }
    int echange;
    do
    {
        echange=0;
        liste*cur=*tete;
        while (cur->suiv!=NULL)
        {
            if (cur->val>cur->suiv->val)
            {
                int temp=cur->val;
                cur->val=cur->suiv->val;
                cur->suiv->val=temp;
                echange=0;
            }
            cur=cur->suiv;
        }
        
    } while (!echange);
    
    
}
void insertliste(liste**tete,int c){
liste*v1=(liste*)malloc(sizeof(liste));
v1->prec=NULL;
v1->suiv=NULL;
v1->val=c;
if (*tete==NULL)
{
    *tete=v1;
    return;
}
liste*cur=*tete;
liste*temp=NULL;
    while (cur->suiv!=NULL && cur->suiv->val<c){
        cur=cur->suiv;
    }
    v1->suiv=cur->suiv;
    v1->prec=cur;
    if (cur->suiv!=NULL)
    {
        cur->suiv->prec=v1;
    }
    cur->suiv=v1;
}
void afficher(liste*tete){
    if (tete==NULL)
    {
        printf("Liste vide\n");
        return;
    }
    liste*cur=tete;
    printf("NULL");
    while (cur!=NULL)
    {
        printf("<-%d->",cur->val);
        cur=cur->suiv;
    }
    printf("NULL\n");
}
int main(){
    int n,a,x;
    liste*l1=NULL;
    printf("Combien d'element souhaiter vous inserer?:");
    scanf("%d",&a);
    for (int i = 0; i < a; i++)
    {
     printf("Entrer l'element %d:",i);
    scanf("%d",&n);
    insert(&l1,n);
    }
    afficher(l1);
    trierliste(&l1);
    afficher(l1);
    printf("Entrer l'element a inserer dans la liste trier:");
    scanf("%d",&x);
    insertliste(&l1,x);
    afficher(l1);
    return 0;
}