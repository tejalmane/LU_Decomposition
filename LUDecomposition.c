%%writefile LUDecomposition.c
//PRN 2019BTEIT00045
//LU Decomposition Algorithm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define star "\n\n*******************************************************\n\n"

void main()
{
    FILE *input,*output;
    if((input = fopen("/content/in.dat","ab+")) == NULL)
    {
        printf("Error! opening input file");
        exit(1);
    }
    if((output = fopen("/content/out.dat","ab+")) == NULL)
    {
        printf("Error! opening output file");
        exit(1);
    }
    float A[20][20]= {0},L[20][20]= {0}, U[20][20];
    float B[20]= {0}, X[20]= {0},Y[20]= {0};
    int i,j,k,n;
 
    printf(star);
    printf("Enter the order of square matrix: ");
    scanf("%d",&n);
    fseek(input, 0, SEEK_SET);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            fread(&A[i][j], sizeof(float), 1, input);
        }
    }
    for(i=0; i<n; i++)
    {
        fread(&B[i], sizeof(float), 1, input);
    }
    //  calc time for the program
    clock_t begin = clock();
        for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(i<=j)
            {
                U[i][j]=A[i][j];
                for(k=0; k<i-1; k++)
                    U[i][j]-=L[i][k]*U[k][j];
                if(i==j)
                    L[i][j]=1;
                else
                    L[i][j]=0;
            }
            else
            {
                L[i][j]=A[i][j];
                for(k=0; k<=j-1; k++)
                    L[i][j]-=L[i][k]*U[k][j];
                L[i][j]/=U[j][j];
                U[i][j]=0;
            }
        }
    }

    printf("\n");
    printf(star);
    printf("[L]: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%9.3f",L[i][j]);
        printf("\n");
    }
    printf(star);
    printf("\n\n[U]: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%9.3f",U[i][j]);
        printf("\n");
    }
   
    for(i=0; i<n; i++)
    {
        Y[i]=B[i];
        for(j=0; j<i; j++)
        {
            Y[i]-=L[i][j]*Y[j];
        }
    }
    printf(star);
    printf("\n\n[Y]: \n");
    for(i=0; i<n; i++)
    {
        printf("%9.3f",Y[i]);
    }
    for(i=n-1; i>=0; i--)
    {
        X[i]= Y[i];
        for(j=i+1; j<n; j++)
        {
            X[i]-=U[i][j]*X[j];
        }
        X[i]/=U[i][i];
    }
 
    clock_t end = clock();


    printf(star);
    printf("\n\n[X]: \n");
    for(i=0; i<n; i++)
    {
        printf("%9.3f ",X[i]);
        fwrite(&X[i],sizeof(X[i]),1,output);
    }
  printf(star);
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Compute time will be : %f",time_spent);
    fclose(input);
    fclose(output);
}
