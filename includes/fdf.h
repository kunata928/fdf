#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../includes/mlx.h"
# include "../libft/includes/libft.h"

# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define WINE 0xAB271D
# define WINSIZE 1000

typedef struct	s_xy
{
	int x;
	int y;
	int color;
}				t_xy;

typedef struct	s_br
{
	int x;
	int y;
	int dx;
	int dy;
	int error;
	int dif;
	int ystep;
}				t_br;

void	print_line_br(void *mlx, void *window, t_xy xy0, t_xy xy1);

# endif
