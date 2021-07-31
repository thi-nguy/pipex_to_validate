#include "pipex.h"

void	ft_count_words_with_quotes(char *s, int *words)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'')
        {
            i++;
            while (s[i] != '\'')
                i++;
            (*words)++;
            i++;
        }
        if (s[i] != ' ' && s[i] != '\'' && s[i] != '\0')
        {
			(*words)++;
            while (s[i] != ' ' && s[i] != '\'')
                i++;
        }
		if (s[i] == ' ')
		{
            while (s[i] == ' ')
                i++;
		}
	}
}


void	alloc_word(char ***tab, char *s)
{
	int	i;
    int count;
    int len_word;

	i = 0;
    count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'' && s[i] != '\0')
        {
            (*tab)[count] = get_one_word(s, i, '\'');
            free_memory_and_update_count(tab, &count, &i, 39);
        }
        else if (s[i] != ' ' && s[i] != '\'' && s[i] != '\0')
        {
            (*tab)[count] = get_one_word(s, i, ' ');
            free_memory_and_update_count(tab, &count, &i, 0);
        }
		else if (s[i] == ' ')
		{
            while (s[i] == ' ')
                i++;
		}
	}
    (*tab)[count] = 0;
}

char    *get_one_word(char *s, int index, char c)
{
    int start_word;
    int len_word;
    char *word;
    int k;
    int j;

    if (c == '\'' && s[index + 1] != c)
        index++;
    start_word = index;
    len_word = 0;
    while (s[index] != c && s[index] != '\'' && s[index] != '\0')
    {
        len_word++;
        index++;
    }
    word = (char *)malloc(sizeof(char) + (len_word + 1));
    if (!word)
        return (NULL);
    k = 0;
    j = start_word;
    while (k < len_word)
    {
        word[k] = s[j];
        k++;
        j++;
    }
    word[len_word] = '\0';
    return (word);
}

void    free_memory_and_update_count(char ***tab, int *count, int *i, int sign) //jthem dieu kien char vao la ok)
{

    if ((*tab)[*count][0] != '\0')
    {
        if (sign == 0)
            *i += ft_strlen((*tab)[*count]);
        else if (sign == 39)
            *i += ft_strlen((*tab)[*count]) + 2;
        (*count)++;
    }
    else
    {
        free((*tab)[*count]);
        (*tab)[*count] = NULL;
        (*i) += 2;
    }
}

static int re_count_word(char **tab)
{
    int i;

    i = 0;
    while (tab[i] != NULL)
        i++;
    return (i);
}

char    **handle_quotes(char *str)
{
    int word_count;
    int num;
    char **result;

   word_count = 0;
   ft_count_words_with_quotes(str, &word_count);
   result = (char **)malloc(sizeof(char *) * (word_count + 1));
   if (!result)
        return (NULL);
    alloc_word(&result, str);
    return (result);
}


char **parse_command(char *str)
{
    char **result;
    int quotes;

    quotes = check_if_quotes_exist(str);

    if (quotes == 0)
    {
        result = ft_split(str, ' ');
        return (result);
    }
    else if (quotes % 2 == 1)
        return (NULL);
    else if (quotes % 2 == 0)
    {
        result = handle_quotes(str);
        return (result);
    }
    return (NULL);
}

int     check_if_quotes_exist(char *str)
{
    int i;
    int count;
    int len;

    i = 1;
    if (str[0] == '\'')
        count = 1;
    else
        count = 0;
    len = ft_strlen(str);
    while (i < len)
    {
        if (str[i] == '\'' && str[i - 1] != '\\')
            count++;
        i++;
    }
    return (count);
}


