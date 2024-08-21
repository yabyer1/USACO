/*
    ID: axi21001
    TASK: friday
    LANG: C++
    */



#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    
    ifstream fin ("friday.in");
    ofstream fout("friday.out");
    unordered_map<string, int> umap; 
   std::string str;
   int years;
  //fin>>stoi(years);
  //years = stoi(str);
  getline(fin, str);
  years = stoi(str);
  //cout<<years;
    umap["saturday"] = 0;
    umap["sunday"] = 0;
    umap["monday"] = 0;
    umap["tuesday"] = 0;
    umap["wednesday"] = 0;
    umap["thursday"] = 0;
    umap["friday"] = 0;
    vector<string> days;
    int curDay = 0;
   
        // cout<<i -> first;
      
       days.push_back("monday"); 
       days.push_back("tuesday");
        days.push_back("wednesday");
       days.push_back("thursday"); 
       days.push_back("friday");
        days.push_back("saturday"); 
       days.push_back("sunday");
    
     //umap["saturday"] += 1;
       // auto it = find(days.begin(), days.end(), "saturday");
        curDay = 5;
        
      for(int i = 0; i < years; i++){
       for(int j = 1; j <= 12; j++){
           
               if(j == 2){
                   if((((1900 + i) % 100 == 0) && ( (1900 + i) % 400 == 0) )  ||(((1900 +i) % 100 != 0) && ((1900 + i) % 4 == 0)) )  {
                    umap[days[curDay]]++;
                   curDay = (curDay + (days.size() + 1)) % days.size();
                  
                  
               }
               else{
                   umap[days[curDay]]++;
               }
               continue;
           }
           
           else if(j == 1 || j == 3 || j ==5 || j == 7 ||j == 8 || j == 10 || j == 12){
                 umap[days[curDay]]++;
                   curDay = (curDay + (days.size() + 3)) % days.size();
                   continue;
           }
           else{
               umap[days[curDay]]++;
                   curDay = (curDay + (days.size() + 2)) % days.size();
           }
       }
    }
    fout<<umap["saturday"]<<" ";
    fout<<umap["sunday"]<<" ";
    fout<<umap["monday"]<<" ";
    fout<<umap["tuesday"]<<" ";
    fout<<umap["wednesday"]<<" ";
    fout<<umap["thursday"]<<" ";
    fout<<umap["friday"] << endl;
    
 
    exit(0);
}