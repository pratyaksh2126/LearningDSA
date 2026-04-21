#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX 15
#define INF INT_MAX

int n;
int cost[MAX][MAX];
int dp[1 << MAX][MAX];

int min(int a, int b) {
    return a < b ? a : b;
}

int tsp(int mask, int pos) {
    if(mask == (1 << n) - 1) return cost[pos][0];

    if(dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INF;

    for(int city = 0; city < n; city++) {
        if((mask & (1 << city)) == 0) {
            int newAns = cost[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    memset(dp, -1, sizeof(dp));

    printf("%d\n", tsp(1, 0));

    return 0;
}