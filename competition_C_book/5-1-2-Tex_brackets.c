/*
Be careful of this. I used %s instead of %c which results in a segmentation fault
char str[] = "This is the end";
char input[100];

printf("%s\n", str);
printf("%c\n", *str);

scanf("%99s", input);

*/

#include<stdio.h>
int main(){
    int c,q=1;
    while((c=getchar())!=EOF){
        if(c=='"'){ printf("%s", q ? "``":"''"); q=!q;}
        else printf("%c",c);

    }
    return 0;
}
