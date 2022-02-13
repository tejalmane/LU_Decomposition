%%writefile p2ludecompose.c
//LU Decomposition Algorithm
#include<stdio.h>
#include<stdlib.h>
//AX=B  Consider A=LU where L is lower Triangular matrix
//U is upper triangular matrix
// LUX=B Let Y=UX hence LY=B

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
    float A[3][3]= {0},L[3][3]= {0}, U[3][3];
    float B[3]= {0}, X[3]= {0},Y[3]= {0};
    int i,j,k,n;
    printf("Enter the order of square matrix: ");
    scanf("%d",&n);
    //reading input from file
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

   //calculating upper triangular matrix
   for (int i = 0; i < n; i++)
	{
		// Upper Triangular
		for (int k = i; k < n; k++)
		{
			// Summation of L(i, j) * U(j, k)
			int sum = 0;
			for (int j = 0; j < i; j++)
				sum += (L[i][j] * U[j][k]);

			// Evaluating U(i, k)
			U[i][k] = A[i][k] - sum;
		}

		// Lower Triangular
		for (int k = i; k < n; k++)
		{
			if (i == k)
	       L[i][i] = 1; // Diagonal as 1
			else
			{
				// Summation of L(k, j) * U(j, i)
				int sum = 0;
				for (int j = 0; j < i; j++)
					sum += (L[k][j] * U[j][i]);

				// Evaluating L(k, i)
				L[k][i]
					= (A[k][i] - sum) / U[i][i];
			}
		}
	}
    printf("Lower triangular matrix\n[L]: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%9.3f",L[i][j]);
        printf("\n");
    }
    printf("\n\nUpper triangular matrix\n[U]: \n");
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
    printf("\n\nOUTPUT\n[X]: \n");
    
    for(i=0; i<n; i++)
    {
        printf("%9.3f",X[i]);
        fwrite(&X[i],sizeof(X[i]),1,output);
    }
    fclose(input);
    fclose(output);
}
