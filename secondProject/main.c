/* 
 * File:   main.c
 * Author: mwj7
 *
 * Created on 09 October 2015, 13:09
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    float a,b,c;
    a = 4.0;
    b = 5.0;
    c = a / b;

    //output
    printf("%1.1f divided by %1.1f equals %1.1f\n",a,b,c);

    return (EXIT_SUCCESS);
}

