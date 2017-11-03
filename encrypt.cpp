//Programmers: Evan Maynard & Justin Palermo        Date: 10/30/2017
//Class: CS1570                                     Section: E
//File: encrypt.cpp
//Purpose: To decrypt a file based on a set encryption.

#include "encrypt.h"


int main()
{
  string data[MAX_WORDS];
  ifstream fin("encrypted.dat");
  ofstream fout("decrypted.dat");
  short sentence_cnt =0;
  short cnt = 0;
  sentence sentences[MAX_SENTENCES];
  
  greet();
  
  
  while(fin>>data[cnt])
  {
    //cout<<"\n";
    //cout<<data[cnt]<<endl;
    if(isEnd(data[cnt].c_str(),strlen(data[cnt].c_str()))) 
    {
      sentences[sentence_cnt].m_num_words = cnt;
      for (int i = 0; i<cnt-1; i++)
      {
        sentences[sentence_cnt].m_sentence[i] = data[i];
      }      
      sentences[sentence_cnt].m_punct = data[cnt][data[cnt].length()-1];
      sentence_cnt++;
      cnt=0;
    }    
    cnt++;    
  }  

  
  
  for (int i = 0; i<sentence_cnt;i++)
  {  
    removeJunk(sentences[i].m_sentence,sentences[i].m_num_words);
    fixApostrophe(sentences[i].m_sentence,sentences[i].m_num_words);
    swapWords(sentences[i].m_sentence,i+1,sentences[i].m_num_words);
    replaceWords(sentences[i].m_sentence,sentences[i].m_num_words);    
  }
  cout<<endl;
  for(int i=0;i<sentence_cnt-1;i++)
  {
    for(int j=0;j<sentences[i].m_num_words-1;j++)
    {
      fout<<sentences[i].m_sentence[j]<<" ";
      cout<<sentences[i].m_sentence[j]<<" ";
    }
  }	
  
  fin.close();
  fout.close();
  
  signoff();
  
  return 0;  
}