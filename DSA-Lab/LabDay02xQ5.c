//Q5. Find the product of ywo matrices using pointers:-

#include <stdio.h>

int main()
{
    int r1, c1, r2, c2;
    int a[10][10], b[10][10], c[10][10];

    int i, j, k;
    //(a) Read Matrix Dimensions:-
    printf("Enter rows and columns of first Matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    //(b) Check Multiplication Condition:-
    if(c1 != r2)
    {
        printf("Matrix multiplication not possible!\n");
        return 0;
    }

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", (*(a + i) + j));
        

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", (*(b + i) + j));

    //(c&b) Multiply matrices using pointers:-
    for (i=0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            *(*(c + i) + j) = 0;
            for (k = 0; k < c1; k++)
            {
                *(*(c + i) + j) += (*(*(a + i) + k)) * (*(*(b + k) + j));
            }
        }
    }
    
    //(e) Display result matrix:-
    printf("Resultant Matrix:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
            printf("%d ", *(*(c + i) + j));
        printf("\n");
    }

    return 0;
}
