#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt for user-input
    // make a do-while loop to check the int to be between 1 and 8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // make a for-loop for the height
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < height - i - 1; k++)
        {
            printf(" ");
        }
        // make a for-loop for the cols
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
