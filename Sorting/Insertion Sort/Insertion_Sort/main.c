#include <stdio.h>
#include <stdlib.h>

unsigned int X[] ;
unsigned int Key = 0 ;
unsigned int N = 0;
int i = 0 ;
int j = 0 ;
void PrintArray(unsigned int Arr[] ,unsigned int N) ;

int main()
{
    printf("Enter N :  ");
    scanf("%d",&N) ;

    for(int i = 0 ; i < N ; i++)
    {
        printf("Enter X[%d] = ",i) ;
        scanf("%d",&X[i]) ;
        fflush(stdin) ;
    }

    printf("Array Before Insertion Sort :\t");
    PrintArray(X ,N);

    for(i = 1 ; i < N ; i++)
    {
        Key = X[i] ;
        for(j = i-1 ; j >= 0 ; j--)
        {
            if(Key < X[j])
            {
                X[j+1] = X[j] ;
            }
            else
            {
                break ;
            }
        }
        X[j+1] = Key ;
    }

    printf("Array After Insertion Sort :\t");
    PrintArray(X ,N);

    return 0;
}

void PrintArray(unsigned int Arr[] ,unsigned int N)
{
    for(int i = 0 ; i < N ; i++)
    {
        printf("%d\t",Arr[i]) ;
    }
    printf("\n") ;
}
