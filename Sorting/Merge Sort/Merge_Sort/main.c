#include <stdio.h>
#include <stdlib.h>

void Merge_Sort(unsigned int Arr[] ,unsigned int Num_Elem ,unsigned int Start ,unsigned int End) ;
void Merge(unsigned int Arr[] ,unsigned int Num_Elem ,unsigned int Start ,unsigned int Mid ,unsigned int End) ;
void Print_Array(unsigned int Arr[] ,unsigned int Num_Elem) ;


int main()
{
    unsigned int Arr[5] = {4 ,5 ,1 ,9} ;
    printf("Before Merge Sort =>\t");
    Print_Array(Arr ,4) ;

    Merge_Sort(Arr ,4 ,0 ,3) ;

    printf("After Merge Sort =>\t");
    Print_Array(Arr ,4) ;
    return 0;
}

void Merge_Sort(unsigned int Arr[] ,unsigned int Num_Elem ,unsigned int Start ,unsigned int End)
{
    unsigned int Mid = 0 ;
    if(End <= Start){/**/}
    else
    {
        Mid = (Start + End) / 2 ;
        Merge_Sort(Arr ,Num_Elem ,Start ,Mid) ;
        Merge_Sort(Arr ,Num_Elem ,(Mid+1) ,End) ;
        Merge(Arr ,Num_Elem ,Start ,Mid ,End) ;
    }

}

void Merge(unsigned int Arr[] ,unsigned int Num_Elem ,unsigned int Start ,unsigned int Mid ,unsigned int End)
{
    unsigned int i = 0 , j = 0 , k = Start;
    unsigned int Left_Len = (Mid - Start) + 1 ;
    unsigned int Right_Len =  End - Mid  ;
    unsigned int Right_Arr[Right_Len] ;
    unsigned int Left_Arr[Left_Len] ;
    for(i = 0 ; i < Left_Len ; i++)
    {
        Left_Arr[i] = Arr[i+Start] ;
    }
    for(i = 0 ; i < Right_Len ; i++)
    {
        Right_Arr[i] = Arr[i + Mid + 1] ;
    }
    i = j = 0  ;
    while((i < Left_Len) && (j < Right_Len))
    {
        if(Left_Arr[i] <= Right_Arr[j])
        {
            Arr[k] = Left_Arr[i] ;
            i++ ;
        }
        else
        {
            Arr[k] = Right_Arr[j] ;
            j++ ;
        }
        k++ ;
    }
    while(i < Left_Len)
    {
        Arr[k] = Left_Arr[i] ;
        i++ ;
        k++ ;
    }
    while(j < Right_Len)
    {
        Arr[k] = Right_Arr[j] ;
        j++ ;
        k++ ;
    }
}

void Print_Array(unsigned int Arr[] ,unsigned int Num_Elem)
{
    for(int i = 0 ; i < Num_Elem ; i++)
    {
        printf("%d\t",Arr[i]) ;
    }
    printf("\n") ;
}










