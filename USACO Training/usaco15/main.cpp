/*
    ID: axi21001
    TASK: skidesign
    LANG: C++17
*/

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define FOR(i, a , b) for(int i = a; i <= b; i++)
string line;
ofstream fout;
int sol = 0;

int  isCycle = 0;

int main() {
    ifstream fin("skidesign.in");
    fout.open("skidesign.out");
    vector<int> vec;
    int n;
    getline(fin, line);
    n = stoi(line);
 
FOR(i, 2, n + 1){
    getline(fin, line);
    int x  = (stoi(line));
    vec.push_back(x);
  
}
    sort(vec.begin(), vec.end());
        
   int amnt = 0;
   int find = 1000000;
   
   for(int i = vec[0]; i < vec[vec.size() - 1]; i++){
       int cost = 0;
        cout<<i<<endl;
       for(int j = 0; j < vec.size(); j++){
          
           //cout<<vec[j]<<" ";
           if(vec[j] < i){
               cost += (pow(abs(vec[j] - i), 2));
           }
           if(vec[j] >  i + 17){
               cost += pow(vec[j] - i - 17, 2);
           }
          
       }
        cout<<cost<<'\n';
       cout<<endl;
       find = min(cost, find);
   }
  
       
      
   fout<<find<<endl;
    return 0;
}
