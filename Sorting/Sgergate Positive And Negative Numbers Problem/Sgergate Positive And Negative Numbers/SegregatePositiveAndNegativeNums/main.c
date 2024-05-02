#include <stdio.h>
#include <stdlib.h>

void Merge_Sort(signed int Arr[] ,unsigned int N ,unsigned int Start ,unsigned int End) ;
void Merge(signed int Arr[] ,unsigned int N ,unsigned int Start ,unsigned int Mid ,unsigned int End) ;
void PrintArray(signed int Arr[] ,unsigned int N) ;

signed int Array[8] = {9,-2,7,2,7,-3,10,-33} ;


int main()
{
    printf("Array Before MergeSort :\t") ;
    PrintArray(Array ,8) ;
    Merge_Sort(Array ,8 ,0 ,7) ;
    printf("Array After MergeSort  :\t") ;
    PrintArray(Array ,8) ;

    return 0;
}

void Merge_Sort(signed int Arr[] ,unsigned int N ,unsigned int Start ,unsigned int End){
    unsigned int Mid = 0 ;
    if(End <= Start){/*Nothing*/}
    else
    {
        Mid = (Start + End) / 2 ;
        Merge_Sort(Arr ,N ,Start ,Mid) ;
        Merge_Sort(Arr ,N ,(Mid + 1) ,End) ;
        Merge(Arr ,N ,Start ,Mid ,End) ;
    }
}

void Merge(signed int Arr[] ,unsigned int N ,unsigned int Start ,unsigned int Mid ,unsigned int End){
    unsigned int i = 0 , j = 0 , k = Start ;
    unsigned int LeftLen = (Mid - Start) + 1 ;
    unsigned int RightLen = End - Mid ;
    signed int LeftArr[LeftLen] ;
    signed int RightArr[RightLen] ;

    for(i = 0 ; i < LeftLen ; i++)
    {
        LeftArr[i] = Arr[Start + i] ;
    }
    for(j = 0 ; j < RightLen ; j++)
    {
        RightArr[j] = Arr[Mid + j + 1] ;
    }
    i = 0 , j = 0 ;
    while((i < LeftLen) && (LeftArr[i] < 0))
    {
        Arr[k] = LeftArr[i] ;
        i++ ;
        k++ ;
    }
    while((j < RightLen) && (RightArr[j] < 0))
    {
        Arr[k] = RightArr[j] ;
        j++ ;
        k++ ;
    }
    while(i < LeftLen)
    {
        Arr[k] = LeftArr[i] ;
        i++ ;
        k++ ;
    }
    while(j < RightLen)
    {
        Arr[k] = RightArr[j] ;
        j++ ;
        k++ ;
    }
}

void PrintArray(signed int Arr[] ,unsigned int N)
{
    for(int i = 0 ; i < N ; i++)
    {
        printf("%d\t",Arr[i]) ;
    }
    printf("\n") ;
}

