%%writefile ludecompose.c
//Initial code to make binary files
#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *input;
    if((input = fopen("/content/in.dat","ab+")) == NULL)
    {
        printf("Error! opening input file");
        exit(1);
    }
    float A[3][3]= {0};
    float B[3]= {0};
    int i,j,n;
    printf("Enter the order of square matrix: ");
    scanf("%d",&n);
    printf("\nEnter matrix element:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("Enter A[%d][%d] element: ", i,j);
            scanf("%f",&A[i][j]);
            fwrite(&A[i][j],sizeof(A[i][j]),1,input);
        }
    }
    printf("\nEnter the constant terms: \n");
    for(i=0; i<n; i++)
    {
        printf("B[%d]: ",i);
        scanf("%f",&B[i]);
        fwrite(&B[i],sizeof(B[i]),1,input);
    }
    fclose(input);
}
