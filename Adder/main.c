//
//  main.c
//  Adder
//
//  Created by Kenneth Stepney on 11/1/17.
//  Copyright © 2017 Kenneth Stepney. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXBITS 8

const char ON = '1';
const char OFF = '0';
const int MASK = 0xFF;

int createBinNumberFromInput(void);
int validInput(int c);
int fullAdder(int bin1, int bin2);

int main(int argc, const char * argv[]) {
    //Another way to make an array.
    int *binaryNum = malloc(sizeof(int) * 2);

    binaryNum[0] = createBinNumberFromInput();
    binaryNum[1] = createBinNumberFromInput();
    
    printf("First Number: %d\nSecond Number: %d\n", binaryNum[0], binaryNum[1]);
    
    free(binaryNum);
    return 0;
}

int fullAdder(int bin1, int bin2){
    int result = 0;
    int counter = 0;
    int i;
    //int counter = 0;
    
    //^
    //bin1 = 1101
    //bin2 = 0011
    
    //result = 1110 C:1
    
    //&
    //bin1 = 1101
    //bin2 = 0011
    //counter = 0001
    
    //All these parathesis aren't necessary
    //result |= ((bin1) ^ (bin2));
    //counter |= ((bin1) & (bin2));
    
    for(i = 0; i < MAXBITS; ++i){
        int x = MAXBITS - (i + 1);
        result = ((bin1 >> x) ^ (bin2 >> x)) ^ counter;
        counter = ((bin1 >> x) & (bin2 >> x));
    }
    
    return result;
}

int createBinNumberFromInput(void){
    int input = 0;
    int i, c;
    
    printf("Input a 8-bit number.\n");
    
    for(i = 0; validInput(c = getchar()) > -1 && i < MAXBITS; ++i){
        input |= (c - OFF) << i;
    }
    
    return (input) & MASK;
}

int validInput(int c){
    if(c == ON) return 1;
    else if(c == OFF) return 0;
    else return -1;
}
