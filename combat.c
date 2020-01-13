#include <stdio.h>

int main() {
	int pv;
	int atk;
	pv = 1000;
	atk = 30;
	printf("pv = %d \n",pv);
	printf("Le monstre frappe votre dos avec son gros gourdin \n");
	pv = pv - atk;
	printf("pv = %d \n",pv);
   return 0;
}