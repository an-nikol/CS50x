#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// create prototype 
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // prompt user for input
    string text = get_string("Text: ");

    // create call functions
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // initialise L and S and convert them to floats because there is an error with int
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;
    // formula for grades
    // include math.h and round the result
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // print output
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    // create a letter counter that is euqal to zero to remove bug with return
    int counter = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // add to the counter only if the letter is lower or uppercase
        if (islower(text[i]) || isupper(text[i]))
        {
            counter++;
        }
    }
    return counter;
}
// create a function that counts word
int count_words(string text)
{
    // loop through the words in a sentence
    // create a counter that start with an one to exclude the final space
    int words = 1;
    for (int j = 0; j < strlen(text); j++)
    {
        // use the ASCII value of a space
        if (text[j] == 32)
        {
            words++;
        }
    }
    return words;
}
int count_sentences(string text)
{
    int sentences = 0;
    for (int k = 0; k < strlen(text); k++)
    {
        // use ASCII value for ., ? and !
        if (text[k] == 46 || text[k] == 63 || text[k] == 33)
        {
            sentences++;
        }
    }
    return sentences;
}
