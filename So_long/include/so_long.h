#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
#include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
#include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_player
{
	int				player_up;
	int				player_down;
	int				player_left;
	int				player_right;
}	t_player;

typedef struct s_game
{
	int		height_map;
	int		width_map;
	int		playercount;
	int		collcount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;

	char	**map;

	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlx_ptr;
	void	*win_ptr;

	void	*xpm_ptr;
	int		x;
	int		y;
	t_player	*moves;

}	t_game;

void	character_valid(t_game *game);
void	check_errors(t_game *game);

int	key_press(int keycode, t_game *game);
int	key_release(int keycode, t_game *game);

void	place_player(t_game *game, int height, int width);
void	place_collectable(t_game *game, int height, int width);
void	place_images_in_game(t_game *game);
void	adding_in_graphics(t_game *game);

void	ft_destroy_images(t_game *game);
void	ft_free_all_allocated_memory(t_game *game);
int	exit_point(t_game *game);
int	map_reading(t_game *game, char **argv);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif