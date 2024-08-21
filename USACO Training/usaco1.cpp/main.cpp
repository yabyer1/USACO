/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: axi21001
LANG: C++ 
TASK: ride
                
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a;
    string b;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    fin >> a;
    fin >> b;
    int proda = 1;
    int prodb = 1;
    for(int i = 0; i < a.length();i++){
        proda *= (alphabet.find(a[i]) + 1);
    }
    for(int j = 0; j < b.length(); j++){
        prodb *= (alphabet.find(b[j]) + 1);
    }
   
    if(proda % 47 == prodb % 47){
        fout<<"GO"<<endl;
    }
    else{
        fout<<"STAY"<<endl;
    }
    return 0;
}