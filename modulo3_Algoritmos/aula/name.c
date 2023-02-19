#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string names[] = {
        "Bill",
        "Charlie",
        "Fred",
        "Jorge",
        "Ginny",
        "Percy",
        "Ron"};

    for (int i = 0; i < 7; i++)
    {
        if (strcmp(names[i], "Ron") == 0)
        {
            printf("Found");
            return 0;
        }
    }
    printf("Not Found");
    return 1;
}