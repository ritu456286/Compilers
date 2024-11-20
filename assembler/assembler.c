#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
    char *code[9][4] = {
        {"PRG1", "START", "", ""},
        {"", "USING", "*", "15"},
        {"", "L", "", ""},
        {"", "A", "", ""},
        {"", "ST", "", ""},
        {"FOUR", "DC", "F", ""},
        {"FIVE", "DC", "F", ""},
        {"TEMP", "DS", "1F", ""},
        {"", "END", "", ""}};
    char avail[16] = "NNNNNNNNNNNNNNNN"; // 16 slots for base availability, initialized to 'N'
    int lc[9] = {0};                     // Location counters for each instruction
    int loc = 0;                         // Current location
    int i, j, k;
    printf("----------------------------------------------------\n");
    printf("LABEL\t\tOPCODE\n");
    printf("----------------------------------------------------\n\n");
    // Printing the opcode table
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%s\t\t", code[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------------------------------\n");
    printf("\nVALUES FOR LC : \n\n");
    // Generating Location Counters (LC) based on the type of instructions
    for (j = 0; j < 9; j++)
    {
        if (strcmp(code[j][1], "START") != 0 && strcmp(code[j][1], "USING") != 0 &&
            strcmp(code[j][1], "L") != 0)
        {
            lc[j] = lc[j - 1] + 4;
        }
        printf("%d\t", lc[j]);
    }
    printf("\n\nSYMBOL TABLE:\n----------------------------------------------------\n");
    printf("SYMBOL\t\tVALUE\t\tLENGTH\t\tR/A\n");
    printf("----------------------------------------------------\n");
    // Constructing the symbol table
    loc = 0;
    for (i = 0; i < 9; i++)
    {
        if (strcmp(code[i][1], "START") == 0)
        {
            printf("%s\t\t%d\t\t%d\t\t%c\n", code[i][0], loc, 4, 'R');
        }
        else if (strcmp(code[i][0], "") != 0)
        {
            printf("%s\t\t%d\t\t%d\t\t%c\n", code[i][0], loc, 4, 'R');
            loc += 4;
        }
        else if (strcmp(code[i][1], "USING") == 0)
        {
            // No symbol generation for 'USING'
        }
        else
        {
            loc += 4;
        }
    }
    printf("----------------------------------------------------\n");
    printf("\n\nBASE TABLE:\n-------------------------------------------------------\n");
    printf("REG NO\t\tAVAILABILITY\tCONTENTS OF BASE TABLE\n");
    printf("-------------------------------------------------------\n");
    // Filling the Base Table for base register availability
    for (j = 0; j < 9; j++)
    {
        if (strcmp(code[j][1], "USING") == 0)
        {
            if (strlen(code[j][3]) > 0)
            { // Check if the base register is specified
                int baseReg = atoi(code[j][3]);
                avail[baseReg - 1] = 'Y'; // Mark base register as available
            }
        }
    }
    // Printing the Base Table
    for (k = 0; k < 16; k++)
    {
        printf(" %d\t\t %c\n", k + 1, avail[k]); // Print base table correctly
    }
    printf("-------------------------------------------------------\n");
    printf("Continue..??");
    getchar();
    // Pass 2 Table
    printf("PASS2 TABLE:\n\n");
    printf("LABEL\t\tOP1\t\tLC\n");
    printf("----------------------------------------------------\n");
    loc = 0;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%s\t\t", code[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------------------------------\n");
}