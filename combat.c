#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
//ici, il y aura les structures et les variables globales
int damage_given = 0;
int damage_taken = 0;
int mp = 0;
int monstre1 = 0;
int monstre2 = 0;
int monstre3 = 0;
int navigateur = 0;
int check = 0;

int one = 0,two = 0,three = 0,four = 0,five = 0,six = 0,seven = 0,eight = 0,nine = 0,ten = 0,eleven = 0,twelve = 0,thirteen = 0,fourteen = 0,fifteen = 0,sixteen = 0;
//provisoire
//int monstre = 11;
//provisoire

typedef struct Heros {
	int pv_max;
    int pv;
    int atk;
    int defense;
    int poison;
    int stun;
    int spe1;
    int spe2;
} heros;

typedef struct Monstres {
    int pv_max;
    int pv;
    int atk;
    int defense;
    int poison;
    int stun;
    int spe1;
} monstres;

heros paladin = {150,150,30,1,0,0,30,0.2};
heros archer = {80,80,30,1,0,0,3,40};
heros mage = {100,100,30,1,0,0,10,4};
heros barbare = {120,120,50,1,0,0,1.5,2};

monstres minotaure = {200, 200, 30, 1,0, 0, 30};
monstres goule = {200, 200, 30, 1,0, 0, 30};
monstres zombie = {200, 200, 30, 1,0, 0, 30};
monstres vampire = {200, 200, 30, 1,0, 0, 30};
monstres squelette = {200, 200, 30, 1,0, 0, 30};
monstres orc = {200, 200, 30, 1,0, 0, 30};
monstres troll = {200, 200, 30, 1,0, 0, 30};
monstres gobelin = {200, 200, 30, 1,0, 0, 30};
monstres elfe_noir = {200, 200, 30, 1,0, 0, 30};
monstres golem = {200, 200, 30, 1,0, 0, 30};
monstres araignee_geante = {200, 200, 30, 1,0, 0, 30};
monstres licorne = {200, 200, 30, 1,0, 0, 30};
monstres geant = {200, 200, 30, 1,0, 0, 30};
monstres sorcier = {200, 200, 30, 1,0, 0, 30};
monstres chien_loup = {200, 200, 30, 1,0, 0, 30};
monstres serpent_geant = {200, 200, 30, 1,0, 0, 30};

int random_nbr (int min, int max){
	int nbr = 0;
	nbr = (min + (rand () % (max + 1 - min)));
	return nbr;
}

int tirage(){
    int tableau_monster[16];
    int k = 0;
    int stock = 0;
    	for (int i = 0; i < 16; ++i){
		    tableau_monster[i] = i + 1;
    	}
    	for (int i = 0; i < 16; ++i){
    	    k = random_nbr(0,15);
    	    stock = tableau_monster[i];
    	    tableau_monster[i] = tableau_monster[k];
    	    tableau_monster[k] = stock;
    	}
}

//Choix du monstre selon la progression du joueur
int select_monstre(manche){
    int nbr_monstre = 0;
	int nombre = 0;
	float niveau = 1;
	int tableau_monster[16];
    int k = 0;
    int stock = 0;
    if (manche == 1){
    	for (int i = 0; i < 16; ++i){
	    	tableau_monster[i] = i + 1;
    	}
    	for (int i = 0; i < 16; ++i){
        	k = random_nbr(0,15);
        	stock = tableau_monster[i];
        	tableau_monster[i] = tableau_monster[k];
        	tableau_monster[k] = stock;
    	}
    	one = tableau_monster[0];
    	two = tableau_monster[1];
    	three = tableau_monster[2];
    	four = tableau_monster[3];
    	five = tableau_monster[4];
    	six = tableau_monster[5];
    	seven = tableau_monster[6];
    	eight = tableau_monster[7];
    	nine = tableau_monster[8];
    	ten = tableau_monster[9];
    	eleven = tableau_monster[10];
    	twelve = tableau_monster[11];
    	thirteen = tableau_monster[12];
    	fourteen = tableau_monster[13];
    	fifteen = tableau_monster[14];
    	sixteen = tableau_monster[15];
    }
//definition du nombre de monstre à sortir (en fonction de la manche)
    switch(manche){
    	case 1:
    		monstre1 = one;
    		niveau = 1;
    		break;
    	case 2:
    		monstre1 = two;
    		niveau = 1.25;
    		break;
    	case 3:
    		monstre1 = three;
    		niveau = 1.5;
    		break;
    	case 4:
    		monstre1 = four;
    		niveau = 1.75;
    		break;
    	case 5:
    		monstre1 = five;
    		niveau = 2;
    		break;
    	case 6:
    		monstre1 = six;
    		monstre2 = seven;
    		niveau = 1.5;
    		break;
    	case 7:
    		monstre1 = eight;
    		monstre2 = nine;
    		niveau = 1.75;
    		break;
    	case 8:
    		monstre1 = ten;
    		monstre2 = eleven;
    		niveau = 2;
    		break;
    	case 9:
    		monstre1 = twelve;
    		monstre2 = thirteen;
    		niveau = 2.25;
    		break;
    	case 10:
    		monstre1 = fourteen;
    		monstre2 = fifteen;
    		monstre3 = sixteen;
    		niveau = 1.75;
    		break;
    }
    //stat des monstres en fonction du niveau

    minotaure.pv_max = 200 * niveau;
    minotaure.pv = minotaure.pv_max;
    minotaure.atk =	30 * niveau;
    minotaure.spe1 = 30 * niveau;

    goule.pv_max = 200 * niveau;
    goule.pv = goule.pv_max;
    goule.atk =	30 * niveau;
    goule.spe1 = 30 * niveau;

    zombie.pv_max = 200 * niveau;
    zombie.pv = zombie.pv_max;
    zombie.atk =	30 * niveau;
    zombie.spe1 = 30 * niveau;

    vampire.pv_max = 200 * niveau;
    vampire.pv = vampire.pv_max;
    vampire.atk =	30 * niveau;
    vampire.spe1 = 30 * niveau;

    squelette.pv_max = 200 * niveau;
    squelette.pv = squelette.pv_max;
    squelette.atk =	30 * niveau;
    squelette.spe1 = 30 * niveau;

    orc.pv_max = 200 * niveau;
    orc.pv = orc.pv_max;
    orc.atk =	30 * niveau;
    orc.spe1 = 30 * niveau;

    troll.pv_max = 200 * niveau;
    troll.pv = troll.pv_max;
    troll.atk =	30 * niveau;
    troll.spe1 = 30 * niveau;

    gobelin.pv_max = 200 * niveau;
    gobelin.pv = gobelin.pv_max;
    gobelin.atk =	30 * niveau;
    gobelin.spe1 = 30 * niveau;

    elfe_noir.pv_max = 200 * niveau;
    elfe_noir.pv = elfe_noir.pv_max;
    elfe_noir.atk =	30 * niveau;
    elfe_noir.spe1 = 30 * niveau;

    golem.pv_max = 200 * niveau;
    golem.pv = golem.pv_max;
    golem.atk =	30 * niveau;
    golem.spe1 = 30 * niveau;

    araignee_geante.pv_max = 200 * niveau;
    araignee_geante.pv = araignee_geante.pv_max;
    araignee_geante.atk =	30 * niveau;
    araignee_geante.spe1 = 30 * niveau;

    licorne.pv_max = 200 * niveau;
    licorne.pv = licorne.pv_max;
    licorne.atk =	30 * niveau;
    licorne.spe1 = 30 * niveau;

    geant.pv_max = 200 * niveau;
    geant.pv = geant.pv_max;
    geant.atk =	30 * niveau;
    geant.spe1 = 30 * niveau;

    sorcier.pv_max = 200 * niveau;
    sorcier.pv = sorcier.pv_max;
    sorcier.atk =	30 * niveau;
    sorcier.spe1 = 30 * niveau;

    chien_loup.pv_max = 200 * niveau;
    chien_loup.pv = chien_loup.pv_max;
    chien_loup.atk =	30 * niveau;
    chien_loup.spe1 = 30 * niveau;
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
        			printf("le Minotaure");
        			break;
        		case 2 :
        			printf("la Goule");
        			break;
        		case 3 :
        			printf("le Zombie");
        			break;
        		case 4 :
        			printf("le Vampire");
        			break;
        		case 5 :
        			printf("le Squelette");
        			break;
        		case 6 :
        			printf("l'Orc");
        			break;
        		case 7 :
        			printf("le Troll");
        			break;
        		case 8 :
        			printf("le Gobelin");
        			break;
        		case 9 :
        			printf("l'Elfe Noir");
        			break;
        		case 10 :
        			printf("le Golem");
        			break;
        		case 11 :
        			printf("l'Araignee Geante");
        			break;
        		case 12 :
        			printf("la Licorne");
        			break;
        		case 13 :
        			printf("le Geant");
        			break;
        		case 14 :
        			printf("le Sorcier");
        			break;
        		case 15 :
        			printf("le Chien-Loup");
        			break;
        		case 16 :
        			printf("le Serpent Geant");
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
       	case 28 :
       		printf("Quel Monstre voulez vous attaquer ? \n");
       		if (monstre3 != 0){
       			printf("[1] Attaquer ");
       			display(7,0,monstre1);
       			display(30,0,monstre1);
       			printf("\n");
       			printf("[2] Attaquer ");
       			display(7,0,monstre2);
       			display(30,0,monstre2);
       			printf("\n");
       			printf("[3] Attaquer ");
       			display(7,0,monstre3);
       			display(30,0,monstre3);
       			printf("\n");
       		}else if (monstre2 != 0){
       			printf("[1] Attaquer ");
       			display(7,0,monstre1);
       			display(30,0,monstre1);
       			printf("\n");
       			printf("[2] Attaquer ");
       			display(7,0,monstre2);
       			display(30,0,monstre2);
       			printf("\n");
       		}else{
       			printf("[1] Attaquer ");
       			display(7,0,monstre1);
       			display(30,0,monstre1);
       			printf("\n");
       		}
       		break;
       	case 29 :
       		display(7,0,monstre);
       		printf(" prend %d points de degats ! \n",hero);
       		break;
		case 30 : //affiche les pv des monstres
			switch (monstre){
        		case 1 :
        			printf(" %d / %d",minotaure.pv,minotaure.pv_max);
        			break;
        		case 2 :
        			printf(" %d / %d",goule.pv,goule.pv_max);
        			break;
        		case 3 :
        			printf(" %d / %d",zombie.pv,zombie.pv_max);
        			break;
        		case 4 :
        			printf(" %d / %d",vampire.pv,vampire.pv_max);
        			break;
        		case 5 :
        			printf(" %d / %d",squelette.pv,squelette.pv_max);
        			break;
        		case 6 :
        			printf(" %d / %d",orc.pv,orc.pv_max);
        			break;
        		case 7 :
        			printf(" %d / %d",troll.pv,troll.pv_max);
        			break;
        		case 8 :
        			printf(" %d / %d",gobelin.pv,gobelin.pv_max);
        			break;
        		case 9 :
        			printf(" %d / %d",elfe_noir.pv,elfe_noir.pv_max);
        			break;
        		case 10 :
        			printf(" %d / %d",golem.pv,golem.pv_max);
        			break;
        		case 11 :
        			printf(" %d / %d",araignee_geante.pv,araignee_geante.pv_max);
        			break;
        		case 12 :
        			printf(" %d / %d",licorne.pv,licorne.pv_max);
        			break;
        		case 13 :
        			printf(" %d / %d",geant.pv,geant.pv_max);
        			break;
        		case 14 :
        			printf(" %d / %d",sorcier.pv,sorcier.pv_max);
        			break;
        		case 15 :
        			printf(" %d / %d",chien_loup.pv,chien_loup.pv_max);
        			break;
        		case 16 :
        			printf(" %d / %d",serpent_geant.pv,serpent_geant.pv_max);
        			break;
        	}
        	break;
        case 31 :
        	display(7,hero,0);
        	printf(" prend %d points de degats !\n",monstre);
        	break;
        case 32 :
        	display(7,0,monstre);
        	print(" se met en position defensive \n");
        	break;
        case 33:
        	print("Le minotaure fonce sur ");
        	display(7,hero,0);
        	printf("\n");
        	break;
        case 34:
        	printf("La goule esquive !\n");
        	break;
        case 35:
        	printf("Le zombie mord ")
        	display(7,hero,0);
        	printf(" ! Il souffre d'une infection !\n")
        	break;
        case 36:
        	printf("Le Vampire vole %d ");
        	display(7,hero,0);
        	printf(" de son sang et regagne %d pv !\n",monstre);
        	break;
        case 37:
        	printf("L'Orc entre dans une rage folle et frappe tout autour de lui !");
        	break;
        case 38:
        	printf("Le Troll entre dans une rage folle et frappe tout autour de lui !");
        	break;
        case 39:
        	printf("Le Gobelin esquive !\n");
        	break;
        case 40:
        	printf("L'Elfe Noir concentre son attaque sur ");
        	display(7,hero,0);
        	printf(" !\n");
        	break;
        case 41:
        	printf("Le Golem frappe ");
        	display(7,hero,0);
        	printf(" en plein sur la tête et l'etourdit !\n");
        	break;
        case 42:
        	printf("L'Araignee Geante crache son venin sur les heros qui sont pris de violentes douleurs\n"); //penser à faire les textes de poisons
        	break;
        case 43:
        	printf("La licorne utilise ses ailes cachées pour s'envoler et esquiver l'attaque !\n");
        	break;
        case 44:
        	printf("Le Geant entre dans une colere noire et frappe tout autour de lui !\n")
        	break;
        case 45:
        	printf("Le sorcier utilise un sort de soin sur ");
    		display(7,0,monstre);
    		printf(" !\n");
        	break;
        case 46:
        	printf("Le Chien-Loup, par l'odeur du sang augmente definitivement la puissance de ses attaques !\n");
        	break;
        case 47:
        	printf("Le Serpent Geant mord ");
        	display(7,hero,0);
        	printf(" ! Le venin parcourt son corps le blessant petit à petit !\n");
        	break;
        case 48:

        	break;

  	}
}    	
int monster_designated(){
    int test = 0;
	int monster_choosen = 0;
	display(28,0,0);
	while (test == 0){
		scanf("%d",&monster_choosen);
		if (monstre3 != 0){
       			if ((monster_choosen <= 3)&&(monster_choosen >= 1)){
       				test = 1;
       			}
       	}else if (monstre2 != 0){
       		if ((monster_choosen <= 2)&&(monster_choosen >= 1)){
       			test = 1;
       		}
       	}else{
       		if (monster_choosen == 1){
       			test = 1;
       		}
       	}
    }
    if (monster_choosen == 1){
    	return monstre1;
    }else if (monster_choosen == 2){
    	return monstre2;
    }else if (monster_choosen == 1){
    	return monstre3;
    }
}
int hero_designated(){
	int choice = 0;
	int test = 0;
	while (test == 0){
		choice = random_nbr(1,4);
		switch (choice){
			case 1:
				if (paladin.pv > 0){
					test = 1;
					return choice;
				}
				break;
			case 2:
				if (archer.pv > 0){
					test = 1;
					return choice;
				}
				break;
			case 3:
				if (mage.pv > 0){
					test = 1;
					return choice;
				}
				break;
			case 4:
				if (barbare.pv > 0){
					test = 1;
					return choice;
				}
				break;
		}
	}
}

hit_hero(hero){
	int oof = 0;
	int oof2 = 0;
	int oof3 = 0;
	int oof4 = 0;
	if (hero == 0){
		oof = damage_taken/paladin.defense;
		oof2 = damage_taken/archer.defense;
		oof3 = damage_taken/mage.defense;
		oof4 = damage_taken/barbare.defense;
		display(31,1,oof);
		display(31,2,oof2);
		display(31,3,oof3);
		display(31,4,oof4);
		paladin.pv -= oof;
		archer.pv -= oof2;
		mage.pv -= oof3;
		barbare.pv -= oof4;
	}else{
		switch (hero){
			case 1:
				oof = damage_taken/paladin.defense;
				paladin.pv -= oof;
				display(31,hero,oof);
				break;
			case 2:
				oof = damage_taken/archer.defense;
				archer.pv -= oof;
				display(31,hero,oof);
				break;
			case 3:
				oof = damage_taken/mage.defense;
				mage.pv -= oof;
				display(31,hero,oof);
				break;
			case 4:
				oof = damage_taken/barbare.defense;
				barbare.pv -= oof;
				display(31,hero,oof);
				break;
		}
	}
}
//
hit_monster(monstre){
	int oof = 0;
	switch(monstre){
		case 1:
			oof = damage_given/minotaure.defense;
 			minotaure.pv -= oof;
 			display(29,oof,monstre);
        	break;
        case 2:
        	oof = damage_given/goule.defense;
            goule.pv -= oof;
            display(29,oof,monstre);
        	break;
        case 3: 
        	oof = damage_given/zombie.defense;
            zombie.pv -= oof;
            display(29,oof,monstre);
        	break;
        case 4:
        	oof = damage_given/vampire.defense;
            vampire.pv -= oof;
            display(29,oof,monstre);
        	break;
        case 5: 
        	oof = damage_given/squelette.defense;
            squelette.pv -= oof;
            display(29,oof,monstre);
        	break;
        case 6: 
        	oof = damage_given/orc.defense;
            orc.pv -= oof;
            display(29,oof,monstre);
        	break;
        case 7: 
        	oof = damage_given/troll.defense;
            troll.pv -= oof;
            display(29,oof,monstre);
        	break;
        case 8:
        	oof = damage_given/gobelin.defense;
            gobelin.pv -= oof;
            display(29,oof,monstre);
        	break;
        case 9: 
        	oof = damage_given/elfe_noir.defense;
            elfe_noir.pv -= oof;
            display(29,oof,monstre);
        	break;
        case 10:
        	oof = damage_given/golem.defense;
            golem.pv -= oof;
            display(29,oof,monstre);
        	break;
        case 11:
        	oof = damage_given/araignee_geante.defense;
            araignee_geante.pv -= oof;
            display(29,oof,monstre);
        	break;
        case 12:
        	oof = damage_given/licorne.defense;
            licorne.pv -= oof;
            display(29,oof,monstre);
        	break;
        case 13: 
        	oof = damage_given/geant.defense;
            geant.pv -= oof;
            display(29,oof,monstre);
        	break;
        case 14: 
        	oof = damage_given/sorcier.defense;
            sorcier.pv -= oof;
            display(29,oof,monstre);
        	break;
        case 15: 
        	oof = damage_given/chien_loup.defense;
            chien_loup.pv -= oof;
            display(29,oof,monstre);
        	break;
        case 16:
        	oof = damage_given/serpent_geant.defense;
            serpent_geant.pv -= oof;
            display(29,oof,monstre);
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
    				monstre = monster_designated();
    				damage_given = paladin.atk;
    				display(6,hero,monstre);
    				hit_monster(monstre);
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
    				monstre = monster_designated();
    				damage_given = archer.atk;
    				display(6,hero,monstre);
    				hit_monster(monstre);
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
    				monstre = monster_designated();
    				damage_given = archer.atk * archer.spe2;
    				archer_spe2(monstre);
    				display(13,0,monstre);
    				hit_monster(monstre);
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
    				monstre = monster_designated();
    				damage_given = mage.atk;
    				display(6,hero,monstre);
    				hit_monster(monstre);
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
    				monstre = monster_designated();
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
    				monstre = monster_designated();
    				damage_given = barbare.atk;
    				display(6,hero,monstre);
    				hit_monster(monstre);
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
    				monstre = monster_designated();
    				damage_given = barbare.atk * barbare.spe1;
    				display(18,0,monstre);
    				hit_monster(monstre);
    				mp -= 3;
    				return 1;
    				break;
    			case 4:
    				//rage
    				monstre = monster_designated();
    				mp -= 6;
    				damage_given = barbare.atk * barbare.spe2;
    				display(19,0,monstre);
    				hit_monster(monstre);
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

//Applique le choix des monstres la valeur de retour nous indique par combien on divise l'attaque reçue, lors de la défense c'est 4 sinon c'est 1 pour ne pas changer la valeur de l'attaque
int choice_m(monstre,choix) {
	int hero = 0;
	switch (monstre){
    case 1:
        switch(choix){
            case 1:
                //attaques
                damage_taken = minotaure.atk;
                hit_hero(0);
                return 1;
                break;
            case 2:
                //défense
                damage_taken = 0;
                display(32,0,monstre);
                return 4;
                break;
            case 3:
                //attaque spé
                hero = hero_designated();
                damage_taken = minotaure.atk * cumul(); //multiplie l'attaque par le nombre de hero encore en vie
                hit_hero(hero);
                minotaure.mp -= 8;
                display(34,hero,0);
                return 1;
                break;
        }
    case 2:
        switch(choix){
            case 1:
                //attaques
                damage_taken = goule.atk;
                hit_hero(0);
                return 1;
                break;
            case 2:
                //défense
                damage_taken = 0;
                display(32,0,monstre);
                break;
            case 3:
                //attaque spé
            	display(34,0,0);
            	goule.mp -= 3;
                return 1000
                break;
        }
    case 3:
        switch(choix){
            case 1:
                //attaques
                damage_taken = zombie.atk;
                hit_hero(0);
                return 1;
                break;
            case 2:
                //défense
                damage_taken = 0;
                display(32,0,monstre);
                return 4;
                break;
            case 3:
                //attaque spé
            	hero = hero_designated();
            	switch (hero){
            		case 1 :
            			paladin.poison = zombie.spe1;
            			break;
            		case 2 :
            			archer.poison = zombie.spe1;
            			break;
            		case 3 :
            			mage.poison = zombie.spe1;
            			break;
            		case 4 :
            			barbare.poison = zombie.spe1;
            			break;
            	}
            	damage_taken = zombie.atk;
            	hit_hero(hero);
                display(35,hero,0);
                zombie.mp -= 5;
                return 1;
                break;
        }
    case 4:
        switch(choix){
            case 1:
                //attaques
                damage_taken = vampire.atk;
                hit_hero(0);
                return 1;
                break;
            case 2:
                //défense
                damage_taken = 0;
                display(32,0,monstre);
                return 4;
                break;
            case 3:
                //attaque spé
            	hero = hero_designated();
                damage_taken = vampire.spe1;
                hit_hero(hero);
                vampire.pv = vampire.pv + vampire.spe1;
                display(36,hero,vampire.spe1);
                vampire.mp -= 6;
                return 1;
                break;
        }
    case 5:
        switch(choix){
            case 1:
                //attaques
                damage_taken = squellette.atk;
                hit_hero(0);
                return 1;
                break;
            case 2:
                //défense
                damage_taken = 0;
                display(32,0,monstre);
                return 4;
                break;
        }
    case 6:
        switch(choix){
            case 1:
                //attaques
                damage_taken = orc.atk;
                hit_hero(0);
                return 1;
                break;
            case 2:
                //défense
                damage_taken = 0;
                display(32,0,monstre);
                return 4;
                break;
            case 3:
                //attaque spé
                damage_taken = orc.atk * orc.spe1;
                hit_hero(0);
                display(37,0,0);
                orc.mp -= 5;
                return 1;
                break;
        }
    case 7:
        switch(choix){
            case 1:
                //attaques
                damage_taken = troll.atk;
                hit_hero(0);
                return 1;
                break;
            case 2:
                //défense
                damage_taken = 0;
                display(32,0,monstre);
                return 4;
                break;
            case 3:
                //attaque spé
                damage_taken = troll.atk * troll.spe1;
                hit_hero(0);
                display(38,0,0);
                troll.mp -= 5;
                return 1;
                break;
        }
    case 8:
        switch(choix){
            case 1:
                //attaques
                damage_taken = goblin.atk;
                hit_hero(0);
                return 1;
                break;
            case 2:
                //défense
                damage_taken = 0;
                display(32,0,monstre);
                return 4;
                break;
            case 3:
                //attaque spé
            	display(39,0,0);
            	gobelin.mp -= 3;
                return 1000
                break;
        }
    case 9:
        switch(choix){
            case 1:
                //attaques
                damage_taken = elfe_noir.atk;
                hit_hero(0);
                return 1;
                break;
            case 2:
                //défense
                damage_taken = 0;
                display(32,0,monstre);
                return 4;
                break;
            case 3:
                //attaque spé
                hero = hero_designated();
                damage_taken = elfe_noir.atk * cumul(); // nombre de hero restant
                hit_hero(hero);
                display(40,hero,0);
                elfe_noir.mp -= 6;
                break;
        }
    case 10:
        switch(choix){
            case 1:
                //attaques
                damage_taken = golem.atk;
                hit_hero(0);
                return 1;
                break;
            case 2:
                //défense
                damage_taken = 0;
                display(32,0,monstre);
                return 4;
                break;
            case 3:
                //attaque spé
            	hero = hero_designated();
            	switch (hero){
            		case 1 :
            			paladin.stun = golem.spe1;
            			break;
            		case 2 :
            			archer.stun = golem.spe1;
            			break;
            		case 3 :
            			mage.stun = golem.spe1;
            			break;
            		case 4 :
            			barbare.stun = golem.spe1;
            			break;
            	}
            	damage_taken = golem.atk;
            	hit_hero(hero);
             	display(41,hero,0);
             	golem.mp -= 4;
                break;
        }
    case 11:
        switch(choix){
            case 1:
                //attaques
                damage_taken = araignee_geante.atk;
                hit_hero(0);
                return 1;
                break;
            case 2:
                //défense
                damage_taken = 0;
                display(32,0,monstre);
                return 4;
                break;
            case 3:
                //attaque spé
            	paladin.poison = araignee_geante.spe1;
            	archer.poison = araignee_geante.spe1;
            	mage.poison = araignee_geante.spe1;
            	barbare.poison = araignee_geante.spe1;
            	display(42,0,0);
                araignee_geante.mp -= 5;
                break;
        }
    case 12:
        switch(choix){
            case 1:
                //attaques
                damage_taken = licorne.atk;
                hit_hero(0);
                return 1;
                break;
            case 2:
                //défense
                damage_taken = 0;
                display(32,0,monstre);
                return 4;
                break;
            case 3:
                //attaque spé
            	display(43,0,0);
            	licorne.mp -= 3;
                return 1000
                break;
        }
        case 13:
        switch(choix){
            case 1:
                //attaques
                damage_taken = geant.atk;
                hit_hero(0);
                return 1;
                break;
            case 2:
                //défense
                damage_taken = 0;
                display(32,0,monstre);
                return 4;
                break;
            case 3:
                //attaque spé
                damage_taken = geant.atk * 2; //degats de zone sup
                geant.mp -= 6;
                display(44,0,0);
                break;
        }
    case 14:
        switch(choix){
            case 1:
                //attaques
                damage_taken = sorcier.atk;
                hit_hero(0);
                return 1;
                break;
            case 2:
                //défense
                damage_taken = 0;
                display(32,0,monstre);
                return 4;
                break;
            case 3:
                //attaque spé
                 monstre = monster_designated();
                 switch (monstre){
                 	case 1:
                 		minotaure.pv += minotaure.pv_max/4;
                 		break;
                 	case 2:
                 		goule.pv += goule.pv_max/4;
                 		break;
                 	case 3:
                 		zombie.pv += zombie.pv_max/4;
                 		break;
                 	case 4:
                 		vampire.pv += vampire.pv_max/4;
                 		break;
                 	case 5:
                 		squelette.pv += squelette.pv_max/4;
                 		break;
                 	case 6:
                 		orc.pv += orc.pv_max/4;
                 		break;
                 	case 7:
                 		troll.pv += troll.pv_max/4;
                 		break;
                 	case 8:
                 		gobelin.pv += gobelin.pv_max/4;
                 		break;
                 	case 9:
                 		elfe_noir.pv += elfe_noir.pv_max/4;
                 		break;
                 	case 10:
                 		golem.pv += golem.pv_max/4;
                 		break;
                 	case 11:
                 		araignee_geante.pv += araignee_geante.pv_max/4;
                 		break;
                 	case 12:
                 		licorne.pv += licorne.pv_max/4;
                 		break;
                 	case 13:
                 		geant.pv += geant.pv_max/4;
                 		break;
                 	case 14:
                 		sorcier.pv += sorcier.pv_max/4;
                 		break;
                 	case 15:
                 		chien_loup.pv += chien_loup.pv_max/4;
                 		break;
                 	case 16:
                 		serpent_geant.pv += serpent_geant.pv_max/4;
                 		break;
                 }
                display(45,0,monstre);
                sorcier.mp -= 5;
                break;
        }
    case 15:
        switch(choix){
            case 1:
                //attaques
                damage_taken = chien_loup.atk;
                hit_hero(0);
                return 1;
                break;
            case 2:
                //défense
                damage_taken = 0;
                display(32,0,monstre);
                return 4;
                break;
            case 3:
                //attaque spé
                chien_loup.atk = chien_loup.atk * chien_loup.spe1;
                display(46,0,0);
                chien_loup.mp -= 6;
                break;
        }
    case 16:
        switch(choix){
            case 1:
                //attaques
                damage_taken = serpent_geant.atk;
                hit_hero(0);
                return 1;
                break;
            case 2:
                //défense
                damage_taken = 0;
                display(32,0,monstre);
                return 4;
                break;
            case 3:
                hero = hero_designated();
                switch(hero){
                	case 1:
                		paladin.poison = serpent_geant.spe1;
                		break;
                	case 2:
                		archer.poison = serpent_geant.spe1;
                		break;
                	case 3:
                		mage.poison = serpent_geant.spe1;
                		break;
                	case 4:
                		barbare.poison = serpent_geant.spe1;
                		break;
                }
                damage_taken = serpent_geant.atk;
                display(47,hero,0);
                serpent_geant.mp -= 8;
                break;
        }
	}
}

//attribution de mana en fin de tour
int cumul(){
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
	return cumul;
}

//Choix d'un hero et de son action
int choose(){
	int hero = 0;
	int monstre = 0;
	int choix = 0;
    int test = 0;
    int hero_disponibles[4];
    hero_disponibles[0] = 1;
    hero_disponibles[1] = 1;
    hero_disponibles[2] = 1;
    hero_disponibles[3] = 1;

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
            paladin.defense = choice_p(hero,monstre,choix);
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
            archer.defense = choice_p(hero,monstre,choix);
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
            mage.defense = choice_p(hero,monstre,choix);
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
            barbare.defense = choice_p(hero,monstre,choix);
            break;
    }
}

choose_m(monster){
	switch(monster){
		case 1:
			test = 0;
			while (test == 0){
				choix = random_nbr(1,3);
				if (minotaure.mp >= 8){
					test = 1;
				}else if ((choix == 1) || (choix == 2)){
					test = 1;
				}
			}
			minotaure.defense = choice_m(monster,choix);
			break;
		case 2:
			test = 0;
			while (test == 0){
				choix = random_nbr(1,3);
				if (goule.mp >= 3){
					test = 1;
				}else if ((choix == 1) || (choix == 2)){
					test = 1;
				}
			}
			goule.defense = choice_m(monster,choix);
			break;
		case 3:
			test = 0;
			while (test == 0){
				choix = random_nbr(1,3);
				if (zombie.mp >= 5){
					test = 1;
				}else if ((choix == 1) || (choix == 2)){
					test = 1;
				}
			}
			zombie.defense = choice_m(monster,choix);
			break;
		case 4:
			test = 0;
			while (test == 0){
				choix = random_nbr(1,3);
				if (vampire.mp >= 6){
					test = 1;
				}else if ((choix == 1) || (choix == 2)){
					test = 1;
				}
			}
			vampire.defense = choice_m(monster,choix);
			break;
		case 5:
			test = 0;
			choix = random_nbr(1,2);
			squelette.defense = choice_m(monster,choix);
			break;
		case 6:
			test = 0;
			while (test == 0){
				choix = random_nbr(1,3);
				if (orc.mp >= 5){
					test = 1;
				}else if ((choix == 1) || (choix == 2)){
					test = 1;
				}
			}
			orc.defense = choice_m(monster,choix);
			break;
		case 7:
			test = 0;
			while (test == 0){
				choix = random_nbr(1,3);
				if (troll.mp >= 5){
					test = 1;
				}else if ((choix == 1) || (choix == 2)){
					test = 1;
				}
			}
			troll.defense = choice_m(monster,choix);
			break;
		case 8:
			test = 0;
			while (test == 0){
				choix = random_nbr(1,3);
				if (gobelin.mp >= 3){
					test = 1;
				}else if ((choix == 1) || (choix == 2)){
					test = 1;
				}
			}
			gobelin.defense = choice_m(monster,choix);
			break;
		case 9:
			test = 0;
			while (test == 0){
				choix = random_nbr(1,3);
				if (elfe_noir.mp >= 6){
					test = 1;
				}else if ((choix == 1) || (choix == 2)){
					test = 1;
				}
			}
			elfe_noir.defense = choice_m(monster,choix);
			break;
		case 10:
			test = 0;
			while (test == 0){
				choix = random_nbr(1,3);
				if (golem.mp >= 4){
					test = 1;
				}else if ((choix == 1) || (choix == 2)){
					test = 1;
				}
			}
			golem.defense = choice_m(monster,choix);
			break;
		case 11:
			test = 0;
			while (test == 0){
				choix = random_nbr(1,3);
				if (araignee_geante.mp >= 5){
					test = 1;
				}else if ((choix == 1) || (choix == 2)){
					test = 1;
				}
			}
			araignee_geante.defense = choice_m(monster,choix);
			break;
		case 12:
			test = 0;
			while (test == 0){
				choix = random_nbr(1,3);
				if (licorne.mp >= 3){
					test = 1;
				}else if ((choix == 1) || (choix == 2)){
					test = 1;
				}
			}
			licorne.defense = choice_m(monster,choix);
			break;
		case 13:
			test = 0;
			while (test == 0){
				choix = random_nbr(1,3);
				if (geant.mp >= 6){
					test = 1;
				}else if ((choix == 1) || (choix == 2)){
					test = 1;
				}
			}
			geant.defense = choice_m(monster,choix);
			break;
		case 14:
			test = 0;
			while (test == 0){
				choix = random_nbr(1,3);
				if (sorcier.mp >= 5){
					test = 1;
				}else if ((choix == 1) || (choix == 2)){
					test = 1;
				}
			}
			sorcier.defense = choice_m(monster,choix);
			break;
		case 15:
			test = 0;
			while (test == 0){
				choix = random_nbr(1,3);
				if (chien_loup.mp >= 6){
					test = 1;
				}else if ((choix == 1) || (choix == 2)){
					test = 1;
				}
			}
			chien_loup.defense = choice_m(monster,choix);
			break;
		case 16:
			test = 0;
			while (test == 0){
				choix = random_nbr(1,3);
				if (serpent_geant.mp >= 8){
					test = 1;
				}else if ((choix == 1) || (choix == 2)){
					test = 1;
				}
			}
			serpent_geant.defense = choice_m(monster,choix);
			break;
	}
}
//chaque tour
int tour(manche){
	//cycles de combats différents en fonction du nombre de monstre (précedement défini par le nombre de manches passées)
    if (manche <= 5){
    	//2 d'affil
    	choose();
    	choose();
    	//riposte
    	choose_m(monster1);
    }else if (manche <= 9){
    	//hero
    	choose();
    	//monstre
    	choose_m(monster2);
    	//hero
    	choose();
    	//monstre
    	choose_m(monster3);
    }else{
    	//hero
    	choose();
    	//monstre
    	choose_m(monster1);
    	//hero
    	choose();
    	//monstre
    	choose_m(monster2);
    	//monstre
    	choose_m(monster3);
    }
    //application des effets (poison + countdown)
}

int main() {
	srand(time(NULL));
	int test = 1;
	int tours = 0;
    //boucle des manches

    for (int manche = 1; manche < 11; manche++){
 		//debut manche
 		test = 1;
    	select_monstre(manche);
    	tours = 0;
    	heros paladin = {150,150,30,0,0,30,0.2};
    	heros archer = {80,80,30,0,0,3,40};
    	heros mage = {100,100,30,0,0,10,4};
    	heros barbare = {120,120,50,0,0,1.5,2};

    	//boucle des tours
    	while (test != 0)/*||(Tous les monstres en vie)*/{
    	tours++;
    		if (tours < 10){
    			display(27,5,tours);
    		}else{
    			display(27,2,tours);
    		}
    		tour(manche);
    	    //compte le nombre de heros en vie et attribue du mana en conséquence
    	    mana += cumul();
    	    test = cumul();
    	}
    }
  return 0;
}