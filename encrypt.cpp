//Programmers: Evan Maynard & Justin Palermo        Date: 10/30/2017
//Class: CS1570                                     Section: E
//File: encrypt.cpp
//Purpose: To decrypt a file based on a set encryption.

#include "encrypt.h"


int main()
{
  string data[MAX_SENTENCES][MAX_WORDS];
  ifstream fin("encrypted.dat");
  ofstream fout("decrypted.dat");
  short sentence_cnt =0;
  short cnt = 0;
  
  
  while(fin>>data[sentence_cnt][cnt])
  {
    if(isEnd(data[sentence_cnt][cnt].c_str(),data[sentence_cnt][cnt].size())) 
    {
      sentence_cnt++;
    }
    cnt++;
  }
  
  for (int i =0; i<sentence_cnt-1;i++)
  {
    for (int j = 0; j<cnt-1;j++)
    {
      //data[i][j]=reduce(data[i][j]);
    }
  }
  
  
  //removeJunk(data,sentence_cnt,cnt);
  //fixApostrophe(data,sentence_cnt,cnt);
  //swapWords(data,sentence_cnt,cnt);
  //replaceWords(data,sentence_cnt,cnt);
  
  for (int i = 0; i<sentence_cnt-1;i++)
  {
    for (int j = 0; j<cnt-1; j++)
    {
      cout<<data[i][j]<<" ";
    }
  }
  
  for(int i=0;i<sentence_cnt-1;i++)
  {
    for(int j=0;j<cnt-1;j++)
	{
	  fout<<data[i][j]<<" ";
	}
  }	
  
  fin.close();
  fout.close();
  return 0;  
}