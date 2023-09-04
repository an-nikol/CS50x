#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    // make a do-while loop
    int start_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    // Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    // Calculate number of years until we reach threshold
    int counter = 0;

    while (start_size < end_size)
    {
        start_size += (start_size / 3) - (start_size / 4);
        counter++;
    }

    // Print number of years
    printf("Years: %i\n", counter);
}
