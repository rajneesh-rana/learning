

#include <iostream>
#include <stdio.h>


int main()
{
		unsigned int row, col;
    printf("\n\n");
		
		int M[3][4] ={  {1,2,3,4},
										{5,6,7,8},
										{9,10,11,12}
								};
		int r=3,c=4; 
		int *p=(int*)M;
    for(row = 0; row < r; row++)
    {
        for(col = 0; col < c; col++)
        {
            //printf("%d\t", *(p + row * c + col));
						M[col][c-row-1]=M[row][col];
        }
        printf("\n");
    }

		r^=c^=r^=c^=r;
 
    for(row = 0; row < r; row++)
    {
        for(col = 0; col < c; col++)
        {
            //printf("%d\t", *(p + row * c + col));
					  printf(" %d ",M[row][col]);
        }
        printf("\n");
    }

    printf("\n\n");
}
