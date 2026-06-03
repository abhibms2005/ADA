#include<stdio.h>
#include<stdlib.h>
int queencolumn[20];
int solutioncount=0;
int isSafe(int currrow, int currcol){
    for(int previousrow=0; previousrow<currrow; previousrow++){
        int previouscol;
        previouscol=queencolumn[previousrow];
        if(previouscol==currcol){
            return 0;
        }
        if (abs(previouscol-currcol)==abs(previousrow-currrow)){
            return 0;
        }
    }
    return 1;
}
void solveNqueens(int currrow, int totalqueens){
    int currcol;
    for(currcol=0; currcol<totalqueens; currcol++){
        if(isSafe(currrow, currcol)){
            queencolumn[currrow]=currcol;
            if (currrow== totalqueens-1){
                solutioncount++;
                printf("Solution: \n%d", solutioncount);
                for(int row=0; row<totalqueens; row++){
                    printf("Row-> %d, Column-> %d\n", row, queencolumn[row]);
                }
                printf("\n");
            }
            else{
                solveNqueens(currrow + 1,totalqueens);
            }
        }
    }
}
int main(){
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);
    solveNqueens(0,n);
    return 0;
}