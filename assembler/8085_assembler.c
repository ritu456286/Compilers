#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    char *code[9][4] = {
        {"PRG1", "START", "", ""},           // Program Start
        {"", "MVI", "A", "05"},              // MVI A, 05
        {"", "MOV", "B", "A"},               // MOV B, A
        {"", "LDA", "", "2000"},             // LDA 2000
        {"", "STA", "", "3000"},             // STA 3000
        {"FOUR", "DC", "F", ""},             // FOUR DC F (Define Constant)
        {"FIVE", "DC", "F", ""},             // FIVE DC F
        {"TEMP", "DS", "1F", ""},            // TEMP DS 1F (Define Storage)
        {"", "HLT", "", ""}                  // HLT (Halt)
    };

    // 8085 Opcode Table: Instruction and corresponding object code
    struct opTable {
        char code[10];
        char objCode[10];
    };

    struct opTable myOpT[5] = {
        {"MVI", "3E"}, // MVI A, data (2 bytes)
        {"MOV", "78"}, // MOV B, A (1 byte)
        {"LDA", "3A"}, // LDA address (3 bytes)
        {"STA", "32"}, // STA address (3 bytes)
        {"HLT", "76"}  // HLT (1 byte)
    };

    char avail[16] = "NNNNNNNNNNNNNNNN"; // 16 slots for base availability, initialized to 'N'
    int lc[9] = {0};                     // Location counters for each instruction
    int loc = 0;                         // Current location
    int i, j, k;
    
    printf("----------------------------------------------------\n");
    printf("LABEL\t\tOPCODE\n");
    printf("----------------------------------------------------\n\n");

    // Printing the opcode table
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) {
            printf("%s\t\t", code[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------------------------------\n");

    printf("\nVALUES FOR LC : \n\n");
    // Generating Location Counters (LC) based on the type of instructions
    for (j = 0; j < 9; j++) {
        if (strcmp(code[j][1], "START") != 0 && strcmp(code[j][1], "USING") != 0 &&
            strcmp(code[j][1], "L") != 0) {
            lc[j] = lc[j - 1] + 4; // Increment location by 4 for each instruction
        }
        printf("%d\t", lc[j]);
    }
    printf("\n\nSYMBOL TABLE:\n----------------------------------------------------\n");
    printf("SYMBOL\t\tVALUE\t\tLENGTH\t\tR/A\n");
    printf("----------------------------------------------------\n");

    // Constructing the symbol table
    loc = 0;
    for (i = 0; i < 9; i++) {
        if (strcmp(code[i][1], "START") == 0) {
            printf("%s\t\t%d\t\t%d\t\t%c\n", code[i][0], loc, 4, 'R');
        } else if (strcmp(code[i][0], "") != 0) {
            printf("%s\t\t%d\t\t%d\t\t%c\n", code[i][0], loc, 4, 'R');
            loc += 4;
        } else {
            loc += 4;
        }
    }
    printf("----------------------------------------------------\n");

    printf("\n\nBASE TABLE:\n-------------------------------------------------------\n");
    printf("REG NO\t\tAVAILABILITY\tCONTENTS OF BASE TABLE\n");
    printf("-------------------------------------------------------\n");

    // Printing the Base Table for base register availability
    for (k = 0; k < 16; k++) {
        printf(" %d\t\t %c\n", k + 1, avail[k]); // Print base table correctly
    }
    printf("-------------------------------------------------------\n");

    printf("Continue..??");
    getchar();

    // Pass 2 Table: Generate the object code for the 8085 instructions
    printf("PASS2 TABLE:\n\n");
    printf("LABEL\t\tOP1\t\tLC\n");
    printf("----------------------------------------------------\n");

    loc = 0;
    for (i = 0; i < 9; i++) {
        printf("%s\t\t", code[i][0]);
        printf("%s\t\t", code[i][1]);
        printf("%s\t\t", code[i][3]);
        printf("\n");
    }
    printf("-----------------------------------------------------\n");

    // Printing Object Code for each instruction
    printf("\nObject Code for Instructions:\n");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 5; j++) {
            if (strcmp(code[i][1], myOpT[j].code) == 0) {
                if (strcmp(myOpT[j].code, "MVI") == 0) {
                    printf("%s %s %s\n", myOpT[j].objCode, code[i][2], code[i][3]);
                } else if (strcmp(myOpT[j].code, "MOV") == 0) {
                    printf("%s %s\n", myOpT[j].objCode, code[i][2]);
                } else if (strcmp(myOpT[j].code, "LDA") == 0 || strcmp(myOpT[j].code, "STA") == 0) {
                    printf("%s %s\n", myOpT[j].objCode, code[i][3]);
                } else if (strcmp(myOpT[j].code, "HLT") == 0) {
                    printf("%s\n", myOpT[j].objCode);
                }
            }
        }
    }

    printf("----------------------------------------------------\n");
}
