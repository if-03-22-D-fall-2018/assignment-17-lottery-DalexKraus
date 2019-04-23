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

#define 	UUID_LEN       40
#define 	MAX_TIP_LEN    17
#define 	MAX_LINE_LEN   (UUID_LEN + 1 + MAX_TIP_LEN + 1)

bool contains(int number, int numbers[TIP_SIZE]);

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
    fseek(fd, MAX_LINE_LEN * tip_number, SEEK_SET);
    fseek(fd, UUID_LEN, SEEK_CUR);

    char tipString[MAX_TIP_LEN];
    fgets(tipString, MAX_TIP_LEN, fd);

    char *ptr;
    char delimiter[] = { separator };
    ptr = strtok(tipString, delimiter);

    int pos = 0;
    while(ptr != NULL) {
        if (!contains(atoi(ptr), tip))
            return false;

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

bool contains(int number, int numbers[TIP_SIZE])
{
    for (int i = 0; i < TIP_SIZE; i++)
    {
        if (numbers[i] == number)
            return true;
    }
    return false;
}
