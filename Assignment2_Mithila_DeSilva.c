/*I declare that the attached assignment is wholly my
 own work in accordance with Seneca Academic Policy.  No part of this
 assignment has been copied manually or electronically from any
 other source (including web sites) or distributed to other students.
 
 Name   _Mithila DeSilva_   Student ID  _068545136_*/

#include <stdio.h>
//Declaring functions
void getValues(int *a,int *b);
void getCounts(int a, int *c, int *d, int *e, int *f, int *g);
void translate(int a, int b, int *c, int *d, int *e, int *f, int *g);
void calculate(int *a);

int main()
{
    //declaring variables
    int firstValue, secondValue, tenThousands, thousands, hundreds, tens, ones;
    char answer;
    
    printf("%53s", "Chinese Translation Program\n");
    printf("==============================================================================\n");
    
    //Calling functions
    do{
    getValues(&firstValue, &secondValue);
    printf("\n|%10s |", "Numbers");
    printf("%39s", " Chinese Equivalent ");
    printf("%26s\n", "|");
    printf("------------------------------------------------------------------------------\n");
    getCounts(firstValue, &tenThousands, &thousands, &hundreds, &tens, &ones);
    translate(firstValue, secondValue, &tenThousands, &thousands, &hundreds, &tens, &ones);
        printf("\nDo you wish to translate again (Y/N)?");
        scanf(" %c", &answer);
    }while (answer == 'y' || answer == 'Y');
    
return 0;
}
//Defining functions
void getValues(int *a,int *b)
{
    int temp;
    //Take first nuber
    do {
        printf("\nPlease enter the first number in range : ");
        temp=scanf("%d", a);
        while(getchar() != '\n');
        if (*a <0 || *a >100000000 || temp == 0) {
            printf("Invalid Input\n");
        }
    } while (*a <0 || *a >100000000 || temp == 0);
    //Take second number
    do {
        printf("Please enter the second number in range: ");
        temp=scanf("%d", b);
        while(getchar() != '\n');
        if (*b <0 || *b >100000000 || *b < *a || temp == 0) {
            printf("Invalid Input\n");
        }
   } while (*b <0 || *b >100000000 || *b < *a || temp == 0);
}

void getCounts(int a, int *c, int *d, int *e, int *f, int *g)
{
    //Assigning(10,000s)
    *c= a / 10000;
    a= a - (*c * 10000);
    
    //Assigning(1,000s)
    *d= a / 1000;
    a= a - (*d * 1000);
    
    //Assigning(100s)
    *e= a / 100;
    a= a - (*e * 100);
    
    //Assigning(10s)
    *f= a / 10;
    a= a - (*f * 10);
    
    //Assigning(1s)
    *g= a / 1;
}

void translate(int a, int b, int *c, int *d, int *e, int *f, int *g)

{
for (int i= a; i <= b; i++) {
    
    printf("|%10d |", i);
    
    //call function getCounts
    getCounts(i, c, d, e, f, g);
    
    //Calculations(10,000s)
    if (*c > 9) {
        getCounts(*c, c, d, e, f, g);
        //Calculations(1,000s)
        if (*d > 0) {
            calculate(d);
            printf(" qian ");
        }
        //Calculations(100s)
        if (*e > 0) {
            calculate(e);
            printf(" bai ");
        }
        //Calculations(10s)
        if (*f > 0) {
            calculate(f);
            printf(" shi ");
        }
        //Calculations(1s)
        calculate(g);
        printf(" wan ");
        getCounts(i, c, d, e, f, g);
    } else if (*c > 0) {
        calculate(c);
        printf(" wan ");
    }
    //Calculations(1,000s)
    if (*d > 0) {
        calculate(d);
        printf(" qian ");
    }
    //Calculations(100s)
    if (*e > 0) {
        calculate(e);
        printf(" bai ");
    }
    //Calculations(10s)
    if (*f > 0) {
        calculate(f);
        printf(" shi ");
    }
    //Calculations(1s)
    calculate(g);
    printf(" |\n");
    }
}
void calculate(int *a)
{
    switch (*a) {
        case 1:
            printf("yi ");
            break;
        case 2:
            printf("er ");
            break;
        case 3:
            printf("san ");
            break;
        case 4:
            printf("si ");
            break;
        case 5:
            printf("wu ");
            break;
        case 6:
            printf("liu ");
            break;
        case 7:
            printf("qi ");
            break;
        case 8:
            printf("ba ");
            break;
        case 9:
            printf("jiu ");
            break;
        default:
            break;
    }
}



