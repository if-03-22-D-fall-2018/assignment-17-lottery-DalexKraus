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
#define 	MAX_TIP_LEN    19
#define 	MAX_LINE_LEN   (UUID_LEN + 1 + MAX_TIP_LEN)

int get_file_length(FILE* fd);
int get_line_length(FILE* fd, int line_index);

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
    if (tip_number < 0 || get_file_length(fd) < (tip_number * MAX_LINE_LEN))
        return false;

    printf("Tip no. %d, pos: %d\n", tip_number, get_line_length(fd, tip_number));

    fseek(fd, MAX_LINE_LEN * tip_number, SEEK_SET);
    fseek(fd, UUID_LEN + 1, SEEK_CUR);

    char tipString[MAX_TIP_LEN];
    fgets(tipString, MAX_TIP_LEN, fd);

    char *ptr;
    char delimiter[] = { separator };
    ptr = strtok(tipString, delimiter);

    int pos = 0;
    while (ptr != NULL)
    {
        tip[pos] = atoi(ptr);
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

int get_file_length(FILE* fd)
{
    int previousPos = ftell(fd);
    fseek(fd, 0, SEEK_END);
    int end = ftell(fd);
    fseek(fd, previousPos, SEEK_SET);
    return end;
}

int get_line_length(FILE* fd, int line_index)
{
    int previousPos = ftell(fd);

    //Jump to target line start
    int pos = 1;
    fseek(fd, 0, SEEK_SET);
    while ((pos - 1) < line_index)
    {
        while (fgetc(fd) != '\n')
        {
            fseek(fd, 1, SEEK_CUR);
        }
        printf("Char: %c", (char) fgetc(fd));

        pos++;
    }
    printf("Line Pos: %d\n", pos);

    //Run through line until \n
    int length = 0;
    while (fgetc(fd) != '\n')
    {
        fseek(fd, 1, SEEK_CUR);
        length++;
    }

    //Jump to previous pos
    fseek(fd, previousPos, SEEK_SET);
    return length;
}
