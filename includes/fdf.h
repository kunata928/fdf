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
# define BUFF 10000

typedef struct	s_o
{
	int x;
	int y;
	int z;
	int color;
}				t_o;

typedef struct	s_lst
{
	int		z;
	t_list	*next;
}				t_lst;

typedef struct	s_val
{
	int n;
	int nums;
}				t_val;

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


void		print_line_br(void *mlx, void *window, t_o xy0, t_o xy1);
int			fdf_read_file(char *txt, t_o ***fdf);

# endif
