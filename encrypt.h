//Programmers: Evan Maynard & Justin Palermo        Date: 10/30/2017
//Class: CS1570                                     Section: E
//File: encrypt.h
//Purpose: To decrypt a file based on a set encryption.

#ifndef ENCRYPT_H
#define ENCRYPT_H


#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

const short MAX_WORDS=50;
//maximum number of words in each sentence


struct sentence
{
  string m_sentence[MAX_WORDS];
  short m_num_words;
  char m_punct;  
};


//The greet() outputs a greeting to the screen.
//Pre: None
//Post: outputs a greeting to the screen.
void greet();

//The signoff() outputs a signoff to the screen.
//Pre: None
//Post: outputs a signoff to the screen.
void signoff();

//The isEnd() checks to see if the end of the array is the end of the sentence.
//Pre: source must contain data terminated by the null character
//    and size must greater than zero and contain the length of the char array.
//Post: Returns true if the last character is a punctuation mark.
bool isEnd(const char source[],const short size);


//The removeJunk() removes junk words from the enryption.
//Pre: sentence must contain data, size must be greater than zero and contain
//the length of the data.
//Post: Removes the junk words from the data.
void removeJunk(string sentence[], const short size);

//The fixApostrophe() will unscramble words with apostrophes in them.
//Pre: sentence must contain data, and size must be greater zero and contain
//     the length of the data.
//Post: Alters the position of the apostrophes to the correct spot.
void fixApostrophe(string sentence[], const short size);

//The swapWords() will swap the words based on whether or not the sentence
//is even or odd.
//Pre: sentence must contain data, count must be greater than zero and
//     contain the sentence number, size must be greater than zero and
//     contain the length of the data.
//Post: The words in odd sentences are swapped and even sentences are
//      swapped pairwise.
void swapWords(string sentence[], const short count, const short size);
			   
//The replaceWords() will replace the words that are coded and need 
//to be decoded.  
//Pre: sentence must contain data, and size must be greater than zero
//     and contain the length of the data.
//Post: Replaces the words that are coded with the decoded equivalent.
void replaceWords(string sentence[], const short size);

//The fixPunct() will fix the punctuation of the words when switched.
//Pre: new_first and new_last must contain data.
//Post: Changes the values of the two reference strings by removing 
//      the punctuation mark and adds it to the other string.
void fixPunct(string & new_first, string & new_last);

//The fixCapitalization() will fix the capitalization of the words
//when switched.
//Pre: lower and upper must contain data.
//Post: lower and upper will swap the capitalization of the words.
void fixCapitalization(string & lower, string & upper);


const short MAX_SENTENCES=20;
//maximum number of sentences you can have in the array

const char PUNCT[3] = {'!','.','?'};
//array of all the punctuation marks

const short WHITESPACE = 32;
//ascii value for whitespace

const short NUM_PUNCT = 3;
//maximum number of puntuation marks

const short NUM_BAD_WORDS=6;
//maximum number of "bad" words 

const short FIRST =0;
//first letter of the sentence


const short NUM_JUNK = 4;
//maximum number of junk

const string JUNK[NUM_JUNK] = {"--umm--","--errr--","--like--","--nstuff--"};
//array of all the junk words that need to be removed

const string BAD_WORDS[NUM_BAD_WORDS]={"she","her","my","there","I","frogs"};
//array of all the bad words that need to be decrypted

#endif  