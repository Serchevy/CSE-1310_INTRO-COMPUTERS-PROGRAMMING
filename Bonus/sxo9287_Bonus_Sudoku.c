#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0


int row(int sudk[9][9], int r);

int column(int sudk[9][9], int c);

int square(int sudk[9][9], int s);


int main()
{
    char infilename[20];
    int sudk[9][9];
    int r;
    int c;
    int s;
    //===================================
    
    printf("Enter file name: ");
    scanf("%s", infilename);
    FILE *fp;
    fp = fopen(infilename, "r");
    if(fp == NULL)
    {
        printf("failed to open file");
        exit(1);
    }
    for(int i = 0; i < 9; i++) // Loop to read in all numbers in file and store them in array.
    {
        for(int j = 0; j < 9; j++)
        {
            fscanf(fp, "%d", &sudk[i][j]) != 1; 
        }
    }
    fclose(fp);
    /*for(int i = 0; i < 9; i++)  
    {
        for(int j = 0; j < 9; j++) 
        {
            printf("%-3d", sudk[i][j]);
        }
        printf("\n");
    }*/
    //===================================
    
    for(r = 0; r < 9; r++) // This loops through the fuction row, while updating the row (r) to be chcked. If false is returned, the sudoku is unvalid. 
    {
        if(row(sudk, r) == 0)
        {
            printf("Invalid Solution. Issue on row #%d\n", r+1);
            break;
        }
        //printf("Row %d is good\n", r+1);
    }
    //===================================
    
    for(c = 0; c < 9; c++) // This loops through the fuction column, while updating the column (c) to be chcked. If false is returned, the sudoku is unvalid. 
    {
        if((column(sudk, c)) == 0)
        {
            printf("Invalid Solution. Issue on column #%d\n", c+1);
            break;
        }
        //printf("Column %d is good\n", c+1);
    }
    //===================================
    
    for(s = 0; s < 9; s++) // This loops through the fuction square, while updating the square (s) to be chcked. If false is returned, the sudoku is unvalid. 
    {
        if((square(sudk, s)) == 0)
        {
            printf("Invalid Solution. Issue on square #%d\n", s+1);
            break;
        }
        //printf("Square %d is good\n", s+1);
    }
    //===================================
    
    /*printf("Row    = %d\n", row(sudk, r));
    printf("Column = %d\n", column(sudk, c));
    printf("Square = %d\n", square(sudk, s));*/
    
    // Statement that check all three fucntions. If all three return true, as in no errors found, then the soduko is a valid solution 
    if((row(sudk, r)) == 1 && (column(sudk, c)) == 1 && (square(sudk, s)) == 1)
    {
        printf("Valid Solution\n");
    }

    return 0;
}

// Simple fuction that compares every value in a row. If any value repeats false is returned/unvalid solution
int row(int sudk[9][9], int r)
{    
    for(int i = 0; i < 9; i++)
    {
        for(int j = i+1; j < 9; j++)
        {
            if(sudk[r][i] == sudk[r][j])
            {
                return false;
            }
        }
        return true;
    }
}

// Same as row fuction. Just swaping the int that is being taken so that function compares all values in a column. 
int column(int sudk[9][9], int c)
{  
    for(int i = 0; i < 9; i++)
    {
        for(int j = i+1; j < 9; j++)
        {
            if(sudk[i][c] == sudk[j][c])
            {
                return false;
            }
        }
        return true;
    }
}

/*In this function each time s increases, a square, which is composed of 9 values is checked. The values composing a square are fixed so function is long.
  If the values in that square don't add up to 45, then the square has either missing or repeating values */
int square(int sudk[9][9], int s)
{  
    int sum = 0;  
    
    if(s == 0)
    {
        sum = sudk[0][0] + sudk[0][1] + sudk[0][2] 
              + sudk[1][0] + sudk[1][1] + sudk[1][2] 
              + sudk[2][0] + sudk[2][1] + sudk[2][2];
        if(sum == 45)
        {
            return true;
        }
        return false;
    }
    else if(s == 1)
    {
        sum = sudk[0][3] + sudk[0][4] + sudk[0][5] 
              + sudk[1][3] + sudk[1][4] + sudk[1][5] 
              + sudk[2][3] + sudk[2][4] + sudk[2][5];
        if(sum == 45)
        {
            return true;
        }
        return false;
    }
    else if(s == 2)
    {
        sum = sudk[0][6] + sudk[0][7] + sudk[0][8] 
              + sudk[1][6] + sudk[1][7] + sudk[1][8] 
              + sudk[2][6] + sudk[2][7] + sudk[2][8];
        if(sum == 45)
        {
            return true;
        }
        return false;
    }
    else if(s == 3)
    {
        sum = sudk[3][0] + sudk[3][1] + sudk[3][2] 
              + sudk[4][0] + sudk[4][1] + sudk[4][2] 
              + sudk[5][0] + sudk[5][1] + sudk[5][2];
        if(sum == 45)
        {
            return true;
        }
        return false;
    }
    else if(s == 4)
    {
        sum = sudk[3][3] + sudk[3][4] + sudk[3][5] 
              + sudk[4][3] + sudk[4][4] + sudk[4][5] 
              + sudk[5][3] + sudk[5][4] + sudk[5][5];
        if(sum == 45)
        {
            return true;
        }
        return false;
    }
    else if(s == 5)
    {
        sum = sudk[3][6] + sudk[3][7] + sudk[3][8] 
              + sudk[4][6] + sudk[4][7] + sudk[4][8] 
              + sudk[5][6] + sudk[5][7] + sudk[5][8];
        if(sum == 45)
        {
            return true;
        }
        return false;
    }
    else if(s == 6)
    {
        sum = sudk[6][0] + sudk[6][1] + sudk[6][2] 
              + sudk[7][0] + sudk[7][1] + sudk[7][2] 
              + sudk[8][0] + sudk[8][1] + sudk[8][2];
        if(sum == 45)
        {
            return true;
        }
        return false;
    }
    else if(s == 7)
    {
        sum = sudk[6][3] + sudk[6][4] + sudk[6][5] 
              + sudk[7][3] + sudk[7][4] + sudk[7][5] 
              + sudk[8][3] + sudk[8][4] + sudk[8][5];
        if(sum == 45)
        {
            return true;
        }
        return false;
    }
    else 
    {
        sum = sudk[6][6] + sudk[6][7] + sudk[6][8] 
              + sudk[7][6] + sudk[7][7] + sudk[7][8] 
              + sudk[8][6] + sudk[8][7] + sudk[8][8];
        if(sum == 45)
        {
            return true;
        }
        return false;
    }
}


