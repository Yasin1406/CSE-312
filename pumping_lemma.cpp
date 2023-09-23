#include<bits/stdc++.h>
using namespace std;
#define power '^'
string RE,zero,one,x,y,z,str;
int n,zero_pow,one_pow;
void divide_string();
void generate_string();
int main(){
    freopen("pumping_lemma.txt","r",stdin);
    srand(time(NULL));
    int i,j,k;
    char ch;
    cin>>RE;
    getchar();
    cin>>n;
    for(i=0;i<RE.size();i++){
        if(RE[i]=='0'){
            i++;
            for(;RE[i]!='1'&&i<RE.size();){
                if(RE[i]!=power){
                    zero+=RE[i];
                   
                }
                i++;
            }
        }
        if(RE[i]=='1'){
            i++;
            for(;RE[i]!='0'&&i<RE.size();){
                if(RE[i]!=power){
                    one+=RE[i];
                }
                i++;
            }
        }
    }
    if(zero.size()==1){
        zero='1'+zero;
    }
    if(one.size()==1){
        one='1'+one;
    }
    zero[zero.size()-1]='\0';
    one[one.size()-1]='\0';
    zero_pow=stoi(zero);
    one_pow=stoi(one);
    generate_string();
    divide_string();
    return 0;
} 

void divide_string(){
    int x_len,y_len,i,j,k;
    char ch;
    x_len=rand()%n;
    y_len=n-x_len;
    x=str.substr(0,x_len);
    y=str.substr(x_len,y_len);
    z=str.substr(n,str.size()-x_len-y_len);
    cout<<"x: "<<x<<endl;    
    cout<<"y: "<<y<<endl;    
    cout<<"z: "<<z<<endl;    
}
void generate_string(){
    int lb=n+1,ub=6,i,j,k;
    int l=(rand()%(ub-lb+1))+lb;
    cout<<"n: "<<l<<endl;
    str.resize(zero_pow*l+one_pow*l);
    if(RE[0]=='0'){
        for(i=0;i<zero_pow*l;i++){
            str[i]='0';
        }
        for(j=0;j<one_pow*l;j++){
            str[i++]='1';
        }
    }
    else{
        for(i=0;i<one_pow*l;i++){
            str[i]='1';
        }
        for(j=0;j<zero_pow*l;j++){
            str[i++]='0';
        }
    }
    cout<<str<<endl;
}           