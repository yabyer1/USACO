/*
    ID: axi21001
    TASK: namenum
    LANG: C++
    */


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> valid_names;
 unordered_map<char, string> phone;

    unordered_set<string> hs;
 void dfs(string n, int i, string ans){
     
     if(i >= n.length()){
         
         auto it = hs.find(ans);
         if(it != hs.end()){
             cout<<"here"<<endl;
             valid_names.push_back(ans);
         }
         return;
     }
     for(int j = 0; j < phone[n[i]].length(); j++){
         ans += phone[n[i]][j];
         dfs(n, i +1, ans);
         ans = ans.erase(ans.length() - 1);
     }
 }


int main()
{   
    ifstream x("dict.txt");
    ifstream fin ("namenum.in");
    ofstream fout;
    fout.open("namenum.out");
    string line;
    
    phone['2'] = "ABC";
    phone['3']= "DEF";
    phone['4'] ="GHI";
    phone['5'] = "JKL";
    phone['6'] = "MNO";
    phone['7'] = "PRS";
    phone['8'] = "TUV";
    phone['9'] = "WXY";
   
    string n;
    auto it = hs.begin();
    while(getline(x, line)){
        if(!line.compare("GRANVILLE"))
        cout<<line<<endl;
        hs.insert(it, line);
    }
   
    getline(fin, line);
    n = (line);
    dfs(n, 0, "");
    if(valid_names.size() == 0) {
        fout<<"NONE"<<endl;
    }
    else{
        for(int i = 0; i < valid_names.size(); i++){
            fout<<valid_names[i];
            if(i != valid_names.size() - 1)
            fout<<endl;
        }
        fout<<endl;
    }
}