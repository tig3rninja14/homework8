//Programmers: Evan Maynard & Justin Palermo        Date: 10/30/2017
//Class: CS1570                                     Section: E
//File: encrypt.h
//Purpose: To decrypt a file based on a set encryption.

#ifndef ENCRYPT_H
#define ENCRYPT_H


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//The greet() outputs a greeting to the screen
//Pre: None
//Post: outputs a greeting to the screen
void greet();

//The signoff() outputs a signoff to the screen
//Pre: None
//Post: outputs a signoff to the screen
void signoff();

//The isEnd() checks to see if the end of the array is the end of the sentence
//Pre: 
//
bool isEnd(const char source[],const short size);

const short MAX_SENTENCES=20;

const short MAX_WORDS=50;

#endif  