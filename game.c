#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>

int randomNum(){

    return (rand() % 3)+ 1;
}

int getUsersChouce();
int getComputerChoice();
void printRoundInfo(int userChoice, int computerChoice);
void checkWinner(int userChoice, int computerChoice, float round, int i);
void finalWInner(int userChoice, int computerChoice, float round, int i );

//AI generated code for dot matrix
// 5-row dot matrix font (each char = 5 rows of 3 cols)
// Order matches ASCII letters A-Z and some extras
typedef struct {
    char ch;
    const char *rows[5];
} DotChar;

static const DotChar font[] = {
    {'A', {" * ", "* *", "***", "* *", "* *"}},
    {'C', {"***", "*  ", "*  ", "*  ", "***"}},
    {'D', {"** ", "* *", "* *", "* *", "** "}},
    {'E', {"***", "*  ", "** ", "*  ", "***"}},
    {'H', {"* *", "* *", "***", "* *", "* *"}},
    {'I', {"***", " * ", " * ", " * ", "***"}},
    {'M', {"* *", "***", "***", "* *", "* *"}},
    {'N', {"* *", "***", "***", "* *", "* *"}},
    {'O', {"***", "* *", "* *", "* *", "***"}},
    {'P', {"** ", "* *", "** ", "*  ", "*  "}},
    {'R', {"** ", "* *", "** ", "* *", "* *"}},
    {'S', {"***", "*  ", "***", "  *", "***"}},
    {'T', {"***", " * ", " * ", " * ", " * "}},
    {'U', {"* *", "* *", "* *", "* *", "***"}},
    {'W', {"* *", "* *", "***", "***", "* *"}},
    {' ', {"   ", "   ", "   ", "   ", "   "}},
    {'-', {"   ", "   ", "***", "   ", "   "}},
    {'\0', {NULL}}  // sentinel
};

// Look up a character's dot-matrix rows
static const DotChar *getChar(char c) {
    // uppercase only
    if (c >= 'a' && c <= 'z') c -= 32;
    for (int i = 0; font[i].ch != '\0'; i++) {
        if (font[i].ch == c) return &font[i];
    }
    return &font[15]; // default to space (index of ' ')
}

/*
 * printOnDotMatrix - prints a string on a simulated dot matrix display
 * @param message : null-terminated string to display
 */
void printOnDotMatrix(const char *message) {
    printf("\n");
    // Print row by row (5 rows per character height)
    for (int row = 0; row < 5; row++) {
        for (int i = 0; message[i] != '\0'; i++) {
            const DotChar *dc = getChar(message[i]);
            printf("%s ", dc->rows[row]);
        }
        printf("\n");
    }
    printf("\n");
}
//-------------------------------------------------------------

int main(){
        srand(time(NULL));


    while (1)
    {
        printf("----------!! ROCK PAPER & SISSORS !!---------\n");


        int round;
        printf("How many rounds do u want-");
        scanf("%d",&round);


        
        

        for(int i = 0; i<round; i++ ){
            printf("\nRound-%d",i+1);
            int userChoice = getUsersChouce();
            int computerChoice = getComputerChoice();


            printRoundInfo(userChoice,computerChoice);
            

            checkWinner(userChoice,computerChoice,round,i);

            printf("\n");
            Sleep(2000);
            if(i+1==round){
                Sleep(2000);
            }

            
            finalWInner(userChoice,computerChoice,round,i);

            
        }

        // AI stuff for restarting the game
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        if (c == EOF) break;  // user hit Ctrl+C or Ctrl+Z, exit cleanly

        printf("\nPress ENTER to play again, or Ctrl+C to quit...\n");
        if (getchar() == EOF) break;             // wait for a fresh Enter press
        // -------------------------------

    }

    printf("\n");
    
    return 0;
}

int getUsersChouce(){
    int input=0;
    do{
        printf("\nEnter your choice \n1-For Rock \n2-For Paper \n3-For Sissors \nInput-");
        scanf("%d",&input);
    }while(input>3||input<1);
    return input;
}
int getComputerChoice(){
    return randomNum();
}

void printRoundInfo(int userChoice, int computerChoice){
    switch (userChoice)
    {
        case 1:
            printf("YOU CHOOSE - ROCK");
            break;
        case 2:
            printf("YOU CHOOSE - PAPER");
            break;
        case 3:
            printf("YOU CHOOSE - SISSORS");
            break;
        default:
            printf("LOOKS LIKE THERE IS AN ERROR!!");
    }
    printf("\n");

    switch (computerChoice)
    {
        case 1:
            printf("COMPUTER CHOOSE - ROCK");
            break;
        case 2:
            printf("COMPUTER CHOOSE - PAPER");
            break;
        case 3:
            printf("COMPUTER CHOOSE - SISSORS");
            break;
        default:
            printf("LOOKS LIKE THERE IS AN ERROR!!");
    }
    printf("\n");
    


}


void checkWinner(int userChoice, int computerChoice,float round,int i){
    
    if((userChoice==computerChoice)){
        printf("============ITS A TIE============");
    }
    else if ((userChoice==1 && computerChoice==2)||
            userChoice==2 && computerChoice==3||
            userChoice==3 && computerChoice==1)
    {
        printf("----------YOU LOOSE! TRY AGAIN----------");
    }
    else{
        printf("!!++++++++++++++YOU WIN++++++++++++++!!");
    }
    
}

void finalWInner(int userChoice, int computerChoice, float round, int i ){

    static int roundsWon = 0;
    static int cpuWon = 0;
    static int tie = 0;

    if ((userChoice==2 && computerChoice==1)||
            userChoice==3 && computerChoice==2||
            userChoice==1 && computerChoice==3)
    {
        roundsWon++;
    }
    else if(userChoice != computerChoice){
        cpuWon++;
    }
    else{
        tie++;
    }

    printf("\n\n");

    

    if(i+1==round){
        printf("---------------------------------------\n");
        printf("---------------SCORECARD---------------\n");
        printf("User-%d, Computer-%d, Tie-%d \n", roundsWon,cpuWon,tie);
        printf("---------------------------------------\n");
        printf("\n");


        if(roundsWon>cpuWon)
        {
            printOnDotMatrix("USER WINS");
        }
        else if(roundsWon==cpuWon)
        {
            printOnDotMatrix("ITS A DRAW");
        }
        else{
            printOnDotMatrix("COMPUTER WINS");
        }

        
        roundsWon = 0;
        cpuWon = 0;
        tie = 0;
    }
    

}
