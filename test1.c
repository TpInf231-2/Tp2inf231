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

int checklist(liste1*tete){
    if (tete==NULL || tete->suiv==NULL)
    {
        printf("Liste triee\n");
        return 1;
    }
    
    liste1*cur=tete;
    while (cur->suiv!=NULL)
    {
        if (cur->val > cur->suiv->val)
        {
            printf("Liste non triee\n");
            return 0;
        }
        cur=cur->suiv;
    }
    printf("Liste triee\n");
    return 1;
}

void insertinlist(liste1**tete,int x){
    liste1*v1=(liste1*)malloc(sizeof(liste1));
    v1->val=x;
    v1->suiv=NULL;
    
    // Cas 1: liste vide
    if (*tete==NULL)
    {
        *tete=v1;
        return;
    }
    
    // Cas 2: insertion en tête
    if (x <= (*tete)->val)
    {
        v1->suiv=*tete;
        *tete=v1;
        return;
    }
    
    // Cas 3: insertion au milieu ou fin
    liste1*cur=*tete;
    while (cur->suiv!=NULL && cur->suiv->val < x)
    {
        cur=cur->suiv;
    }
    v1->suiv=cur->suiv;
    cur->suiv=v1;
}

void trier(liste1**tete){
    if (*tete==NULL || (*tete)->suiv==NULL)
    {
        return;
    }
    
    liste1* newList = NULL;
    liste1* cur = *tete;
    liste1* next;
    
    while (cur != NULL)
    {
        next = cur->suiv;
        
        // Insérer cur dans newList de manière triée
        if (newList == NULL || cur->val <= newList->val)
        {
            // Insertion en tête
            cur->suiv = newList;
            newList = cur;
        }
        else
        {
            // Insertion au milieu ou fin
            liste1* temp = newList;
            while (temp->suiv != NULL && temp->suiv->val < cur->val)
            {
                temp = temp->suiv;
            }
            cur->suiv = temp->suiv;
            temp->suiv = cur;
        }
        cur = next;
    }
    *tete = newList;
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
    
    printf("Liste initiale: ");
    afficher(liste);
    
    int d;
    printf("\n");
    printf("Entrer l'element a inserer: ");
    scanf("%d",&d);
    
    if(checklist(liste)){
        printf("Insertion dans liste triee: ");
        insertinlist(&liste,d);
    } else{
        printf("Tri de la liste puis insertion: ");
        trier(&liste);
        insertinlist(&liste,d);
    }
    
    printf("Liste finale: ");
    afficher(liste);

    return 0;
}