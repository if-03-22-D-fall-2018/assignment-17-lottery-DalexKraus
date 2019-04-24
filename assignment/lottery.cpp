/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: 17
 * File:			lottery.c
 * Author(s):		David Kraus
 * Due Date:		idk lol
 *-----------------------------------------------------------------------------
 * Description:
 * Implementation of a library for analyzing lottery tips.
 *-----------------------------------------------------------------------------
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lottery.h"

#define 	UUID_LEN       36
#define 	MAX_TIP_LEN    17

//Unused?
#define 	MAX_LINE_LEN   (UUID_LEN + 1 + MAX_TIP_LEN)

FILE* fd;
char separator;

bool init_lottery(const char *csv_file, char csv_separator)
{
    fd = fopen(csv_file, "r");
    separator = csv_separator;
    return fd != 0;
}

bool get_tip(int tip_number, int tip[TIP_SIZE])
{
    //Validate tip number
    if (tip_number < 0 || tip_number >= 1000000)
        return false;

    //Jump to start of the file
    fseek(fd, 0, SEEK_SET);
    //Iterate to target line start (can't use fseek() because each line is differently long)
    int currentLine = 0; //Representing the current line in file
    while (currentLine < tip_number)
        while (!feof(fd) && fgetc(fd) == '\n') {
            currentLine++;
            break;
        }

    //Skip UUID (+first separator)
    fseek(fd, (UUID_LEN + 1) * sizeof(char), SEEK_CUR);
    printf("\npos in file: %d\n", ftell(fd));

    //Read tip string
    char tipString[MAX_TIP_LEN];
    fgets(tipString, MAX_TIP_LEN, fd);
    printf("TipString: %s\n", tipString);

    //Split tip string
    char delimiter[2] = { separator, '\0' };
    char *ptr = strtok(tipString, delimiter);

    //Parse tip
    int pos = 0;
    while(ptr != NULL) {
        int tipNumber = atoi(ptr);
        tip[pos] = tipNumber;
        ptr = strtok(NULL, delimiter);
        pos++;
    }
    return true;
}

bool set_drawing(int drawing_numbers[TIP_SIZE])
{
  return 0;
}

int get_tip_result(int tip_number)
{
    return 0;
}

int get_right_tips_count(int right_digits_count)
{
    return 0;
}
