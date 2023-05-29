#include <stdio.h>
#include <stdlib.h>

int match(const char *text, const char *pattern)
{
    int i = 0;
    int j = 0;
    int text_len = 0;
    int pattern_len = 0;

    while (text[text_len] != '\0')
    {
        text_len++;
    }

    while (pattern[pattern_len] != '\0')
    {
        pattern_len++;
    }

    int *failure = (int *)malloc(sizeof(int) * pattern_len);
    failure[0] = 0;

    for (i = 1; i < pattern_len; i++)
    {
        j = failure[i - 1];
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = failure[j - 1];
        }
        if (pattern[i] == pattern[j])
        {
            failure[i] = j + 1;
        }
        else
        {
            failure[i] = 0;
        }
    }

    i = 0;
    j = 0;
    while (i < text_len)
    {
        if (pattern[j] == text[i] || pattern[j] == text[i] + 32 || pattern[j] == text[i] - 32)
        {
            i++;
            j++;
            if (j == pattern_len)
            {
                free(failure);
                return 1;
            }
        }
        else if (j > 0)
        {
            j = failure[j - 1];
        }
        else
        {
            i++;
        }
    }

    free(failure);
    return 0;
}

int main()
{
    char nome[100001];
    scanf("%s", nome);

    if (match(nome, "zelda") || match(nome, "Zelda"))
    {
        printf("Link Bolado\n");
    }
    else
    {
        printf("Link Tranquilo\n");
    }

    return 0;
}