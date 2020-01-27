/*
Préface : 
Le code fonctionne mais n'a été testé que sur un compileur de C en ligne
Un seul bug trouvé mais inexpliquable qui consiste en des opérations qui ne devraient jamais avoir lieu à ce moment, je n'ai pas trouvé la cause de ce bug mais le compilateur freeze avant que le bug n'apparaisse

On peut affronter plusieurs monstres à la fois, mais pas avant d'avoir passer la 5ème manche puis le niveau 10 final nous permet même d'en affronter 3 en même temps
l'xp arrive lorsque l'on tue un monstre (plus d'xp pour celui qui l'achève)


Il reste à :
-modifier les valeurs des statistiques des monstres dans les var globales ainsi que dans select_monstre
-modifier les valeurs d'upgrade des compétences spéciales des heros dans amelioration()

Aide à la navigation dans le code : fonctions et fonctions qu'elles contiennent
ps : (hors display() qui est quasiment partout)

main()
	select_monstre()
		random_nbr()
	tour()
		choose()
			cumul()
			choice_p()
				hit_monster()
					death()
						side_xp()
							xp()
								amelioration()
					end_m()
				monster_designated()
				paladin_spe1()
				paladin_spe2()
				archer_spe2()
				mage_spe1()
				mage_spe2()
		choose_m()
			random_nbr()
			choice_m()
				hit_hero()
				hero_designated()
					random_nbr()
				monster_designated()
		poison()
	cumul()
	monstre_mp()
*/
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

typedef struct Heros {
	int pv_max;
    int pv;
    int atk;
    int defense;
    int poison;
    int stun;
    int spe1;
    float spe2;
    int xp;
} heros;

typedef struct Monstres {
    int pv_max;
    int pv;
    int atk;
    int defense;
    int poison;
    int stun;
    int spe1;
    int mp;
} monstres;

heros paladin = {150,150,30,1,0,0,30,0.2,0};
heros archer = {80,80,30,1,0,0,3,40,0};
heros mage = {100,100,30,1,0,0,10,4,0};
heros barbare = {120,120,50,1,0,0,1.5,2,0};

monstres minotaure = {200, 200, 30, 1,0, 0, 30,0};
monstres goule = {200, 200, 30, 1,0, 0, 30,0};
monstres zombie = {200, 200, 30, 1,0, 0, 30,0};
monstres vampire = {200, 200, 30, 1,0, 0, 30,0};
monstres squelette = {200, 200, 30, 1,0, 0, 30,0};
monstres orc = {200, 200, 30, 1,0, 0, 30,0};
monstres troll = {200, 200, 30, 1,0, 0, 30,0};
monstres gobelin = {200, 200, 30, 1,0, 0, 30,0};
monstres elfe_noir = {200, 200, 30, 1,0, 0, 30,0};
monstres golem = {200, 200, 30, 1,0, 0, 30,0};
monstres araignee_geante = {200, 200, 30, 1,0, 0, 30,0};
monstres licorne = {200, 200, 30, 1,0, 0, 30,0};
monstres geant = {200, 200, 30, 1,0, 0, 30,0};
monstres sorcier = {200, 200, 30, 1,0, 0, 30,0};
monstres chien_loup = {200, 200, 30, 1,0, 0, 30,0};
monstres serpent_geant = {200, 200, 30, 1,0, 0, 30,0};

//sert lors de la selection du hero dans choose()
int hero_disponibles[4];

int random_nbr (int min, int max){
	int nbr = 0;
	nbr = (min + (rand () % (max + 1 - min)));
	return nbr;
}

//Choix du monstre selon la progression du joueur
void select_monstre(int manche){
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
void display(int code, int hero, int monstre){
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
            printf("[1] Attaque --- 0 mp \n[2] Defense --- 0 mp \n[3] Esquive --- 1 mp \n[4] Fleche empoisonee --- 10 mp (Probabilite de succes : 50%%) \n");
            break;
        case 4 :
            //mage
            printf("[1] Attaque --- 0 mp \n[2] Defense --- 0 mp \n[3] Guerison --- 5 mp \n[4] Somnifere --- 5 mp\n");
            break;
        case 5 :
            //barbare
            printf("[1] Attaque --- 0 mp \n[2] Defense --- 0 mp \n[3] Frappe sanglante --- 3 mp \n[4] Rage --- 6 mp (Probabilite de prendre cher : 50%%)\n");
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
        	if (monstre == 0){
        		display(7,0,monstre);
        		printf(" se met en position defensive \n");
        	}else{
        		display(7,0,monstre);
        		printf(" lance une attaque ! \n");
        	}
        	break;
        case 33:
        	printf("Le Minotaure fonce sur ");
        	display(7,hero,0);
        	printf("\n");
        	break;
        case 34:
        	if (monstre == 0){
        		printf("La Goule esquive !\n");
        	}else{
        		printf("Le Squelette esquive !\n");
        	}
        	break;
        case 35:
        	printf("Le zombie mord ");
        	display(7,hero,0);
        	printf(" ! Il souffre d'une infection !\n");
        	break;
        case 36:
        	printf("Le Vampire vole %d ",monstre);
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
        	printf("Le Geant entre dans une colere noire et frappe tout autour de lui !\n");
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
        	display(7,hero,0);
        	printf(" n'est pas disponible\n");
        	break;
        case 49:
        	display(7,hero,0);
        	printf(" gagne de l'xp : ");
            switch(monstre){
                case 1:
                    printf("▓░░░░░░░░░\n");
                    break;
                case 2:
                    printf("▓▓░░░░░░░░\n");
                    break;
                case 3:
                    printf("▓▓▓░░░░░░░\n");
                    break;
                 case 4:
                    printf("▓▓▓▓░░░░░░\n");
                    break;
                case 5:
                    printf("▓▓▓▓▓░░░░░\n");
                    break;
                case 6:
                    printf("▓▓▓▓▓▓░░░░\n");
                    break;
                case 7:
                    printf("▓▓▓▓▓▓▓░░░\n");
                    break;
                case 8:
                    printf("▓▓▓▓▓▓▓▓░░\n");
                    break;
                case 9:
                    printf("▓▓▓▓▓▓▓▓▓░\n");
                    break;
                case 10:
                    printf("▓▓▓▓▓▓▓▓▓▓\n");
                    break;
            }
        	break;
       	case 50:
       		switch (hero){
       			case 1:
       				printf("Le Paladin monte d'un niveau !\nAmeliorer une competence speciale : [1] Soins - [2] Resurection\n");
       				break;
       			case 2:
       				printf("L'Archer monte d'un niveau !\nAmeliorer une competence speciale : [1] Esquive - [2] Fleche Empoisone\n");
       				break;
       			case 3:
       				printf("Le Mage monte d'un niveau !\nAmeliorer une competence speciale : [1] Guerison - [2] Somnifere\n");
       				break;
       			case 4:
       				printf("Le Barbare monte d'un niveau !\nAmeliorer une competence speciale : [1] Frappe Sanglante - [2] Rage\n");
       				break;
       		}
       		break;
       	case 51 :
       		printf("-------- Debut d'une Nouvelle Manche --------\n----------- Manche manche %d / 10 ------------\n",hero);
       		break;
       	case 52 :
       		printf("Vous avez deja utilise ");
       		display(7,hero,0);
       		printf(" ce tour !\n");
       		break;
  	}
}
void amelioration(int hero){
	int choix = 0;
	display(50,hero,0);
    scanf("%d",&choix);
	switch (hero){
    case 1:
        if (choix == 1){
            paladin.spe1 = paladin.spe1 * 2;
        }else{
            paladin.spe2 += 0.2;
        }
        paladin.xp = 0;
        break;
    case 2:
        if (choix == 1){
            archer.spe1++;
        }else{
            archer.spe2++;
        }
        archer.xp = 0;
        break;
    case 3:
        if (choix == 1){
            mage.spe1++;
        }else{
            mage.spe2++;
        }
        mage.xp = 0;
        break;
    case 4:
        if (choix == 1){
            barbare.spe1++;
        }else{
            barbare.spe2++;
        }
        barbare.xp = 0;
        break;
    }
}
void xp(int hero){
	switch(hero){
		case 1:
			switch (paladin.xp){
				case 1:
					display(49,hero,1);
					break;
				case 2:
					display(49,hero,2);
					break;
				case 3:
					display(49,hero,3);
					break;
				case 4:
					display(49,hero,4);
					break;
				case 5:
					display(49,hero,5);
					break;
				case 6:
					display(49,hero,6);
					break;
				case 7:
					display(49,hero,7);
					break;
				case 8:
					display(49,hero,8);
					break;
				case 9:
					display(49,hero,9);
					break;
				case 10:
					display(49,hero,10);
					amelioration(hero);
					break;
			}
			break;
		case 2:
			switch (archer.xp){
				case 1:
					display(49,hero,1);
					break;
				case 2:
					display(49,hero,2);
					break;
				case 3:
					display(49,hero,3);
					break;
				case 4:
					display(49,hero,4);
					break;
				case 5:
					display(49,hero,5);
					break;
				case 6:
					display(49,hero,6);
					break;
				case 7:
					display(49,hero,7);
					break;
				case 8:
					display(49,hero,8);
					break;
				case 9:
					display(49,hero,9);
					break;
				case 10:
					display(49,hero,10);
					amelioration(hero);
					break;
			}
			break;
		case 3:
			switch (mage.xp){
				case 1:
					display(49,hero,1);
					break;
				case 2:
					display(49,hero,2);
					break;
				case 3:
					display(49,hero,3);
					break;
				case 4:
					display(49,hero,4);
					break;
				case 5:
					display(49,hero,5);
					break;
				case 6:
					display(49,hero,6);
					break;
				case 7:
					display(49,hero,7);
					break;
				case 8:
					display(49,hero,8);
					break;
				case 9:
					display(49,hero,9);
					break;
				case 10:
					display(49,hero,10);
					amelioration(hero);
					break;
			}
			break;
		case 4:
			switch (barbare.xp){
				case 1:
					display(49,hero,1);
					break;
				case 2:
					display(49,hero,2);
					break;
				case 3:
					display(49,hero,3);
					break;
				case 4:
					display(49,hero,4);
					break;
				case 5:
					display(49,hero,5);
					break;
				case 6:
					display(49,hero,6);
					break;
				case 7:
					display(49,hero,7);
					break;
				case 8:
					display(49,hero,8);
					break;
				case 9:
					display(49,hero,9);
					break;
				case 10:
					display(49,hero,10);
					amelioration(hero);
					break;
			}
			break;
    }
}
void side_xp(int hero){
	switch (hero){
        	case 1:
        		archer.xp += 2;
        		mage.xp += 2;
        		barbare.xp += 2;
        		break;
        	case 2:
        		paladin.xp += 2;
        		mage.xp += 2;
        		barbare.xp += 2;
        		break;
        	case 3:
        		paladin.xp += 2;
        		archer.xp += 2;
        		barbare.xp += 2;
        		break;
        	case 4:
        		paladin.xp += 2;
        		archer.xp += 2;
        		mage.xp += 2;
        		break;
    }
    xp(1);
    xp(2);
    xp(3);
    xp(4);
}
//gere les morts chez les monstres et donne l'xp aux heros
int death(int pv, int hero){
    if(pv<=0){
        switch (hero){
        	case 1:
        		paladin.xp += 4;
        		side_xp(hero);
        		break;
        	case 2:
        		archer.xp += 4;
        		side_xp(hero);
        		break;
        	case 3:
        		mage.xp += 4;
        		side_xp(hero);
        		break;
        	case 4:
        		barbare.xp += 4;
        		side_xp(hero);
        		break;
        }
        return 1;  
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

void hit_hero(int hero){
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
void end_m(int mort, int monstre){
	if (mort == 1){
		if (monstre1 == monstre){
			monstre1 = 0;
		}else if (monstre2 == monstre){
			monstre2 = 0;
		}else if (monstre3 == monstre){
			monstre3 = 0;
		}
	}
}
void hit_monster(int monstre, int hero){
	int oof = 0;
	int mort = 0;
	switch(monstre){
		case 1:
			oof = damage_given/minotaure.defense;
 			minotaure.pv -= oof;
 			display(29,oof,monstre);
            mort = death(minotaure.pv,hero);
 			end_m(mort,monstre);
        	break;
        case 2:
        	oof = damage_given/goule.defense;
            goule.pv -= oof;
            display(29,oof,monstre);
            mort = death(goule.pv,hero);
            end_m(mort,monstre);
        	break;
        case 3: 
        	oof = damage_given/zombie.defense;
            zombie.pv -= oof;
            display(29,oof,monstre);
            mort = death(zombie.pv,hero);
            end_m(mort,monstre);
        	break;
        case 4:
        	oof = damage_given/vampire.defense;
            vampire.pv -= oof;
            display(29,oof,monstre);
            mort = death(vampire.pv,hero);
            end_m(mort,monstre);
        	break;
        case 5: 
        	oof = damage_given/squelette.defense;
            squelette.pv -= oof;
            display(29,oof,monstre);
            mort = death(squelette.pv,hero);
            end_m(mort,monstre);
        	break;
        case 6: 
        	oof = damage_given/orc.defense;
            orc.pv -= oof;
            display(29,oof,monstre);
            mort = death(orc.pv,hero);
            end_m(mort,monstre);
        	break;
        case 7: 
        	oof = damage_given/troll.defense;
            troll.pv -= oof;
            display(29,oof,monstre);
            mort = death(troll.pv,hero);
            end_m(mort,monstre);
        	break;
        case 8:
        	oof = damage_given/gobelin.defense;
            gobelin.pv -= oof;
            display(29,oof,monstre);
            mort = death(gobelin.pv,hero);
            end_m(mort,monstre);
        	break;
        case 9: 
        	oof = damage_given/elfe_noir.defense;
            elfe_noir.pv -= oof;
            display(29,oof,monstre);
            mort = death(elfe_noir.pv,hero);
            end_m(mort,monstre);
        	break;
        case 10:
        	oof = damage_given/golem.defense;
            golem.pv -= oof;
            display(29,oof,monstre);
            mort = death(golem.pv,hero);
            end_m(mort,monstre);
        	break;
        case 11:
        	oof = damage_given/araignee_geante.defense;
            araignee_geante.pv -= oof;
            display(29,oof,monstre);
            mort = death(araignee_geante.pv,hero);
            end_m(mort,monstre);
        	break;
        case 12:
        	oof = damage_given/licorne.defense;
            licorne.pv -= oof;
            display(29,oof,monstre);
            mort = death(licorne.pv,hero);
            end_m(mort,monstre);
            break;
        case 13: 
        	oof = damage_given/geant.defense;
            geant.pv -= oof;
            display(29,oof,monstre);
            mort = death(geant.pv,hero);
            end_m(mort,monstre);
        	break;
        case 14: 
        	oof = damage_given/sorcier.defense;
            sorcier.pv -= oof;
            display(29,oof,monstre);
            mort = death(sorcier.pv,hero);
            end_m(mort,monstre);
        	break;
        case 15: 
        	oof = damage_given/chien_loup.defense;
            chien_loup.pv -= oof;
            display(29,oof,monstre);
            mort = death(chien_loup.pv,hero);
            end_m(mort,monstre);
        	break;
        case 16:
        	oof = damage_given/serpent_geant.defense;
            serpent_geant.pv -= oof;
            display(29,oof,monstre);
            mort = death(serpent_geant.pv,hero);
            end_m(mort,monstre);
        	break;
    }
}


void paladin_spe1(){
	int test = 0;
   	int choix_paladin = 0;
   	while (test == 0){
   		display(9,0,0);
   		scanf("%d",&choix_paladin);
   		if (choix_paladin == 2){
    		if (archer.pv > 0){
    			archer.pv += paladin.spe1;
    			test = 1;
    		}
    	}else if (choix_paladin == 3){
    		if (mage.pv > 0){
    			mage.pv += paladin.spe1;
    			test = 1;
    		}
    	}else if (choix_paladin == 4){
    		if (barbare.pv > 0){
    			barbare.pv += paladin.spe1;
    			test = 1;
    		}
    	}else{
    		paladin.pv += paladin.spe1;
    		test = 1;
    	}	
    }
}
void paladin_spe2(){
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
void archer_spe2(int monstre){
	switch (monstre){
        case 1:
            minotaure.poison = 1;
            break;
        case 2:
            goule.poison = 1;
            break;
        case 3:
            zombie.poison = 1;
            break;
        case 4:
            vampire.poison = 1;
            break;
        case 5:
            squelette.poison = 1;
            break;
        case 6:
            orc.poison = 1;
            break;
        case 7:
            troll.poison = 1;
            break;
        case 8:
            gobelin.poison = 1;
            break;
        case 9:
            elfe_noir.poison = 1;
            break;
        case 10:
            golem.poison = 1;
            break;
        case 11:
            araignee_geante.poison = 1;
            break;
        case 12:
            licorne.poison = 1;
            break;
        case 13:
            geant.poison = 1;
            break;
        case 14:
            sorcier.poison = 1;
            break;
        case 15:
            chien_loup.poison = 1;
            break;
        case 16:
            serpent_geant.poison = 1;
            break;
    }
}
void mage_spe1(){
	int test = 0;
	int choix_mage = 0;
	display(14,0,0);
	scanf("%d",&choix_mage);
	while (test == 0){
		switch (choix_mage){
			case 1:
				paladin.pv += mage.spe1;
				paladin.poison = 0;
				paladin.stun = 0;
				test = 1;
				break;
			case 2:
				archer.pv += mage.spe1;
				archer.poison = 0;
				archer.stun = 0;
				test = 1;
				break;
			case 3:
				mage.pv += mage.spe1;
				mage.poison = 0;
				mage.stun = 0;
				test = 1;
				break;
			case 4:
				barbare.pv += mage.spe1;
				barbare.poison = 0;
				barbare.stun = 0;
				test = 1;
				break;
		}
	}
	display(15,choix_mage,0);
}
void mage_spe2(int monstre){
	switch (monstre){
		case 1:
			minotaure.stun = 2;
			break;
		case 2:
			goule.stun = 2;
			break;
		case 3:
			zombie.stun = 2;
			break;
		case 4:
			vampire.stun = 2;
			break;
		case 5:
			squelette.stun = 2;
			break;
		case 6:
			orc.stun = 2;
			break;
		case 7:
			troll.stun = 2;
			break;
		case 8:
			gobelin.stun = 2;
			break;
		case 9:
			elfe_noir.stun = 2;
			break;
		case 10:
			golem.stun = 2;
			break;
		case 11:
			araignee_geante.stun = 2;
			break;
		case 12:
			licorne.stun = 2;
			break;
		case 13:
			geant.stun = 2;
			break;
		case 14:
			sorcier.stun = 2;
			break;
		case 15:
			chien_loup.stun = 2;
			break;
		case 16:
			serpent_geant.stun = 2;
			break;
	}
}

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
    				hit_monster(monstre,hero);
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
    				hit_monster(monstre,hero);
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
    				hit_monster(monstre,hero);
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
    				hit_monster(monstre,hero);
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
    				hit_monster(monstre,hero);
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
    				hit_monster(monstre,hero);
    				mp -= 3;
    				return 1;
    				break;
    			case 4:
    				//rage
    				monstre = monster_designated();
    				mp -= 6;
    				damage_given = barbare.atk * barbare.spe2;
    				display(19,0,monstre);
    				hit_monster(monstre,hero);
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
int choice_m(int monstre, int choix) {
	int hero = 0;
	switch (monstre){
    case 1:
        switch(choix){
            case 1:
                //attaques
            	display(32,1,monstre);
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
                display(32,1,monstre);  
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
                return 1000;
                break;
        }
    case 3:
        switch(choix){
            case 1:
                //attaques
            	display(32,1,monstre);
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
            	display(32,1,monstre);
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
            	display(32,1,monstre);
                damage_taken = squelette.atk;
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
            	display(34,0,1);
            	squelette.mp -= 3;
                return 1000;
                break;
        }
    case 6:
        switch(choix){
            case 1:
                //attaques
            	display(32,1,monstre);
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
            	display(32,1,monstre);
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
            	display(32,1,monstre);
                damage_taken = gobelin.atk;
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
                return 1000;
                break;
        }
    case 9:
        switch(choix){
            case 1:
                //attaques
            	display(32,1,monstre);
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
            	display(32,1,monstre);
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
            	display(32,1,monstre);
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
            	display(32,1,monstre);
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
                return 1000;
                break;
        }
        case 13:
        switch(choix){
            case 1:
                //attaques
            	display(32,1,monstre);
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
            	display(32,1,monstre);
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
            	display(32,1,monstre);
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
            	display(32,1,monstre);
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

//Choix d'un hero et de son action
void choose(){
	int hero = 0;
	int monstre = 0;
	int choix = 0;
    int test = 0;
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
            switch(hero){
            	case 1:
            		if ((paladin.stun != 0)||(paladin.pv <= 0)){
            			display(48,hero,0);
            		}else{
            			hero_disponibles[0] = 0;
            			test = 1;
            		}
            		break;
            	case 2:
            		if ((archer.stun != 0)||(archer.pv <= 0)){
            			display(48,hero,0);
            		}else{
            			hero_disponibles[1] = 0;
            			test = 1;
            		}
            		break;
            	case 3:
            		if ((mage.stun != 0)||(mage.pv <= 0)){
            			display(48,hero,0);
            		}else{
            			hero_disponibles[2] = 0;
            			test = 1;
            		}
            		break;
            	case 4:
            		if ((barbare.stun != 0)||(barbare.pv <= 0)){
            			display(48,hero,0);
            		}else{
            			hero_disponibles[3] = 0;
            			test = 1;
            		}
            		break;
            }
        }else{
        	display(52,hero,0);
        }
        if (cumul() == 0){
        	break;
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
void choose_m(int monster){
	int choix = 0;
	int test = 0;
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
			choix = random_nbr(1,3);
			if (squelette.mp >= 3){
					test = 1;
				}else if ((choix == 1) || (choix == 2)){
					test = 1;
				}
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
void monstre_mp(int monstre){
	switch (monstre){
		case 1:
			minotaure.mp += 2;
			break;
		case 2:
			goule.mp += 2;
			break;
		case 3:
			zombie.mp += 2;
			break;
		case 4:
			vampire.mp += 2;
			break;
		case 5:
			squelette.mp += 2;
			break;
		case 6:
			orc.mp += 2;
			break;
		case 7:
			troll.mp += 2;
			break;
		case 8:
			gobelin.mp += 2;
			break;
		case 9:
			elfe_noir.mp += 2;
			break;
		case 10:
			golem.mp += 2;
			break;
		case 11:
			araignee_geante.mp += 2;
			break;
		case 12:
			licorne.mp += 2;
			break;
		case 13:
			geant.mp += 2;
			break;
		case 14:
			sorcier.mp += 2;
			break;
		case 15:
			chien_loup.mp += 2;
			break;
		case 16:
			serpent_geant.mp += 2;
			break;
	}
}
void poison(){
	//heros
	if (paladin.poison != 0){
		paladin.pv -= paladin.poison;
	}
	if (archer.poison != 0){
		archer.pv -= archer.poison;
	}
	if (mage.poison != 0){
		mage.pv -= mage.poison;
	}
	if (barbare.poison != 0){
		barbare.pv -= barbare.poison;
	}
	//stun
	if (paladin.stun != 0){
		paladin.stun--;
	}
	if (archer.stun != 0){
		archer.stun--;
	}
	if (mage.stun != 0){
		mage.stun--;
	}
	if (barbare.stun != 0){
		barbare.stun--;
	}
	//monstres
	if (minotaure.poison != 0){
		minotaure.pv -= minotaure.poison;
	}
	if (goule.poison != 0){
		goule.pv -= goule.poison;
	}
	if (zombie.poison != 0){
		zombie.pv -= zombie.poison;
	}
	if (vampire.poison != 0){
		vampire.pv -= vampire.poison;
	}
	if (squelette.poison != 0){
		squelette.pv -= squelette.poison;
	}
	if (orc.poison != 0){
		orc.pv -= orc.poison;
	}
	if (troll.poison != 0){
		troll.pv -= troll.poison;
	}
	if (gobelin.poison != 0){
		gobelin.pv -= gobelin.poison;
	}
	if (elfe_noir.poison != 0){
		elfe_noir.pv -= elfe_noir.poison;
	}
	if (golem.poison != 0){
		golem.pv -= golem.poison;
	}
	if (araignee_geante.poison != 0){
		araignee_geante.pv -= araignee_geante.poison;
	}
	if (licorne.poison != 0){
		licorne.pv -= licorne.poison;
	}
	if (geant.poison != 0){
		geant.pv -= geant.poison;
	}
	if (sorcier.poison != 0){
		sorcier.pv -= sorcier.poison;
	}
	if (chien_loup.poison != 0){
		chien_loup.pv -= chien_loup.poison;
	}
	if (serpent_geant.poison != 0){
		serpent_geant.pv -= serpent_geant.poison;
	}
	//stun
	if (minotaure.stun != 0){
		minotaure.stun--;
	}
	if (goule.stun != 0){
		goule.stun--;
	}
	if (zombie.stun != 0){
		zombie.stun--;
	}
	if (vampire.stun != 0){
		vampire.stun--;
	}
	if (squelette.stun != 0){
		squelette.stun--;
	}
	if (orc.stun != 0){
		orc.stun--;
	}
	if (troll.stun != 0){
		troll.stun--;
	}
	if (gobelin.stun != 0){
		gobelin.stun--;
	}
	if (elfe_noir.stun != 0){
		elfe_noir.stun--;
	}
	if (golem.stun != 0){
		golem.stun--;
	}
	if (araignee_geante.stun != 0){
		araignee_geante.stun--;
	}
	if (licorne.stun != 0){
		licorne.stun--;
	}
	if (geant.stun != 0){
		geant.stun--;
	}
	if (sorcier.stun != 0){
		sorcier.stun--;
	}
	if (chien_loup.stun != 0){
		chien_loup.stun--;
	}
	if (serpent_geant.stun != 0){
		serpent_geant.stun--;
	}
}

int cumul_m(){
	int cumul = 0;
	if (monstre1 != 0){
		cumul++;
	}
	if (monstre2 != 0){
		cumul++;
	}
	if (monstre3 != 0){
		cumul++;
	}
	return cumul;
}

//chaque tour
void tour(int manche){
	//cycles de combats différents en fonction du nombre de monstre (précedement défini par le nombre de manches passées)
    if (manche <= 5){
    	choose();
    	choose_m(monstre1);
    	choose();
    }else if (manche <= 9){
    	//hero
    	choose();
    	//monstre
    	choose_m(monstre1);
    	//hero
    	choose();
    	//monstre
    	choose_m(monstre2);
    }else{
    	//hero
    	choose();
    	//monstre
    	choose_m(monstre1);
    	//hero
    	choose();
    	//monstre
    	choose_m(monstre2);
    	//monstre
    	choose_m(monstre3);
    }
    //application des effets (poison + countdown)
    poison();
    hero_disponibles[0] = 1;
    hero_disponibles[1] = 1;
    hero_disponibles[2] = 1;
    hero_disponibles[3] = 1;
}

int main() {
	srand(time(NULL));
	int test = 1;
	int test_m = 1;
	int tours = 0;
	hero_disponibles[0] = 1;
    hero_disponibles[1] = 1;
    hero_disponibles[2] = 1;
    hero_disponibles[3] = 1;
    //boucle des manches

    for (int manche = 1; manche < 11; manche++){
 		//debut manche
 		display(51,manche,0);
 		test = 1;
 		test_m = 1;
    	select_monstre(manche);
    	tours = 0;
    	mp = 0;
    	paladin.pv = paladin.pv_max;
    	paladin.poison = 0;
    	paladin.stun = 0;
    	archer.pv = archer.pv_max;
    	archer.poison = 0;
    	archer.stun = 0;
    	mage.pv = mage.pv_max;
    	mage.poison = 0;
    	mage.stun = 0;
    	barbare.pv = barbare.pv_max;
    	barbare.poison = 0;
    	barbare.stun = 0;

    	//boucle des tours
    	while ((test != 0)&&(test_m != 0)){
    		tours++;
    		if (tours < 10){
    			display(27,1,tours);
    		}else{
    			display(27,2,tours);
    		}
    		tour(manche);
    	    //compte le nombre de heros en vie et attribue du mana en conséquence
    	    mp += cumul();
    	    monstre_mp(monstre1);
    	    monstre_mp(monstre2);
    	    monstre_mp(monstre3);
    	    test = cumul();
    	    test_m = cumul_m();
    	}
    }
  return 0;
}