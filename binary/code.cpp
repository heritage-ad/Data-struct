/* Program name: Binary to Decimal
Author: Heritage Adigun
Date last updated: 10/23/2024
Purpose: A program that uses a stack to convert a binary number into an equivalent decimal number.*/



#include "linkedStack.h" 
#include<iostream>
using namespace std;


int main(){

//defining a stack of char type

linkedStackType<char> stack;

cout<<"Enter a binary number: ";

char c;

//receiving the binary number, character by character, 

//until newline character is encountered

while(cin.peek()!='\n'){

cin>>c;

if(c!='1' && c!='0'){

//if the char is not 0 or 1, then it is not a valid binary number

cout<<"Invalid binary number"<<endl;

exit(1);

}

//pushing the character to the stack

stack.push(c);

}

int decimal=0;

int multiplier=1;//value which will get doubled in each iteration (powers of 2)

//loops until the stack is empty

while(!stack.isEmptyStack()){

//getting the top character

char c=stack.top();

if(c=='1'){

/*only if the character is '1', adding the multiplier value to the resultant

decimal result*/

decimal+=multiplier;

}

//doubling the multiplier

multiplier=multiplier*2;

//popping the top character

stack.pop();

}

//displaying the result

cout<<"Decimal equivalent= "<<decimal<<endl;


return 0;

}