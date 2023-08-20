#include<bits/stdc++.h>
using namespace std;
vector<string> comments;
int main(){
    FILE *fp=fopen("src.txt","r");
    if(fp==NULL){
        cout<<"Cannot read file"<<endl;
        exit(1);
    }
    int i,j,k;
    char ch='a';
    for(;ch!=EOF;){
        string str;
        for(j=0;ch!='\n';j++){
            fscanf(fp,"%c",&ch);
            str[j]=ch;
        }
        comments.push_back(str);
    }
    for(i=0;i<comments.size();i++){
        cout<<comments[i]<<endl;
    }
    fclose(fp);
    return 0;
}