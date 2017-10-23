#include<iostream>
#include<math.h>
using namespace std;
int p_bit[64] ={0};
int q_bit[64] ={0};
int i,j;
int s=5;
int bin[5]={0};
string ct="";
string cipher="";
string encrypted_text="";
int iv[64] = {            1,0,1,0,1,0,1,0,
                          1,0,1,0,1,0,1,0,
                          1,0,1,0,1,0,1,0,
                          1,0,1,0,1,0,1,0,
                          1,0,1,0,1,0,1,0,
                          1,0,1,0,1,0,1,0,
                          1,0,1,0,1,0,1,0,
                          1,0,1,0,1,0,1,0,};
int key = 4;


void perform_encryption()
{
  int i;
  for(i=0;i<8;i++)
  {
    ct[i]+=(char)((int)ct[i]+4);
  }
//  cout<<iv<<endl;
}
void converttostring()
{
  int binary[8],rem,base=2,dec;
  int c=0;
  for(int j=0;j<8;j++)
    {
      for(int k=0;k<8;k++)
        binary[k] = iv[k+c];

      int i=7;
      while(i>=0)
       {
         rem = binary[i];
         dec+=rem*pow(base,7-i);
         i--;
       }
       char ch=(char)dec;
       ct+=ch;
       c+=8;
    }
//cout<<ct<<endl;
}
void converttostring_final()
{
  int binary[8],rem,base=2,dec;
  int c=0;
  for(int j=0;j<8;j++)
    {
      for(int k=0;k<8;k++)
        binary[k] = q_bit[k+c];

      int i=7;
      while(i>=0)
       {
         rem = binary[i];
         dec+=rem*pow(base,7-i);
         i--;
       }
       char ch=(char)dec;
       cipher+=ch;
       c+=8;
    }
//cout<<ct<<endl;
}
void converttobinary(string p)
{
  int ch=0;
  for(int j=0;j<p.length();j++)
    {
      char c = p[j];
      int bits[8], i;

      for(i = 0; i < 8; i++)
    	   bits[i] = ((1<<i) & c) != 0 ? 1:0;

      for(i = 7; i >= 0; i--)
       	p_bit[7-i+ch]=bits[i];

      ch+=8;

    }
}
void converttobinary_pt(string p)
{
  int ch=0;
  for(int j=0;j<p.length();j++)
    {
      char c = p[j];
      int bits[8], i;

      for(i = 0; i < 8; i++)
    	   bits[i] = ((1<<i) & c) != 0 ? 1:0;

      for(i = 7; i >= 0; i--)
       	q_bit[7-i+ch]=bits[i];

      ch+=8;

    }
}

void shifter()
{
int t;
for( t=0;t<s;t++)
bin[t]=p_bit[i] ^ q_bit[i];

for(t=0;t<64;t++)
q_bit[t]=q_bit[t+s-1];

for(int t=59;t<64;t++)
q_bit[t]=bin[t-59];
}

int main()
{
  string pt="Abhishekyd";
  string xt="";
converttostring();
perform_encryption();
converttobinary(ct);
converttobinary(pt);
//int ss=pt.length()/s;
//value of shift is 5 and 16 for 80 divide by 5
  for(i=0;i<16;i++)
    {
    shifter();
    }
converttostring_final();
  cout<<"\nyour cipher text is "<<cipher<<endl;
}
