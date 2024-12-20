#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

void F1(char a); 

void F2(int year);

float F3(int kWh);

int F4(int num1, char chr, int num2);

int F5(int n);

void F6(int num);

int F7(void);

void F8(int str);


int main()
{
    char a;
    printf("Please enter a character: ");
    scanf("%c", &a);
    F1(a);
    
    printf("-----------------\n");
    
    int year;
    printf("Please enter a year: ");
    scanf("%d", &year);
    F2(year);
    
    printf("-----------------\n");
    
    int kWh;
    printf("How many kWh did you use this month? ");
    scanf("%d", &kWh);
    printf("You owe $%.2f\n", F3(kWh));
    
    printf("-----------------\n");
    
    int num1;
    int num2;
    char chr;
    printf("Please enter an operation in the format of \"1+1\". You may change the numbers and the operation\n");
    scanf(("%d%c%d"), &num1, &chr, &num2);
    printf("%d%c%d=%d\n", num1, chr, num2 ,F4(num1, chr, num2));
    
    printf("-----------------\n");
    
    int n;
    printf("Please enter an int: ");
    scanf("%d", &n);
    printf("%d! = %d\n", n, F5(n));
    
    printf("-----------------\n");
    
    int num;
    printf("Please enter an int: ");
    scanf("%d", &num);
    F6(num);
    
    printf("-----------------\n");
    
    printf("The total is %d\n", F7());
    
    printf("-----------------\n");
    
    int str;
    printf("Please enter an int: ");
    scanf("%d", &str);
    F8(str);
    
    return 0;

}


void F1(char a)
{
    if (a >= '0' && a <= '9')
    {
        printf("You have entered a number\n");
    }
    else if (a >= 'A' && a <= 'Z')
    {
        printf("You have entered an upper case letter\n");
    }
    else if ( a >= 'a' && a <= 'z' )
    {
        printf("You have entered a lower case letter\n");
    }
    // had to use ctype.h for white space, otherwise if a special char was entered it would define it as white space. I don't know why it kept hapenning, but this fixed the issue. 
    else if ( isspace(a))
    {
        printf("You have entered a white space\n");
    }
    else
    {
        printf("You have entered a special character\n");
    }   
}

void F2(int year)
{
    // leap year if perfectly divisible by 400 or 4. Not a leap year if divisible by 100
   if (year % 400 == 0) 
   {
      printf("It is a leap year\n");
   }
   else if (year % 100 == 0) 
   {
      printf("It is not a leap year\n");
   }
   else if (year % 4 == 0) 
   {
      printf("It is a leap year\n");
   }
   // anything else is irrelevant
   else 
   {
      printf("It is not a leap year\n");
   }
}

float F3(int kWh)
{

    if (kWh <= 500)
    {
        float A = kWh * 0.15;
        return A;
    }
    //Here if kWh is >500 but <=1000 the charge is 0.12. Since the fisrt 500 are always charged at 0.15. you have to take away 500 from whatever the iput from user is, then clculate the cost at 0.12 and then add 500 * 0.15. Same logic applies to the rest of the statements. Hope that made sense.  
    else if (kWh > 500 && kWh <= 1000)
    {
        float A = (500 * 0.15) + ((kWh - 500) * 0.12);
        return A;
    }
    else if (kWh > 1000 && kWh <= 2000)
    {
        float A = (500 * 0.15) + (500 * 0.12) + ((kWh - 1000) * 0.14);
        return A;
    }
    else
    {
        float A = (500 * 0.15) + (500 * 0.12) + (1000 * 0.14) + ((kWh - 2000) * 0.17);
        return A;
    }
}

int F4( int num1, char chr, int num2)
{
    int result;
    //Basically matches the character to a case 
    switch(chr)
    {
        case '+': 
            result = num1 + num2;
            break;

        case '-': 
            result = num1 - num2;
            break;

        case '*': 
            result = num1 * num2;
            break;

        case '/': 
            result = num1 / num2;
            break;
            
        case '%': 
            result = num1 % num2;
            break;
        //This just in case the input is something weird
        default: 
            printf("That's not what I asked for");
    }
    
    return result;
}

int F5(int n)
{
    //f and i start as 1, but as the loop progresses f will be 1 less than i and so the factorial can be calculated until the loop's condition is no longer true.
    int f,i;
    f=1;
    i=1;
    while(i<=n)
    {
        f = f * i;
        i++;
    }
    
    return f;
}

void F6(int num)
{
    printf("%-10s%-10s%-10s%10s%10s\n","n","n^2","n^3","n^-1","n^-2");
    float i;
    //As long as i<= the user's unput, the loop will keep runing. But after each run, one will be added to i. So the loop cancels once i> user's input.  
    for (i=1; i<=num; i++)
    {
        printf("%-10d%-10d%-10d%10.3f%10f\n", (int) i, (int) pow(i,2), (int) pow(i,3), pow(i,-1), pow(i,-2));
    }
}

int F7()
{
    //Num is the user's input and sum is the total of all the numbers. So while num is not 0 it loops the statement while adding all the inputs from user. 
    int num, sum = 0;
    while (num != 0)
    {
        printf("Enter a number: ");
        scanf("%d", &num);
        sum += num;
    }
    
    return sum;
    
}

void F8(int str)
{
   //Outer and Inner loops. Inner is the one that repeats the most which prints the stars and once its condition is no longe true a spaceline is printed, Outer loop then strats and if condition is true then inner loop strats again. 
   int i, j;
   for (i = 1; i <= str; ++i) 
   {
      for (j = 1; j <= i; ++j) 
      {
         printf("*");
      }
      printf("\n");
   }
}


