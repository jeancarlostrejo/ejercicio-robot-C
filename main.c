#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define FIL 15 //para que el robot se mueva en un tablero de 15x15 se deben definir en 17 las constantes
#define COL 15 // ya que 2 espacios ocuparan las paredes (izquierda-derecha y arriba-abajo)
#define MAX_MOV 20 // Máximos movimientos permitidos
#define OBSTACULOS 2 // cantidad de obstáculos a generar 
#include "funciones.h"

int main(int argc, char *argv[]){
	int pos_x, pos_y, max_mov, mapa[FIL][COL], ganar = 0, choque = 0;
	char mov[MAX_MOV];
	
	srand(time(NULL));
				
	do{	
		system("CLS");
		vaciar_mapa(mapa);
		cargar_mapa(mapa, &pos_x, &pos_y);
		imprimir_mapa(mapa);
		movimientos(mov, &max_mov, mapa);
		simulacion(mapa, mov, pos_x, pos_y, max_mov, &ganar, &choque);
		imprimir_mapa(mapa);
		
		if(ganar){
			printf("\nFelicidades, has logrado llegar a la puerta :D\n");
		} else {
			if(choque){
				printf("\nPerdiste, has chocado :(\n");	
			}else {
				printf("\nPerdiste, tus movimientos no alcanzaron para llegar a la salida :(\n");
			}
		}
		
		getch();
	}while(1);
	
	return 0;
}