#include <stdio.h>

//Hey yo we got comments
/*
I'm going to skip a lot of stuff, just seeing what is different from C++. As such, it will likely be a bit more messy/less organized
This is from https://w3schools.com/c by the way
*/

int main() {
    printf("\n");

    printf("Hey! C! Are you in there? Why should I use you over C++?\n");


    printf("\n");


    int exampleInt = 52;
    float exampleFloat = 9;
    char exampleChar = 'N';
    printf("  int: %i\n", exampleInt); //%d also works (%decimal or %integer)
    printf("float: %f\n", exampleFloat); //(%float)
    printf(" char: %c\n", exampleChar); //(%char)


    int thisx = 5, thisy = 6, thisz = 7; //declare and initialize all
    int thatx, thaty, thatz = 6; //declare all, only thatz is initialized (thatx and thaty are random values)



    printf("\n");
    return 0;
}