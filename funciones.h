void vaciar_mapa(int mapa[FIL][COL])
{
	int i, j;
	
	for (i = 0; i < FIL; i++) {	
		for (j = 0; j < COL; j++) {
			if (i == 0 || i == FIL-1 || j == 0 || j == COL-1) {
				mapa[i][j] = 1;
			} else{
				mapa[i][j] = 0;
			}
		}
	}
}

void cargar_obstaculos(int mapa[FIL][COL])
{
	int x, y;
	
	do {
		 x = 1 + rand()%FIL-2;
		 y = 1 + rand()%COL-1;
	} while(mapa[x][y] != 0 || mapa[x+1][y] != 0 || mapa[x+2][y] != 0);
		
	mapa[x][y] = 10;
	mapa[x+1][y] = 10;
	mapa[x+2][y] = 10;
}

void cargar_puerta(int mapa[FIL][COL])
{
	int x, y;
	
	do {
		x = 1 + rand()%FIL-1;
		y = 1 + rand()%COL-1;
	} while(mapa[x][y] != 0);
		
		mapa[x][y] = 2;
}

void cargar_robot(int mapa[FIL][COL], int *xRobot, int *yRobot) {
	int x, y;
	
	do {
		x = 1 + rand()%FIL-1;
		y = 1 + rand()%COL-1;
	} while(mapa[x][y] != 0);
		
	mapa[x][y] = 5;
		
	*xRobot = x;
	*yRobot = y;
	printf("posicion del robot en la funcion x:%d y:%d", x,y);	
}

	void cargar_mapa(int mapa[FIL][COL], int *pos_x, int *pos_y)
	{	
		int x, y, i;
		
		for (i = 0 ; i < OBSTACULOS; i++) {
			cargar_obstaculos(mapa);	
		}
		
		cargar_robot(mapa, &*pos_x, &*pos_y);
		cargar_puerta(mapa);
	}	
	
void imprimir_mapa(int mapa[FIL][COL])
{
		int i, j;
		
		for (i = 0; i < FIL; i++) {
			printf("\n");
			for( j=0; j<COL; j++) {
	  		//imprimimos bordes	 	  		 	 
				if (mapa[i][j] == 1) {
					printf("*");	
				}
				
			 	//imrpimimos espacios en blanco 
				if(mapa[i][j] == 0) {
					printf(" ");	
				}				
				
				//imprimimos robot 
				if(mapa[i][j] == 5) {	
					printf("R");
				}
				
			 	//imprimimos obstaculos
				if (mapa[i][j] == 10){
					printf("#");
				}
				
				//imprimimos puerta
				if(mapa[i][j] == 2) {
					printf("D");
				}
				
				//imprimimos rastro
				if (mapa[i][j] == 4){
					printf("-");
				}
			}
		}
	}
	
	void movimientos(char mov[MAX], int *max_mov, int mapa[FIL][COL])
	{
		int i=0;
		char resp;
		
		printf("\nIngrese movimientos: arriba(A) abajo(B) derecha(D) izquierda(I)");
		
		do
		{		
			printf("\nIngrese movimiento %d", i+1);//calidar que no se salga
			fflush(stdin);
			scanf("%c", &mov[i]);
		
			resp = mov[i];
			
			i++;
		}while( resp != 'r' && i<MAX);
		
		*max_mov = i;
	}	
	void simulacion(int mapa[FIL][COL], char mov[MAX], int pos_x, int pos_y)
	{
		int i;
		
 	 	for (i=0; i<MAX; i++) {		
			if(mov[i] == 'a') {		
				mapa[pos_x][pos_y] = 4;
				
				if (mapa[pos_x-1][pos_y] == 2 ) {
					printf("Ha logrado llegar a la puerta");
					break;
				}
				
				pos_x--;
				mapa[pos_x][pos_y] = 5;
			}
			
			if(mov[i] == 'b') {
				mapa[pos_x][pos_y] = 4;
				
				if(mapa[pos_x+1][pos_y] == 2 ) {
					printf("Ha logrado llegar a la puerta");
					break;
				}
				
				pos_x++;
				mapa[pos_x][pos_y] = 5;
			}
			
			if(mov[i] == 'd') {
				mapa[pos_x][pos_y] = 4;
				
				if(mapa[pos_x][pos_y+1] == 2 ) {
					printf("Ha logrado llegar a la puerta");
					break;
				}
				
				pos_y++;
				mapa[pos_x][pos_y] = 5;
			}
			
			if (mov[i] == 'i') {
				mapa[pos_x][pos_y] = 4;
				
				if(mapa[pos_x][pos_y-1] == 2 ) {
					printf("Ha logrado llegar a la puerta");
					break;
				}
				
				pos_y--;
				mapa[pos_x][pos_y] = 5;
			}
		}
	}

