#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
//ici, il y aura les structures et les variables globales
struct Heros {
    int pv = 0;
    int mp = 0;
    int atk = 0;
    int poison = 0;
    int this_turn = 0;
}

//Choix du monstre selon la progression du joueur
int select_monstre(){
    //choix du monster aleatoire
        //chaque monster a ses capacites propres (spé1 et spé2)
    //choix des stats defini
}

//chaque tour
int tour(){


    monstre = select_monstre();
    //Choix du joueur



    //le joueur joue 2 fois avec 2 persos différents
    choice_p(hero,choix,atk);
        //actualisation points à chaque etape


    //choix du monstre
    //les monstres riposte
    choice_m(monstre,choix,atk);
    //actualisation
}

//affichage generique des stats : visuel de l'avancée du jeu. Quels heros sont encores en vie, barre d'xp...
int display(){
    //selection des personnages (vie, mp, xp, effets(ex : poison) pour chaque hero)
    printf("[1] Paladin ----- Vie : %d/%d ----- Attaque : %d \n[2] Archer ----- Vie : %d/%d ----- Attaque : %d \n[3] Mage ----- Vie : %d/%d ----- Attaque : %d \n[4] Barbare ----- Vie : %d/%d ----- Attaque : %d \n",paladin.pv,paladin.atk,archer.pv,archer.atk,mage.pv,mage.atk,barbare.pv,barbare.atk);

    //+
    //Menu d'attaque de chaque hero
}


//determine les actions a effectuer en fonction des choix du joueur
int choice_p(hero,choix,atk) {
    //textes des attaques
}
//determine le choix des monstres en focntion de quel choix genere/quel monstre combat
int choice_m(monstre,choix,atk) {

}
int main() {
    //boucle des monstres
        select_monstre();
        //avancée des joueurs dans le jeu
        //reset de la vie, des mp, etc

        //boucle des tours
            tour();
  return 0;
}