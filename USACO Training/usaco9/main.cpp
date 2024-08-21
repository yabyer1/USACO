/*
    ID: axi21001
    TASK: dualpal
    LANG: C++
    */


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define PB push_back;
#define FOR(i, a , b) for(int i = a; i <= b; i++)
ofstream fout;
unordered_map<int,char> um;
bool is_palindrome(int x){
    int p = 0;
    for(int base = 2; base <= 10; base++){
        if(p >=2)
        return true;
        int num  = x;
        vector<char> vec;
        while(num > 0){
        int x = num % base;
        if(x > 9){
           // cout<<x<<". ";
           // cout<<um[x]<<endl;
            vec.push_back((um[x]));
            
        }
        else{
        vec.push_back('0' + (num % base));
               
        }
        num /=base;
        }
        int i = 0;
        int j = vec.size() -1;
        bool c = true;
        while(i <= j){
            if(vec[i] != vec[j]){
                 c = false;
                break;
             }
             i++; 
             j--;
         }
        if(c){
            p++;
        }
    
    
    }
    return (p >= 2);
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
    ifstream fin ("dualpal.in");
    
    fout.open("dualpal.out");
    string line;
     getline(fin, line);
     int n = stoi(line.substr(0, line.find(" ")));
     int s = stoi(line.substr(line.find(" ") + 1));
     bool found = false;
     while(!found){
        
            if(is_palindrome(s)){
             fout<<s<<endl;
             n--;
            }
            if(n == 0)
            exit(0);
              s++;
     }
     
    exit(0);
}
