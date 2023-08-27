#include<bits/stdc++.h>
using namespace std;
int state_num,sym_num;
void get_regex(vector<vector<string>> pre_regex,vector<vector<string>> &cur_regex,int k);
void print_regex(vector<vector<string>> regex);
int main(){
    cout<<"Enter number of states and symbols: ";
    cin>>state_num>>sym_num;
    getchar();
    char states[state_num],symbols[sym_num];
    int i,j,k;
    char transition_list[state_num][sym_num];
    cout<<endl;
    cout<<"Enter the states: ";
    for(i=0;i<state_num;i++){
        cin>>states[i];
        getchar();
    }
    cout<<"Enter the symbols: ";
    for(i=0;i<sym_num;i++){
        cin>>symbols[i];
        getchar();
    }
    cout<<endl;
    for(i=0;i<state_num;i++){
        printf("Enter the transitions for State-%c:\n",states[i]);
        for(j=0;j<sym_num;j++){
            printf("For %c: ",symbols[j]);
            cin>>transition_list[i][j];
            getchar();
        }
        cout<<endl;
    }

    cout<<"\t\t";
    for(i=0;i<sym_num;i++){
        printf("Symbol-%c\t",symbols[i]);
    }
    cout<<endl;
    for(i=0;i<state_num;i++){
        printf("State-%c\t\t",states[i]);
        for(j=0;j<sym_num;j++){
            cout<<transition_list[i][j]<<"\t\t";
        }
        cout<<endl;
    }
    vector<vector<string>> regex;
    regex.resize(state_num,vector<string>(state_num));
    for(i=0;i<state_num;i++){
        for(j=0;j<state_num;j++){
            regex[i][j].push_back('(');
            for(k=0;k<sym_num;k++){
                if(transition_list[i][k]==states[j]){
                    regex[i][j].push_back(symbols[k]);
                    regex[i][j].push_back('+');
                }
            }
            if(i==j){
                regex[i][j]+="E+";
            }
            if(regex[i][j].size()==1){
                regex[i][j]+="#";
            }
            if(regex[i][j].back()=='+'){
                regex[i][j].pop_back();
            }
            regex[i][j].push_back(')');
        }
    }
    printf("For k=0\n");
    for(i=0;i<state_num;i++){
        for(j=0;j<state_num;j++){
            printf("R%d%d: ",i+1,j+1);
            cout<<regex[i][j]<<endl;
        }
    }
    cout<<endl;
    vector<vector<string>> regex1;
    get_regex(regex,regex1,1); 
    printf("For k=1\n");
    for(i=0;i<state_num;i++){
        for(j=0;j<state_num;j++){
            printf("R%d%d: ",i+1,j+1);
            cout<<regex1[i][j]<<endl;
        }
    }  
    vector<vector<string>> regex2;
    get_regex(regex1,regex2,1); 
    printf("For k=2\n");
    for(i=0;i<state_num;i++){
        for(j=0;j<state_num;j++){
            printf("R%d%d: ",i+1,j+1);
            cout<<regex2[i][j]<<endl;
        }
    }   
    // print_regex(regex1);
    return 0;
}
void get_regex(vector<vector<string>> pre_regex,vector<vector<string>> &cur_regex,int k){
    int i,j;
    cur_regex.resize(state_num,vector<string>(state_num));
    for(i=0;i<state_num;i++){
        for(j=0;j<state_num;j++){
            // cur_regex[i].push_back(pre_regex[i][j]);
            cur_regex[i][j]+=pre_regex[i][j];
            cur_regex[i][j].push_back('+');
            // cur_regex[i].push_back(pre_regex[i][k-1]);
            cur_regex[i][j]+=pre_regex[i][k-1];
            cur_regex[i][j].push_back('(');
            // cur_regex[i].push_back(pre_regex[k-1][k-1]);
            cur_regex[i][j]+=pre_regex[k-1][k-1];
            cur_regex[i][j].push_back(')');
            cur_regex[i][j].push_back('*');
            // cur_regex[i].push_back(pre_regex[k-1][j]);
            cur_regex[i][j]+=pre_regex[k-1][j];
        }
    }
}
void print_regex(vector<vector<string>> regex){
    int i,j;
    

}