//Armin Darabi Mahboub
//libs
#include <stdio.h>
#include <math.h>

int main(void)
{
    /*input*///////////////////////////////////////////////////
    int n;
    printf("Please enter the number: ");
    scanf("%d", &n);
    if(n > 15 || n < 1)
    {
        printf("Your number must be between 1 to 15");
        return 1;
    }

    /*calculation*/////////////////////////////////////////////
    int total = (int)pow(2, n);
    int rows[total][n]; //we will have 2^n different values that each has n numbers in total

    /*
    0
    1
    1
    0
    is the pattern which keeps repeating until we meet the 2^n
    each one repeats 2^(position - 1) (cause position starts from 0, we ignore the -1)
    */
    
    for(int position = 0; position < n; position++)
    {
        int totalTemp = total;
        int step = 0; //using for selecting the each step in 0110 loop

        while (1)
        {
            //first 0
            if (totalTemp > 0)
            {
                totalTemp -= (int) pow(2, position);
                for (int numbers = step; numbers < step + (int) pow(2, position); numbers++)
                {
                    rows[numbers][position] = 0;
                }
                step += (int) pow(2, position);
            }
            
            //first 1
            if (totalTemp > 0)
            {
                totalTemp -= (int) pow(2, position);
                for (int numbers = step; numbers < step + (int) pow(2, position); numbers++)
                {
                    rows[numbers][position] = 1;
                }
                step += (int) pow(2, position);
            }

            //second 1
            if (totalTemp > 0)
            {
                totalTemp -= (int) pow(2, position);
                for (int numbers = step; numbers < step + (int) pow(2, position); numbers++)
                {
                    rows[numbers][position] = 1;
                }
                step += (int) pow(2, position);
            }

            //second 0
            if (totalTemp > 0)
            {
                totalTemp -= (int) pow(2, position);
                for (int numbers = step; numbers < step + (int) pow(2, position); numbers++)
                {
                    rows[numbers][position] = 0;
                }
                step += (int) pow(2, position);
            }

            //Dead-end
            if (totalTemp <= 0)
            {
                break;
            }
        }
    }

    /*output*////////////////////////////////////////////////////////////////
    for (int row = 0; row < total; row++)
    {
        for (int position = n - 1; position >= 0; position -= 1)
        {
            printf("%d", rows[row][position]);
        }
        printf("\n");
    }

    getchar();
    getchar();
    return 0;
}