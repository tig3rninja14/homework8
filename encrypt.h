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

const short MAX_WORDS=50;

//The removeJunk() removes junk words from the enryption.
//Pre:
//Post:
void removeJunk(string source[][MAX_WORDS], const short size1, const short size2);

//The fixApostrophe() will unscramble words with apostrophes in them.
//Pre:
//Post:
void fixApostrophe(string source[][MAX_WORDS], const short size1,
                   const short size2);

//
//
//
void swapWords(string source[][MAX_WORDS], const short size1, 
               const short size2);
			   
//the replaceWords() 
//
//
void replaceWords(string source[][MAX_WORDS], const short size1, 
                  const short size2);

const short MAX_SENTENCES=20;

const NUM_BAD_WORDS=6;

const short NUM_JUNK = 4;

const string JUNK[NUM_JUNK] = {"--umm--","--errr--","--like--","--nstuff--"};

const string BAD_WORD[NUM_BAD_WORDS]=={"she","her","my","there","I","frogs"};

#endif  