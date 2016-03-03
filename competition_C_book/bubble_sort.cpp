#include<stdio.h>
#include<string.h>
#define maxn 1000
int get_next(int x){
    int a,b,n;
    char s[10];
    sprintf(s,"%d",x);
    n = strlen(s);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[j]<s[i]){
                char t = s[i];s[i] = s[j];s[j] = t;
            }

        }
    }
    sscanf(s,"%d",&b);
    //next is to find a
    for(int i=0;i<n/2;i++){
        char t = s[i];
        s[i] = s[n-1-i];
        s[n-1-i] = s[i];

    }
    sscanf(s,"%d",&a);

    return a-b;
}
int count;
int nums[maxn];
int main(){
    scanf("%d",&nums[0]);
    printf("%d",nums[0]);

    count=1;
    for(;;){
        nums[count] = get_next(nums[count-1]);
        printf(" -> %d",nums[count]);

        int found = 0;
        for(i=0;i<count;i++){
            if(nums[i]==nums[count]){
                found = 1;
                break;
            }
        }
        if(found) break;
        count++;
    }

    printf("\n");
    return 0;
}
