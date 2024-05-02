#include <stdio.h>
#include <stdlib.h>

/**
  * @problem : Frequency Character [ASCII Letters Only]
  * @input   : "internet access"
  * @output  : i  n  t  e  r  a  c  s
               1  2  2  3  1  1  2  2  1
**/


char *Input = "internet access" ;

int Freq[127] ;


int main()
{
    int Count = 0 ;
    while('\0' != Input[Count])
    {
        Freq[Input[Count]]++ ;
        Count++ ;
    }

    Count = 0 ;
    for(int i = 0 ; i < 128 ; i++)
    {
        if(0 != Freq[i])
        {
            printf("%c - > %d \n",i,Freq[i]) ;
            Count++ ;
        }
        else{/*Nothing*/}
    }
    return 0;
}
