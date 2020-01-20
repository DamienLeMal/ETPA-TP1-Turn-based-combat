#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

int dmg_taken = 0;
int dmg_given = 0;
int poison_p = 0;
int poison_m = 0;
int mp_p = 0;
int mp_m = 0;

int choice_p(int choix, int atk) {
    switch (choix){
        case 1 :
            printf("--Vous frapez le monstre avec votre gros gourdin \n");
            dmg_given = atk;
            return 1;
            break;
            
        case 2 :
            printf("--Vous levez votre bouclier en attente d'une attaque \n");
            dmg_given = 0;
            return 4;
            break;
        
        case 3 :
            printf("--Vous empoisonnez le monstre ! \n");
            dmg_given = 0;
            mp_p = mp_p - 5;
            poison_m = 1;
            return 1;
            break;
        
        case 4 :
            printf("--Vous utilisez un sort d'antidote ! \n");
            dmg_given = 0;
            mp_p = mp_p - 5;
            poison_p = 0;
            return 1;
            break;
        default:
            printf("--Dans votre confusion vous n'avez rien fait \n");
            break;
    }
}
int choice_m(int choix, int atk) {
    switch (choix){
        case 1 :
            printf("--Le monstre vous frappe avec votre gros gourdin \n");
            dmg_taken = atk;
            return 1;
            break;
            
        case 2 :
            printf("--Le monstre leve votre bouclier en attente d'une attaque \n");
            dmg_taken = 0;
            return 4;
            break;
            
        case 3 :
            printf("--Le monstre vous empoisonne ! \n");
            dmg_taken = 0;
            mp_m = mp_m - 5;
            poison_p = 1;
            return 1;
            break;
        case 4 :
            printf("--Le mosntre utilise un sort d'antidote ! \n");
            dmg_taken = 0;
            mp_m = mp_m - 5;
            poison_m = 0;
            return 1;
            break;
    }
}
int main() {
    int choix_m = 0;
    int choix_p = 0;
    int atk_m = 20;
    int pv_m = 100;
    int atk_p = 20;
    int pv_p = 100;
	int defense_p = 0;
    int defense_m = 0;
    
	printf("pv = %d \n",pv_m);
	do {
		printf("Que faites vous ? \n [1] Attaquer \n [2] Se Defendre \n [3] Emposonner (coute 5 mp)\n [4] Antidote (coute 5 mp) \n");
		scanf("%d",&choix_p);
		while (mp_p < 5){
		    if (choix_p > 2){
		        printf("--Vous n'avez pas assez de mana");
		        printf("Que faites vous ? \n [1] Attaquer \n [2] Se Defendre \n [3] Emposonner (coute 5 mp)\n [4] Antidote (coute 5 mp) \n");
		        scanf("%d",&choix_p);
		    }else{
		        break;
		    }
		}
		while (choix_p == 4){
		    if (poison_p == 0){
		        printf("--Vous n'etes pas empoisonne \n");
		        printf("Que faites vous ? \n [1] Attaquer \n [2] Se Defendre \n [3] Emposonner (coute 5 mp)\n [4] Antidote (coute 5 mp) \n");
		        scanf("%d",&choix_p);
		    }else{
		        break;
		    }
		}
		srand(time(NULL));
		if (mp_m < 5){
		    choix_m = (rand() % (2)+1);
		}else if (poison_m == 0){
		    choix_m = (rand() % (3)+1);
		}else{
		    choix_m = (rand() % (4)+1);
		}
		
		defense_p = choice_p(choix_p,atk_p);
		defense_m = choice_m(choix_m,atk_m);
		
		dmg_given = dmg_given/defense_m;
		dmg_taken = dmg_taken/defense_p;
		pv_p = pv_p - dmg_taken;
		pv_m = pv_m - dmg_given;
		if (mp_p < 10){
		    mp_p = mp_p + 1;
		}
		if (mp_m < 10){
		    mp_m = mp_m + 1;
		}
		if (poison_p == 1){
		    pv_p = pv_p - 1;
		    printf("--Vous prennez des dommages de poison ! \n");
		}
		if (poison_m == 1){
		    pv_m = pv_m - 1;
		    printf("--Le monstre prend des dommages de poison ! \n");
		}
		printf("Pv du Monstre : %d/100 \n",pv_m);
		printf("Vos pv : %d/100 \n",pv_p);
		printf("Mana : %d/10 \n",mp_p);
		printf("===== Fin du Tour ===== \n");
	}while(pv_m > 0 && pv_p > 0);
	printf("pv = %d \n",pv_p);
	printf("pv monstre = %d \n",pv_m);
  return 0;
}