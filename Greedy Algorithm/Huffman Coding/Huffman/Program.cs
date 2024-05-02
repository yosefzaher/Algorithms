using System.CodeDom.Compiler;
using System.Collections;
using System.Security.Cryptography.X509Certificates;

public class Application
{   
    static void Main(string[] args)
    {
        string Msg = "The output from Huffman's algorithm can be viewed as a variable length code table for encoding a source symbol. The algorithm derives this table from the estimated probability or frequency of occurrence for each possible value of the source symbol. as in other entropy encoding methods, more common symbols are generally represented using fewer bits than less common symbols. Huffman's method can be efficiently implemented, finding a code in time linear to the number of input weights if these weights are sorted. However, although optimal among methods encoding symbols separately, Huffman coding is not always optimal among all compression methods it is replaced with arithmetic coding or asymmetric numeral systems if better compression ratio is required.";
        string m = "internet";
        Huffman huffman = new Huffman(Msg);

        foreach(char c in huffman.Codes.Keys)
        {
            Console.WriteLine(c +" =>  " + huffman.Codes[c]);
        }
        
    }
}

/*Heap Data Structure Class Start*/
public class HeapNode
{
    public char Data;
    public int Freq;
    public HeapNode LeftNode;
    public HeapNode RightNode;
    public HeapNode(char Data, int Freq)
    {
        this.Data = Data;
        this.Freq = Freq;
        this.LeftNode = this.RightNode = null;
    }
}
/*Heap Data Structure Class End*/

/*Huffman Algorithm Class Start*/
public class Huffman
{
    public Hashtable Codes = new Hashtable();
    char NULL_Char  = (char)0;
    private PriorityQueue<HeapNode ,int> MinHeap = new PriorityQueue<HeapNode, int>() ;
    public Huffman(string Message)
    {
        Hashtable FreqTable = new Hashtable() ;

        for (int i = 0; i < Message.Length; i++)
        {
            if(FreqTable[Message[i]] == null)
            {
                FreqTable[Message[i]] = 1 ;
            }
            else
            {
                FreqTable[Message[i]] = (int)FreqTable[Message[i]] + 1  ; 
            }
        }

        foreach(char K in  FreqTable.Keys) 
        {
            HeapNode NewNode = new HeapNode(K, (int)FreqTable[K]);
            MinHeap.Enqueue(NewNode, (int)FreqTable[K]);
        }

        HeapNode Left, Right, Top;
        int NewFreq;
        while (MinHeap.Count != 1)
        {
            Left = MinHeap.Dequeue();
            Right = MinHeap.Dequeue();
            NewFreq = Left.Freq + Right.Freq;
            Top = new HeapNode(NULL_Char, NewFreq);
            Top.LeftNode = Left;
            Top.RightNode = Right;
            Top.Freq = NewFreq;
            MinHeap.Enqueue(Top, NewFreq);
        }
        GenerateCode(MinHeap.Peek(), "");
    }

    private void GenerateCode(HeapNode Node ,string Str)
    {
        if(Node == null)
        {
            return;
        }
        if(Node.Data != NULL_Char)
        {
            Codes[Node.Data] = Str;
        }
        GenerateCode(Node.LeftNode, Str + "0");
        GenerateCode(Node.RightNode,Str + "1");
    }
}
/*Huffman Algorithm Class End*/


