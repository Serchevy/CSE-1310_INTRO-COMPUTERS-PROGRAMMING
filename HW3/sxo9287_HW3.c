#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int average(int sum);

int hours(int seconds);

int minutes(int seconds);

// I had to add a fourth fucntion since I took a different approach with the seconds convertion
int sec(int seconds);


int main(void)
{
    
    int a, b;    
    
    printf("Enter fisrt number (a):");
    scanf("%d", &a);
    
    printf("Enter second number (b):");
    scanf("%d", &b);
    
        printf("a + b = %d\n", a + b);
        printf("a - b = %d\n", a - b);
        printf("a * b = %d\n", a * b);
        printf("a / b = %d\n", a / b);
        printf("a %% b = %d\n", a % b);  
    
    printf("-------------------\n");
    
    
    int c, d, e;
    
    printf("Enter fisrt number (a):");
    scanf("%d", &a);
    
    printf("Enter second number (b):");
    scanf("%d", &b);
    
    printf("Enter third number (c):");
    scanf("%d", &c);
    
    printf("Enter fourth number (d):");
    scanf("%d", &d);
    
    printf("Enter fifth number (e):");
    scanf("%d", &e);
    
        printf(" %d, %d, %d, %d, %d\n", a, b, c, d, e);
        
        printf("The sum of these numbers is %d\n", (a + b + c + d + e));
      
    int sum = a + b + c + d + e;
        
        average(sum);
        
    printf("-------------------\n");
    
    
    printf("Enter a number (a):");
    scanf("%d", &a);
    
        int sqr = pow(a,2);
        printf("a^2 = %d\n", sqr);
        
        int cub = pow(a,3);
        printf("a^3 = %d\n", cub);
        
    printf("-------------------\n");  
    

    printf("Enter a negative number (a):");
    scanf("%d", &a);
         
        int n = abs(a);
        printf("|a| = %d\n", n);
        
    printf("-------------------\n"); 
    
    int s;
    
    printf("Enter the number of seconds:");
    scanf("%d", &s);
    
    int seconds = s;
    
        hours(seconds);
        
        minutes(seconds);
        
        sec(seconds);
    
      
    return 0;
    
}


int average(int sum)
{
   int avg = sum/5;
   printf("The average of these numbers is %d\n", avg);
}


// So with the hours, minutes, and seconds I took a more clean approach which would not require updating the "seconds" once hours and minutes were calculated.

int hours(int seconds)
{
    int h = seconds / 3600;
    printf("Hours = %d, ", h);
}


int minutes(int seconds)
{
    int m = (seconds % 3600) / 60;
    printf("Minutes = %d, ", m);
}

int sec(int seconds)
{
    int S = (seconds % 3600) % 60;
    printf("Seconds = %d\n", S);
}


