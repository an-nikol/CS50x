#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// Complete the Boolean function below
bool valid(string password)
{
    // create a bool for each prerequisite
    bool is_lower = false;
    bool is_upper = false;
    bool is_number = false;
    bool is_symbol = false;

    // iterate through the password
    for (int i = 0; i < strlen(password); i++)
    {
        if (islower(password[i]))
        {
            is_lower = true;
        }
        else if (isupper(password[i]))
        {
            is_upper = true;
        }
        else if (isdigit(password[i]))
        {
            is_number = true;
        }
        else if (ispunct(password[i]))
        {
            is_symbol = true;
        }
    }
    // check if all of the conditions are true and then return true or false
    if (is_lower == is_upper == is_number == is_symbol == true)
    {
        return true;
    }
    return false;
}
