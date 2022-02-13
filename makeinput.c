%%writefile makeinput.c

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
//PRN 2019BTEIT00045
#define star "\n\n*******************************************************\n\n"
void main()
{
    srand(time(0));
    FILE *input;
    if((input = fopen("/content/in.dat","ab+")) == NULL)
    {
        printf("something went wrong!!");
        exit(1);
    }
 
    float A[20][20]= {0};
    float B[20]= {0};
    int i,j,n;
 
    printf(star);
    printf("\n Enter the order of square matrix: ");
    scanf("%d",&n);
    printf(star);
    printf("\n Generated Matrix elements are:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            float val=rand()%10;
            printf("Value at A[%d][%d] element: %f \n", i,j,val);
            fwrite(&val,sizeof(A[i][j]),1,input);
        }
    }
    printf(star);
    printf("\n Generated Constant terms are: \n");
    for(i=0; i<n; i++)
    {
        float val=rand()%10;
        if(rand()%10>5)
        val*=-1;
        printf("Value at B[%d] element: %f \n", i,val);
        fwrite(&val,sizeof(B[i]),1,input);
    }
    printf(star);
    fclose(input);
}
