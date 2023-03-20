/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:28:08 by mdarbois          #+#    #+#             */
/*   Updated: 2023/03/16 13:28:10 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

static int	keyboard_w(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 119)
	{
		j--;
		if (game->map[j][i] == '1')
			return (0);
		k = move(game, i, j);
		if (!k)
			return (0);
		game->map[j + 1][i] = '0';
	}
	return (1);
}

static int	keyboard_s(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 115)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		k = move(game, i, j);
		if (!k)
			return (0);
		game->map[j - 1][i] = '0';
	}
	return (1);
}

static int	keyboard_a(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 97)
	{
		i--;
		if (game->map[j][i] == '1')
			return (0);
		k = move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i + 1] = '0';
	}
	return (1);
}

static int	keyboard_d(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 100)
	{
		i++;
		if (game->map[j][i] == '1')
			return (0);
		k = move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i - 1] = '0';
	}
	return (1);
}

int	key_press(int command, t_game *game)
{
	int	works;

	if (command == 65307)
		destroy(game, "You quit\n", 0);
	if (command == 115)
		works = keyboard_s(game, command);
	if (command == 119)
		works = keyboard_w(game, command);
	if (command == 97)
		works = keyboard_a(game, command);
	if (command == 100)
		works = keyboard_d(game, command);
	if (works)
		graphics(game);
	print(game);
	return (1);
}
