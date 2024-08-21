#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FIL 15 //para que el robot se mueva en un talbero 15x15 se deben definir en 17 las constantes
#define COL 15  // ya que 2 espacios ocuparan las paredes
#define MAX 20
#include "funciones.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]){
	
	srand(time(NULL));
	
	int pos_x, pos_y, max_mov, mapa[FIL][COL];
		
	char mov[MAX];										
	
	do{	
		
		system("CLS");
		vaciar_mapa(mapa);
		cargar_mapa(mapa, &pos_x, &pos_y);
		imprimir_mapa(mapa);
		movimientos(mov, &max_mov, mapa);
		simulacion(mapa, mov, pos_x, pos_y);
		imprimir_mapa(mapa);		
		
		getch();
	
	}while(1);
	return 0;
}

