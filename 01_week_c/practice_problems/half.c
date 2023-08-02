// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip); // prototype

int main(void)
{
    // main functions
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// return function
float half(float bill, float tax, int tip)
{
    // tax_percent to decimal
    float tax_money = bill * (tax / 100);

    // bill before tip
    float bill_before_tip = bill + tax_money;

    // tip_percent to decimal
    // convert the tip from an int to a float, because we divide it by a 100
    float tip_money = bill_before_tip * ((float) tip / 100);

    // total amount
    float total_amount = bill_before_tip + tip_money;

    return total_amount / 2;
}
