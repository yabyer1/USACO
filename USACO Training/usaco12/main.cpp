/*
    ID: axi21001
    TASK: crypt1
    LANG: C++
    */


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define PB push_back;
#define FOR(i, a , b) for(int i = a; i <= b; i++)
ofstream fout;
struct Compare{
bool operator()(int  i1, int i2)
{
    return (i1 < i2);
}
};
   set<int> hs;
bool valid(int x, int y){
    int temp = x;
    for(int i = 0; i < 3; i++){
        if(temp == 0)
        return false;
        if(hs.find(temp % 10) == hs.end()){
            return false;
        }
        temp /= 10;
    }
     //if(temp > 0) return false;
    temp = y;
      for(int i = 0; i < 2; i++){
        if(temp == 0)
        return false;
        if(hs.find(temp % 10) == hs.end()){
            return false;
        }
        temp /= 10;
    }
    // if(temp > 0) return false;
    int amnt1 = x * (y % 10);
      temp = amnt1;
    for(int i = 0; i < 3; i++){
        if(temp == 0)
        return false;
        if(hs.find(temp % 10) == hs.end()){
            return false;
        }
        temp /= 10;
    }
   if(temp > 0) return false;
   int  amnt2 = x * (y / 10);
    temp = amnt2 ;
     for(int i = 0; i < 3; i++){
        if(temp == 0)
        return false;
        if(hs.find(temp % 10) == hs.end()){
            return false;
        }
        temp /= 10;
    }
      if(temp > 0) return false;
    //if(amnt1 - amnt2 != 0) return false;
    int fin = amnt1 + amnt2 * 10;
    temp = fin;
      // for(int i = 0; i < 4; i++){
      while(temp > 0){
       // if(temp == 0)
        //return false;
        if(hs.find(temp % 10) == hs.end()){
            return false;
        }
        temp /= 10;
    }
    // if(temp > 0) return false;
      //cout<<x <<"   ";
     // cout<<y<<" ";
       // cout<<fin<<endl;
    return true;
}
int main()
{
    ifstream fin ("crypt1.in");
    
    fout.open("crypt1.out");
    string line;
     getline(fin, line);
  
     getline(fin, line);
     for(char c : line){
         if(!isspace(c)){
             hs.insert(c - '0');
         }
     }
     int amnt = 0;
     for(int i = 100; i <= 999; i++){
         for(int j = 10; j < 100; j++){
             if(valid(i, j)){
                
                 amnt++;
             }
         }
     }
     fout<<amnt<<endl;
     
    exit(0);
}
