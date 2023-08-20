#include<bits/stdc++.h>
using namespace std;
int main(){
    FILE *fp=fopen("test_code.c","r");
    if(fp==NULL){
        cout<<"Cannot read file"<<endl;
        exit(1);
    }
    int i,j,k;
    bool new_line=true;
    char ch='a';
    int l=1;
    while(ch!=EOF){
        ch=fgetc(fp);
        if(ch=='\n'){
            l++;
        }
        if(ch=='/'){
            ch=fgetc(fp);
            if(ch=='\n'){
                l++;
            }
            if(ch=='/'){
                string str;
                cout<<l<<". ";
                for(j=0;ch!='\n'&&ch!=EOF;j++){
                    ch=fgetc(fp);
                    if(ch=='\n'){
                        l++;
                    }
                    cout<<ch;
                }
            }
            else if(ch=='*'){
                cout<<l<<". ";
                while(1){
                    ch=fgetc(fp);
                    if(ch=='\n'){
                        l++;
                    }
                    if(ch=='*'){
                        char temp=fgetc(fp);
                        if(temp=='/'){
                            cout<<endl;
                            break;
                        }
                        cout<<ch;
                        if(temp=='\n'){
                            l++;
                            cout<<temp;
                            cout<<l<<". ";
                        }
                        
                        else{
                            cout<<temp;
                        }
                    }
                    else{
                        cout<<ch;
                        if(ch=='\n'){
                            cout<<l<<". ";
                        }
                    }
                }
               
            }
        }
    }
    cout<<endl;
    fclose(fp);
    return 0;
}