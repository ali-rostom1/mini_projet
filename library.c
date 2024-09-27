#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void add_book();
void print_all_books();
void search_book();
void update_quantity();
void delete_book();
void total_books();




/*Ajouter un livre au stock.
Afficher tous les livres disponibles.
Rechercher un livre par son titre.
Mettre à jour la quantité d'un livre.
Supprimer un livre du stock.
Afficher le nombre total de livres en stock.
*/
int choice;
char title[100][50];
char author[100][50];
float prices[100];
int quantities[100];
int tracker=0;


int main(){
    
    do{
        printf("\n************ Menu ************\n");
        printf("1. Ajouter un livre au stock.\n");
        printf("2. Afficher tous les livres disponibles.\n");
        printf("3. Rechercher un livre par son titre.\n");
        printf("4. Mettre à jour la quantité d'un livre.\n");
        printf("5. Supprimer un livre du stock.\n");
        printf("6. Afficher le nombre total de livres en stock.\n");
        printf("7. EXIT.\n");
        printf("choisir une option: ");
        while(scanf("%d",&choice)!=1 || choice<1 || choice>7){
            printf("veuillez saisir un nombre entre 1 et 7");
            while(getchar()!='\n');
        }
        switch(choice){
            case 1 :
                add_book();
                break;
            case 2:
                print_all_books();
                break;
            case 3:
                search_book();
                break;
            case 7:
                printf("EXiting ..........");
                break;
        }
    }while(choice!=7);
}

void add_book(){
    if(tracker<100){
        printf("saisir le nom de livre: ");
        scanf(" %[^\n]",title[tracker]);
        printf("saisir le nom de l'auteur: ");
        scanf(" %[^\n]",author[tracker]);
        printf("saisir le prix: ");
        scanf("%f",&prices[tracker]);
        printf("saisir la quantite de livre dans le stock: ");
        scanf("%d",&quantities[tracker]);
        tracker++;
    }else {
        printf("stock de livres full.");
    }
}
void print_all_books(){
    if(tracker==0){
        printf("le stock de livre est vide");
    }else{
        for(int i=0;i<tracker;i++){
            printf("\nlivre %d :\n",i+1);
            printf("\tle nom de livre %s\n",title[i]);
            printf("\tl'auteur de livre %s\n",author[i]);
            printf("\tle prix de livre %.02f\n",prices[i]);
            printf("\tla quantite du livre %d\n",quantities[i]);
        }
    }
}
void search_book() {
    if (tracker == 0) {
        printf("\nLe stock de livres est vide.\n");
    } else {
        char title1[50];
        int hit = 0;
        printf("\nSaisir le nom de livre: ");
        scanf(" %[^\n]", title1);
        
        for (int i = 0; i < tracker; i++) {
            if (strcmp(title[i], title1) == 0) {
                hit = 1;
                printf("\nLe livre recherché est le livre numéro %d:\n", i + 1);
                printf("\tLe nom de livre: %s\n", title[i]);
                printf("\tL'auteur de livre: %s\n", author[i]);
                printf("\tLe prix de livre: %.02f\n", prices[i]);
                printf("\tLa quantité du livre: %d\n", quantities[i]);
            }
        }
        
        if (hit == 0) {
            printf("\nAucun livre avec le nom donné.\n");
        }
    }
}
void update_quantity(){
    if(tracker==0){
        printf("\nLe stock de livres est vide.\n");
    }else{
        char title1[50];
        int quantity1,hit=0;

        printf("\nSaisir le nom de livre: ");
        scanf(" %[^\n]", title1);

        printf("\nSaisir la nouvelle quantitee: ");
        scanf("%d",&quantity1);

        for (int i = 0; i < tracker; i++) {
            if (strcmp(title[i], title1) == 0) {
                hit = 1;
                quantities[i] = quantity1;
                printf("nouvelle quantite assigner a le livre %d !",i+1);
            }
        }

        if(hit==0){
            printf("aucun livre trouve avec le nom donnee");
        }
    }

}
