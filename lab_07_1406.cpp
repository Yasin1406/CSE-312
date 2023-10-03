#include<bits/stdc++.h>
using namespace std;
#define max 100
int state_num,sym_num,final_num,new_state_num,new_final_num;
char states[max],symbols[max],finals[max],transition[max][max],table[max][max],new_states[max],new_transition_table[max][max],new_finals[max];
bool finishing_state[max][max];
string checkers[]={"0","1","00","01","10","11"};
vector<pair<int,int>> equivalent_pairs;

void read_input();
bool isFinal(char st);
int state_in(char st);
int sym_in(char sym);
void cross_finals();
void create_finishing_state_table();
char traverse(char starting,string str);
void create_distinguishability_table();
void minimize_dfa();

int main(){
    freopen("input.txt","r",stdin);
    int i,j,k;
    read_input();
    create_finishing_state_table();
    create_distinguishability_table();
    minimize_dfa();
    cout<<"Distinguishability table:\n";
    for(i=1;i<state_num;i++){
        cout<<states[i]<<" ";
        for(j=0;j<i;j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"  ";
    for(i=0;i<state_num-1;i++){
        cout<<states[i]<<" ";
    }
    cout<<endl<<endl;
    cout<<"Minimized transition table:"<<endl;;
    cout<<"States\t\t";
    for(i=0;i<sym_num;i++){
        cout<<"Symbol-"<<symbols[i]<<"\t";
    }
    cout<<endl;
    for(i=0;i<new_state_num;i++){
        cout<<new_states[i]<<"\t\t";
        for(j=0;j<sym_num;j++){
            cout<<new_transition_table[i][j]<<"\t\t";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}

void read_input(){
    int i,j,k;
    // cout<<"Enter number of states, symbols and final states: ";
    cin>>state_num>>sym_num>>final_num;
    states[state_num];
    symbols[sym_num];
    finals[final_num];
    transition[state_num][sym_num];
    table[state_num][state_num];
    finishing_state[state_num][6];
    new_finals[state_num];
    for(i=0;i<state_num;i++){
        for(j=0;j<state_num;j++){
            table[i][j]='=';
        }
    }
    // cout<<"Enter the states: ";
    for(i=0;i<state_num;i++){
        cin>>states[i];
    }
    getchar();
    // cout<<"Enter the symbols: ";
    for(i=0;i<sym_num;i++){
        cin>>symbols[i];
    }
    getchar();
    // cout<<"Enter the final states: ";
    for(i=0;i<final_num;i++){
        cin>>finals[i];
    }
    getchar();
    for(i=0;i<state_num;i++){
        // cout<<endl;
        // cout<<"Enter transitions for state "<<states[i]<<endl;
        for(j=0;j<sym_num;j++){
            // cout<<"For symbol "<<symbols[j]<<": ";
            cin>>transition[i][j];
        }
    }
}

bool isFinal(char st){
    for(int i=0;i<final_num;i++){
        if(st==finals[i]){
            return true;
        }
    }
    return false;
}

int state_in(char st){
    for(int i=0;i<state_num;i++){
        if(st==states[i]){
            return i;
        }
    }
    return -1;
}

int sym_in(char sym){
    for(int i=0;i<sym_num;i++){
        if(sym==symbols[i]){
            return i;
        }
    }
    return -1;
}

void cross_finals(){
    for(int i=0;i<final_num;i++){
        int index=state_in(finals[i]);
        for(int j=0;j<index;j++){
            if(!isFinal(states[j])){
                table[index][j]='x';
            }
        }
        for(int j=index+1;j<state_num;j++){
            if(!isFinal(states[j])){
                table[j][index]='x';
            }
        }
    }
}

void create_finishing_state_table(){
    for(int i=0;i<state_num;i++){
        for(int j=0;j<6;j++){
            if(isFinal(traverse(states[i],checkers[j]))){
                finishing_state[i][j]=true;
            }
            else{
                finishing_state[i][j]=false;
            }
        }
    }
}

char traverse(char starting,string str){
    for(int i=0;i<str.size();i++){
        starting=transition[state_in(starting)][sym_in(str[i])];
    }
    return starting;
}

void create_distinguishability_table(){
    cross_finals();
    int i,j,k;
    for(i=1;i<state_num;i++){
        for(j=0;j<i;j++){
            if(table[i][j]!='x'){
                for(k=0;k<6;k++){
                    if(finishing_state[i][k]!=finishing_state[j][k]){
                        table[i][j]='x';
                        break;
                    }
                }
                if(k==6){
                    equivalent_pairs.push_back({j,i});
                }
            }
        }
    }
}

void minimize_dfa(){
    new_state_num=state_num-equivalent_pairs.size();
    new_states[new_state_num];
    new_transition_table[new_state_num][sym_num];
    int i,j,k=0;
    for(i=0;i<state_num;i++){
        for(j=0;j<equivalent_pairs.size();j++){
            if(i==equivalent_pairs[j].second){
                break;
            }
        }
        if(j==equivalent_pairs.size()){
            new_states[k++]=states[i];
        }
    }
    k=0;
    for(i=0;i<new_state_num;i++){
        if(isFinal(new_states[i])){
            new_finals[k++]=new_states[i];
        }
    }
    new_final_num=k;
    k=0;
    for(i=0;i<state_num;i++){
        int index=find(new_states,new_states+new_state_num,states[i])-new_states;
        if(index!=new_state_num){
            for(j=0;j<sym_num;j++){
                new_transition_table[k][j]=transition[i][j];
            }
            k++;
        }
    }
    for(i=0;i<new_state_num;i++){
        for(j=0;j<sym_num;j++){
            for(k=0;k<equivalent_pairs.size();k++){
                if(state_in(new_transition_table[i][j])==equivalent_pairs[k].second){
                    new_transition_table[i][j]=states[equivalent_pairs[k].first];
                }
            }
        }
    }
}