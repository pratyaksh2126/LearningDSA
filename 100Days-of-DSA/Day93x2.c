#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int canPlace(int position[], int n, int m, int dist)
{
    int count = 1;
    int last = position[0];

    for (int i = 1; i < n; i++)
    {
        if (position[i] - last >= dist)
        {
            count++;
            last = position[i];
        }
        if (count >= m)
            return 1;
    }
    return 0;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int position[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &position[i]);

    qsort(position, n, sizeof(int), cmp);

    int low = 1;
    int high = position[n - 1] - position[0];
    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canPlace(position, n, m, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}