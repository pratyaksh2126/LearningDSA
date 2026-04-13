#include <stdio.h>
#include <stdlib.h>

void dfs(int** image, int m, int n, int r, int c, int oldColor, int newColor) {
    if (r < 0 || r >= m || c < 0 || c >= n || image[r][c] != oldColor)
        return;

    image[r][c] = newColor;

    dfs(image, m, n, r + 1, c, oldColor, newColor);
    dfs(image, m, n, r - 1, c, oldColor, newColor);
    dfs(image, m, n, r, c + 1, oldColor, newColor);
    dfs(image, m, n, r, c - 1, oldColor, newColor);
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int** image = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        image[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    int sr, sc, color;
    scanf("%d %d %d", &sr, &sc, &color);

    int oldColor = image[sr][sc];

    if (oldColor != color) {
        dfs(image, m, n, sr, sc, oldColor, color);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++)
        free(image[i]);
    free(image);

    return 0;
}