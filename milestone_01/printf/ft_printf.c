/* int ft_printf(const char *, ...)
{
    
    return (0);
} */

#include <stdio.h>

int main()
{
    int age;

    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Your age is: %d\n", age);
    return 0;
}