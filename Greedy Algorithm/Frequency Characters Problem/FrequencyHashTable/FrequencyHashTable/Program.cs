using System.Collections;
using System.Security.Cryptography.X509Certificates;

namespace FrequencyHashTable
{
    internal class GreedyAlgorithm
    {
        static void Main(string[] args)
        {
            string key = "The output from Huffman's algorithm can be viewed as a variable length code table for encoding a source symbol. The algorithm derives this table from the estimated probability or frequency of occurrence for each possible value of the source symbol. as in other entropy encoding methods, more common symbols are generally represented using fewer bits than less common symbols. Huffman's method can be efficiently implemented, finding a code in time linear to the number of input weights if these weights are sorted. However, although optimal among methods encoding symbols separately, Huffman coding is not always optimal among all compression methods it is replaced with arithmetic coding or asymmetric numeral systems if better compression ratio is required.";
            Frequency(key);
        }

        static void Frequency(string Key)
        {
            Hashtable hashtable = new Hashtable();  

            Console.WriteLine("Hash Table Frequency :-");
            for (int i = 0; i < Key.Length; i++)
            {
                if (hashtable[Key[i]] == null)
                {
                    hashtable[Key[i]] = 1;
                }
                else
                {
                    hashtable[Key[i]] = (int)hashtable[Key[i]] + 1; 
                }
            }

            foreach(char KeyChar in hashtable.Keys) 
            {
                Console.WriteLine(KeyChar + " ->  " + hashtable[KeyChar]);
            }
            Console.WriteLine("=============================================");
            SortHash(hashtable);
        }

        static void SortHash(Hashtable Table)
        {
            int[,] Freq = new int[Table.Count ,2] ;
            int i = 0;
            foreach(char KeyChar in Table.Keys)
            {
                Freq[i, 0] = (int)KeyChar ;
                Freq[i, 1] = (int)Table[KeyChar]; 
                i++;
            }
            Sort(Freq ,0 ,Table.Count - 1);
            
            for(int j =  0; j <Table.Count  ; j++)
            {
                Console.Write((char)Freq[j, 0] + " ->    ");
                Console.WriteLine((int)Freq[j, 1]);
            }
        }

        static void Sort(int[,] Freq ,int Start ,int End)
        {
            if(End <= Start)
            {
                return ;
            }
            int Mid = (Start + End) / 2;

            Sort(Freq, Start ,Mid) ;
            Sort(Freq, (Mid+1) ,End) ;
            Merge(Freq ,Start ,Mid ,End) ;

        }

        static void Merge(int[,] Freq, int Start, int Mid, int End)
        {
            int i, j, k;
            int Left_length = Mid - Start + 1;
            int Right_Length = End - Mid;
            int[,] Left_Arr = new int[Left_length, 2];
            int[,] Right_Arr = new int[Right_Length, 2];

            // Populate Left_Arr
            for (i = 0; i < Left_length; i++)
            {
                Left_Arr[i, 0] = Freq[Start + i, 0];
                Left_Arr[i, 1] = Freq[Start + i, 1];
            }

            // Populate Right_Arr
            for (j = 0; j < Right_Length; j++)
            {
                Right_Arr[j, 0] = Freq[Mid + j + 1, 0];
                Right_Arr[j, 1] = Freq[Mid + j + 1, 1];
            }

            i = j = 0;
            k = Start;

            // Merge Left_Arr and Right_Arr back into Freq
            while (j < Right_Length && i < Left_length)
            {
                if (Right_Arr[j, 1] <= Left_Arr[i, 1])
                {
                    Freq[k, 0] = Right_Arr[j, 0];
                    Freq[k, 1] = Right_Arr[j, 1];
                    j++;
                }
                else
                {
                    Freq[k, 0] = Left_Arr[i, 0];
                    Freq[k, 1] = Left_Arr[i, 1];
                    i++;
                }
                k++;
            }

            while (j < Right_Length)
            {
                Freq[k, 0] = Right_Arr[j, 0];
                Freq[k, 1] = Right_Arr[j, 1];
                j++;
                k++;
            }
            while (i < Left_length)
            {
                Freq[k, 0] = Left_Arr[i, 0];
                Freq[k, 1] = Left_Arr[i, 1];
                i++;
                k++;
            }
        }

    }
}
