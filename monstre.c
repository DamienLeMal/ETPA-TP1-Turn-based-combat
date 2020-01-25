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
    int pv_max;
    int pv;
    int atk;
    int poison;
    int stun;
    int spe1;
};

typedef struct Monstre monster ;
typedef struct Hero human ;

int mp = 0;

//Choix du monstre selon la progression du joueur

monster monsterChoice(monster monster1, int niveau){

   // int nombre = 0;

        monster minotaure = {200*niveau,200*niveau,30,0,0,30*niveau};
        monster goule = {200*niveau,200*niveau,30,0,0,30*niveau};
        monster zombie = {200*niveau,200*niveau,30,0,0,30*niveau};
        monster vampire = {200*niveau,200*niveau,30,0,0,30*niveau};
        monster squellette = {200*niveau,200*niveau,30,0,0,30*niveau};
        monster orc = {200*niveau,200*niveau,30,0,0,30*niveau};
        monster troll = {200*niveau,200*niveau,30,0,0,30*niveau};
        monster goblin = {200*niveau,200*niveau,30,0,0,30*niveau};
        monster elfe_noir = {200*niveau,200*niveau,30,0,0,30*niveau};
        monster golem = {200*niveau,200*niveau,30,0,0,30*niveau};
        monster araignee_geante = {200*niveau,200*niveau,30,0,0,30*niveau};
        monster licorne = {200*niveau,200*niveau,30,0,0,30*niveau};
        monster geant = {200*niveau,200*niveau,30,0,0,30*niveau};
        monster sorcier = {200*niveau,200*niveau,30,0,0,30*niveau};
        monster chien_loup = {200*niveau,200*niveau,30,0,0,30*niveau};
        monster serpent_geant = {200*niveau,200*niveau,30,0,0,30*niveau};
    //int select_monstre(){
    //choix du monster aleatoire
        //chaque monster a ses capacites propres (spé1 et spé2)
    //choix des stats defini

       


        //int choixMonstre;
        //choixMonstre = (rand() % (16 + 1 - 1)) + 1; 
            int nombre;
            nombre = random_nbr(1,16);
        
        switch (nombre)
        {
        case 1: 
            monster1 = minotaure;
            printf("\n");
            printf("vie:%d \n", minotaure.pv);

            current_monster = 1
        break;

        case 2: 
            monster1 = goule;
            printf("\n");
            printf("vie:%d \n", goule.pv);

            current_monster2 = 2
        break;

        case 3: 
            monster1 = zombie;
            printf("\n");
            printf("vie:%d \n", zombie.pv);

            current_monster3 = 3
        break;

        case 4:
            monster1 = vampire;
            printf("\n");
            printf("vie:%d \n", vampire.pv);

            current_monster4 = 4
        break;

        case 5: 
            monster1 = squellette;
            printf("\n");
            printf("vie:%d \n", squellette.pv);

            current_monster5 = 5
        break;

        case 6: 
            monster1 = orc;
            printf("\n");
            printf("vie:%d \n", orc.pv);

            current_monster6 = 6
        break;

        case 7: 
            monster1 = troll;;
            printf("\n");
            printf("vie:%d \n", troll.pv);

            current_monste7 = 7
        break;

        case 8:
            monster1 = goblin;
            printf("\n");
            printf("vie:%d \n", goblin.pv);

            current_monster8 = 8
        break;

        case 9: 
            monster1 = elfe_noir;
            printf("\n");
            printf("vie:%d \n", elfe_noir.pv);

            current_monster9 = 9
        break;

        case 10: 
            monster1 = golem;
            printf("\n");
            printf("vie:%d \n", golem.pv);

            current_monster10 = 10
        break;

        case 11: 
            monster1 = araignee_geante;
            printf("\n");
            printf("vie:%d \n", araignee_geante.pv);

            current_monster11 = 11
        break;

        case 12:
            monster1 = licorne;
            printf("\n");
            printf("vie:%d \n", licorne.pv);

            current_monster12 = 12
        break;

        case 13: 
            monster1 = geant;
            printf("\n");
            printf("vie:%d \n", geant.pv);

            current_monster13 = 13
        break;

        case 14: 
            monster1 = sorcier;
            printf("\n");
            printf("vie:%d \n", sorcier.pv);

            current_monster14 = 14
        break;

        case 15: 
            monster1 = chien_loup;
            printf("\n");
            printf("vie:%d \n", chien_loup.pv);

            current_monster15 = 15
        break;

        case 16:
            monster1 = serpent_geant;
            printf("\n");
            printf("vie:%d \n", serpent_geant.pv);

            current_monster16 = 16
        break;


        }

        return monster1;


    }



switch (monstre){
    case 1:
        switch(choix_monstre){
            case 1:
                //attaque
                break;
            case 2:
                //défense
                break;
            case 3:
                //attaque spé
                break;
        }
    case 2:
        switch(choix_monstre){
            case 1:
                //attaque
                break;
            case 2:
                //défense
                break;
            case 3:
                //attaque spé
                break;
        }
    case 3:
        switch(choix_monstre){
            case 1:
                //attaque
                break;
            case 2:
                //défense
                break;
            case 3:
                //attaque spé
                break;
        }
    case 4:
        switch(choix_monstre){
            case 1:
                //attaque
                break;
            case 2:
                //défense
                break;
            case 3:
                //attaque spé
                break;
        }
    case 5:
        switch(choix_monstre){
            case 1:
                //attaque
                break;
            case 2:
                //défense
                break;
            case 3:
                //attaque spé
                break;
        }
    case 6:
        switch(choix_monstre){
            case 1:
                //attaque
                break;
            case 2:
                //défense
                break;
            case 3:
                //attaque spé
                break;
        }
    case 7:
        switch(choix_monstre){
            case 1:
                //attaque
                break;
            case 2:
                //défense
                break;
            case 3:
                //attaque spé
                break;
        }
    case 8:
        switch(choix_monstre){
            case 1:
                //attaque
                break;
            case 2:
                //défense
                break;
            case 3:
                //attaque spé
                break;
        }
    case 9:
        switch(choix_monstre){
            case 1:
                //attaque
                break;
            case 2:
                //défense
                break;
            case 3:
                //attaque spé
                break;
        }
    case 10:
        switch(choix_monstre){
            case 1:
                //attaque
                break;
            case 2:
                //défense
                break;
            case 3:
                //attaque spé
                break;
        }
    case 11:
        switch(choix_monstre){
            case 1:
                //attaque
                break;
            case 2:
                //défense
                break;
            case 3:
                //attaque spé
                break;
        }
    case 12:
        switch(choix_monstre){
            case 1:
                //attaque
                break;
            case 2:
                //défense
                break;
            case 3:
                //attaque spé
                break;
        }
    case 14:
        switch(choix_monstre){
            case 1:
                //attaque
                break;
            case 2:
                //défense
                break;
            case 3:
                //attaque spé
                break;
        }
    case 15:
        switch(choix_monstre){
            case 1:
                //attaque
                break;
            case 2:
                //défense
                break;
            case 3:
                //attaque spé
                break;
        }
    case 16:
        switch(choix_monstre){
            case 1:
                //attaque
                break;
            case 2:
                //défense
                break;
            case 3:
                //attaque spé
                break;
        }
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