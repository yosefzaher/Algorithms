#include <stdio.h>
#include <stdlib.h>

int String_Length(char *str);
int Print_2DArray(int **Arr, int Rows, int Columns);
int MAX(int x, int y);

int ret = 0;

int main(void) {
    char *text_01 = "HELLOWORLD";
    char *text_02 = "OHELOD";

    int Out = String_Length(text_02);

    int c1 = 0;
    int c2 = 0;

    /* Milestone 1 -> Create the Table for Solution */
    int Row = String_Length(text_02) + 1;
    int Column = String_Length(text_01) + 1;

    /* Create the Table of the Solution Using DMA */
    int **Table = (int **)calloc(Row, sizeof(int *)); // Array of pointers to array of integers
    if (!Table) 
	{
        return -1;
    } 
	else 
	{
        for (int i = 0; i < Row; i++) 
		{
            Table[i] = (int *)calloc(Column, sizeof(int)); // Allocate integers
            if (!Table[i]) 
			{
                for (int j = i; j >= 0; j--) 
				{
                    free(Table[j]);
                }
                free(Table);
                return -1;
            }
        }

        /* Milestone 2 -> Fill the Table Cells */
        for (int i = 1, c1 = 0; i < Row; i++, c1++) 
		{
            for (int j = 1, c2 = 0; j < Column; j++, c2++) 
			{
                // if Characters Match
                if (text_02[c1] == text_01[c2]) 
				{
                    Table[i][j] = 1 + Table[i - 1][j - 1];
                } 
				else 
				{
                    Table[i][j] = MAX(Table[i - 1][j], Table[i][j - 1]);
                }
            }
        }

        /* Milestone 3 -> Find the LCS from the Table */
		int LCS_Length = Table[Row - 1][Column - 1] ; //The Length Of LCS
        char *LCS = (char *)calloc(LCS_Length + 1, sizeof(char)); // Allocate based on LCS length + 1
        int Counter = LCS_Length - 1; // Start filling LCS from the last position
        int i = Row - 1, j = Column - 1;

        // Start from the bottom-right cell
        while((i > 0) && (j > 0)) 
		{
			if(Table[i][j] > Table[i][j-1])
			{
				if(Table[i][j] == Table[i-1][j])
				{
					i-- ;
				}
				else
				{
					LCS[Counter] = text_02[i-1] ;
					Counter-- ;
					i-- ;
					j-- ;
				}
			}
			else
			{
				j-- ;
			}
        }

        /* Milestone 4 -> Print the Output */
        printf("LCS: %s\n", LCS);

        // Free memory
        free(LCS);
        for (int i = 0; i < Row; i++) {
            free(Table[i]);
        }
        free(Table);
    }

    return 0;
}

int String_Length(char *str) {
    int len = 0;
    int Count = 0;

    if (NULL == str) {
        return -1;
    }

    while (str[Count] != '\0') {
        len++;
        Count++;
    }

    return len;
}

int Print_2DArray(int **Arr, int Rows, int Columns) {
    if (NULL == Arr) {
        return -1;
    }

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Columns; j++) {
            printf("%d\t", Arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}

int MAX(int x, int y) {
    return (x > y) ? x : y;
}
