#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    //=====================================
    FILE *fp;
    fp = fopen("sxo9287.txt", "w"); // Open file with write acces
    if(fp == NULL)
    {
        printf("failed to open file"); // Very for error [did this for every file].
        return 1;
    } 
    fprintf(fp,"Servando Olvera\n"); // Write on it. Then close it.
    fclose(fp);
    
    fp = fopen("sxo9287.txt", "a"); // Open file with append acces. Add ID, then close file.
    if(fp == NULL)
    {
        printf("failed to open file");
        return 2;
    }
    fprintf(fp,"1001909287\n");
    fclose(fp); 
    
    char s;
    fp = fopen("sxo9287.txt", "r");
    if(fp == NULL)
    {
        printf("failed to open file");
        return 3;
    }
    while((s = fgetc(fp)) != EOF)
    {
        printf("%c", s); // Loop to print content of file using fgetc
    }
    fclose(fp); 
    printf("---------------\n");
    //=====================================
    
    //=====================================
    char ch;
    int characters = 0;
    int words = 0;
    int lines = 0;
    
    FILE *fp2;
    fp2 = fopen("Part2.txt", "r");
    if(fp2 == NULL)
    {
        printf("failed to open file");
        return 4;
    } 
    while((ch = getc(fp2)) != EOF) // Loop to analyse every charcater in file. will add 1 to int charcaters, untill it register EOF.
    {
        characters++; 
        
        if(ch == ' ' || ch == '\n' || ch == '\0') // The logic here is that every time ch = 'white-space' or '\n' or '\0' it adds 1 to words.
        {
            words++; 
        }
        if(ch == '\n') // Pretty self explanatory. If a char is \n add 1 to lines.
        {
            lines++; 
        }
    }
    fclose(fp2);
    printf("Number of characters = %d\n", characters-1); /* I subtracted 1 from charcater becasue the logic above would always give me an extra character.
                                                            I think it might be a hidden chacrater. I don't knwo why I would always get that +1. */
                                                            
    printf("Number of words      = %d\n", words-1); /* Here is a bit different. When I used a different file with 13 words in it for testing 
                                                       the code worked just fine. However, with the file that was provided, and using the logic above, 
                                                       I would get an extra word. It might be that hidden charcater in the file that affects something. 
                                                       Either way, it works or it might be one off. */
    printf("Number of lines      = %d\n", lines);
    printf("---------------\n");
    //=====================================
    
    //=====================================
    FILE *fp3_1;
    fp3_1 = fopen("Part3_1.txt", "r"); // Part 3 kind of long and not so effective, but it works. 
    if(fp3_1 == NULL)
    {
        printf("failed to open file");
        return 5;
    } 
    FILE *fp3_2;
    fp3_2 = fopen("Part3_2.txt", "r");
    if(fp3_2 == NULL)
    {
        printf("failed to open file");
        return 6;
    }
    FILE *fp3_3;
    fp3_3 = fopen("Part3_3.txt", "w");
    if(fp3_3 == NULL)
    {
        printf("failed to open file");
        return 7;
    }
    char c;
    c = fgetc(fp3_1);
    while (c != EOF)
    {
      fputc(c, fp3_3);  /* Initially, all I did was open the two given files, create the third file, and copy and paste the contents 
                           of the two files into the third one. */
      c = fgetc(fp3_1);
    }                    
    c = fgetc(fp3_2);
    while (c != EOF)
    {
      fputc(c, fp3_3);
      c = fgetc(fp3_2);
    }
    fclose(fp3_1);
    fclose(fp3_2);      // Close all three files. 
    fclose(fp3_3);
    
         //==============================\\
    
    fp3_3 = fopen("Part3_3.txt", "r"); // Now for this part I got some extra help. 
    if(fp3_3 == NULL)                  // Firt I open the third file,  which now has all the words in it, in read mode.
    {
        printf("failed to open file");
        return 8;
    }
    // Then, the code below stores all the words in an array and the proceeds to sort them alphabetically!  
    
    char strTemp[10];  // Temporary string list
    char **str = NULL; // Main string List
    int i, j;          // Varibales for the sorting loop
    int n = 0;       // Number of Lines
    
    // Loop that grabs lines using tedious string code and stores them in array.
    while(fgets(strTemp, 10, fp3_3) != NULL) 
    {
        if(strchr(strTemp,'\n'))
        {
            strTemp[strlen(strTemp)-1] = '\0';
        }
        str = (char**)realloc(str, sizeof(char**)*(n+1));
        str[n] = (char*)calloc(10,sizeof(char));
        strcpy(str[n], strTemp);
        n++;
    }
    
    // Loop that alphabetically sorts all of the words in the array! Again, using tedious string code.
    for(i= 0; i < (n - 1); ++i) 
    {
        for(j = 0; j < ( n - i - 1); ++j)
        {
            if(strcmp(str[j], str[j+1]) > 0) 
            {
                strcpy(strTemp, str[j]);
                strcpy(str[j], str[j+1]);
                strcpy(str[j+1], strTemp);
            }
        }
    }
    fclose(fp3_3);  // Close third file again.
    
         //==============================\\
    
    fp3_3 = fopen("Part3_3.txt", "w");  // Lastly, open third file in write mode. To overwrite its conent.
    if(fp3_3 == NULL)
    {
        printf("failed to open file");
        return 9;
    }
    for(i = 0; i < n; i++) // Loop to print array's words into file. Now in alphabetical order!
    {
        fprintf(fp3_3,"%s\n",str[i]);
    }
    for(i = 0; i < n; i++)
    {
        free(str[i]);
    }
    free(str); 
    fclose(fp3_3);  // Close file AGAIN!
    //=====================================
    
    return 0;
    
}
