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
  cout<<"\nThank you for using the decryption protocol!"<<endl;
  return;
}

bool isEnd(const char source[], const short size)
{      
  return (source[size-1] == '.' || source[size-1] == '!' || source[size-1] == '?');
}

short removeJunk(string sentence[], const short size)
{
  short num_removed=0;
  for (int i = 0; i<size-1-num_removed;i++)
  {
    for (int k = 0; k<NUM_JUNK; k++)
    {      
      if (sentence[i]==JUNK[k])
      {
        for (int j=i;j<=size-i-1;j++)
        {
          sentence[j] = sentence[j+1];
        }
         num_removed++;
      }
    }
  }
  
}

void fixApostrophe(string sentence[], const short size)
{
  char word[MAX_SENTENCES];
  
  for (int i = 0; i<size-1;i++)
  {
    strcpy(word,sentence[i].c_str());
    for (int k = strlen(word)-1; k>FIRST; k--)
    {
      if (word[k]=='\'')
      {
        if (k!=strlen(word)-1)
        {
          swap(word[k],word[k+1]);
        }else
        {
          swap(word[strlen(word)-1],word[FIRST]);
        }
      }
    }
      sentence[i] = word;
  }
  return;
}


void swapWords(string sentence[],const short count, const short size)
{   
  if (count%2==0)
    {  
      //even sentences            
      swap(sentence[FIRST], sentence[size-1]);      
      
      fixCapitalization(sentence[size-1],sentence[FIRST]);
      fixPunct(sentence[FIRST],sentence[size-1]);
    }else if (count%2==1)
    {
      for (int j = 0; j<size-1; j++)
      {    
        if (j!=size-1 && j%2==0)                     
          //odd sentences
          {          
            swap(sentence[j],sentence[j+1]);
          }                 
      }
    }
  return;  
}

void replaceWords(string sentence[], const short size)
{
  for(int i=0;i<size-1;i++)
  {    
	  for (int k = 0; k<NUM_BAD_WORDS-1; k++)
    {
      if (sentence[i]==BAD_WORDS[k])
      {
        sentence[i] = "";
      }
    }   
  }
  return;
}



void fixCapitalization(string & lower, string & upper)
{
  lower[FIRST] +=32;
  upper[FIRST] -=32;
  return;
}

void fixPunct(string & new_first, string & new_last)
{
  short length_first = new_first.length();
  short length_last = new_last.length();
  
  char temp;
  temp = new_first[length_first-1];
  
  new_first[length_first-1]='\0'; 
  new_last+=temp;
  
  return;  
}

