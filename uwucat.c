#include <stdio.h>
#include <stdlib.h>

#define ERROR_CODE 84

static void uwu_putchar(const char c)
{
    switch(c) {
        case 'r':
        case 'l':
            putchar('w');
            break;
        case 'R':
        case 'L':
            putchar('W');
            break;
        default:
            putchar(c);
    }
}

static void uwucat(const char *file)
{
    FILE *file_ptr = fopen(file, "r");
    if (file_ptr == NULL) {
        perror("Error opening the file");
        exit(ERROR_CODE);
    }

    char c;
    while ((c = fgetc(file_ptr)) != EOF) {
        uwu_putchar(c);
    }
    fclose(file_ptr);
}

static void getline_uwufy()
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i;

    while (1) {
        read = getline(&line, &len, stdin);

        if (read == -1)
            break;
        while (line[i] != '\0') {
            uwu_putchar(line[i]);
            i++;
        }
        i = 0;
    }
    free(line);
}

int main(int argc, char **argv)
{
    if (argc > 2)
        return ERROR_CODE;
    else if (argc == 1)
        getline_uwufy();
    else
        uwucat(argv[1]);
    return 0;
}
