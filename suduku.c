#include<stdio.h>
#include<stdbool.h>

void printsuduku(int suduku[][9]) {
    for(int i=0;i<9;i++){
        if(i%3==0){
            printf("----------------------------------\n");
        }
        for(int j=0;j<9;j++) {
            if(j%3==0){
                printf("| ");
            }
             printf("%d  ",suduku[i][j]);
        }
        printf("|\n");
    }
    printf("----------------------------------\n");
}

bool issafe(int suduku[9][9],int row,int col,int digit) {
    //vertical
    for(int i=0;i<=8;i++){
        if(suduku[i][col]==digit) {
            return false;
        }
    }

    //horizontal
    for(int j=0;j<=8;j++) {
        if(suduku[row][j]==digit) {
            return false;
        }
    }

    //3*3 grid
    int startRow=(row/3)*3; //staring row of each grid
    int startcol=(col/3)*3; //staring col of each grid

    for(int i=startRow;i<=startRow+2;i++) {
        for(int j=startcol;j<=startcol+2;j++) {
            if(suduku[i][j]==digit) {
                return false;
            }
        }
    }
    return true;
}

bool sudukuSolver(int suduku[9][9],int row,int col) {
           if(row==9) { //is solved
            printsuduku(suduku);
            return true;
           }

           int nextRow=row;
           int nextcol=col+1;
           if(col+1==9) { //reached last col
            nextRow=row+1;
            nextcol=0;
           }

           if(suduku[row][col]!=0) { //recursive call
            return(sudukuSolver(suduku,nextRow,nextcol));
           }


           for(int digit=1;digit<=9;digit++){
            if (issafe(suduku,row,col,digit)) {
                suduku[row][col]=digit;
                if(sudukuSolver(suduku,nextRow,nextcol)) {
                    return true;
                }
                suduku[row][col]=0;
            }
           }
           return false;
}

int main() {
    int suduku[9][9]={{0,0,8,0,0,0,0,0,0},
                     {4,9,0,1,5,7,0,0,2},
                    {0,0,3,0,0,4,1,9,0},
                    {1,0,5,0,6,0,0,2,0},
                    {0,0,0,0,2,0,0,6,0},
                    {9,6,0,4,0,5,3,0,0},
                    {0,3,0,0,7,2,0,0,4},
                     {0,4,9,0,3,0,0,5,7},
                    {8,2,7,0,0,9,0,1,3}};
     sudukuSolver(suduku,0,0);
     return 0;               
}