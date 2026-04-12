#include <stdio.h>
#include <stdlib.h>

void dfs(int room, int** rooms, int* roomsColSize, int* visited) {
    visited[room] = 1;
    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key]) {
            dfs(key, rooms, roomsColSize, visited);
        }
    }
}

int canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int* visited = (int*)calloc(roomsSize, sizeof(int));

    dfs(0, rooms, roomsColSize, visited);

    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            free(visited);
            return 0;
        }
    }

    free(visited);
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int** rooms = (int**)malloc(n * sizeof(int*));
    int* roomsColSize = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &roomsColSize[i]);
        rooms[i] = (int*)malloc(roomsColSize[i] * sizeof(int));
        for (int j = 0; j < roomsColSize[i]; j++) {
            scanf("%d", &rooms[i][j]);
        }
    }

    if (canVisitAllRooms(rooms, n, roomsColSize))
        printf("true");
    else
        printf("false");

    for (int i = 0; i < n; i++)
        free(rooms[i]);
    free(rooms);
    free(roomsColSize);

    return 0;
}