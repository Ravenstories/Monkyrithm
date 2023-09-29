#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    !!! NOTICE: Incomplete
*/

void radixSort (int array[], int arraySize)
{
    int maxValue = getMaxValue(array, arraySize);
    int digitLength = getDigitLength(maxValue);

    for (int i = 0; i < arraySize-1; i++)
    {
     printf("%d \n", array[i]);
    }

    //int bucket[digitLength][10]; //OLD
    int bucket[10][arraySize]; //NEW
    int counter[10];

    int modulusTemp = 100;
    int dividerTemp = 10;

    for (int i = 0; i < digitLength; i++)
    {
        memset(counter, 0, sizeof counter);
        memset(bucket, 0, sizeof bucket);

        if(i < 1)
        {
            for (int j = 0; j < arraySize-1; j++)
            {
                printf("Iteration %d BUCKET BUCKET BUCKET BUCKET\n", i+1);
                int bucketNumber = array[j] % 10;
                //bucket[i][bucketNumber] = array[j]; //OLD

                bucket[bucketNumber][counter[bucketNumber]] = array[j]; //NEW
                counter[bucketNumber]++;

                printf("Iteration %d, number : %d\n", i+1, array[j]);
                printf("Iteration %d, bucket : %d\n",i+1, bucketNumber);
                printf("Iteration %d, counter: %d\n", i+1, counter[bucketNumber]);
            }
            // Put into array here??
        }
        else if(i > 0)
        {
            for (int j = arraySize -1; j > 0; j--)
            {
                printf("Iteration %d BUCKET BUCKET BUCKET BUCKET\n", i+1);
                int lastDigit = array[j] % 10;
                int bucketNumber = ((array[j]-lastDigit) % modulusTemp)/dividerTemp; //modulus starts at 100, divider at 10
                //bucket[i][bucketNumber] = array[j]; //OLD

                bucket[bucketNumber][counter[bucketNumber]] = array[j]; //NEW
                counter[bucketNumber]++;

                printf("Iteration %d, number : %d\n", i+1, bucket[i][bucketNumber]);
                printf("Iteration %d, bucket : %d\n", i+1, bucketNumber);
                printf("Iteration %d, counter: %d\n", i+1, counter[bucketNumber]);
            }
            modulusTemp *= 10;
            dividerTemp *= 10;
            // Put into array here??
        }

        // HER PRØVER JEG AT SMIDE DET TILBAGE I ARRAY, DET VIRKER IKKE

        printf("AFTER SORTING AFTER SORTING AFTER SORTING\n");
        int placement;
        for(int j = 0; j < 10; j++)
        {
            placement = 0;
            printf("Bucket number : %d\n", j);
            for(int k = 0; k < counter[j]; k++)
            {
                array[placement] = bucket[j][k];
                //printf("FROM BUCKET %d\n", bucket[j][k]);
                printf("FROM ARRAY %d\n", array[placement]);
                printf("PLACEMENT : %d\n", placement);
                /*
                int testB = bucket[j][k];
                int testA = array[placement];
                printf("FROM BUCKET %\n", testB);
                printf("FROM ARRAY %\n", testA);
                printf("PLACEMENT : %d\n", placement);
                */
                placement++;

            }
        }
    }

    for (int i = 0; i < arraySize-1; i++)
    {
     printf("%d \n", array[i]);
    }
}

int getMaxValue(int array[], int arraySize)
{
    int maxValue = array[0];
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] > maxValue)
        {
            maxValue = array[i];
        }
    }
    return maxValue;
}

int getDigitLength(int maxValue)
{
    int digitLength = 0;
    while(maxValue > 0)
    {
        digitLength++;
        maxValue /= 10;
    }
    return digitLength;
}