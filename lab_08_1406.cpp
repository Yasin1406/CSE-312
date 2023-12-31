#include<bits/stdc++.h>
using namespace std;
#define power '^'
string RE,zero,one,x,y,z,str;
int n,zero_pow,one_pow,len;
void divide_string();
void generate_string();
void pump(string &st,int k);
bool check(string st);
int main(){
    freopen("pumping_lemma.txt","r",stdin);
    srand(time(NULL));
    int i,j,k;
    char ch;
    cin>>RE;
   // getchar();
    //cin>>n;
    if(RE[0]=='0'){
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
                for(;i<RE.size();){
                    if(RE[i]!=power){
                        one+=RE[i];
                    }
                    i++;
                }
            }
        }
    }
    else{
        for(i=0;i<RE.size();i++){
            if(RE[i]=='1'){
                i++;
                for(;RE[i]!='0'&&i<RE.size();){
                    if(RE[i]!=power){
                        one+=RE[i];
                    }
                    i++;
                }
            }
            if(RE[i]=='0'){
                i++;
                for(;i<RE.size();){
                    if(RE[i]!=power){
                        zero+=RE[i];
                    }
                    i++;
                }
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
    bool isTrue=true;
    k=0;
    while(isTrue){
        string st;
        pump(st,k);
        isTrue=check(st);
        k++;
    }
    cout<<"Not a regular expression for k="<<--k<<endl;
    return 0;
}

void divide_string(){
    n=rand()%len;
    if(n==0){
        n++;
    }
    int x_len,y_len,i,j,k;
    cout<<"n: "<<n<<endl;
    x_len=rand()%n;
    cout<<"x_len: "<<x_len<<endl;
    int lb=1,ub=n-x_len;
    y_len=(rand()%(ub-lb+1))+lb;
    cout<<"y_len: "<<y_len<<endl;
    x=str.substr(0,x_len);
    cout<<"x: "<<x<<endl;
    y=str.substr(x_len,y_len);
    cout<<"y: "<<y<<endl;
    z=str.substr(x_len+y_len,str.size()-x_len-y_len);
    cout<<"z: "<<z<<endl;
}
void generate_string(){
   // n=(rand()%(6-1+1))+1;
    int lb=6,ub=10,i,j,k;
    int l=(rand()%(ub-lb+1))+lb;
    len=l*zero_pow+l*one_pow;
    cout<<"L: "<<len<<endl;
    str.resize(len);
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

void pump(string &st,int k){
    int i,j;
    st+=x;
    for(i=0;i<=k;i++){
        st+=y;
    }
    st+=z;
    cout<<"After "<<k<<" pump: "<<st<<endl;
}

bool check(string st){
    int zero_cnt=0,one_cnt=0;
    int i,j,k;
    if(RE[0]=='0'){
        for(i=0;st[i]=='0';i++){
            zero_cnt++;
        }
        for(;i<st.size();i++){
            if(st[i]=='0'){
                return false;
            }
            one_cnt++;
        }
    }
    else{
        for(i=0;st[i]=='1';i++){
            one_cnt++;
        }
        for(;i<st.size();i++){
            if(st[i]=='1'){
                return false;
            }
            zero_cnt++;
        }
    }
    if((double)zero_cnt/one_cnt==(double)zero_pow/one_pow){
        return true;
    }
    else{
        return false;
    }
}
