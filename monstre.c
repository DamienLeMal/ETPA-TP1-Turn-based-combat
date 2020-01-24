#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 


//ici, il y aura les structures et les variables globales
struct Heros {
    int pv ;
    int mp ;
    int atk ;
    int poison ;
    int this_turn;
};

struct Monstre {
    int pv ;
    int mp ;
    int atk ;
    int poison ;
    int spe_1;
    int spe_2;
    int this_turn;
    int id;
};

typedef struct Monstre monster ;
typedef struct Hero human ;

//Choix du monstre selon la progression du joueur

monster monsterChoice(monster monster1, int niveau){
        monster minotaure = {1000, 5, 50, 5, 70, 80};
        monster goule = {300, 10, 30, 20, 40, 50};
        monster zombie = {100, 10, 20, 30, 50, 60};
        monster sucre = {500, 20, 40, 10, 30, 40};
    //int select_monstre(){
    //choix du monster aleatoire
        //chaque monster a ses capacites propres (spé1 et spé2)
    //choix des stats defini
        int choixMonstre;
        const int MIN = 1, MAX = 4;
        choixMonstre = (rand() % (MAX + 1 - MIN)) + MIN; 
           
        
        switch (choixMonstre)
        {
        case 1:
            monster1 = minotaure;
            printf("Minotaure en avant \n");
            printf("vie:%d mana:%d\n", minotaure.pv, minotaure.mp );
        break;

        case 2:
            monster1 = goule;
            printf("Salut, je suis une goule\n");
            printf("vie:%d mana:%d\n", goule.pv, goule.mp );
        break;

        case 3:
            monster1 = zombie;
            printf("BRAIIIIN\n");
            printf("vie:%d mana:%d\n", zombie );
        break;

        case 4:
            monster1 = sucre;
            printf("hello, je suis du sucre\n");
            printf("vie:%d mana:%d\n", sucre );
        break;

        default:
            printf("Salut, je suis une goule\n");
            printf("vie:%d mana:%d\n", choixMonstre );
        break;
        }

        return monster1;
    }



//chaque tour
int tour(){


}



//affichage generique des stats : visuel de l'avancée du jeu. Quels heros sont encores en vie, barre d'xp...
int display(){
    //selection des personnages (vie, mp, xp, effets(ex : poison) pour chaque hero)

    //+
    //Menu d'attaque de chaque hero
}


//determine les actions a effectuer en fonction des choix du joueur
//int choice_p(hero,choix,atk) {
    //textes des attaques

//determine le choix des monstres en focntion de quel choix genere/quel monstre combat
//int choice_m(monstre,choix,atk) {
    // attaque monstre
    


int main() {
    srand(time(NULL)); 
 monster monster1;
 int niveau = 1;

monster1 =  monsterChoice(monster1, niveau);

//printf("%d\n", monsterChoice(monster1, niveau));

    //boucle des monstres
        //avancée des joueurs dans le jeu
        //reset de la vie, des mp, etc

        //boucle des tours
            tour();
  return 0;
}