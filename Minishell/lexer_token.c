/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:36:26 by mdarbois          #+#    #+#             */
/*   Updated: 2023/06/15 17:36:28 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token *lexer_token(char *input, t_data *data)
{
    t_token *token;
    int i;
    i = 0;

       while(input && input[i])
       {
        if (line[i] == '<' && line[i++] != '<')
            token->e_token = 1;
        else if (line[i] == '>' && line[i++] != '<>')
            token->e_token = 2;
        else if (line[i] == '<' && line[i++] == '<')
            token->e_token = 6;
        else if (line[i] == '>' && line[i++] == '>')
            token->e_token = 5;
        else if (is_space(input[i]))
            token->e_token = 7;
        else if (line[i] == '|')
            token->e_token = 4;
        else if (line[i] == '$')
        else if(line[i] == '\'')
            token->e_token = 8;
        else if(line[i] == '\"')
            token->e_token = 9;  
        
       }
}