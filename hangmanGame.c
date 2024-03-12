#include <stdio.h>
#include <string.h>

int main(){
    
    char letter, guess[100]; 
    int size, attempts, riskWord;

    printf("You have 6 attempts\nWith each mistake they decrease!\n");

    printf("Word chosen!\nGood luck!\n");
    char word[] = "barbecue"; // you put any word you want here, i chose barbecue. 
    size = strlen(word);

    char hiddenWord[size];

    for (int i = 0; i <= (size - 1); i++){
        hiddenWord[i] = '_';
    }

    attempts = 1;
     
    //loop do jogo:

    while (attempts <= 6){

        for (int j = 0; j <= (size - 1); j++){
            printf("%c", hiddenWord[j]);
        }

        if (attempts == 6)
            printf("\nLast try.");
        

        if (attempts >= (size / 2)){

            printf("\nDo you already know what the word is? YES(1)/NO(0): ");
            scanf("%d", &riskWord);
            
            if (riskWord == 1){

                char guess[size];

                printf("What word is it? ");
                scanf("%s", &guess);
                 
                    if (strcmp(guess, word) == 0){ 
                        printf("You got it right, congratulations!\n");
                        break;
                    } else {
                        printf("You missed :(\nEnd of the game.\n");
                        break; 
                    } 
            } else {
                int correctAnswer = 0;
                printf("Type a letter: ");
                scanf(" %c", &letter);
                for (int j = 0; j <= (size - 1); j++){
                    if (word[j] == letter){
                        correctAnswer = 1;
                        hiddenWord[j] = letter;
                    }

                }
                if (!correctAnswer)
                    attempts++;
            
            }
        } else {
                int correctAnswer = 0;
                printf("\nType a letter: ");
                scanf(" %c", &letter);
                for (int j = 0; j <= (size - 1); j++){
                    if (word[j] == letter){
                        correctAnswer = 1;
                        hiddenWord[j] = letter;
                    }
                } 
                if (!correctAnswer)
                    attempts++;
            }
        }

    return 0;
}
