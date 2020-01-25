#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
//ici, il y aura les structures et les variables globales
int damage_given = 0;
int damage_taken = 0;
int mp = 0;

//provisoire
int monstre = 1;
//provisoire

typedef struct Heros {
	int pv_max;
    int pv;
    int atk;
    int poison;
    int stun;
    int spe1;
    int spe2;
} heros;

heros paladin = {150,150,30,0,0,30,0.2};
heros archer = {80,80,30,0,0,3,40};
heros mage = {100,100,30,0,0,10,4};
heros barbare = {120,120,50,0,0,1.5,2};


int random_nbr (int min, int max){
	int nbr = 0;
	nbr = (min + (rand () % (max + 1 - min)));
	printf("\n %d \n",nbr);
	return nbr;
}

//Choix du monstre selon la progression du joueur
int select_monstre(){
    //choix du monster aleatoire
        //chaque monster a ses capacites propres (spé1 et spé2)
    //choix des stats defini
}

//affichage generique des stats : visuel de l'avancée du jeu. Quels heros sont encores en vie, barre d'xp...
int display(int code, int hero, int monstre){
    switch (code){
        case 1 :
            //selection des personnages (vie, mp, xp, effets(ex : poison) pour chaque hero)
            printf("[1] Paladin ----- Vie : %d/%d ----- Attaque : %d \n[2] Archer ----- Vie : %d/%d ----- Attaque : %d \n[3] Mage ----- Vie : %d/%d ----- Attaque : %d \n[4] Barbare ----- Vie : %d/%d ----- Attaque : %d \n",paladin.pv,paladin.pv_max,paladin.atk,archer.pv,archer.pv_max,archer.atk,mage.pv,mage.pv_max,mage.atk,barbare.pv,barbare.pv_max,barbare.atk);
            break;
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
            printf("[1] Attaque --- 0 mp \n[2] Defense --- 0 mp \n[3] Frappe sanglante --- 3 mp \n[4] Rage --- 6 mp (Probabilite de prendre cher : 50%)\n");
            break;
        case 6 :
        	//attaque
        	switch (hero){
        		case 1 :
        			printf("Le Paladin assene un coup d'epee sur ");
        			display(7,0,monstre);
        			printf("\n");
        			break;
        		case 2 :
        			printf("L'Archer décoche sa fleche sur ");
        			display(7,0,monstre);
        			printf("\n");
        			break;
        		case 3 :
        			printf("Le Mage lance un sort de feu sur ");
        			display(7,0,monstre);
        			printf("\n");
        			break;
        		case 4 :
        			printf("Le Barbare s'élance, epee a la main sur ");
        			display(7,0,monstre);
        			printf("\n");
        			break;
        	}
        	break;
        case 7 :
        	switch (monstre){
        		case 1 :
        			printf("le Zombie");
        			break;
        		default :
        			break;
        	}
        	switch (hero){
        		case 1 :
					printf("le Paladin");
        			break;
        		case 2 :
					printf("l'Archer");
        			break;
        		case 3 :
					printf("le Mage");
        			break;
        		case 4 :
					printf("le Barbare");
        			break;
        		default :
        			break;
        	}
        	break;
        case 8 :
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
        case 9 :
        	printf("Quel hero voulez vous soigner ?\n[1] Le Paladin %d/%d \n[2] L'archer %d/%d \n[3] Le Mage %d/%d \n[4] Le Barbare %d/%d \n",paladin.pv,paladin.pv_max,archer.pv,archer.pv_max,mage.pv,mage.pv_max,barbare.pv,barbare.pv_max);
        	break;
        case 10 :
        	printf("Quel hero voulez vous ranimer ?\n[1] Le Paladin \n[2] L'archer \n[3] Le Mage \n[4] Le Barbare \n");
        	break;
        case 11 :
        	printf("L'archer tente une esquive... L'esquive réussit ! Il esquive ");
        	display(7,0,monstre);
        	printf(" !\n");
        	break;
        case 12 :
        	printf("L'archer tente une esquive... L'esquive echoue ! Il se prend l'attaque lancee par ");
        	display(7,0,monstre);
        	printf(" de plein fouet !\n");
        	break;
        case 13 :
        	printf("L'archer empoisone ");
        	display(7,0,monstre);
        	printf("\n");
        	break;
        case 14 :
        	printf("Quel hero voulez vous guerir ?\n[1] Le Paladin \n[2] L'archer \n[3] Le Mage \n[4] Le Barbare \n");
        	break;
        case 15 :
        	printf("Le Mage soigne ");
        	display(7,hero,0);
        	printf(" de tous ses maux !\n");
        	break;
        case 16 :
        	printf("Le mage tente en vain d'endormir ");
        	display(7,0,monstre);
        	printf("\n");
        	break;
        case 17 :
        	printf("Le mage endore ");
        	display(7,0,monstre);
        	printf("\n");
        	break;
        case 18 :
        	printf("Le Barbare plante son epee de toutes ses forces dans ");
        	display(7,0,monstre);
        	printf(" !\n");
        	break;
        case 19 :
        	printf("Le Barbare, fou de rage, se jette sur ");
        	display(7,0,monstre);
        	printf(" !\n");
        	break;
        case 20 :
        	printf("Apres avoir violement abattu son courroux sur ");
        	display(7,0,monstre);
        	printf(" le barbare se fait violement envoye a terre !\n");
        	break;
        case 21 :
        	printf("Le courroux du Barbare s'est abattu sur ");
        	display(7,0,monstre);
        	printf(" la decheance de ce dernier n'est plus qu'une question de temps...\n");
        	break;
       	case 22 :
       		printf("Choisissez votre personnage : \n");
       		display(1,0,0);
       		break;
       	case 23 :
       		display(25,0,0);
       		printf("Menu d'action pour ");
       		display(7,hero,0);
       		printf("\n");
       		break;
       	case 24 :
       		printf("Vous ne disposez pas de suffisament de mana ! \n");
       		break;
       	case 25 :
       		printf("Mana : %d \n",mp);
       		break;
       	case 26 :
       		printf("Vous gagnez %d mp \n",hero);
       		break;
       	case 27 :
       		if (hero == 1){
       			//1 digits
       			printf("---------- Debut d'un Nouveau Tour ----------\n------------------ Tour %d -------------------\n",monstre);
       		}else{
       			//2 digits
       			printf("---------- Debut d'un Nouveau Tour ----------\n------------------ Tour %d ------------------\n",monstre);
       		}
       		break;
    }
}

int paladin_spe1(){
	int test = 0;
   	int choix_paladin = 0;
   	while (test == 0){
   		display(9,0,0);
   		scanf("%d",&choix_paladin);
   		if (choix_paladin == 2){
    		if (archer.pv != 0){
    			archer.pv += paladin.spe1;
    			test = 1;
    		}
    	}else if (choix_paladin == 3){
    		if (mage.pv != 0){
    			mage.pv += paladin.spe1;
    			test = 1;
    		}
    	}else if (choix_paladin == 4){
    		if (barbare.pv != 0){
    			barbare.pv += paladin.spe1;
    			test = 1;
    		}
    	}else{
    		paladin.pv += paladin.spe1;
    		test = 1;
    	}	
    }
}
int paladin_spe2(){
	int test = 0;
   	int choix_paladin = 0;
   	while (test == 0){
   		display(10,0,0);
   		scanf("%d",&choix_paladin);
   		if (choix_paladin == 2){
    		if (archer.pv == 0){
    			archer.pv = archer.pv_max * paladin.spe2;
    			test = 1;
    		}
    	}else if (choix_paladin == 3){
    		if (mage.pv == 0){
    			mage.pv = mage.pv_max * paladin.spe2;
    			test = 1;
    		}
    	}else if (choix_paladin == 4){
    		if (barbare.pv == 0){
    			barbare.pv = barbare.pv_max * paladin.spe2;
    			test = 1;
    		}
    	}
    }
}
int archer_spe2(monstre){
	switch (monstre){
		case 1:
			//zombie.poison = 1;
			break;
	}
}
int mage_spe1(){
	int test = 0;
	int choix_mage = 0;
	display(14,0,0);
	scanf("%d",&choix_mage);
	while (test == 0){
		switch (choix_mage){
			case 1:
				paladin.pv += mage.spe1;
				paladin.poison = 0;
				//paladin.autre
				test = 1;
				break;
			case 2:
				archer.pv += mage.spe1;
				archer.poison = 0;
				test = 1;
				break;
			case 3:
				mage.pv += mage.spe1;
				mage.poison = 0;
				test = 1;
				break;
			case 4:
				barbare.pv += mage.spe1;
				barbare.poison = 0;
				test = 1;
				break;
		}
	}
	display(15,choix_mage,0);
}
int mage_spe2(monstre){
	switch (monstre){
		case 1:
			//zombie.stun = 1;
			break;
	}
}


//determine les actions a effectuer en fonction des choix du joueur
int choice_p(int hero, int monstre, int choix) {
	int chance = 0;
    //textes des attaques
    switch (hero){
    	//paladin
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
    				display(8,hero,0);
    				return 4;
    				break;
    			case 3:
    				//soins
    				damage_given = 0;
    				paladin_spe1();
    				mp -= 5;
    				return 1;
    				break;
    			case 4:
    				//resurection
    				damage_given = 0;
    				paladin_spe2();
    				mp -= 10;
    				return 1;
    				break;
    		}
    		break;
    	//archer
    	case 2 :
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
    				display(8,hero,0);
    				return 4;
    				break;
    			case 3:
    				//esquive
    				damage_given = 0;
    				chance = random_nbr(1,archer.spe1);
    				if (chance == 1){
    					return 1000;
    					display(11,0,monstre);
    				}else{
    					return 1;
    					display(12,0,monstre);
    				}
    				mp -= 1;
    				break;
    			case 4:
    				//fleche empoisonée
    				damage_given = archer.atk * archer.spe2;
    				archer_spe2(monstre);
    				display(13,0,monstre);
    				mp -= 5;
    				return 1;
    				break;
    		}
    		break;
    	//mage
    	case 3 :
    		switch(choix){
    			case 1:
    				//attaque
    				damage_given = mage.atk;
    				display(6,hero,monstre);
    				return 1;
    				break;
    			case 2:
    				//defense
    				damage_given = 0;
    				display(8,hero,0);
    				return 4;
    				break;
    			case 3:
    				//guerison
    				damage_given = 0;
    				mage_spe1();
    				mp -= 5;
    				return 1;
    				break;
    			case 4:
    				//somnifère
    				chance = random_nbr(1,mage.spe2);
       				if (chance == 1){
    					display(17,0,monstre);
    					mage_spe2(monstre);
    				}else{
    					display(16,0,monstre);
    				}
    				damage_given = 0;
    				mp -= 5;
    				return 1;
    				break;
    		}
    		break;
    	//barbare
    	case 4 :
    		switch(choix){
    			case 1:
    				//attaque
    				damage_given = barbare.atk;
    				display(6,hero,monstre);
    				return 1;
    				break;
    			case 2:
    				//defense
    				damage_given = 0;
    				display(8,hero,0);
    				return 4;
    				break;
    			case 3:
    				//frappe sanglante
    				damage_given = barbare.atk * barbare.spe1;
    				display(18,0,monstre);
    				mp -= 3;
    				return 1;
    				break;
    			case 4:
    				//rage
    				mp -= 6;
    				damage_given = barbare.atk * barbare.spe2;
    				display(19,0,monstre);
    				chance = random_nbr(1,3);
    				if (chance == 1){
    					barbare.pv -= barbare.atk;
    					display(20,0,monstre);
    					return 0.5;
    				}else{
    					display(21,0,monstre);
    					return 1;
    				}
    				break;
    		}
    		break;
    }
}

//determine le choix des monstres en focntion de quel choix genere/quel monstre combat
int choice_m(monstre,choix,atk) {

}

//attribution de mana en fin de tour
int mana(){
	int cumul = 0;
	if (paladin.pv > 0){
		cumul++;
	}
	if (archer.pv > 0){
		cumul++;
	}
	if (mage.pv > 0){
		cumul++;
	}
	if (barbare.pv > 0){
		cumul++;
	}
	mp = mp + cumul;
	display(26,cumul,0);
	return cumul;
}
//chaque tour
int tour(){
	int hero = 0;
	int choix = 0;
    int test = 0;
    int hero_disponibles[4];
    hero_disponibles[0] = 1;
    hero_disponibles[1] = 1;
    hero_disponibles[2] = 1;
    hero_disponibles[3] = 1;
    
    //2 personnages
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
            display(22,0,0);
            scanf("%d",&hero);
            if (hero_disponibles[hero - 1] == 1){
                hero_disponibles[hero - 1] = 0;
                test = 1;
            }else{
            	printf("Choix impossible\n");
            }
        }

        //Choix action
        switch (hero) {
            case 1:
                test = 0;
                while (test == 0){
                	display(23,hero,0);
                    display(2,0,0);
                    scanf("%d",&choix);
                    if (mp >= 10) {
                    	test = 1;
                    }else{
                    	if (mp >= 5){
                    		if (choix != 4) {
                    			test = 1;
                    		}
                    	}else{
                    		if ((choix == 1) || (choix == 2)){
                    			test = 1;
                    		}else{
                    			display(24,0,0);
                    		}
                    	}
                    }
                }
                test = 0;
                choice_p(hero,monstre,choix);
                break;

            case 2:
                test = 0;
                while (test == 0){
                	display(23,hero,0);
                    display(3,0,0);
                    scanf("%d",&choix);
                    if (mp >= 5) {
                    	test = 1;
                    }else{
                    	if (mp >= 1){
                    		if (choix != 4) {
                    			test = 1;
                    		}
                    	}else{
                    		if ((choix == 1) || (choix == 2)){
                    			test = 1;
                    		}else{
                    			display(24,0,0);
                    		}
                    	}
                    }
                }
                test = 0;
                choice_p(hero,monstre,choix);
                break;

            case 3: 
                test = 0;
                while (test == 0){
                	display(23,hero,0);
                    display(4,0,0);
                    scanf("%d",&choix);
                    if (mp >= 5) {
                    	test = 1;
                    }else{
                    	if (mp <= 5){
                    		if ((choix == 1) || (choix == 2)){
                    			test = 1;
                    		}else{
                    			display(24,0,0);
                    		}
                    	}
                    }
                }
                test = 0;
                choice_p(hero,monstre,choix);
                break;
            case 4:
                test = 0;
                while (test == 0){
                	display(23,hero,0);
                    display(5,0,0);
                    scanf("%d",&choix);
                    if (mp >= 8) {
                    	test = 1;
                    }else{
                    	if (mp >= 3){
                    		if (choix != 4) {
                    			test = 1;
                    		}
                    	}else{
                    		if ((choix == 1) || (choix == 2)){
                    			test = 1;
                    		}else{
                    			display(24,0,0);
                    		}
                    	}
                    }
                }
                test = 0;
                choice_p(hero,monstre,choix);
                break;
        }
    }
    //Riposte monstre

}


int main() {
	srand(time(NULL));
	int test = 1;
	int tours = 0;
    //boucle des manches
    for (int manche = 0; manche < 10; manche++){
 		//debut manche
    	select_monstre();
    	heros paladin = {150,150,30,0,0,30,0.2};
    	heros archer = {80,80,30,0,0,3,40};
    	heros mage = {100,100,30,0,0,10,4};
    	heros barbare = {120,120,50,0,0,1.5,2};

    	//boucle des tours
    	while ((test != 0)/*||(Tous les monstres en vie)*/){
    		tours++;
    		if (tours < 10){
    			display(27,1,tours);
    		}else{
    			display(27,2,tours);
    		}
    		tour();
    	    //compte le nombre de heros en vie et attribue du mana en conséquence
    	    test = mana();

    	}
    }
  return 0;
}
