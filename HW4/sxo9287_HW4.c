#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int flt(float a);
 
int table(void);

int character(char var);


int main(void)
{
    float a;
    printf("please input a float:");
    scanf("%f", &a);
        
    //Here I craeted an int to catch the returned value and print it out  along with the function "flt" Technically I'm calling out the function
        int value;
        value = flt(a);
        printf("int value = %d\n", value);

    printf("----------------\n");
    
        table();
    
    printf("----------------\n");
    
    char var;
    //This scans the variable and stores it
    printf("Please input a chacater:");
    scanf("%c", &var);     
    scanf("%c", &var);
    
    //Here I craeted an int to catch the returned value and print it out along with the function "character". Technically I'm calling out the function
        int chr;
        chr = character(var);
        printf("Decimal value again = %d\n", chr );
        
    printf("Please input a chacater:");
    scanf("%c", &var);   
    scanf("%c", &var);
    
        int car;
        car = character(var);
        printf("Decimal value again = %d\n", car );
        
    return 0;
    
}

int flt(float a)
{
    int f = floor(a);
    int c = ceil(a);
    int r = round(a);
    
    printf("Original value = %f\n", a);
    printf("Floor of value = %d\n", f);
    printf("Cealing of value = %d\n", c);
    printf("Round of value = %d\n", r);
    
    int A = a;
    
    return A;
}


int table(void)
{   
    // Don't know if this how I was intended to use strings, but here they are :)
    char* a = "n^1";
    char* b = "n^2";
    char* c = "n^3";
    char* d = "n^-1";
    char* e = "n^-2";
    // Since floats allowed me to assigned the pow to a variable I created 10 different ones
    float f = 1;   
    float g = 2;
    float h = 3;
    float i = 4;
    float j = 5;
    float k = 6;
    float l = 7;
    float m = 8;
    float n = 9;
    float o = 10;
    // for the power table, I formated it so that it would take the float into a pow function do the math and then display the outpot in its respevtive position
    printf("%s%10s%10s%17s%10s\n", a, b, c, d, e);
    printf("%.0f%10.0f%10.0f%19.3f%10f\n", f, pow(f,2), pow(f,3), pow(f,-1), pow(f,-2)); 
    printf("%.0f%10.0f%10.0f%19.3f%10f\n", g, pow(g,2), pow(g,3), pow(g,-1), pow(g,-2)); 
    printf("%.0f%10.0f%11.0f%18.3f%10f\n", h, pow(h,2), pow(h,3), pow(h,-1), pow(h,-2));
    printf("%.0f%10.0f%11.0f%18.3f%10f\n", i, pow(h,2), pow(i,3), pow(i,-1), pow(i,-2));
    printf("%.0f%11.0f%11.0f%17.3f%10f\n", j, pow(j,2), pow(j,3), pow(j,-1), pow(j,-2));
    printf("%.0f%11.0f%11.0f%17.3f%10f\n", k, pow(k,2), pow(k,3), pow(k,-1), pow(k,-2));
    printf("%.0f%11.0f%11.0f%17.3f%10f\n", l, pow(l,2), pow(l,3), pow(l,-1), pow(l,-2));
    printf("%.0f%11.0f%11.0f%17.3f%10f\n", m, pow(m,2), pow(m,3), pow(m,-1), pow(m,-2)); 
    printf("%.0f%11.0f%11.0f%17.3f%10f\n", n, pow(n,2), pow(n,3), pow(n,-1), pow(n,-2));
    printf("%.0f%11.0f%11.0f%16.3f%10f\n", o, pow(o,2), pow(o,3), pow(o,-1), pow(o,-2));
    
    return 0;
}


//Basic funtion. It takes in the character, does the respective conversion, and then the int is returned to main
int character(char var)
{        
    printf("Char value: %c\n", var); 
    printf("Decimal value: %d\n", var);
    printf("Hex value: %x\n", var);
    
    int B = var;
    
    return B;
    
}


