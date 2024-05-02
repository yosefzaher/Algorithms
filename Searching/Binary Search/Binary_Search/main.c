#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

signed int Recursive_Binary_Search(unsigned int Arr[] ,unsigned int N ,unsigned int High ,unsigned int Low ,unsigned int Key) ;
signed int Noremal_Binary_Search(unsigned int Arr[] ,unsigned int N ,unsigned int Key) ;

unsigned int X[7] = {1 ,2 ,3 ,4 ,5 ,6 ,7} ;
signed int Index = 0 ;
unsigned int Item = 0 ;

int main()
{
    printf("Please Enter The Item You Want To Search For :  ") ;
    scanf("%d" ,&Item) ;
    printf("Binary Search Algorithm") ;
    for(int i = 0 ; i < 13 ; ++i)
    {
        printf(".") ;
        Sleep(250) ;
    }
    printf("\n") ;
    Index = Recursive_Binary_Search(X ,7 ,6 ,0 ,Item) ;
    if(-1 == Index)
    {
        printf("The Element Doesn't Exist :( \n") ;
    }
    else
    {
        printf("The Element You Search for is in index : %d \n",Index) ;
    }
    printf("========================================================================================\n") ;
    printf("Please Enter The Item You Want To Search For :  ") ;
    scanf("%d" ,&Item) ;
    printf("Binary Search Algorithm") ;
    for(int i = 0 ; i < 13 ; ++i)
    {
        printf(".") ;
        Sleep(250) ;
    }
    printf("\n") ;
    Index = Noremal_Binary_Search(X ,7,Item) ;
    if(-1 == Index)
    {
        printf("The Element Doesn't Exist :( \n") ;
    }
    else
    {
        printf("The Element You Search for is in index : %d \n",Index) ;
    }
    return 0;
}

signed int Recursive_Binary_Search(unsigned int Arr[] ,unsigned int N ,unsigned int High ,unsigned int Low ,unsigned int Key)
{
    unsigned int Mid = (High + Low) / 2 ;
    if(Low > High)
    {
        return -1 ;
    }
    if(Key == Arr[Mid])
    {
        return Mid ;
    }
    else if(Key > Arr[Mid])
    {
        # if 0
        if(Mid == 0)
        {
            return -1 ;
        }
        #endif // 0
        Low = Mid + 1 ;
        return Recursive_Binary_Search(Arr ,N ,High ,Low ,Key) ;
    }
    else if(Key < Arr[Mid])
    {
        # if 0
        if(Mid == 0)
        {
            return -1 ;
        }
        #endif // 0
        High = Mid - 1 ;
        return Recursive_Binary_Search(Arr ,N ,High ,Low ,Key) ;
    }
}

signed int Noremal_Binary_Search(unsigned int Arr[] ,unsigned int N ,unsigned int Key)
{

    unsigned int Low = 0 ;
    unsigned int High = N-1 ;

    unsigned int Mid = 0 ;

    while(Low <= High)
    {
        Mid = (High + Low) / 2 ;
        if(Key == Arr[Mid])
        {
            return Mid ;
        }
        else if(Key < Arr[Mid])
        {
            High = Mid - 1 ;
        }
        else if(Key > Arr[Mid])
        {
            Low = Mid + 1 ;
        }
    }
    return -1 ;
}
