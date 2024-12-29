#include <stdio.h>
#include <locale.h>

// ‘ункци€ дл€ нахождени€ максимального количества подр€д идущих свободных мест
void findMaxFreeSeats(int train[100][100], int wagons, int seats, int* maxFree, int* wagonNumber) {
    *maxFree = 0;
    *wagonNumber = -1;

    for (int i = 0; i < wagons; i++) {
        int currentFree = 0;

        for (int j = 0; j < seats; j++) {
            if (train[i][j] == 0) {
                currentFree++;
            }
            else {
                if (currentFree > *maxFree) {
                    *maxFree = currentFree;
                    *wagonNumber = i + 1;
                }
                currentFree = 0;
            }
        }

        if (currentFree > *maxFree) {
            *maxFree = currentFree;
            *wagonNumber = i + 1;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    int train[100][100];
    int wagons, seats;

    printf("¬ведите количество вагонов: ");
    scanf_s("%d", &wagons);
    printf("¬ведите количество мест в каждом вагоне: ");
    scanf_s("%d", &seats);

    for (int i = 0; i < wagons; i++) {
        printf("¬ведите данные дл€ вагона %d (0 - свободно, 1 - зан€то):\n", i + 1);
        for (int j = 0; j < seats; j++) {
            scanf_s("%d", &train[i][j]);
        }
    }
    int maxFree, wagonNumber;
    findMaxFreeSeats(train, wagons, seats, &maxFree, &wagonNumber);

    if (wagonNumber != -1) {
        printf("ћаксимальное количество подр€д идущих свободных мест: %d\n", maxFree);
        printf("Ќомер вагона с этим количеством свободных мест: %d\n", wagonNumber);
    }
    else {
        printf("¬се места зан€ты.\n");
    }

    return 0;
}
