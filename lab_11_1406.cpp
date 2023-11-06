#include<bits/stdc++.h>
using namespace std;

string str;
vector<string> productions={"S","aS","aSbS",""};
vector<string> leftmost_output1,leftmost_output2;

void leftmost_derivation(vector<string> &leftmost_output);


int main(){
    cout<<"Enter string: ";
    cin>>str;
    leftmost_output1.push_back("S");
    leftmost_output1.push_back("aS");
    string temp;
    int i,cur=0;
    for(i=1;i<str.size();i++){
        temp=leftmost_output1.back();
        if(str[i]=='a'){
            if(str[i+1]=='b'){

            }
            else{

            }
        }
    }
    leftmost_output2.push_back("S");
    leftmost_output2.push_back("aSbS");
    
}

void leftmost_derivation(vector<string> &leftmost_output){

}