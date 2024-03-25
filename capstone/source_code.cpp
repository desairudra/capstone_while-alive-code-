#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s1[100];
    FILE *fptr1=fopen("newword.txt","r");
    FILE *fptr=fopen("dictonary.txt","r");
    map<string,int>word_checker;
    string p;
    char s2[1000];
    while(fscanf(fptr,"%s",s2)!=EOF)
    { 
      word_checker[s2]=1;
    }
    vector<string>Wrong_words;
     while(fscanf(fptr1,"%s",s1)!=EOF)
    { 
      if(!(word_checker[s1]))
      Wrong_words.push_back(s1);
       
    }
    
    fclose(fptr);
    
    fptr=fopen("dictonary.txt","a");
    for(int i=0;i<Wrong_words.size();i++)
    { 
      
      cout<<"add "<<Wrong_words[i]<<" to dictonary"<<endl;
      string s3;
      cin>>s3;
      for(int j=0;j<Wrong_words[i].size();j++)
      s1[j]=Wrong_words[i][j];
      s1[Wrong_words[i].size()]='\0';
      
      if(s3=="yes")
      {fprintf(fptr,"%s\n",s1);}
      
    
    }
    cout<<"Exit"<<endl;
    fclose(fptr);
    fclose(fptr1);
    return 0; 
}