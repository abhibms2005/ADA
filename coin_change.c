#include <stdio.h>

int main()
{
    int n, amount, i;

    printf("Enter number of coin denominations: ");
    scanf("%d", &n);

    int coin[n];

    printf("Enter coin denominations in descending order:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &coin[i]);

    printf("Enter amount: ");
    scanf("%d", &amount);

    printf("Coins used: ");

    for(i = 0; i < n; i++)
    {
        while(amount >= coin[i])
        {
            printf("%d ", coin[i]);
            amount -= coin[i];
        }
    }

    return 0;
}