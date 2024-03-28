#include<bits/stdc++.h>
using namespace std;
int distance_checker(string s1,string s2,int i,int j,long long *a)
{    
      if(i==s1.length())return s2.length()-j;
      else if(j==s2.length())return s1.length()-i;
      else if(a[j*s1.size()+i]!=-1)
      { 
              return a[j*s1.size()+i];
      }
     else if(s1[i]==s2[j]) {
      a[j*s1.size()+i]=distance_checker(s1,s2,i+1,j+1,&a[0]);
      return a[j*s1.size()+i];}
      else 
      {     
            a[j*s1.size()+i]=min(min(1+distance_checker(s1,s2,i+1,j+1,&a[0]),1+distance_checker(s1,s2,i,j+1,&a[0])),1+distance_checker(s1,s2,i+1,j,&a[0]));
            
             return a[j*s1.size()+i];
      }
}
vector<pair<int,string>> all_suggested_words(string s1){
char s2[1000];
vector<pair<int,string>>s;
FILE *fptr1=fopen("dictonary.txt","r");
while(fscanf(fptr1,"%s",s2)!=EOF)
{long long a[s1.size()*strlen(s2)];
vector<vector<long long>>k;
map<pair<long long,long long>,long long>l;
for(int i=0;i<s1.size()*strlen(s2);i++)a[i]=-1;
  int p=distance_checker(s1,s2,0,0,&a[0]);
  s.push_back(make_pair(p,s2));
 
 
}



return s;

}

int main()
{
    char s1[100];
    cout<<"give the name of the input file"<<endl;
    char file_name[1000];
    cin>>file_name;
    FILE *fptr1=fopen(file_name,"r");
    FILE *fptr=fopen("dictonary.txt","r");
    map<string,int>word_checker;
    int k=0,f=0;
    char s2[1000];
    if(fptr1==NULL)
    cout<<"Name of the file is invalid"<<endl;
    else
    {
    while(fscanf(fptr,"%s",s2)!=EOF)
    { 
      word_checker[s2]=1;
 
    }
    vector<string>all_wrong_words;
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
       if(s1[i]>'A'-1&&s1[i]<'Z'+1)
       s1[i]=s1[i]+32;
       k++;
       f=i;
      }
      s1[f+1]='\0';
      if(!word_checker[s1])
      { cout<<s1<<" is absent in our dictonary??May be a new word??If yes,"<<endl;
        cout<<"add "<<s1<<" to dictonary??"<<endl; 
       string s3;
       cin>>s3;
       if(s3=="yes")
       { fprintf(fptr,"%s ",s1);
         word_checker[s1]=1;
       }
       else
       {
           all_wrong_words.push_back(s1);       
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
    FILE *fptr2=fopen("dictonary.txt","a");
    map<pair<int,int>,long long>l123;
    cout<<"all wrong words are as follows:-"<<endl;
    for(int i=0;i<all_wrong_words.size();i++)cout<<all_wrong_words[i]<<endl;
    m1:cout<<"for which element you want to see suggestion of the word if it's first element than print 1"<<endl;
    long long s;
    cin>>s;
if(s<all_wrong_words.size()+1)
    {vector<pair<int,string>>p=all_suggested_words(all_wrong_words[s-1]);
    sort(p.begin(),p.end());
    for(int i=0;i<10;i++)cout<<p[i].second<<endl;
    cout<<"want to see suggestions of other wrong words"<<endl;
    string h;
    cin>>h;
    if(h=="yes")
    goto m1;
    
    }
    else
    {cout<<"the value you input should be in range of 1 to "<<all_wrong_words.size()<<endl;
     goto m1;
    }
    
    
    fclose(fptr);
    fclose(fptr1);
    fclose(fptr2);
    return 0;}
}