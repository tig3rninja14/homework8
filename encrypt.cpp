//Programmers: Evan Maynard & Justin Palermo        Date: 10/30/2017
//Class: CS1570                                     Section: E
//File: encrypt.cpp
//Purpose: To decrypt a file based on a set encryption.

#include "encrypt.h"


int main()
{
  string data[MAX_SENTENCES][MAX_WORDS]
  ifstream fin("encrypted.dat");
  ofstream fout(decrypted.dat");
  short sentence_cnt =0;
  short cnt = 0;
  
  
  while(fin>>data[sentence_cnt][cnt]
  {
    if(is_end(data[sentence_cnt][cnt].c_str(),data[sentence_cnt][cnt].strlen())
    {
      sentence_cnt++;
    }
    cnt++;
  }
  
  for (int i = 0; i<sentence_cnt-1;i++)
  {
    for (int j = 0; j<cnt-1; j++)
    {
      cout<<data[i][j];
    }
  }
  
  
  fin.close();
  fout.close();
  return 0;  
}