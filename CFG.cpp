#include<bits/stdc++.h>
using namespace std;

vector<string> grammar;
vector<string> output;

int main(){
    grammar.push_back("e");
    grammar.push_back("0");
    grammar.push_back("1");
    grammar.push_back("0P0");
    grammar.push_back("1P1");
    string str;
    cin>>str;
    output.push_back("P");
    int i;
    if(str.size()>1){
        string tmp;
        tmp=str[0]+output[0]+str[0];
        output.push_back(tmp);
        for(i=1;i<str.size()/2;i++){
            string temp,substr1,substr2;
            substr1=output[i].substr(0,(output[i].size()/2));
            substr2=output[i].substr((output[i].size()/2)+1);
            temp=substr1+str[i]+'P'+str[i]+substr2;
            output.push_back(temp);
        }
        string temp;
        temp=output[output.size()-1];
        if(str.size()%2){
            temp[temp.size()/2]=str[str.size()/2];
        }
        else{
            string substr1,substr2;
            substr1=temp.substr(0,(temp.size()/2));
            substr2=temp.substr((temp.size()/2)+1);
            temp=substr1+substr2;
        }
        output.push_back(temp);
    }
    else{
        cout<<output[0]<<" => ";
        cout<<str[0]<<endl;
        return 0;
    }
    
    if(str!=output[output.size()-1]){
        cout<<"Not in the grammar"<<endl;
        return 0;
    }
    cout<<output[0];
    for(i=1;i<output.size();i++){
        cout<<" => "<<output[i];
    }
    cout<<endl;
    return 0;
}

