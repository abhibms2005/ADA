#include <stdio.h>

int a[10], dir[10];

int getMobile(int n)
{
    int mobile = 0, pos = 0, i;

    for(i = 0; i < n; i++)
    {
        if(dir[a[i]-1] == 0 && i != 0)
        {
            if(a[i] > a[i-1] && a[i] > mobile)
            {
                mobile = a[i];
                pos = i;
            }
        }

        if(dir[a[i]-1] == 1 && i != n-1)
        {
            if(a[i] > a[i+1] && a[i] > mobile)
            {
                mobile = a[i];
                pos = i;
            }
        }
    }

    return pos;
}

void printPerm(int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

void johnsonTrotter(int n)
{
    int i, pos, temp;

    for(i = 0; i < n; i++)
    {
        a[i] = i + 1;
        dir[i] = 0;
    }

    printPerm(n);

    while(1)
    {
        pos = getMobile(n);

        if(a[pos] == 0)
            break;

        if(dir[a[pos]-1] == 0)
        {
            temp = a[pos];
            a[pos] = a[pos-1];
            a[pos-1] = temp;
            pos--;
        }
        else
        {
            temp = a[pos];
            a[pos] = a[pos+1];
            a[pos+1] = temp;
            pos++;
        }

        for(i = 0; i < n; i++)
        {
            if(a[i] > a[pos])
                dir[a[i]-1] = !dir[a[i]-1];
        }

        printPerm(n);
    }
}

int main()
{
    int n;

    printf("Enter value of n: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}