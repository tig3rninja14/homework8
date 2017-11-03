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


void swapWords(string source[][MAX_WORDS], const short size1, 
               const short size2)
{
  for (int i = 0; i<size1-1; i++)
  {
    bool even = false;
    for (int j = 0; j<size2-1; j++)
    {    
      if (i%2==0 && !(even))
      {
        
        //even sentences
        swap(source[i][FIRST],source[i][size2-1]);
        
        fixCapitalization(source[i][size2-1],source[i][FIRST]);
        fixPunct(source[i][FIRST],source[i][size2-1]);
        
        
        
        even = true;
      }else if (j!=size2-1 && j%2==0)                     
         //odd sentences
        {          
          swap(source[i][j],source[i][j+1]);
          
          
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
	  for (int k = 0; k<NUM_BAD_WORDS-1; k++)
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

string reduce(const string& str,
                   const string& fill,
                   const string& whitespace)
{
    // trim first
    string result = trim(str, whitespace);

    // replace sub ranges
    short beginSpace = result.find_first_of(whitespace);
    while (beginSpace != string::npos)
    {
        const short endSpace = result.find_first_not_of(whitespace, beginSpace);
        const short range = endSpace - beginSpace;

        result.replace(beginSpace, range, fill);

        const short newStart = beginSpace + fill.length();
        beginSpace = result.find_first_of(whitespace, newStart);
    }

    return result;
}


string trim(const string& str,
                 const string& whitespace)
{
    const short strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const short strEnd = str.find_last_not_of(whitespace);
    const short strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}
