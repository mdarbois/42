
#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_coord
{
	int				x;
	int				y;
}				t_coord;

typedef struct s_game
{
	int				**map;
	int				height;
	int				width;
	t_coord			player;
	int				player_up;
	int				player_down;
	int				player_left;
	int				player_right;
	int				player_move;
	int				player_coll;
	t_coord			exit;
	t_coord			*coll;
	int				count_coll;
	int				count_exit;
	int				count_player;
}				t_game;

typedef struct s_board
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			*mlx_img;
	t_game			*game;
	t_img			*player;
	t_img			*exit;
	t_img			*coll;
	t_img			*wall;
	t_img			*floor;
}				t_board;

void			game_destroy(t_game *game);
void			die(char *errmsg, int errnum);
void			destroy(t_board *board, char *errmsg, int errnum);
void			map_height(t_board *board, char *file);
void			map_width(t_board *board, char *file);
void			map_isvalid(t_board *board, char *file);
int				key_press(int keycode, t_board *board);
int				key_release(int keycode, t_board *board);
int				destroy_hook(int keycode, t_board *board);
void			draw(t_board *board);
t_board			*board_init(char *filename);
void			map_parsing(t_board *board, char *file);
void			map_read(t_board *board, char *file);
void			map_init(t_board *board, char *filename);
void			game_init(t_board *board, char *filename);
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);
void			mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
unsigned int	mlx_get_pixel(t_img *img, int x, int y);
void			move_up(t_board *board, int x, int y);
void			move_down(t_board *board, int x, int y);
void			move_left(t_board *board, int x, int y);
void			move_right(t_board *board, int x, int y);
void			update(t_board *board);

#endif
