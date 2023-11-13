#include<bits/stdc++.h>
using namespace std;
/*
  state   symbol  stack  transition stack_operation
    a       0       z        a         push(0)
    a       0       0        a         push(0)
    a       1       0        b         pop(0)
    b       1       0        b         pop(0)
    b       0       0        d         pop(0)
    b       eps(e)  z        c         do nothing        
          
*/
string states="abcd",symbol="01e";
vector<string> table={"a0za","a00a","a10b","b10b","bezc","b1zb","b00d","b0zd","d0zd","d00d","d10d","d1zd"};
char starting_state='a',final_state='c';
int num_state=3,num_symbol=2;
stack<char> st;
string str;
string cur_status="abc";

int get_transition_index();
int main(){
    freopen("lab12.txt","r",stdin);
    cin>>str;
    int i,j;
    char current_state='a',cur_transition;
    st.push('z');
    for(i=0;i<str[i]&&!st.empty();i++){
        cur_status[0]=current_state;
        cur_status[1]=str[i];
        cur_status[2]=st.top();
        current_state=table[get_transition_index()][3];
        for(j=0;j<cur_status.size();j++){
            cout<<cur_status[j]<<" ";
        }
        cout<<current_state<<endl;
        if(cur_status[1]=='0'){
            st.push('0');
        }
        else{
            st.pop();
        }
    }
    if(final_state!=current_state){
        cout<<"Not ";
    }
    cout<<"accepted"<<endl;
    return 0;
}

int get_transition_index(){
    string s;
    for(int i=0;i<table.size();i++){
        s=table[i].substr(0,3);
        if(s==cur_status){
            return i;
        }
    }
    return -1;
}