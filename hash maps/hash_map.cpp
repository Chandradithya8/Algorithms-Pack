#include<bits/stdc++.h>
using namespace std;

// hash function

// implemented by using the array efficiently (bucket array)

// 1. hash code - conversion of the any datatype(string, char, own object) 
//    to int 

// 2. compression function - compress the value obtained from the hash code
//    within a sepcific range to maintain uniform distribution

// when the hash code generates same int value for different objects there 
// occurs collision.
// example - > babbar (42) ,   babbra (42) (addition of letters)

// collision handling
// 1. open hashing - place the value in the same place which is the head of
//    a linkedlist but in different node to maintain uniform distribution(seperate chaining)

// 2. closed addressing - place the value in the different place

// closed addressing
// -> linear probing - keeps on checking the next place in the 
//    array(i = 1, 2,.....n) nextPlace = currentPlace + i until it finds the 
//    empty place

// -> quadractic probing
//    nextPlace = currentPlace + i^2 (i = 1, 2,..n until it finds the empty place)

// -> similarly many different types

int main() {
    
}

