#include <stdio.h>
#include <stdlib.h>

unsigned int Start[6] = {9 ,10 ,11 ,12 ,13 ,15}  ;
unsigned int End[6] = {11 ,11 ,12 ,14 ,15 ,16}  ;
unsigned int Results[] ;

unsigned int *Counter = NULL ;

unsigned int* Activity_Selection_Greedy_Algorithm(unsigned int Start[] ,unsigned int End[] ,unsigned int N) ;
void Print_Array(unsigned int Arr[] ,unsigned int N) ;

int main()
{
    Counter = Activity_Selection_Greedy_Algorithm(Start ,End ,6) ;
    Print_Array(Results ,*Counter) ;
    return 0;
}


unsigned int* Activity_Selection_Greedy_Algorithm(unsigned int Start[] ,unsigned int End[] ,unsigned int N)
{
    static unsigned int Counter = 1 ;
    unsigned int i = 1 ;
    unsigned int j = 0 ;
    Results[0] = 0 ;

    for( ;i < N ; i++)
    {
        if(Start[i] >= End[j])
        {
            Results[Counter] = i ;
            j = i ;
            Counter++ ;
        }
    }
    return (&Counter) ;
}

void Print_Array(unsigned int Arr[] ,unsigned int N)
{
    for(int i = 0 ; i < N ; i++)
    {
        if(i == N-1)
        {
            printf("%d] \n",Arr[i]) ;
        }
        else if(i == 0)
        {
            printf("[%d ,",Arr[i]) ;
        }
        else
        {
            printf("%d ,",Arr[i]) ;
        }
    }
}

