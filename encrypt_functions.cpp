//Programmers: Evan Maynard & Justin Palermo        Date: 10/30/2017
//Class: CS1570                                     Section: E
//File: encrypt_functions.cpp
//Purpose: To decrypt a file based on a set encryption.

#include "encrypt.h"

void greet()
{
  cout<<"Hello and welcome to the decryption protocol!";
  return;
}

void signoff()
{
  cout<<"Thank you for using the decryption protocol!"<<endl;
  return;
}

bool isEnd(const char source[], const short size)
{
  return (source[size-1] == '.' || source[size-1] == '!' || source[size-1] == '?');
}

void removeJunk(string source[][MAX_WORDS], const short size1, const short size2)
{
  for (int i = 0; i<size1-1;i++)
  {
    for (int j = 0; j<size2-1; j++)
    {
      for (int k = 0; k<NUM_JUNK; k++)
      {
        if (source[i][j]==JUNK[k])
        {
          source[i][j] = "";
        }
      }
    }
  }
}

void fixApostrophe(string source[][MAX_WORDS], const short size1, const short size2)
{
  char word[MAX_SENTENCES];
  
  for (int i = 0; i<size1-1;i++)
  {
    for (int j = 0; j<size2-1; j++)
    {
      strcpy(word,source[i][j].c_str());
      for (int k = strlen(word)-1; k>0; k--)
      {
        if (word[k]=='\'')
        {
          if (k!=strlen(word)-1)
          {
            swap(word[k],word[k+1]);
          }else
          {
            swap(word[strlen(word)-1],word[0]);
          }
        }
      }
      source[i][j] = word;
    }
  }
  return;
}


