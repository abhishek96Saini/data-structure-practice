#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,*p,numberofelements;

    printf("How many elements?\n");
    scanf("%d",&numberofelements);

    p = (int *)malloc(numberofelements * sizeof(int));

    for(i=0; i<numberofelements; i++)
        p[i] = i+1;

    printf("\n");
    for(i=0;i<numberofelements;i++)
        printf("\t%d",p[i]);

    printf("\n");

    return 0;
}
