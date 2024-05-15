#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char tictactoe[3][3];
	int x,y;

	for(x = 0; x < 3; x++)
		for(y = 0; y < 3; y++)
			tictactoe[x][y] = '.';
	
	puts("Tic Tac Toe");
	for(x = 0; x < 3; x++)
	{
		for(y = 0; y < 3; y++)
			printf(" %c ",tictactoe[x][y]);
		putchar('\n');
	}

	char playerOne;
	char playerTwo;	

	printf("Choose (X) or (O): ");
	scanf(" %c", &playerOne);
	
	if (playerOne == 'X'){
		
		playerTwo = 'O';
		puts("Player One is X and Player Two is O");
	
	}else{
	
		playerTwo = 'X';
		puts("Player One is O and Player Two is X");

	} 
	
	int line;
	int column;
	int turn = 0;
	int winner = 0;
	int moves = 0;
	
	while (1)
	{
		//player 1
		if (turn == 0){

			printf("Player One choose your position [lines(1 to 3)][columns(1 to 3)]: ");
			scanf("%d %d", &line, &column);

			//LINE CONVERT
			switch (line){
				case  1:
					line = 0;
					break;
				case  2:
					line = 1;
					break;
				case  3:
					line = 2;
					break;	
			}

			//COLUMN CONVERT
			switch (column){
				case 1:
					column = 0;
					break;
				case 2:
					column = 1;
					break;
				case 3:
					column = 2;
					break;	
			}
			
			while (1){

				if (tictactoe[line][column] == 'X' || tictactoe[line][column] == 'O') {
					
					printf("Position already taken. Try again.\n");
					printf("Player One choose again a position [lines(1 to 3)][columns(1 to 3)]: ");
					scanf("%d %d", &line, &column);
				
				} else 
					break;
			}

			tictactoe[line][column] = playerOne;

			moves++;
			winner = 0;

			

			//LINES
			for (int j = 0; j < 3; j++){
				for (int m = 0; m < 3; m++){
					if (tictactoe[j][m] == playerOne){
						winner ++;
						if (winner == 3){
							for(x = 0; x < 3; x++){
								for(y = 0; y < 3; y++)
									printf(" %c ", tictactoe[x][y]);
								putchar('\n');
							}
							puts("Player One WINS!23");
							exit(EXIT_SUCCESS);
						}
					}
				}

				winner = 0;
			}

			//COLUMNS
			for (int c = 0; c < 3; c++) {
					winner = 0; 
					for (int r = 0; r < 3; r++) {
						if (tictactoe[r][c] == playerOne) {
							winner++;
							if (winner == 3){
								
								for(x = 0;x < 3; x++){
									for(y = 0; y < 3; y++)
										printf(" %c ", tictactoe[x][y]);
									putchar('\n');
								}
								
								puts("Player One WINS!11");
								exit(EXIT_SUCCESS);
							}
						}
					}			
				}

			//DIAGONAIS
			//1º DIAGONAL
			if (tictactoe[0][0] == playerOne && tictactoe[1][1] == playerOne && tictactoe[2][2] == playerOne){
				for(x = 0;x < 3; x++){
					for(y = 0; y < 3; y++)
						printf(" %c ", tictactoe[x][y]);
					putchar('\n');
				}

				puts("Player One WINS!99");
				exit(EXIT_SUCCESS);

			}

			//2º DIAGONAL
			if (tictactoe[0][2] == playerOne && tictactoe[1][1] == playerOne && tictactoe[2][0] == playerOne){
				for(x = 0;x < 3; x++){
					for(y = 0; y < 3; y++)
						printf(" %c ", tictactoe[x][y]);
					putchar('\n');
				}

				puts("Player One WINS!45");
				exit(EXIT_SUCCESS);

			}
			
			for(x = 0;x < 3; x++){
				for(y = 0; y < 3; y++)
					printf(" %c ", tictactoe[x][y]);
				putchar('\n');
			}

			if (moves == 9){
				
				for(x = 0;x < 3; x++){
					for(y = 0; y < 3; y++)
						printf(" %c ", tictactoe[x][y]);
					putchar('\n');
				}

				puts("A DRAW!");
				exit(EXIT_SUCCESS);
			}

			turn = 1;

		} else {
			//player 2
				printf("Player Two choose a position [lines(1 to 3)][columns(1 to 3)]: ");
				scanf("%d %d", &line, &column);

				//LINE CONVERT
				switch (line){
					case  1:
						line = 0;
						break;
					case  2:
						line = 1;
						break;
					case  3:
						line = 2;
						break;	
				}

				//COLUMN CONVERT
				switch (column){
					case 1:
						column = 0;
						break;
					case 2:
						column = 1;
						break;
					case 3:
						column = 2;
						break;	
				}

				while (1){

					if (tictactoe[line][column] == 'X' || tictactoe[line][column] == 'O') {
					
						printf("Position already taken. Try again.\n");
						printf("Player Two choose again a position [lines(1 to 3)][columns(1 to 3)]: ");
						scanf("%d %d", &line, &column);
				
					} else 
						break;
				}
		
			tictactoe[line][column] = playerTwo;

			moves++;
			winner = 0;

			//LINES
			for (int b = 0; b < 3; b++){
				for (int n = 0; n < 3; n++){

					if (tictactoe[b][n] == playerTwo){
						winner ++;
						
						if (winner == 3){
							for(x = 0; x < 3; x++){
								for(y = 0; y < 3; y++)
									printf(" %c ", tictactoe[x][y]);
								putchar('\n');
							}
							
							puts("Player Two WINS!50");
							exit(EXIT_SUCCESS);
						}
					}
				}
				
				winner = 0;
			
			}

			//COLUMNS
			for(int d = 0; d < 3; d++){
				winner = 0;
				for (int e = 0; e < 3; e++) {
					if (tictactoe[e][d] == playerTwo) {
						winner++;
						if (winner == 3){
							
							for(x = 0; x < 3; x++){
								for(y = 0; y < 3; y++)
									printf(" %c ", tictactoe[x][y]);
								putchar('\n');
							}
							
							puts("Player Two WINS!22");
							exit(EXIT_SUCCESS);
						}
					}
				}
			}

			//DIAGONAIS
			//1º DIAGONAL
			if (tictactoe[0][0] == playerTwo && tictactoe[1][1] == playerTwo && tictactoe[2][2] == playerTwo){
				for(x = 0;x < 3; x++){
					for(y = 0; y < 3; y++)
						printf(" %c ", tictactoe[x][y]);
					putchar('\n');
				}

				puts("Player Two WINS!333");
				exit(EXIT_SUCCESS);

			}

			//2º DIAGONAL
			if (tictactoe[0][2] == playerTwo && tictactoe[1][1] == playerTwo && tictactoe[2][0] == playerTwo){
				for(x = 0;x < 3; x++){
					for(y = 0; y < 3; y++)
						printf(" %c ", tictactoe[x][y]);
					putchar('\n');
				}

				puts("Player Two WINS!78");
				exit(EXIT_SUCCESS);

			}
 
			for(x = 0; x < 3; x++){
				for(y = 0; y < 3; y++)
					printf(" %c ", tictactoe[x][y]);
				putchar('\n');
			}

			turn = 0;
		
		} 		
	}
	
	return 0;
}