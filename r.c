#include<stdio.h>
int main(){
    int i,j,n,m;
    printf("Enter number of rows and columns: ");
    scanf("%d%d", &m,&n);
    int F[m][n], C[m][n];
    printf("Enter coin matrix: ");
    for(i=0; i<m;i++){
        for(j=0; j<n; j++){
            scanf("%d", &C[i][j]);
        }
    }
    F[0][0]=C[0][0];
    for(i=1; i<m; i++){
        F[i][0]=F[i-1][0]+C[i][0];
    }
    for(j=1; j<n; j++){
        F[0][j]=F[0][j-1]+C[0][j];
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if (F[i-1][j]>F[i][j-1]){
                F[i][j]=F[i-1][j]+C[i][j];
            }else{
                F[i][j]=F[i][j-1]+C[i][j];
            }
        }
    }
    printf("Max Coins: %d", F[m-1][n-1]);
    return 0;
    
}