/*
    ID: axi21001
    TASK: transform
    LANG: C++
    */


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool first_type(vector<string> & o, vector<string> & t){
    for(int i = 0; i < o.size(); i++){
        for(int j = 0; j < o[i].size(); j++){
            if(o[i][j] =='@'){
                int new_I = j;
                //int new_J = i;
               int  new_J = o[i].size() - 1 - i;
               // cout<<i<<" ";
                //    cout<<j<<" ";
                 //   cout<<new_I<<" ";
                 //   cout<<new_J<<endl;
                if(t[new_I][new_J] != '@'){
                  
                    return false;
                }
            }
        }
    }
    return true;
}
bool second_type(vector<string> & o, vector<string> & t){
    for(int i = 0; i < o.size(); i++){
        for(int j = 0; j < o[i].size(); j++){
            if(o[i][j] =='@'){
                int new_I  = j;
                int new_J = o[i].size() - 1 - i;
                for(int x = 0; x < 1; x++){
                int temp = new_I;
                 new_I = new_J;
                new_J = o[i].size() - 1 - temp;
                }
                if(t[new_I][new_J] != '@'){
                    return false;
                }
            }
        }
    }
    return true;
}
bool third_type(vector<string> & o, vector<string> & t){
    for(int i = 0; i < o.size(); i++){
        for(int j = 0; j < o[i].size(); j++){
            if(o[i][j] =='@'){
                int new_I  = j;
                int new_J = o[i].size() - 1 - i;
                for(int x = 0; x < 2; x++){
                int temp = new_I;
                 new_I = new_J;
                new_J = o[i].size() - 1 - temp;
                }
                if(t[new_I][new_J] != '@'){
                    return false;
                }
            }
        }
    }
    return true;
}
bool reflection(vector<string> & o, vector<string> & t){
    for(int i = 0; i < o.size(); i++){
        for(int j = 0; j < o[i].size(); j++){
            if(o[i][j] =='@'){
                int new_I  = i;
                int new_J = o[i].size() - 1 - j;
                if(t[new_I][new_J] != '@'){
                    return false;
                }
            }
        }
    }
    return true;
}
bool reflection_first(vector<string> & o, vector<string> & t){
    for(int i = 0; i < o.size(); i++){
        for(int j = 0; j < o[i].size(); j++){
            if(o[i][j] =='@'){
                int new_I  = i;
                int new_J = o[i].size() - 1 - j;
                int temp = new_I;
                  new_I = new_J;
                new_J = o[i].size() - 1 - temp;
                if(t[new_I][new_J] != '@'){
                    return false;
                }
            }
        }
    }
    return true;
}
bool reflection_second(vector<string> & o, vector<string> & t){
    for(int i = 0; i < o.size(); i++){
        for(int j = 0; j < o[i].size(); j++){
            if(o[i][j] =='@'){
                 int new_I  = i;
                int new_J = o[i].size() - 1 - j;
                for(int x = 1; x <= 2; x++){
                int temp = new_I;
                  new_I = new_J;
                new_J = o[i].size() - 1 - temp;
                }
                if(t[new_I][new_J] != '@'){
                    return false;
                }
            }
        }
    }
    return true;
}
bool reflection_third(vector<string> & o, vector<string> & t){
    for(int i = 0; i < o.size(); i++){
        for(int j = 0; j < o[i].size(); j++){
            if(o[i][j] =='@'){
                int new_I  = i;
                int new_J = o[i].size() - 1 - j;
                for(int x = 1; x <= 3; x++){
             int temp = new_I;
                  new_I = new_J;
                new_J = o[i].size() - 1 - temp;
                }
                if(t[new_I][new_J] != '@'){
                    return false;
                }
            }
        }
    }
    return true;
}
bool no_change(vector<string> & o, vector<string> & t){
     for(int i = 0; i < o.size(); i++){
        for(int j = 0; j < o[i].size(); j++){
            if(o[i][j] =='@'){
              
                
                if(t[i][j] != '@'){
                    return false;
                }
            }
            }
        }
          return true;
    }
  

int main()
{
    ifstream fin ("transform.in");
    ofstream fout;
    fout.open("transform.out");
    string line;
    vector<string> original;
    vector<string> transform;
    int n;
    getline(fin, line);
    int char_count1 = 0;
    int char_count2 = 0;
    n = stoi(line);
    for(int i  = 2; i <= n +1; i++){
         getline(fin, line);
         for(int i = 0; i < line.length(); i++){
             if(line[i] == '@')
             char_count1++;
         }
         original.push_back(line);
    }
    for(int i = n + 2; i <= 2*n + 1; i++){
        getline(fin, line);
         for(int i = 0; i < line.length(); i++){
             if(line[i] == '@')
             char_count2++;
         }
        transform.push_back(line);
    }
   
    if(char_count1 != char_count2){
        fout<<"7"<<endl;
        exit(0);
    }
    if(first_type(original,  transform) == true){
        fout<<"1"<<endl;
        exit(0);
    }
    if(second_type(original,  transform)){
        fout<<"2"<<endl;
        exit(0);
    }
    if(third_type(original,  transform)){
        fout<<"3"<<endl;
        exit(0);
    }
    if(reflection(original,  transform)){
        fout<<"4"<<endl;
        exit(0);
    }
    if(reflection_first(original,  transform)){
        fout<<"5"<<endl;
        exit(0);
    }
     if(reflection_second(original,  transform)){
        fout<<"5"<<endl;
        exit(0);
    }
     if(reflection_third(original,  transform)){
        fout<<"5"<<endl;
        exit(0);
    }
    if(no_change(original, transform)){
        fout<<"6"<<endl;
        exit(0);
    }
   fout<<"here"<<endl;
    fout<<"7"<<endl;
    exit(0);
}