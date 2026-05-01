#include <stdio.h>
#include <stdlib.h>

struct Car {
    int pos;
    int speed;
};

int compare(const void* a, const void* b) {
    struct Car* c1 = (struct Car*)a;
    struct Car* c2 = (struct Car*)b;
    return c2->pos - c1->pos;
}

int carFleet(int target, int* position, int* speed, int n) {
    struct Car* cars = (struct Car*)malloc(n * sizeof(struct Car));

    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].speed = speed[i];
    }

    qsort(cars, n, sizeof(struct Car), compare);

    int fleets = 0;
    double prevTime = 0.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;
        if (time > prevTime) {
            fleets++;
            prevTime = time;
        }
    }

    free(cars);
    return fleets;
}

int main() {
    int n, target;
    scanf("%d", &n);

    int position[n], speed[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &position[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    scanf("%d", &target);

    printf("%d\n", carFleet(target, position, speed, n));

    return 0;
}