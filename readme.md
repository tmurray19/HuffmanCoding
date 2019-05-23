# Huffman Coding

A C++ Implementation of the Huffman Coding compression algorithm

The basic idea is:

* The user inputs data (in this case, it will be a string).
* Each character in the string is given an occurrence frequency.
* E.G the string `A_DEAD_DAD_CEDED_A_BAD_BABE_A_BEADED_ABACA_BED`.

         A:11
         B:6
         C:2
         D:10
         E:7
         _ :10

 * The character and the number of occurrences will be stored in a 'huffmanLeaf' Struct.
 * Take the 2 'leaves' with the lowest frequency value.
 - Create a new leaf from the 2 leaves with the combined frequency and characters.
 - Repeat until only one leaf remains.

 - The finished, Huffman tree is output as the following Huffman code dictionary:

         _ :00
         D :01
         A :10
         E :110
         C :1110
         B :1111
