#include <iostream>
#include "operations.h"

using namespace std;

void getFirstNumberFromUser();  //to get input from user
void getSecondNumberFromUser(); //to get input from user
void listOperations();          //to print out list of operations 
void calculate();               //main function  

char operations[] = {'_', '+', '-', '*', '/', '!'};
int userTotal = 0;
int userFirstNumber;
int userSecondNumber;
int operationChoice;

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

int mul(int a, int b){
    return a * b;
}

int quo(int a, int b){
    if(b == 0){
        cout << "Error! Second number can not be 0" << endl;
        calculate();
    }
    return a / b;
}

int fac(int a){
    if(a == 1){
        return 1;
    }
    else{
        return a * fac(a-1);
    }
}

void getFirstNumberFromUser(){
    cout << "Enter your first Number: ";
    cin >> userFirstNumber;
}

void getSecondNumberFromUser(){
    cout << "Enter your second Number: ";
    cin >> userSecondNumber;
}

void listOperations(){
    cout << "Choose an Operation: (choose number 1 = add)" << endl;
    cout << "1. Addition [+]" << endl;
    cout << "2. Subtraction [-]" << endl;
    cout << "3. Multiplication [*]" << endl;
    cout << "4. Division [/]" << endl;
    cout << "5 Factorial [!]" << endl;
    cout << "Operation: ";
    cin >> operationChoice;
    //error handling 
    if(operationChoice > 5 || operationChoice == 0 || operationChoice < 0){
        cout << "Error! Invalid Operation Choice" << endl;
        calculate();
    }
    //actual choices
    else if(operationChoice == 1){
        getSecondNumberFromUser();
        userTotal = add(userFirstNumber, userSecondNumber);
    }
    else if(operationChoice == 2){
        getSecondNumberFromUser();
        userTotal = sub(userFirstNumber, userSecondNumber);
    }
    else if(operationChoice == 3){
        getSecondNumberFromUser();
        userTotal = mul(userFirstNumber, userSecondNumber);
    }
    else if(operationChoice == 4){
        getSecondNumberFromUser();
        userTotal = quo(userFirstNumber, userSecondNumber);
    }
    else if(operationChoice == 5){
       userTotal =  fac(userFirstNumber);
    }
}

void calculate(){
    getFirstNumberFromUser();
    listOperations();
    cout << userFirstNumber << " " << operations[operationChoice] << " " << userSecondNumber << " = " << userTotal << endl;
}

int main(){
    calculate();
    return 0;
}