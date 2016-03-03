#include<stdio.h>
#include<string.h>
int main(){
    //to find the shorted string cycle of an array of characters
    char word[100];
    scanf("%s",word);
    int len = strlen(word);
    //then enumerating the length of cycle
    int i,j;
    for(i=1;i<=len;i++){
        int ok=1;
        for(j=i;j<len;j++){
            if(word[j]!=word[j-i]){
                ok=0;
                break;
            }
        }
        if(ok){
        printf("%d\n",i);
        break;
        }
    }
    return 0;
}
