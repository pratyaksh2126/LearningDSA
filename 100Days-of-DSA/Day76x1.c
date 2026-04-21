#include <stdio.h>
#include <string.h>

#define SIZE 7

int table[SIZE];

void init() {
    for(int i = 0; i < SIZE; i++) table[i] = -1;
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int h = hash(key);
    for(int i = 0; i < SIZE; i++) {
        int idx = (h + i*i) % SIZE;
        if(table[idx] == -1) {
            table[idx] = key;
            return;
        }
    }
}

int search(int key) {
    int h = hash(key);
    for(int i = 0; i < SIZE; i++) {
        int idx = (h + i*i) % SIZE;
        if(table[idx] == key) return 1;
        if(table[idx] == -1) return 0;
    }
    return 0;
}

int main() {
    int q;
    scanf("%d", &q);
    init();
    while(q--) {
        char op[10];
        int x;
        scanf("%s %d", op, &x);
        if(strcmp(op, "INSERT") == 0) insert(x);
        else if(strcmp(op, "SEARCH") == 0) {
            if(search(x)) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }
    return 0;
}