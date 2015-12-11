#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# define PCSIZE 4
# define MAXPCS 26

typedef struct	s_cur
{
  int	i;
  int	h;
  int	w;
  int	nb;
  int	nl;
}		t_cur;

typedef struct	s_board
{
  int	h;
  int	w;
  int	nb;
  char	**pcs;
}		t_board;

void fillit_error(char *msg);

#endif
