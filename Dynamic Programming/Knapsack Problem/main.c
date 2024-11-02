#include <stdio.h>
#include <stdlib.h>

// Define the number of items and the maximum weight capacity of the knapsack
#define NUM_OF_ITEMS 4
#define MAX_WEIGHT 8

// Arrays to store items, their respective profits, and weights
char Items[NUM_OF_ITEMS] = {'1', '2', '3', '4'};  // Identifiers for items
char Profit[NUM_OF_ITEMS] = {4, 9, 12, 11};       // Profit values for each item
char Weight[NUM_OF_ITEMS] = {1, 3, 5, 4};         // Weight values for each item
char Solution[NUM_OF_ITEMS] = {0, 0, 0, 0};       // Array to store selected items in the optimal solution

// Variable to keep track of remaining weight capacity in the knapsack
int remain = MAX_WEIGHT;

// Function declarations
int Max(int x, int y);                             // Function to get the maximum of two integers
void Print_2DArr(int **Arr, int Row, int Columns); // Function to print a 2D array

int main(void) 
{
    // Dynamic allocation for 2D array Ptr to store maximum profit values
    int **Ptr = (int **)calloc(NUM_OF_ITEMS + 1, sizeof(int *));
    if(!Ptr)  // Check for successful allocation
    {
        return -1; // Return error if memory allocation fails
    }
    else
    {
        // Allocate memory for each row in Ptr and initialize to zero
        for(int i = 0; i <= NUM_OF_ITEMS; i++)
        {
            Ptr[i] = (int *)calloc(MAX_WEIGHT + 1, sizeof(int));
            if(!(Ptr[i]))  // Check for allocation failure of row
            {   
                // Free previously allocated memory if allocation fails
                for (int j = i; j >= 0; j--)
                {
                    free(Ptr[j]);
                }
                free(Ptr);
                Ptr = NULL; // Nullify pointer after freeing

                return -1; // Return error if memory allocation fails
            }
        }

        // Filling Ptr array using dynamic programming to solve the knapsack problem
        for (int i = 1, c0 = 0; i <= NUM_OF_ITEMS; i++, c0++)
        {
            for(int j = 1; j <= MAX_WEIGHT; j++)
            {
                if(Weight[c0] <= j)
                {
                    // Maximize profit by choosing to include or exclude the current item
                    Ptr[i][j] = Max(Ptr[i - 1][j], Profit[c0] + Ptr[i - 1][j - Weight[c0]]);
                }
                else
                {
                    Ptr[i][j] = Ptr[i - 1][j]; // Exclude the item if it exceeds current weight limit
                }
            }
        }
        
        // Backtracking to find the items included in the optimal solution
        int i = NUM_OF_ITEMS;
        int j = MAX_WEIGHT;
        while (remain > 0)
        {
            if(Ptr[i][j] > Ptr[i - 1][j]) // If current item contributes to max profit
            {
                Solution[i - 1] = Weight[i - 1]; // Include the item in the solution
                remain -= Weight[i - 1];         // Reduce remaining weight capacity
                j = remain;                      // Update column pointer
                i--;                             // Move to previous item
            }
            else
            {
                i--; // Move to the previous item if the current item is not included
            }
        }
        
        // Display the selected items in the solution
        for(int i = 0; i < NUM_OF_ITEMS; i++)
        {
            printf("%d ", Solution[i]);
        }
        printf("\n");
    }

    return 0;
}

// Function to return the maximum of two integers
int Max(int x, int y) 
{
    if(x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

// Function to print the elements of a 2D array
void Print_2DArr(int **Arr, int Row, int Columns)
{
    for(int i = 0; i < Row; i++)
    {
        for(int j = 0; j < Columns; j++)
        {
            printf("%d  ", Arr[i][j]);
        }
        printf("\n");
    }
    printf("===============================================\n");
}
