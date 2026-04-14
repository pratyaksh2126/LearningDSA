#include <stdio.h>

#define MAX 10

int orangesRotting(int grid[MAX][MAX], int m, int n) {
    int queue[100][2];
    int front = 0, rear = 0;
    int fresh = 0, time = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            } else if(grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    while(front < rear && fresh > 0) {
        int size = rear - front;

        for(int k = 0; k < size; k++) {
            int x = queue[front][0];
            int y = queue[front][1];
            front++;

            for(int d = 0; d < 4; d++) {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];

                if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    queue[rear][0] = nx;
                    queue[rear][1] = ny;
                    rear++;
                    fresh--;
                }
            }
        }
        time++;
    }

    if(fresh > 0) return -1;
    return time;
}

int main() {
    int m, n;
    int grid[MAX][MAX];

    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = orangesRotting(grid, m, n);
    printf("%d", result);

    return 0;
}