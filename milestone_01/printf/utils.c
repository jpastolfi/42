#include <unistd.h>

void write_char(int c)
{
    write(1, &c, 1);
}

void write_string(char *string)
{
    int index;

    index = 0;
    while (string[index])
    {
        write_char(string[index]);
        index++;
    }
}

/* int main(void)
{
    write_char('c');
    write_string("Batata");
} */