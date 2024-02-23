#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d", &n);

    int *ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("memory not allocated");
        exit(1);
    }
    else
    {   
        for (int i = 0; i < n; i++)
        {
            printf("enter the integer");
            scanf("%d",ptr+i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d",*(ptr+i));
    }
    
    return 0;
}