#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

int main() {

	int choix_m;
	int choix;
	int atk_monster = 20;
	int pv_monster = 100;
	int atk = 20;
	int pv = 100;
	int dmg_taken;
	int dmg_given;
	
	printf("pv = %d \n",pv_monster);
	do {
		printf("Que faites vous ? \n [1] Attaquer \n [2] Se Defendre \n");
		scanf("%d",&choix);
		choix_m = (rand() % (2));
		if (choix == 1){
			printf("Pv du monstre: %d \n",pv_monster);
			if (choix_m == 0){
				dmg_taken = atk_monster;
				dmg_given = atk;
				printf("Le monstre vous frappe avec votre gros gourdin \n");
				pv = pv - dmg_taken;
				printf("Vous frapez le monstre avec votre gros gourdin \n");
				pv_monster = pv_monster - dmg_given;
			}else{
				dmg_given = atk/4;
				printf("Vous frapez le monstre avec votre gros gourdin \n");
				pv_monster = pv_monster - dmg_given;				
			}
		}else if (choix == 2){
			if (choix_m == 0){
				dmg_taken = atk_monster/4;
				printf("Le monstre vous frappe avec votre gros gourdin \n");
				pv = pv - dmg_taken;
			}else{
				printf("Vous vous jaugez mutuellement du regard sans rien faire \n");				
			}
		}else{
			printf("choix non valide\n");
		}
		printf("Pv du Monstre : %d \n",pv_monster);
		printf("Vos pv : %d \n",pv);
	}while(pv_monster > 0 && pv > 0);
  return 0;
}