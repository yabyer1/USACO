/*
    ID: axi21001
    TASK: palsquare
    LANG: C++
    */


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define PB push_back;
#define FOR(i, a , b) for(int i = a; i <= b; i++)
ofstream fout;
unordered_map<int,char> um;


void is_palindrome(int num, int base, int original){
    string new_num = "";
   
    vector<char> vec;
    while(num > 0){
        int x = num % base;
        if(x > 9){
           // cout<<x<<". ";
           // cout<<um[x]<<endl;
            vec.push_back((um[x]));
            new_num += um[x];
        }
        else{
        vec.push_back('0' + (num % base));
                new_num += num % base;
        }
        num /=base;
    }
    int i = 0;
    int j =  new_num.length() - 1;
    while(i <= j){
        if(new_num[i] != new_num[j]){
            return;
            
        }
        i++;
        j--;
    }
    vector<char> o;
      while(original > 0){
          int x = original % base;
          if(x > 9){
          
              o.push_back((um[x]));
          }
          else{
        o.push_back('0' + (original % base));
          }
        original /=base;
    }
    for(int i = o.size() - 1; i > -1; i--)
    fout<<o[i];
    
      fout<<" ";
    FOR(i, 0, vec.size() -1)
     fout<<vec[i];
     
   
   
    fout<<endl;
  
}

int main()
{
um[10] = 'A';
um[11] = 'B';
um[12] = 'C';
um[13] = 'D';
um[14] = 'E';
um[15] = 'F';
um[16] = 'G';
um[17] = 'H';
um[18] = 'I';
um[19] = 'J';
    ifstream fin ("palsquare.in");
    
    fout.open("palsquare.out");
    string line;
     getline(fin, line);
     int base = stoi(line);
     FOR(i, 1, 300){
        
             is_palindrome(i * i, base, i);
     }
     
    exit(0);
}
