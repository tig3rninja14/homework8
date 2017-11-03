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

struct sentence
{
  string m_sentence[MAX_WORDS];
  short m_num_words;
  char m_punct;  
};


//The greet() outputs a greeting to the screen
//Pre: None
//Post: outputs a greeting to the screen
void greet();

//The signoff() outputs a signoff to the screen
//Pre: None
//Post: outputs a signoff to the screen
void signoff();

//The isEnd() checks to see if the end of the array is the end of the sentence.
//Pre: 
//Post:
bool isEnd(const char source[],const short size);



//The removeJunk() removes junk words from the enryption.
//Pre:
//Post:
short removeJunk(string sentence[], const short size);

//The fixApostrophe() will unscramble words with apostrophes in them.
//Pre:
//Post:
void fixApostrophe(string sentence[], const short size);

//
//
//
void swapWords(string sentence[], const short count, const short size);
			   
//the replaceWords() 
//
//
void replaceWords(string sentence[], const short size);

const short MAX_SENTENCES=20;




void fixPunct(string & new_first, string & new_last);




void fixCapitalization(string & lower, string & upper);







const char PUNCT[3] = {'!','.','?'};
const short WHITESPACE = 32;
const short NUM_PUNCT = 3;

const short NUM_BAD_WORDS=6;
const short FIRST =0;

const short NUM_JUNK = 4;

const string JUNK[NUM_JUNK] = {"--umm--","--errr--","--like--","--nstuff--"};

const string BAD_WORDS[NUM_BAD_WORDS]={"she","her","my","there","I","frogs"};

#endif  