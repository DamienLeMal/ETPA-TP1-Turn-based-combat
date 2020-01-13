#include <stdio.h>

int main() {
	int pv_monster;
	int atk;
	pv_monster = 100;
	atk = 30;
	printf("pv = %d \n",pv_monster);
	do {
		printf("Vous frapez le monstre avec votre gros gourdin \n");
		pv_monster = pv_monster - atk;
		printf("pv = %d \n",pv_monster);
	}while(pv_monster > 0);
   return 0;
}