/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Morgan
 *
 * Created on January 7, 2016, 10:15 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int doasyouaretold(int (*f)(int) );

int fred(int x)
{
	printf("Hello from Fred \n");
	return x*x;
}

int bert(int x)
{
	printf("Hello from Bert \n");
	return x*100;
}


int main(int argc, char** argv) {
    int r;

    int (*f) (int); /* a variable to use to point at functions */

    f = &fred;
    r = doasyouaretold(f);
    printf("r was set equal to %d\n",r);

    f = &bert;
    r = doasyouaretold(f);
    printf("r was set equal to %d\n",r);
        
    return (EXIT_SUCCESS);
}


int doasyouaretold(int (*f)(int) )
{
	return 	f(6);
        // can also write following
	// return 	(*f)(6);
}


