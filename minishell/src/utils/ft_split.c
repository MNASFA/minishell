/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:42:25 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/02/23 19:57:15 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

int is_special_char(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int word_len(char *str)
{
	int i;
	char quote;
	
	i = 0;
	if (str[i] == '\'' || str[i] == '\"')
	{
		quote = str[i++];
		while (str[i] && str[i] != quote)
			i++;
		if (str[i] == quote)
			i++;
	}
	else if (is_special_char(str[i]))
    {
		if ((str[i] == '<' || str[i] == '>') && str[i + 1] == str[i])
			return 2;
		return 1;
	}
	else
	{
		while (str[i] && !is_whitespace(str[i]) && !is_special_char(str[i]))
			i++;
	}
	return (i);
}

char **ft_split(char *input)
{
	char	**tokens;
	int		count;
	int		i;
	int		len;

	i = 0;
	count = 0;
	tokens = malloc(sizeof(char *) * 100);
	
	while (input[i])
	{
		while (is_whitespace(input[i]))
			i++;
		if (!input[i])
			break;
		len = word_len(&input[i]);
		if (len == 0)
			break;
		tokens[count] = malloc(len + 1);
		if (!tokens[count])
			return (NULL);
		
		ft_memcpy(tokens[count], &input[i], len);
		tokens[count][len] = '\0';
		count++;
		i += len;
	}
	tokens[count] = NULL;
	return (tokens);
}
