#include "libft.h"
char **ft_split(const char *s, char c)
{
    char **result;
    int i, j, k, count;

    count = 0;
    i = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i] != '\0')
        {
            count++;
            while (s[i] && s[i] != c)
                i++;
        }
    }

    result = malloc((count + 1) * sizeof(char *));
    if (!result)
        return (NULL);

    i = 0;
    j = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i] != '\0')
        {
            k = 0;
            while (s[i + k] && s[i + k] != c)
                k++;
            
            result[j] = malloc(k + 1);
            if (!result[j])
                return (NULL);
            
            k = 0;
            while (s[i] && s[i] != c)
                result[j][k++] = s[i++];
            result[j][k] = '\0';
            j++;
        }
    }
    result[j] = NULL;
    return (result);
}

int main(int ac, char **av)
{
    char **split;
    int i;

    if (ac > 1)
    {
        split = ft_split(av[1], av[2][0]);
        if (split)
        {
            for (i = 0; split[i]; i++)
            {
                printf("%s\n", split[i]);
                free(split[i]);
            }
            free(split);
        }
    }
    return (0);
}
