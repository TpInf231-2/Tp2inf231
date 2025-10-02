#include<stdio.h>
#include<stdlib.h>
typedef struct liste{
    struct liste*suiv;
    struct liste*prec;
    int val;
}liste;

liste*createliste(int n){
liste*v1=(liste*)malloc(sizeof(liste));
v1->suiv=v1->prec=NULL;
v1->val=n;
return v1;
}

void afficher(liste*tete){
    if (tete==NULL){
        printf("Liste vide\n");
        return;
    }
    printf("NULL");
    liste*cur=tete;
    while (cur!=NULL)
    {
        printf("<-%d->",cur->val);
        cur=cur->suiv;
    }

    printf("NULL");
}
void insertenqueu(liste**tete,int x){
     liste* v1=createliste(x);
    if (*tete==NULL)
    {
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

void insertinhead(liste**tete,int x){
liste*v1=createliste(x);
if (*tete==NULL)
{
    *tete=v1;
}else{
    liste*cur=*tete;
    cur->suiv=*tete;
    (*tete)->prec=v1;
    *tete=v1;
}


    
}
int main(){
    liste*p=NULL;
    int n,a;
    printf("Nombre d'element a inserer dans la liste:");
    scanf("%d",&n);
    for (int i = 0; i < n/2; i++)
    {
        printf("Inserer l'element %d:",i);
        scanf("%d",&a);
        insertinhead(&p,a);
        printf("\n");
        for (int j = (n/2); i < n; i++)
        {
        printf("Inserer l'element %d:",i);
        scanf("%d",&a);
        insertenqueu(&p,a);
        printf("\n");  
        }
        
    }
    afficher(p);
    printf("\n");
    return 0;
}