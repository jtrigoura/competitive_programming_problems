#include <stdio.h>
#include <stdlib.h>

void printInteger(int *number){
    *number+=1;
    printf("This is the number in the function: %d\n", *number);
}
/*int main() {
    int num=9;
    int *numPointer= &num;
    printInteger(&num);
    printf("This is the number outside the function: %d\n" ,num);
    return 0;
}*/