/*Huffman coding is a lossless data compression algorithm, meaning there is no loss of data in the compression.
The basic idea is:
    --The user inputs data (in this case, it will be a string).
    --Each character in the string is given an occurence frequency.
    --e.g the string "A_DEAD_DAD_CEDED_A_BAD_BABE_A_BEADED_ABACA_BED".
        ++A:11
        ++B:6
        ++C:2
        ++D:10
        ++E:7
        ++_:10
    --The character and the number of occurences will be stored in a 'huffmanLeaf' Struct.
    --Take the 2 'leafs' with the lowest frequency value.
    --Create a new leaf from the 2 leafs with the combined frequency and characters.
    --Repeat until only one leaf remains.

    --The finished, huffman tree is output as the following Huffman code dictionary:
        ++_:00
        ++D:01
        ++A:10
        ++E:110
        ++C:1110
        ++B:1111
*/
#include <bits/stdc++.h>
using namespace std;

//The huffmanLeaf struct. Stores character, number of occurences, and the 'leafs' to the left and the right (these are stored as pointers to the actual leafs, as opposed to the leafs themselves).
struct huffmanLeaf{
    //Initialising variables for Huffman Leaf.
    /*Consists of:
        ++A char, which is the letter for the leaf.
        ++An int, which stores the number of occurences for the character.
        ++Pointers to the leafs to the left and right of any given leaf in the tree.
    */
    char character;
    unsigned occurences;
    huffmanLeaf *left, *right;

    //Constructor for leaf.
    //Initialises all variables to be 'empty'.
    huffmanLeaf(char character, unsigned occurences){
        left = right = NULL;
        this->character = character;
        this->occurences = occurences;
    }

    //Destructor method for the struct.
    //Deletes the left and right leafs.
    ~huffmanLeaf(){
        delete left;
        delete right;
    }
};

//A function to compare the two leafs to see which is the larger is required.
struct leafComparison{
    //A boolean operator to check which of the two frequencies of the leafs are larger.
    //Returns true if the left freqency is larger.
    //Otherwise returns false.
    //The bool operator() part allows me to use open and close brackets around a given leaf as shorthand for the code.
    bool operator() (huffmanLeaf* left, huffmanLeaf* right){
        return ( left->occurences > right->occurences );
    }
};

//This function prints out the code for the Huffman Tree.
//Takes  a string, and a huffmanLeaf struct as input.
//This huffmanLeaf, however, is the root, the endpoint of the huffman alorithm.
void huffmanTreePrint(struct huffmanLeaf* root, string str){
    //If the root of the tree does not exist, the function exits.
    if (!root){
        return;
    }

    //These two lines just handle printing out the character.
    //If the character in the root is not a placeholder character (in this case, '?'), the Huffman Tree is printed out, one character at a time.
    if(root->character != '?'){
        cout << root->character << ":" << str << "\n";
    }

    //These two lines handle printing out the corresponding huffman code for the character.
    //If there are leafs to the left, then a '0' is appended to the string.
    //If there are leafs to the right, then a '1' is appended to the string.
    huffmanTreePrint(root->left, str+"0");
    huffmanTreePrint(root->right, str+"1");
}

//The main algorith for the huffman encoding.
//Takes an array of characters, an array of occurence, and an int, the size of the huffmanHeap heap.
void huffmanAlgorithm(char character[], int frequency[], int len){
    //Initalises 3 huffmanLeaf structs.
    struct huffmanLeaf *left, *right, *top;


    //Creates a priority queue, named huffmanHeap. The priority queue makes sure that the largest value is always at the top, and can be easily accessed.
    //This is similar in function to a heap, hence the name, 'huffmanHeap'.
    /*
    It takes:
        ++The huffmanLeaf struct
        ++A container for the structs (in the form of a vector)
        ++A way to check for the largest element (obtained using the leafComparison function defined eariler)
    */
    priority_queue<huffmanLeaf*, vector<huffmanLeaf*>, leafComparison> huffmanHeap;

    //This for loop creates a new huffman leap for each character, with the corresponding number of occurences.
    //It is repeated until the 'i' value reaches the 'size' value, in other words, it repeats for the lenght of the data being encoded.
    for(int i=0; i<len; i++){
        huffmanHeap.push(new huffmanLeaf( character[i], frequency[i] ));
    }

    //While the heap does not consist of one element:
    while(!(huffmanHeap.size() == 1)){

        /*This takes the two leafs with the lowest amount of occurences in the tree
        and extracts (pops) them.*/
        //This pops the left leaf out.
        left = huffmanHeap.top();
        huffmanHeap.pop();

        //This pops the right leaf out.
        right = huffmanHeap.top();
        huffmanHeap.pop();

        //This rewrites the top leaf as being a conglomerate of the two leafs popped from the tree.
        //The occurences are the combined occurences of the two child leafs.
        //The question mark is just a placeholder for the character data.
        //In reality, if the two leafs popped were 'c' and 'f' for example, that question mark would read 'cf'.
        top = new huffmanLeaf('?', left->occurences + right->occurences);

        //this makes the two leafs popped out earlier the left and right children of the current top leaf
        top->left = left;
        top->right = right;

        //This pushes the 'top' leaf to the top of the heap.
        huffmanHeap.push(top);
    }
    //Calls the print function to print out the finished Huffman tree.
    huffmanTreePrint(huffmanHeap.top(), "");
}
