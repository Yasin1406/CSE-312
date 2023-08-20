#include<stdio.h>
int main(){
    FILE *fp=fopen("test_code.c","r");
    if(fp==NULL){
        printf("Cannot read file\n");
        return 0;
    }
    int i,j,k;
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
                printf("%d: ",l);
                for(j=0;ch!='\n'&&ch!=EOF;j++){
                    ch=fgetc(fp);
                    if(ch=='\n'){
                        l++;
                    }
                    printf("%c",ch);
                }
            }
            else if(ch=='*'){
                printf("%d: ",l);
                while(1){
                    ch=fgetc(fp);
                    if(ch=='\n'){
                        l++;
                    }
                    if(ch=='*'){
                        char temp=fgetc(fp);
                        if(temp=='/'){
                          printf("\n");
                            break;
                        }
                        printf("%c",ch);
                        if(temp=='\n'){
                            l++;
                            printf("%c",temp);
                            printf("%d: ",l);
                        }
                        
                        else{
                            printf("%c",temp);
                        }
                    }
                    else{
                        printf("%c",ch);
                        if(ch=='\n'){
                            printf("%d: ",l);
                        }
                    }
                }
               
            }
        }
    }
  printf("\n");
    fclose(fp);
    return 0;
}