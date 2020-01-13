#include <stdio.h>

int main() {
	int choix;
	int atk_monster;
	int pv_monster;
	int atk;
	int pv;
	int dmg_taken;
	atk_monster = 20;
	pv_monster = 100;
	atk = 30;
	pv = 100; // on commence exo5
	printf("pv = %d \n",pv_monster);
	do {
		printf("Que faites vous ? \n [1] Attaquer \n [2] Se Defendre \n");
		scanf("%d",&choix);
		if (choix == 1){
			printf("Vous frapez le monstre avec votre gros gourdin \n");
			pv_monster = pv_monster - atk;
			printf("Pv du monstre: %d \n",pv_monster);
			dmg_taken = atk_monster;
		}else if (choix == 2){
			dmg_taken = atk_monster/4;
		}else{
			printf("choix non valide\n");
		}
		printf("Le monstre vous frappe avec votre gros gourdin \n");
		pv = pv - dmg_taken;
		printf("Vos pv : %d \n",pv);
	}while(pv_monster > 0 && pv > 0);
  return 0;
}