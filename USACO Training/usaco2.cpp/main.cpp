/*
    ID: axi21001
    TASK: gift1
    LANG: C++
    */



#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ofstream fout("gift1.out");
    ifstream fin ("gift1.in");
    unordered_map<string, int> umap; 
    vector<string> vec;
   std::string str;
  while (getline(fin,str))
    vec.push_back(str);
    
    int amnt = stoi(vec[0]);
    for(int j = 1; j <= amnt; j++){
        umap[vec[j]] = 0;
    }
    int i = amnt + 1;
    while(i < vec.size()){
        string line = vec[i];
        if(line.find(" ") != string::npos){
                   // cout<<line<< endl;

            int bought = stoi(line.substr(0, line.find(" ")));
            
            int split = stoi(line.substr(line.find(" ") + 1));
            
            if(split != 0) {
            umap[vec[i - 1]] -= bought;
            umap[vec[i - 1]] += (bought % split);
            int temp = i + 1;
            for(int j = 0; j < split; j++){
                
                 //cout<<vec[j]<<" "<<bought / split<<endl;
                umap[vec[temp + j]] +=(bought / split);
               
            }
            }
            i+=(split + 1);
            continue;
        } else{
            i++;
        }
    }
      for(int j = 1; j <= amnt; j++){
          
        fout<<vec[j]<<" "<<umap[vec[j]]<<endl;
    }
    
 
    exit(0);
}
