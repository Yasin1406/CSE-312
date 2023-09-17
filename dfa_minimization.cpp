#include<bits/stdc++.h>
using namespace std;

int main(){
    int state_num,sym_num,final_num,i,j,k;
    cout<<"Enter number of states, symbols and final states: ";
    cin>>state_num>>sym_num>>final_num;
    char states[state_num],symbols[sym_num],finals[final_num],transition[state_num][sym_num];
    cout<<"Enter the states: ";
    for(i=0;i<state_num;i++){
        cin>>states[i];
    }
    getchar();
    cout<<"Enter the symbols: ";
    for(i=0;i<sym_num;i++){
        cin>>symbols[i];
    }
    getchar();
    cout<<"Enter the final states: ";
    for(i=0;i<final_num;i++){
        cin>>finals[i];
    }
    getchar();
    for(i=0;i<state_num;i++){
        cout<<endl;
        cout<<"Enter transitions for state "<<states[i]<<endl;
        for(j=0;j<sym_num;j++){
            cout<<"For symbol "<<symbols[j]<<": ";
            cin>>transition[i][j];
        }
    }
    cout<<endl;
    cout<<"\t\t";
    for(i=0;i<sym_num;i++){
        cout<<"Sym-"<<symbols[i]<<"\t";
    }
    cout<<endl;
    for(i=0;i<state_num;i++){
        cout<<"State-"<<states[i]<<"\t";
        for(j=0;j<)
    }
    return 0;
}