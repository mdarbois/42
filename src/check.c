/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:09:29 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/02 12:09:30 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int check_identifier_factor(char *string)
{
    int i;
    int fd;
    char *str;
    char *sub;

    fd = 0;    
    i = 2;
    while (string[i] != '\0' && string[i] == ' ')
        i++;
    sub = ft_substr(string, ft_strlen(string) - 4, 5);
    if (ft_strncmp(sub, ".xpm", 5) != 0)
	{	
		free(sub);
		printf("Invalid file type, use .xpm!");
        return (1);
	}
    str = ft_substr(string, i, ft_strlen(string));
    fd = open(str, O_RDONLY);
    if (fd < 0)
        return (1);
    return (0);
}

static bool check_range(char *number)
{
    if (ft_atoi(number) <= 0 || ft_atoi(number) >= 255)
        return false;
    return true;
}

void check_identifier_c_f (char *string)
{
    int i;
    char *str;
    char **split;

    i = 1;
    while (string[i] != '\0' && string[i] == ' ')
        i++;
    str = ft_substr(string, i, ft_strlen(string));
    split = ft_split(str, ',');
    if (split[3] || check_range(split[0]) || check_range(split[1]) || check_range(split[2]))
        printf("Error, 3 digits expected between 0 and 255");
}

void check_identifier(t_board *board)
{
    int i;
    char *str;
    char **split_f;
    char **split_c;
   
    i = 1;
    while (board->f[i] != '\0' && board->f[i] == ' ')
        i++;
    str = ft_substr(board->f, i, ft_strlen(board->f));
    split_f = ft_split(str, ',');
    if (split_f[3] || check_range(split_f[0])|| check_range(split_f[1]) || check_range(split_f[2]))
        printf("Error floor, 3 digits expected between 0 and 255");
    i = 1;
    while (board->c[i] != '\0' && board->c[i] == ' ')
        i++;
    split_c = ft_split(board->c, ',');
    if (split_c[3] || check_range(split_c[0])|| check_range(split_c[1]) || check_range(split_c[2]))
        printf("Error ceiling, 3 digits expected between 0 and 255");
}

void check_map_walls(t_board *board)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (board->map[0][i] && board->map[0][i] == ' ')
        i++;
    while (board->map[0][i] && board->map[0][i] != '\n' && board->map[0][i] == '1')
         i++;
    if(board->map[0][i] != '\n')
        printf("Error, your map must be surrounded by walls\n");
    i = 0;
    while (board->map[i][0] && board->map[i][0] == ' ')
        i++;
    while (board->map[i][0] && board->map[i][0] != '\n' && board->map[i][0] == '1')
        i++;
    if(board->map[i][0] != '\n')
        printf("Error, your map must be surrounded by walls\n");
    i = 0;
    while (board->map[j][i] && board->map[j + 1][i])
        j++;
    
    while (board->map[j][i] && board->map[j][i] == ' ')
        i++;
    while (board->map[j][i] && board->map[j][i] != '\n' && board->map[j][i] == '1')
        i++;
    if(board->map[j][i] != '\n')
        printf("Error, your map must be surrounded by walls\n");
    j = 0;
    i = 0;
    while (board->map[j][i] && board->map[j][i + 1])
        i++;
    while (board->map[j][i] && board->map[j][i] == ' ')
        j++;
    while (board->map[j][i] && board->map[j][i] != '\n' && board->map[j][i] == '1')
        j++;
    if(board->map[j][i] != '\n')
        printf("Error, your map must be surrounded by walls\n");
}
/* # chekc not the first or last column but first and last character of each fukcing row must be a 1
 */
void check_map_characters(t_board *board)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (board->map[i][j] < board->height)
    {    
        i = 0;
        while (board->map[i][j] < board->width)
        {
            if (board->map[i][j] != '0' || board->map[i][j] != '1' || board->map[i][j] != 'N' || board->map[i][j] != 'S' || board->map[i][j] != 'E' || board->map[i][j] != 'W')
            {
                if (board->map[i][j] == ' ')
                    board->map[i][j] = '0';
                else if (board->map[i][j] == '\0')
                    board->map[i][j] = '1';
                else
                    printf("Error wrong character in the map\n");
            }
            i++;
        }
        j++;
    }
}

