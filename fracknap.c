#include <stdio.h>

struct Item {
    int weight;
    int value;
    float ratio;
};

struct Item items[100];   // Global array

void swap(int i, int j) {
    struct Item temp = items[i];
    items[i] = items[j];
    items[j] = temp;
}

void sortItems(int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(items[j].ratio < items[j + 1].ratio) {
                swap(j, j + 1);
            }
        }
    }
}

float fractionalKnapsack(int n, int capacity) {
    float totalProfit = 0.0;

    for(int i = 0; i < n; i++) {
        if(capacity >= items[i].weight) {
            totalProfit += items[i].value;
            capacity -= items[i].weight;
        }
        else {
            totalProfit += items[i].ratio * capacity;
            break;
        }
    }

    return totalProfit;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter value and weight of each item:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    sortItems(n);

    float maxProfit = fractionalKnapsack(n, capacity);

    printf("Maximum profit = %.2f\n", maxProfit);

    return 0;
}