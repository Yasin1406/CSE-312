#include<bits/stdc++.h>
using namespace std;

vector<char> var={'S','A','B'};
vector<vector<string>> grammar={{"A1B"},{"0A",""},{"0B","1B",""}};
vector<string> left_output,right_output;
string str;

int var_index(char ch);
void left_derivation();
bool is_var(char ch);

int main(){
    int i,j,k,cur;
    cout<<"Enter string: ";
    cin>>str;
    cout<<endl;
    string temp;
    left_output.push_back("S");
    left_output.push_back("A1B");
    for(cur=0;str[cur]!='1';cur++){
        temp=left_output.back();
        temp="0"+temp;
        left_output.push_back(temp);
    }
    temp=left_output.back();
    temp=temp.substr(0,cur)+temp.substr(cur+1);
    cur++;
    left_output.push_back(temp);
    i=cur;
    while(cur<str.size()){
        temp=left_output.back();
        temp=temp.substr(0,cur)+str[i]+temp.substr(cur);
        left_output.push_back(temp);
        cur++;
        i++;
    }
    temp=left_output.back();
    temp[temp.size()-1]='\0';
    left_output.push_back(temp);
    cout<<"Left most derivation:"<<endl;
    cout<<left_output[0];
    for(i=1;i<left_output.size();i++){
        cout<<" => "+left_output[i];
    }  
    cout<<endl<<endl;

    right_output.push_back("S");
    right_output.push_back("A1B");
    cur=2;
    for(i=0;str[i]!='1';i++);
    for(i++;i<str.size();i++){
        temp=right_output.back();
        temp=temp.substr(0,cur)+str[i]+temp.substr(cur);
        right_output.push_back(temp);
        cur++;
    }
    temp=right_output.back();
    temp[temp.size()-1]='\0';
    right_output.push_back(temp);
    cur=0;
    for(i=0;str[i]!='1';i++){
        temp=right_output.back();
        temp=temp.substr(0,cur)+str[i]+temp.substr(cur);
        right_output.push_back(temp);
        cur++;
    }
    temp=right_output.back();
    temp=temp.substr(0,cur)+temp.substr(cur+1);
    right_output.push_back(temp);
    cout<<"Right most derivation:"<<endl;
    cout<<right_output[0];
    for(i=1;i<right_output.size();i++){
        cout<<" => "+right_output[i];
    } 
    cout<<endl;
    return 0;
}






// int main(){
//     cin>>str;
// }

// int var_index(char ch){
//     for(int i=0;i<var.size();i++){
//         if(var[i]==ch){
//             return i;
//         }
//     }
//     return -1;
// }

// void left_derivation(){
//     int cur=0,var_in;
//     left_output.push_back("S");
//     left_output.push_back(grammar[0][0]);
//     int i=1,j;
//     while(left_output.back()!=str){
//         string temp=left_output[i];
//         if(var_in=var_index(str[i])!=-1){
//             for(j=0;j<grammar[var_in].size();j++){
//                 if(grammar[var_in][j][0]==str[i]){
//                     break;
//                 }
//             }

//         }
//     }
// }

// bool is_var(char ch){
//     for(auto x:var){

//     }
// }


