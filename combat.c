#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
//ici, il y aura les structures et les variables globales
srand(time(NULL));

int damage_given = 0;
int damage_taken = 0;

struct Heros {
	int pv_max = 0;
    int pv = 0;
    int mp = 0;
    int atk = 0;
    int poison = 0;
    int spe1 = 0;
    int spe2 = 0;
}

//Choix du monstre selon la progression du joueur
int select_monstre(){
    //choix du monster aleatoire
        //chaque monster a ses capacites propres (spé1 et spé2)
    //choix des stats defini
}

//chaque tour
int tour(){
    int test = 0;
    int hero_disponibles[4];
    hero_disponibles[0] = 1;
    hero_disponibles[1] = 1;
    hero_disponibles[2] = 1;
    hero_disponibles[3] = 1;
    
    for (int i = 0; i < 2; ++i) {
        //Choix hero
        if (paladin.pv == 0){
        	hero_disponibles[0] = 0;
        }
        if (archer.pv == 0){
        	hero_disponibles[1] = 0;
        }
        if (mage.pv == 0){
        	hero_disponibles[2] = 0;
        }
        if (barbare.pv == 0){
        	hero_disponibles[3] = 0;
        }
        while (test == 0){
            display(1,0,0);
            scanf("%d",&hero);
            if (hero_disponibles[hero - 1] == 1){
                hero_disponibles[hero - 1] = 0;
                test = 1;
            }else{
            	printf("Choix impossible\n");
            }
        }

        //Choix action
        switch hero {
            case 1:
                test = 0;
                while (test == 0){
                    display(2,0,0);
                    scanf("%d",&choix);
                    if (mana >= 10) {
                    	test = 1;
                    }else{
                    	if (mana >= 5){
                    		if (choix != 4) {
                    			test = 1;
                    		}
                    	}else{
                    		if ((choix == 1) || (choix == 2)){
                    			test = 1;
                    		}
                    	}
                    }
                }
                choice_p(hero,choix,paladin.atk);
                break;

            case 2:
                test = 0;
                while (test == 0){
                    display(3,0,0);
                    scanf("%d",&choix);
                    if (mana >= 5) {
                    	test = 1;
                    }else{
                    	if (mana >= 1){
                    		if (choix != 4) {
                    			test = 1;
                    		}
                    	}else{
                    		if ((choix == 1) || (choix == 2)){
                    			test = 1;
                    		}
                    	}
                    }
                }
                choice_p(hero,choix,archer.atk);
                break;

            case 3: 
                test = 0;
                while (test == 0){
                    display(4,0,0);
                    scanf("%d",&choix);
                    if (mana >= 5) {
                    	test = 1;
                    }else{
                    	if (mana <= 5){
                    		if ((choix != 4)||(choix != 3)) {
                    			test = 1;
                    		}
                    	}
                    }
                }
                choice_p(hero,choix,mage.atk);
                break;
            case 4:
                test = 0;
                while (test == 0){
                    display(5,0,0);
                    scanf("%d",&choix);
                    if (mana >= 8) {
                    	test = 1;
                    }else{
                    	if (mana >= 3){
                    		if (choix != 4) {
                    			test = 1;
                    		}
                    	}else{
                    		if ((choix == 1) || (choix == 2)){
                    			test = 1;
                    		}
                    	}
                    }
                }
                choice_p(hero,choix,barbare.atk);
                break;
        }
    }



    monstre = select_monstre();
    //Choix du joueur



    //le joueur joue 2 fois avec 2 persos différents
    choice_p(int hero, int choix, int atk);
        //actualisation points à chaque etape


    //choix du monstre
    //les monstres riposte
    choice_m(int monstre, int choix, int atk);
    //actualisation
}

//affichage generique des stats : visuel de l'avancée du jeu. Quels heros sont encores en vie, barre d'xp...
int display(int display, int hero, int monster){
    switch (display){
        case 1 :
            //selection des personnages (vie, mp, xp, effets(ex : poison) pour chaque hero)
            printf("[1] Paladin ----- Vie : %d/%d ----- Attaque : %d \n[2] Archer ----- Vie : %d/%d ----- Attaque : %d \n[3] Mage ----- Vie : %d/%d ----- Attaque : %d \n[4] Barbare ----- Vie : %d/%d ----- Attaque : %d \n",paladin.pv,paladin.pv_max,paladin.atk,archer.pv,archer.pv_max,archer.atk,mage.pv,mage.pv_max,mage.atk,barbare.pv,barbare.pv_max,barbare.atk);
            break;
        //+
        //Menu d'attaque de chaque hero

        case 2 :
            //paladin
            printf("[1] Attaque --- 0 mp \n[2] Defense --- 0 mp \n[3] Soins --- 5 mp \n[4] Resurection --- 10 mp\n");
            break;
        case 3 :
            //archer
            printf("[1] Attaque --- 0 mp \n[2] Defense --- 0 mp \n[3] Esquive --- 1 mp \n[4] Fleche empoisonee --- 10 mp (Probabilite de succes : 50%)\n");
            break;
        case 4 :
            //mage
            printf("[1] Attaque --- 0 mp \n[2] Defense --- 0 mp \n[3] Guerison --- 5 mp \n[4] Somnifere --- 5 mp\n");
            break;
        case 5 :
            //barbare
            printf("[1] Attaque --- 0 mp \n[2] Defense --- 0 mp \n[3] Frappe sanglante --- 3 mp \n[4] Rage --- 8 mp (Probabilite de prendre cher : 50%)\n");
            break;
        case 6 :
        	//attaque
        	switch (hero){
        		case 1 :
        			printf("Le Paladin assene un coup d'epee sur ");
        			break;
        		case 2 :
        			printf("L'Archer décoche sa fleche sur");
        			break;
        		case 3 :
        			printf("Le Mage lance un sort de feu sur");
        			break;
        		case 4 :
        			printf("Le Barbare s'élance, epee a la main sur");
        			break;
        	}
        	switch (monstre){
        		case 1 :
        			printf("le Zombie\n");
        			break;
        	}
        	break;
        case 7 :
        	switch (hero){
        		case 1 :
					printf("Le Paladin lève son bouclier\n");
        			break;
        		case 2 :
					printf("L'Archer se prépare à encaisser un coup\n");
        			break;
        		case 3 :
					printf("Le Mage utilise un sort de protection\n");
        			break;
        		case 4 :
					printf("Le Barbare gaine les abdos\n");
        			break;
        	}
        	
        	break;
        case 8 :
        	printf("Quel hero voulez vous soigner ?\n[1] Le Paladin %d/%d \n[2] L'archer %d/%d \n[3] L'archer %d/%d \n[4] L'archer %d/%d \n",paladin.pv,paladin.pv_max,archer.pv,archer.pv_max,mage.pv,mage.pv_max,barbare.pv,barbare.pv_max);
        	break;
        case 9 :
        	printf();
        	break;
        case 10 :
        	printf();
        	break;
        case 11 :
        	printf();
        	break;
        case 12 :
        	printf();
        	break;
        case 13 :
        	printf();
        	break;
        case 14 :
        	printf();
        	break;
        case 15 :
        	printf();
        	break;
        case 16 :
        	printf();
        	break;
        case 17 :
        	printf();
        	break;
        case 18 :
        	printf();
        	break;
        case 19 :
        	printf();
        	break;
        case 20 :
        	printf();
        	break;
    }
}


//determine les actions a effectuer en fonction des choix du joueur
int choice_p(hero,monstre,choix,atk) {
    //textes des attaques
    switch (hero){
    	case 1 :
    		switch(choix){
    			case 1:
    				//attaque
    				damage_given = paladin.atk;
    				display(6,hero,monstre);
    				return 1;
    				break;
    			case 2:
    				//defense
    				damage_given = 0;
    				display(7,hero,0);
    				return 4;
    				break;
    			case 3:
    				//soins
    				damage_given = 0;
    				paladin_spe1();
    				return 1;
    				break;
    			case 4:
    				//resurection
    				damage_given = 0;
    				paladin_spe2();
    				return 1;
    				break;
    		}
    		break;
    	case 2 :
    		case 1 :
    		switch(choix){
    			case 1:
    				//attaque
    				damage_given = archer.atk;
    				display(6,hero,monstre);
    				return 1;
    				break;
    			case 2:
    				//defense
    				damage_given = 0;
    				display(7,hero,0);
    				return 4;
    				break;
    			case 3:
    				//esquive
    				damage_given = 0;
    				int chance = (rand() % (2)+1);
    				if (chance == 1){
    					return 1000;
    				}else{
    					return 1;
    				}
    				break;
    			case 4:
    				//fleche empoisonée
    				damage_given = archer.atk;

    				return 1;
    				break;
    		}
    		break;
    	case 3 :
    		case 1 :
    		switch(choix){
    			case 1:
    				//attaque
    				damage_given = paladin.atk;
    				display(6,hero,monstre);
    				return 1;
    				break;
    			case 2:
    				//defense
    				damage_given = 0;
    				display(7,hero,0);
    				return 4;
    				break;
    			case 3:
    				//guerison
    				damage_given = 0;

    				return 1;
    				break;
    			case 4:
    				//somnifère
    				damage_given = 0;

    				return 1;
    				break;
    		}
    		break;
    	case 4 :
    		case 1 :
    		switch(choix){
    			case 1:
    				//attaque
    				damage_given = paladin.atk;
    				display(6,hero,monstre);
    				return 1;
    				break;
    			case 2:
    				//defense
    				damage_given = 0;
    				display(7,hero,0);
    				return 4;
    				break;
    			case 3:
    				//frappe sanglante
    				damage_given = 0;

    				return 1;
    				break;
    			case 4:
    				//rage
    				damage_given = barbare.atk * 2;
    				int chance = (rand() % (3)+1);
    				if (chance = 1){
    					return 0.5;
    				}else{
    					return 1;
    				}
    				break;
    		}
    		break;




    }
}

int paladin_spe1(){
	int test = 0;
   	int choix_paladin = 0;
   	while (test == 0){
   		display(8);
   		scanf("%d",&choix_paladin);
   		if (choix_paladin == 2){
    		if (archer.pv != 0){
    			archer.pv += paladin.spe1;
    		}
    	}else if (choix_mage == 3){
    		if (mage.pv != 0){
    			mage.pv += paladin.spe1;
    		}
    	}else if (choix_mage == 4){
    		if (barbare.pv != 0){
    			barbare.pv += paladin.spe1;
    		}
    	}else{
    		paladin.pv += paladin.spe1;
    	}	
    }
}
int paladin_spe2(){
	int test = 0;
   	int choix_paladin = 0;
   	while (test == 0){
   		display(9);
   		scanf("%d",&choix_paladin);
   		if (choix_paladin == 2){
    		if (archer.pv == 0){
    			archer.pv += paladin.spe2;
    		}
    	}else if (choix_mage == 3){
    		if (mage.pv == 0){
    			mage.pv += paladin.spe2;
    		}
    	}else if (choix_mage == 4){
    		if (barbare.pv == 0){
    			barbare.pv += paladin.spe2;
    		}
    	}
    }
}
//determine le choix des monstres en focntion de quel choix genere/quel monstre combat
int choice_m(monstre,choix,atk) {

}
int main() {
    //boucle des monstres
        select_monstre();

        //avancée des joueurs dans le jeu
        //(re)set de la vie, des mp, etc

        //boucle des tours
            tour();
  return 0;
}