//main.cpp

//Including functions for the code.
#include <iostream>
#include <vector>
#include <map>
#include "huffmanAlgorithm.cpp"

int main(){
    /*METHOD 1 - DIRECT LIST INPUT:
    This block of code was what I originally came up with. It is a simple block of code which
    has the two arrays for the huffmanALgorithm function. This code is more straightwforward
    to understand, but it is very user unfriendly. To make use of this block, you need to
    already know the characters that occur, and the number of occrences for each character.*/
    cout << "METHOD 1 - DIRECT LIST INPUT: " << "\n" << "\n";

    //Create two arrays, one which records the charcters, and one which records the number of occurences of the characters.
    char characters1[] = {'e', 'd', '_', 's', 'h', 'r', 'a', 'n', 'i', 'g'  };
    int occurences1[] = {4,1,2,2,1,2,1,2,1,1};

    //The size of the heap is calculated here.
    int size = sizeof(characters1) / sizeof(characters1[0]);

    //Calls the huffmanAlgorith function on the two arrays.
    huffmanAlgorithm(characters1, occurences1, size);

    /*METHOD 2 - USER DEFINED ARRAYS:
    This block of code is more user friendly. The idea is that the user inputs a string of
    their desire. The code then turns the string into a vector, which is then converted into
    a map. A map in c++ is similar to a dictionary in python, in that it has a value, and a
    definition to that corresponding value.

    A map with a char and an int value is created from the vector, the char being the unique
    character in the user inputted string, and the int being the number of occurenecs of that.
    character. This map is then converted back into two seperate vectors, one storing the characters,
    and one storing the number of occrences. These two vectors are then converted back into simple
    arrays so that the huffmanAlgorithm function may work on it.*/
    cout << "\n" << "METHOD 2 - USER DEFINED ARRAYS: " << "\n" << "\n";

    //Initialises a user input of type string.
    string userIn;

    //Asks user for input.
    cout << "Enter string: " << "\n";
    cin >> userIn;

    /*Creates a character vector called bin, which stores all the values from the string array
    Entered by the user.*/
    vector<char> bin;

    //Creating a huffman map that stores the characters and the corresponding number of occurences.
    map<char, int> huffman;

    //For loop adding each character the user input into the bin vector.
    for(int i=0; i<userIn.length(); i++){
        bin.push_back(userIn[i]);
    }

    //For each c(haracter) in the bin vector:
    for(char c : bin){
        //The value of the c character is increased by 1.
        //If the value does note exist in the map, this code initialises it as well.
        huffman[c]++;
    }

    //Creates 2 vectors to store the characters and the corresponding number of occurences.
    vector <char> chars;
    vector <int> occurs;

    //For each e(lement) in the huffman map:
    /*(The auto keyword automatically assumes the variable type. This is because the map holds
    mutliple different variable types.)*/
    for(auto e : huffman){
        //Add the first half of the e-th data point (the unique character) to the chars vector.
        chars.push_back(e.first);
        //Add the second half of the e-th data point (the number of occcurences) to the occurs vector.
        occurs.push_back(e.second);
    }

    //Newline printed for ease of reading.
    cout << "\n";

    //Defines two arrays for the huffmanAlgorithm function.
    //These arrays are defined using address pointers to the vectors
    char* characters2 = &chars[0];
    int* occurences2 = &occurs[0];

    //Calling the huffman algorithm on the sorted arrays.
    huffmanAlgorithm(characters2, occurences2, huffman.size());
}
