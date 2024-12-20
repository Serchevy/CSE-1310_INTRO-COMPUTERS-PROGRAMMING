#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int arr_fct(int arr[10]);

void arr_2D(int arr2[5][5]);

void receipt(void);


int main()
{

    int arr[10];
    int i, n;
    
    for(i = 0; i < 10; i++)
        {
	    printf("Inoput nuber #%d: ", i+1);
	    scanf("%d", &n);
	    arr[i] = n;
	    }  	  
    //If statement to call 1st fucntion and print out what the funtion determined. 
        if(arr_fct(arr) == 1 )
        {
            printf("There are duplicate values\n");
        }
        else
        {
            printf("All unique values\n");
        }
        
    printf("--------------------\n");
    
    int arr2[5][5] = { {183, 226, 180, 117, 222},
                       {193, 188, 0, 124, 52}, 
                       {46, 157, 214, 49, 246}, 
                       {1, 78, 167, 143, 204}, 
                       {98, 175, 159, 152, 248} };

    arr_2D(arr2);
    
    printf("--------------------\n");
    
    receipt();

    return 0; 
}


int arr_fct(int arr[10])
{
    int i, j;
    int true = 1;
    int false = 0;
    //Two loops which compare all values stored in the array. It checks whethere value are equal or not
    for(i = 0; i < 10; i++)
        {
            for(j = i + 1; j < 10 ; j++)
            
                if(arr[i] == arr[j])
                {
                    return true;
                }  
        }  
    return false;
}

void arr_2D(int arr2[5][5])
{
    int i, j;
    int new;
    //Two loops to substract a value in the 2D array from 225 and then print it out the result.
    for(i = 0; i < 5; i++)    
    {        
        for (j = 0; j < 5; j++)    
        {    
            new = 255 - arr2[i][j];
            printf("%-5d",new);  
        }  
        printf("\n");  
    }
           
}


void receipt(void)
{
    int i, j;
    float sum = 0;
    int code[10];
    float price[10];
    //Two loops to store the code and price repectively, one at a time
    for(i = 0; i < 10; i++)
    {
        printf("Enter UPC #%d: ", i+1);
        scanf("%d", &code[i]);
        
        for(j = i; j == i; j++)
        {
            printf("Enter price #%d: ", j+1);
            scanf("%f", &price[j]);
            sum += price[j];
        }
    }
    // Formated the Recepit just so that it can be readable
    printf("**********************\n");
    printf("%-11s%s\n", "Item Code", "Item Price");
    //Two loops again to print out code and price respectively, one at a time
    for(i = 0; i < 10; i++)
    {
        printf("%-12d", code[i]);
        
        for(j = i; j == i; j++)
        {
            printf("$%.2f\n", price[j]);
        }
    }
    printf("**********************\n");
    printf("%-12s%s%.2f\n", "Total", "$", sum);
}





