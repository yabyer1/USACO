/*
    ID: axi21001
    TASK: milk
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
int main()
{
    ifstream fin ("barn1.in");
    
    fout.open("barn1.out");
    string line;
     getline(fin, line);
     int m = stoi(line.substr(0, line.find(" ")));
     line = (line.substr(line.find(" ") + 1));
     int s = stoi(line.substr(0, line.find(" ")));
     int c = stoi((line.substr(line.find(" ") + 1)));
     vector<int> vec;
     FOR(i, 2, c + 1){
        
            getline(fin, line);
           int x = stoi(line);
           vec.push_back(x);
     }
    
     sort(vec.begin(), vec.end());
     int tot = vec[vec.size() - 1] - vec[0] + 1;
     vector<int> diff;
     FOR(i, 1, vec.size() - 1){
         diff.push_back(vec[i] - vec[i - 1] - 1);
     }
     sort(diff.rbegin(), diff.rend());
     //m = min(m, diff.size());
     FOR(i, 0, m - 2){
         if(i >= diff.size())
         break;
         cout<<diff[i]<<endl;
         tot -= diff[i];
     }
     fout<<tot<<endl;
    exit(0);
}
