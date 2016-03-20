/*
 * change the bits between position i to j of M to N
 */
#include<stdio.h>
int updateBits(int m,int n, int i,int j){

    int max = ~0; // all ones
    int left = max - ((1<<j)-1);
    int right = (1<<i)-1;
    int mask = left | right;

    return (m&mask)| (n<<i);
}

int main(){
    //testing
    int m = 0b10000000000;
    int n = 0b10101;
    int i = 2;
    int j = 6;
    printf("Is the answer correct? %d ",updateBits(m,n,i,j)==0b10001010100);
}
