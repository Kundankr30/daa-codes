#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int profit;
    int weight;
    float ratio;
} Item;

void swapItems(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
} 

void bubbleSortItems(Item items[], int n) {
    int i, j;
    for (i = 1; i <= n - 1; i++) {
        for (j = 1; j <= n - i; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                swapItems(&items[j], &items[j + 1]);
            }
        }
    }
}

float greedyKnapsack(Item items[], int n, float M) {
    float U = M;
    float total_profits = 0;

    for (int i = 1; i <= n; i++) {
        if (U == 0) {
            break;
        }

        if (items[i].weight > U) {

            if (items[i].weight > 0) {
                 float fraction = U / items[i].weight;
                 total_profits += fraction * items[i].profit;
            }
            U = 0;
            break;
        } else {
            total_profits += (float)items[i].profit;
            U = U - items[i].weight;
        }
    }

    return total_profits;
}

int main() {
    int n, i;

    printf("Enter the total no. of items in knapsack (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of items.\n");
        return 1;
    }

    Item items[n + 1];

    printf("Enter the profits of the %d items (starting from item 1):\n", n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &items[i].profit);
    }

    printf("Enter the weights of the %d items (starting from item 1):\n", n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &items[i].weight);

        if (items[i].weight > 0) {
            items[i].ratio = (float)items[i].profit / items[i].weight;
        } else {
            items[i].ratio = 0.0f;
        }
    }

    float M;
    printf("Enter the knapsack capacity (M): ");
    scanf("%f", &M);

    bubbleSortItems(items, n);

    float max_profit = greedyKnapsack(items, n, M);

    printf("\nMaximum Total Profit (Optimal Solution): %.2f\n", max_profit);

    return 0;
}