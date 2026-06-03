#include <stdio.h>

int main()
{
    int n, i;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    int coin[n];

    printf("Enter coin values:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &coin[i]);

    int F[n + 1];

    F[0] = 0;
    F[1] = coin[0];

    for(i = 2; i <= n; i++)
    {
        int include = coin[i - 1] + F[i - 2];
        int exclude = F[i - 1];

        if(include > exclude){
            F[i] = include;
        } else{
            F[i] = exclude;
        }
    }

    printf("Maximum amount collected = %d\n", F[n]);

    return 0;
}