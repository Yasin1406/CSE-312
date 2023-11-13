#include<bits/stdc++.h>
using namespace std;

string str;
vector<string> productions={"S","aS","aSbS",""};
vector<string> leftmost_output1,leftmost_output2;

void print_derivation(vector<string> derivation);
int count_b(int index);

int main(){
    freopen("lab11.txt","r",stdin);
    cin>>str;
    if(str[0]=='b'){
        cout<<str<<" cannot be derived using this grammar"<<endl;
        cout<<"The grammar may not be ambiguous."<<endl;
        return 0;
    }
    if(str[0]=='a'&&str[1]=='b'){
        cout<<str<<" cannot be derived using production 'aS'"<<endl;
        cout<<"The grammar may not be ambiguous."<<endl;
        return 0;
    }
    int idx,index,b_num;
    leftmost_output1.push_back("S");
    string temp,sub1,sub2,sub3;
    int i,cur=0;
    for(i=0;i<str.size();i++){
        temp=leftmost_output1.back();
        if(str[i]=='a'){
            if(i+1!=str.size()&&str[i+1]=='b'){
                i++;
                sub3="aSbS";
            }
            else{
                b_num=count_b(i);
                if(b_num>1){
                    sub3="aSbS";
                }
                sub3="aS";
            }
            sub1=temp.substr(0,temp.size()-1);
            temp=sub1+sub3;
            leftmost_output1.push_back(temp);
        }
    }
    temp=leftmost_output1.back();
    while((idx=temp.find('S'))!=string::npos){
        sub1=temp.substr(0,idx);
        sub2=temp.substr(idx+1);
        temp=sub1+sub2;
        leftmost_output1.push_back(temp);
    }
    temp=leftmost_output1.back();
    if(temp!=str){
        cout<<str<<" is not in the grammar!"<<endl;
        return 0;
    }
    print_derivation(leftmost_output1);
    leftmost_output2.push_back("S");
    leftmost_output2.push_back("aSbS");
    idx=str.find('b');
    if(idx==string::npos){
        cout<<str<<" cannot be derived using production 'aSbS'"<<endl;
        cout<<"The grammar may not be ambiguous."<<endl;
        return 0;
    }

    for(i=1;i<idx;i++){
        temp=leftmost_output2.back();
        index=temp.find('S');
        sub1=temp.substr(0,index);
        sub2=temp.substr(index);
        temp=sub1+"a"+sub2;
        leftmost_output2.push_back(temp);
    }
    temp=leftmost_output2.back();
    index=temp.find('S');
    sub1=temp.substr(0,index);
    sub2=temp.substr(index+1);
    temp=sub1+sub2;
    leftmost_output2.push_back(temp);
    for(i++;i<str.size();i++){
        temp=leftmost_output2.back();
        sub1=temp.substr(0,temp.size()-1);
        if(i+1<str.size()&&str[i+1]=='b'){
            sub2="aSbS";
        }
        else{
            sub2="aS";
        }
        temp=sub1+sub2;
        leftmost_output2.push_back(temp);
        if(i+1<str.size()&&str[i+1]=='b'){
            index=temp.find('S');
            sub1=temp.substr(0,index);
            sub2=temp.substr(index+1);
            temp=sub1+sub2;
            leftmost_output2.push_back(temp);
            i++;
        }
    }
    temp=leftmost_output2.back();
    while((idx=temp.find('S'))!=string::npos){
        sub1=temp.substr(0,idx);
        sub2=temp.substr(idx+1);
        temp=sub1+sub2;
        leftmost_output2.push_back(temp);
    }
    temp=leftmost_output2.back();
    if(temp!=str){
        cout<<str<<" is not in the grammar!"<<endl;
        cout<<"The grammar may not be ambiguous."<<endl;
        return 0;
    }
    print_derivation(leftmost_output2);
    cout<<"The grammar is ambiguous."<<endl;
    return 0;
}



void print_derivation(vector<string> derivation){
    if(derivation[1]=="aSbS"){
        cout<<"Leftmost 2: ";
    }
    else{
        cout<<"Leftmost 1: ";
    }
    cout<<derivation[0];
    for(int i=1;i<derivation.size();i++){
        cout<<" => "<<derivation[i];
    }
    cout<<endl;
}

int count_b(int index){
    int count=0;
    for(int i=index;i<str.size();i++){
        if(str[i]=='b'){
            count++;
        }
    }
    return count;
}