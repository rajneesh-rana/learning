#include<stdio.h>

struct my_struct {
    int x;
    int y;
    int *m;
    int *h;
};
int main()
{
    printf("offset %d\n", (int) &((((struct my_struct*)0)->h)));
    printf("offset %d\n", (int) &(((struct my_struct*)0)->h));
    return 0;
}
