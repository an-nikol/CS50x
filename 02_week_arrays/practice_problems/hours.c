#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output); // prototype

int main(void)
{
    // prompting the user for the total number of weeks
    int weeks = get_int("Number of weeks taking CS50: ");
    // an array of the hours with size week

    // this array stores the hours spend for each of the weeks [1,2,6]
    int hours[weeks];

    // prompting the user for the hours of the particular week
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    // asking for total hours or average hours
    // if the user dont enter either T or A- the user is reprompted
    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');
    // here the calc_hours function is called
    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

float calc_hours(int hours[], int weeks, char output)
{
    // first -find the total hours saved in the array weeks into a new variable
    // looping through the array and adding all the items of the array into a variable
    int total_hours = 0;
    for (int current_week = 0; current_week < weeks; current_week++)
    {
        // every week add to the total hours
        total_hours += hours[current_week];
    }

    if (output == 'A')
    {
        // change either one of the values to a float, because an int divide it by an int it will always be an int
        return (total_hours / (float)weeks);
    }
    else
    {
        return total_hours;
    }

