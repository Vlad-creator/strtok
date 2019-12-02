#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strtok_my(char** text);

void skip_tabulations(char*** s);
void skip_letters(char*** s);

int main()
{
    char text[] = "surg     eouryg eurgfy sekufgy ";
    char* a = calloc(100 , sizeof(char));
    strcpy(a , text);
    char* f = 0;
    for( ; ; )
    {
    f = strtok_my(&a);
    if (f == NULL)
        break;
    printf("%s\n" , f);
    }
    return 0;

}


char* strtok_my(char** text)
{
    if ((**text) == '\0')
        return NULL;
    skip_tabulations(&text);
    char* wordstart = *text;
    skip_letters(&text);
    if ((**text) == '\0')
        return wordstart;
    (**text) = '\0';
    (*text)++;
    return wordstart;
}

void skip_tabulations(char*** s)
{
    while (((***s) == ' ') /*&& ((***s) == '\n')*/)
        (**s)++;
}

void skip_letters(char*** s)
{
    while (((***s) != '\n') && ((***s) != ' '))
    {
        if ((***s) == '\0')
            break;
        else
            (**s)++;
    }
}
