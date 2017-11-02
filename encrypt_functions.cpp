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

void fixApostrophe(string source[][MAX_WORDS], const short size1,
                   const short size2)
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


void swapWords(string source[][MAX_WORDS], const short size1, const short size2)
{
  const short first =0;
  for (int i = 0; i<size1-1; i++)
  {
    for (int j = 0; j<size2-1; j++)
    {
      if (i%2==0)
      {
        //even sentences
        swap(source[i][j],source[i][size2-1]);
        source[i][size2-1][first]=source[i][size2-1][first]-32;
        source[i][first][first]=source[i][first][first]+32;
        
        strcat(source[i][size2-1].c_str(),source[i][first][source[i][size2-1].
		length()-1]);
        source[i][first][source[i][first].length()-1] = '\0';
        break;
      }else
      {
        //odd sentences 
        if (j!=size2-1 && j%2==0)
        {
          swap(source[i][j],source[i][j+1]);
        }                
      }
      
    }
  }
  
  
  return;  
}

void replaceWords(string source[][MAX_WORDS], const short size1, 
                  const short size2)
{
  for(int i=0;i<size1-1;i++)
  {
    for(int j=0;j<size2-1;j++)
	{
	  for (int k = 0; k<NUM_BAD_WORDS; k++)
      {
        if (source[i][j]==BAD_WORDS[k])
        {
          source[i][j] = "";
        }
      } 
	}   
  }
  
  return;
}  
			
