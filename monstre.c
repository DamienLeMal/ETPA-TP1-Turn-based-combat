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
        monster squelette = {200*niveau,200*niveau,30,0,0,30*niveau};
        monster orc = {200*niveau,200*niveau,30,0,0,30*niveau};
        monster troll = {200*niveau,200*niveau,30,0,0,30*niveau};
        monster gobelin = {200*niveau,200*niveau,30,0,0,30*niveau};
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
            monster1 = squelette;
            printf("\n");
            printf("vie:%d \n", squelette.pv);

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
            monster1 = gobelin;
            printf("\n");
            printf("vie:%d \n", gobelin.pv);

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
                //attaques
                damage_taken = minotaure.atk;
                break;
            case 2:
                //défense
                damage_taken = 0;
                break;
            case 3:
                //attaque spé
                hero= hero_designated();
                minotaure.atk = minotaure.atk* ;//nbr de hero vivant
                printf("Le minotaure attaque %d, ce qui lui inflige %d de degats\n", hero_designated , minotaure.atk*; )// (nbr de heros vivant) 
                break;
        }
    case 2:
        switch(choix_monstre){
            case 1:
                //attaques
                damage_taken = goule.atk;
                break;
            case 2:
                //défense
                damage_taken = 0;
                break;
            case 3:
                //attaque spé
                printf("La goule a esquiver, elle ne recoit donc aucun degats\n");
                return 1000
                break;
        }
    case 3:
        switch(choix_monstre){
            case 1:
                //attaques
                damage_taken = zombie.atk;
                break;
            case 2:
                //défense
                damage_taken = 0;
                break;
            case 3:
                //attaque spé
                hero.infection = 1
                printf("Le zombie a touche un hero, il est maintenant infecte\n");
                break;
        }
    case 4:
        switch(choix_monstre){
            case 1:
                //attaques
                damage_taken = vampire.atk;
                break;
            case 2:
                //défense
                damage_taken = 0;
                break;
            case 3:
                //attaque spé
                damage_taken = 20;
                vampire.pv = vampire.pv + 20;
                printf("le vampire a vole de la vie a un hero\n");
                break;
        }
    case 5:
        switch(choix_monstre){
            case 1:
                //attaques
                damage_taken = squelette.atk;
                break;
            case 2:
                //défense
                damage_taken = 0;
                break;
            case 3:
                //attaque spé qu'il  faut que Damien fasse
                break;
        }
    case 6:
        switch(choix_monstre){
            case 1:
                //attaques
                damage_taken = orc.atk;
                break;
            case 2:
                //défense
                damage_taken = 0;
                break;
            case 3:
                //attaque spé
                damage_taken = orc.atk*2
                printf("L'orc a fais une attaques plus puissante que d'habitude, les heros prennent 2 fois plus de degats\n", );
                break;
        }
    case 7:
        switch(choix_monstre){
            case 1:
                //attaques
                damage_taken = troll.atk;
                break;
            case 2:
                //défense
                damage_taken = 0;
                break;
            case 3:
                //attaque spé
                damage_taken = troll.atk*2
                printf("Le troll n'est pas content, il fais donc une attaque surpuissante qui inflige 2 fois plus de degats\n");
                break;
        }
    case 8:
        switch(choix_monstre){
            case 1:
                //attaques
                damage_taken = gobelin.atk;
                break;
            case 2:
                //défense
                damage_taken = 0;
                break;
            case 3:
                //attaque spé
                printf("Le gobelin a reussi sont esquive, il ne recoit donc aucun degats\n");
                return 1000
                break;
        }
    case 9:
        switch(choix_monstre){
            case 1:
                //attaques
                damage_taken = elfe_noir.atk;
                break;
            case 2:
                //défense
                damage_taken = 0;
                break;
            case 3:
                //attaque spé
                hero= hero_designated();
                elfe_noir.atk = elfe_noir.atk* // nombre de hero restant
                printf("L'elfe noir a attaque avec precision, toute sont attaque et rediriger vers %d. \n", hero_designated);
                break;
        }
    case 10:
        switch(choix_monstre){
            case 1:
                //attaques
                damage_taken = golem.atk;
                break;
            case 2:
                //défense
                damage_taken = 0;
                break;
            case 3:
                //attaque spé
                hero.stun = 1;
                printf("Le golem a etourdit un hero. Ce hero ne peut pas attaquer le tour prochain\n");
                break;
        }
    case 11:
        switch(choix_monstre){
            case 1:
                //attaques
                damage_taken = araignee_geante.atk;
                break;
            case 2:
                //défense
                damage_taken = 0;
                break;
            case 3:
                //attaque spé
                hero.poison = 1;
                printf("L'araignée géante a lancé son venin sur les heros. Ils sont tous pris de douleur qui leur enlève %d de point de vie\n", araignee_geante.atk);
                break;
        }
    case 12:
        switch(choix_monstre){
            case 1:
                //attaques
                damage_taken = licorne.atk;
                break;
            case 2:
                //défense
                damage_taken = 0;
                break;
            case 3:
                //attaque spé
                printf("La licorne s'envole et esquive donc l'attaque. Elle ne recoit donc aucun degats");
                return 1000
                break;
        }
        case 13:
        switch(choix_monstre){
            case 1:
                //attaques
                damage_taken = geant.atk;
                break;
            case 2:
                //défense
                damage_taken = 0;
                break;
            case 3:
                //attaque spé
                geant.atk = geant.atk*3 //degats de zone sup
                printf("Le geant s'est fais secouer par les heros, il est tres en colere. Ses dégats de zone sont 3 fois plus puissant, ceci affaiblie tres fortement nos heros.\n", );
                break;
        }
    case 14:
        switch(choix_monstre){
            case 1:
                //attaques
                damage_taken = sorcier.atk;
                break;
            case 2:
                //défense
                damage_taken = 0;
                break;
            case 3:
                //attaque spé
                 monstre= monstre_designated();
                 monstre.pv = monstre.pv+100;
                 printf("Le sorcier a redonner de la vie a %d.\n", monstre_designated);
                break;
        }
    case 15:
        switch(choix_monstre){
            case 1:
                //attaques
                damage_taken = chien_loup.atk;
                break;
            case 2:
                //défense
                damage_taken = 0;
                break;
            case 3:
                //attaque spé
                chien_loup.atk = chien_loup.atk*2
                chien_loup.mp = chien_loup.mp*2
                //si t"as d'autre idée de truc a boost
                printf("Le chien loup, par l'odeur du sang, a ses capacites qui double. Tout a augmente sauf sa vie\n");
                break;
        }
    case 16:
        switch(choix_monstre){
            case 1:
                //attaques
                damage_taken = serpent_geant.atk;
                break;
            case 2:
                //défense
                damage_taken = 0;
                break;
            case 3:
                //attaque spé
                monstre= monstre_designated();
                hero.burn = 1;
                printf("Le venin du serpent geant est si puissant que ca brule %d. \n", monstre_designated );
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
    damage_taken = paladin.atk;

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