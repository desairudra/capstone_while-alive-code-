#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s1[100];
    FILE *fptr1=fopen("newword.txt","r");
    FILE *fptr=fopen("dictonary.txt","r");
    map<string,int>word_checker;
    int k=0,f=0;
    char s2[1000];
    while(fscanf(fptr,"%s",s2)!=EOF)
    { 
      word_checker[s2]=1;
    }
    vector<string>Wrong_words;
    while(fscanf(fptr1,"%s",s1)!=EOF)
    { if(s1[strlen(s1)-1]=='.'||s1[strlen(s1)-1]=='!'||s1[strlen(s1)-1]=='?'||s1[strlen(s1)-1]==','||s1[strlen(s1)-1]==';'||s1[strlen(s1)-1]==':')
      s1[strlen(s1)-1]='\0';
      if(!(word_checker[s1]))
      Wrong_words.push_back(s1);
       
    }
    fclose(fptr);
    fptr=fopen("dictonary.txt","a");
    for(auto s:Wrong_words)
    { 
     
      
     m: for(int i=0;s[k]!='.'&&s[k]!='?'&&s[k]!=','&&k<s.size()&&s[k]!='!';i++)
      {s1[i]=s[k];
       k++;
       f=i;
      }
      s1[f+1]='\0';
      if(!word_checker[s1])
      { cout<<"add "<<s1<<" to dictonary"<<endl; 
       string s3;
       cin>>s3;
       if(s3=="yes")
       { fprintf(fptr,"%s ",s1);
         word_checker[s1]=1;
       }
       k++;
       if(k<s.size())
       goto m;
       else
       k=0;
      }
      else
      {
          k++;
         
          if(k<s.size())
          goto m;
          else
          k=0;
      }
    }
      
    
    
    fclose(fptr);
    fclose(fptr1);
    return 0; 
}