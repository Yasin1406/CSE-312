#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
char path[101];
char str[101];
int flag,state_num,sym_num,F_num;
void isNFA(char states[state_num],char sym[sym_num],char final_states[F_num],char transition_list[state_num][sym_num][state_num],int transition_num[state_num][sym_num],char cur_state,int str_index,int path_index);
int main(){
    int i,j,k;
    printf("Enter number of states and symbols: ");
    scanf("%d %d",&state_num,&sym_num);
    printf("Enter number of final states: ");
    scanf("%d",&F_num);
    getchar();
    printf("\n");
    char states[state_num],sym[sym_num],transition_list[state_num][sym_num][state_num],init_state,final_states[F_num];

    int transition_num[state_num][sym_num];
    printf("Enter the states: ");
    for(i=0;i<state_num;i++){
        scanf("%c",&states[i]);
        getchar();
    }
    printf("\n");
    printf("Enter symbols: ");
    for(i=0;i<sym_num;i++){
        scanf("%c",&sym[i]);
        getchar();
    }
    printf("\n");
    for(i=0;i<state_num;i++){
        for(j=0;j<sym_num;j++){
            printf("Enter number of transitions for State-%c and Symbol-%c: ",states[i],sym[j]);
            scanf("%d",&transition_num[i][j]);
            getchar();
            if(transition_list[i][j]>0){
                printf("Enter the transitions for State-%c and Symbol-%c: ",states[i],sym[j]);
                for(k=0;k<transition_num[i][j];k++){
                    scanf("%c",&transition_list[i][j][k]);
                    getchar();
                }
            }
            
        }
    }
    printf("\nEnter initial state: ");
    scanf("%c",&init_state);
    getchar();
    printf("Enter the final states: ");
    for(i=0;i<F_num;i++){
        scanf("%c",&final_states[i]);
        getchar();
    }
    printf("\n\nStates\t");
    for(i=0;i<sym_num;i++){
        printf("Symbol-%c   ",sym[i]);
    }
    printf("\n");
    for(i=0;i<state_num;i++){
        printf("%c\t",states[i]);
        for(j=0;j<sym_num;j++){
            for(k=0;k<transition_num[i][j];k++){
                printf("%c ",transition_list[i][j][k]);
            }
            printf("\t\t");
        }
        printf("\n");
    }
    while(1){
        flag=0;
        printf("Enter the string: ");
        scanf("%s",str);
        getchar();
        isNFA(states,sym,final_states,transition_list,transition_num,init_state,0,0);
        if(flag==1){
            printf("Accepted\n");
            printf("Path: ");
            for(i=0;path[i]!='\0';i++){
                printf("%c ",path[i]);
            }
            printf("\n");
        }
        else{
            printf("Rejected\n");
        }
    }  
    return 0;
}
void isNFA(char states[state_num],char sym[sym_num],char final_states[F_num],char transition_list[state_num][sym_num][state_num],int transition_num[state_num][sym_num],char cur_state,int str_index,int path_index){
    int i,j,k,sym_index,state_index;
    if(str[str_index]=='\0'){
        for(i=0;i<F_num;i++){
            if(cur_state==final_states[i]){
                path[path_index]=cur_state;
                path[path_index+1]='\0';
                flag=1;
                break;
            }
        }
        return;
    }
    for(i=0;i<sym_num;i++){
        if(str[str_index]==sym[i]){
            sym_index=i;
            break;
        }
    }
    for(i=0;i<state_num;i++){
        if(cur_state==states[i]){
            state_index=i;
            break;
        }
    }    
    if(transition_num[state_index][sym_index]==0){
        // Stucked
        return;
    }
    int transition_index;
    for(i=0;i<transition_num[state_index][sym_index]&&flag!=1;i++){
        path[path_index]=cur_state;
        path[path_index+1]='\0';
        isNFA(states,sym,final_states,transition_list,transition_num,transition_list[state_index][sym_index][i],str_index+1,path_index+1);
    }     
}
