#include <stdio.h>

void update(int *a,int *b) {
    int sum; int ad;
    sum = *a + *b;
    if (*a > *b){
        ad = *a-*b;
    }
    else{
        ad = *b-*a;
    }
    *a = sum; /*since pa is the stored value this operation change globally the value of a*/
    *b = ad; /*idem for b from the line above */
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b; /* this means pa access the stored value of the varaible a. similar to pb */
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}