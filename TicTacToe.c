#include <stdio.h>
static int Exit=0;
char WhoIsTheWinner(int m, int n, char board[3][3]){
    int x, o;
    for (int i=0; i<3; i++){
        for (int j= 0 ; j<3; j++){
            if(board[i][j]=='x'){
                x++;
            }
            else if(board[i][j]=='o'){
                o++;
            }
        }
        if (x==3){
            return 'x';
        } else if (o==3){
            return 'o';
        }
        x=0;
        o=0;
    }
    for (int i=0; i<3; i++){
        for (int j= 0 ; j<3; j++){
            if(board[j][i]=='x'){
                x++;
            }
            else if(board[j][i]=='o'){
                o++;
            }
        }
        if (x==3){
            return 'x';
        } else if (o==3){
            return 'o';
        }
        x=0;
        o=0;
    }
    for(int i=0;i<3; i++){
        if(board[i][i]=='x'){
            x++;
        }
        else if(board[i][i]=='o'){
            o++;
        }
    }
    if (x==3){
        return 'x';
    } else if (o==3){
        return 'o';
    }
    x=0;
    o=0;
    int i=0;
    for (int j=2 ; j>0; j--) {
        if (board[j][i] == 'x') {
            x++;
        } else if (board[j][i] == 'o') {
            o++;
        }
        if (x == 3) {
            return 'x';
        } else if (o == 3) {
            return 'o';
        }
        i++;
    }
    x=0;
    o=0;
    return 'd';
}
void InitializeBoard (int m, int n,char board[3][3]) {
    int c=1;
    for ( int i = 0 ; i<3; i++){
        for ( int j= 0 ; j<3; j++){
            board[i][j]= c+'0' ;
            c++;
        }
    }
}
void PrintBoard (int m, int n,char board[3][3]){
    printf(" TIC-TAC-TOE\n");
    printf(" ___________ \n");
    for (int i=0; i<=2; i++){
        printf("|   |   |   |\n");
        for (int j=0; j<=2; j++){
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        printf("|___|___|___|\n");
    }
}
void CreateBoard (int m, int n,char board[3][3]){
    int cell=1;
    char x_or_o;
    while(cell>0 && Exit==0){
        printf("Enter the number of the cell where you want to insert x or o, or enter -1 to exit: \n");
        scanf("%d", &cell);
        if(cell!=-1 && cell<=9){
            printf("Enter small case x or o:\n");
            scanf(" %c", &x_or_o);
            if(x_or_o=='x' || x_or_o=='o'){
                board[(cell-1)/3][(cell-1)%3]= x_or_o;
            } else{
                printf("Please enter small case x or o\n");
            }
        }
        PrintBoard(m,n,board);
        WhoIsTheWinner(m, n, board);
        if (WhoIsTheWinner(m, n, board)=='x'){
            printf("X is the winner\n");
            Exit=1;
        }
        WhoIsTheWinner(m, n, board);
        if (WhoIsTheWinner(m, n, board)=='o'){
            printf("O is the winner\n");
            Exit=1;
        }
        WhoIsTheWinner(m, n, board);
        if (WhoIsTheWinner(m, n, board)!='x'&&WhoIsTheWinner(m, n, board)!='o'){
            printf("No winner yet\n");
        }
    }
}
void IsValidBoard ( int m, int n, char board[3][3]){
    int x=0,o=0;
    for ( int i = 0 ; i<3; i++){
        for ( int j= 0 ; j<3; j++){
            if(board[i][j]=='x'){
                x=x+1;
            }
            else if(board[i][j]=='o'){
                o=o+1;
            }
        }
    }
    int diff= x-o;
    if(diff>1){
        printf("Board is invalid\n");
    } else {
        printf("Board is valid\n");
    }
}
void ListWinningCells(int m, int n, char board[3][3]){
    int cellnum=0,cellnum2=1,cellnum3=1, xcount=0, ocount=0, xcount2=0, ocount2=0, xcount3=0, ocount3=0, j=0;
    int cellnum4=7, xcount4=0, ocount4=0;
    for (int i=0 ; i<3; i++){
        xcount=0, ocount=0 ;
        for (int j= 0 ; j<3; j++){
            if (board[i][j]=='x'){
                ++xcount;
            } else if (board[i][j]=='o'){
                ++ocount;
            }
        }
        if (xcount==2 && ocount!=1){
            for (int k=0; k<3; k++){
                ++cellnum;
                if (board[i][k]!='x'){
                    if (board[i][k]!='o'){
                        printf("Cell %d is the winning move horizontally for player 'X'\n",cellnum);
                    }
                }
            }
        }
        if (ocount==2 && xcount!=1){
            for (int k=0; k<3; k++){
                cellnum++;
                if (board[i][k]!='o'){
                    if (board[i][k]!='x'){
                        printf("Cell %d is the winning move horizontally for player 'O'\n",cellnum);
                    }
                }
            }
        }
    }
    for (int i=0 ; i<3; i++){
        xcount2=0, ocount2=0 ;
        for (int j= 0 ; j<3; j++){
            if (board[j][i]=='x'){
                ++xcount2;
            } else if (board[j][i]=='o'){
                ++ocount2;
            }
        }
        if (xcount2==2 && ocount2!=1){
            for (int k=0; k<3; k++){
                if (board[k][i]!='x'){
                    if (board[k][i]!='o'){
                        printf("Cell %d is the winning move vertically for player 'X'\n",cellnum2);
                    }
                }
                cellnum2=cellnum2+3;
            }
        }
        else if (ocount2==2 && xcount2!=1){
            for (int k=0; k<3; k++){
                if (board[k][i]!='o'){
                    if (board[k][i]!='x'){
                        printf("Cell %d is the winning move vertically for player 'O'\n",cellnum2);
                    }
                }
                cellnum2=cellnum2+3;
            }
        } else {
            cellnum2=cellnum2+6;
        }
        cellnum2=cellnum2-5;
    }
    for (int i=0; i<3; i++){
        if (board[i][i]=='x'){
            ++xcount3;
        } else if (board[i][i]=='o'){
            ++ocount3;
        }
    }
    if (xcount3==2 && ocount3!=1){
        for (int k=0; k<3; k++){
            if (board[k][k]!='x'){
                if (board[k][k]!='o'){
                    printf("Cell %d is the winning move diagonally for player 'X'\n",cellnum3);
                }
            }
            cellnum3+=4;
        }
    }
    else if (ocount3==2 && xcount3!=1){
        for (int k=0; k<3; k++){
            if (board[k][k]!='o'){
                if (board[k][k]!='x'){
                    printf("Cell %d is the winning move diagonally for player 'O'\n",cellnum3);
                }
            }
            cellnum3+=4;
        }
    }
    for (int i=2; i>=0; i--){
        if (board[i][j]=='x'){
            ++xcount4;
        } else if (board[i][j]=='o'){
            ++ocount4;
        }
        j++;
    }
    j=0;
    if (xcount4==2 && ocount4!=1){
        for (int k=2; k>=0; k--){
            if (board[k][j]!='x'){
                if (board[k][j]!='o'){
                    printf("Cell %d is the winning move diagonally for player 'X'\n",cellnum4);
                }
            }
            j++;
            cellnum4= cellnum4-2;
        }
    }
    else if (ocount4==2 && xcount4!=1){
        for (int k=2; k>=0; k--){
            if (board[k][j]!='o'){
                if (board[k][j]!='x'){
                    printf("Cell %d is the winning move diagonally for player 'O'\n",cellnum4);
                }
            }
            j++;
            cellnum4= cellnum4-2;
        }
    }
}
int main()
{
    int n=3, m=3;
    char board[3][3];
    char choice;
    InitializeBoard(m,n,board);
    printf("                    WELCOME TO TIC-TAC-TOE                         \n");
    while (Exit!=1){
        printf(" _________________________________________________________________ \n");
        printf("| Press 'p' to print the tic-tac-toe board                        |\n");
        printf("|-----------------------------------------------------------------|\n");
        printf("| Press 'c' to create a tic-tac-toe board with some x and o cells |\n");
        printf("|-----------------------------------------------------------------|\n");
        printf("| Press 't' to test if a tic-tac-toe board is valid or invalid    |\n");
        printf("|-----------------------------------------------------------------|\n");
        printf("| Press 'w' to predict winning cell for player x or o             |\n");
        printf("|-----------------------------------------------------------------|\n");
        printf("| Press 'e' to Exit                                               |\n");
        printf("|_________________________________________________________________|\n");
        scanf(" %c", &choice);
        if (choice=='p'){
            PrintBoard(m,n,board);
        }
        if (choice=='c'){
            CreateBoard(m,n,board);
        }
        if (choice=='t'){
            IsValidBoard(m,n,board);
        }
        if (choice=='w'){
            ListWinningCells (m,n, board);
        }
        if (choice=='e'){
            Exit=1;
            printf("             *********************************\n");
            printf("             ***** Thank you for playing *****\n");
            printf("             *********************************\n");
        }
    }
}