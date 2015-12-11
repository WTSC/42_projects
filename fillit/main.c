#include "fillit.h"

void fillit_init(t_board *board, t_cur *c)
{
  int i;

  i = 0;
  c->w = 0;
  c->h = 0;
  c->nb = 0;
  board->nb = 0;
  board->h = 0;
  board->w = 0;
  board->pcs = (char **)malloc(sizeof(char *) * (MAXPCS + 1));
  while (i < MAXPCS)
    board->pcs[i] = ft_strnew((PCSIZE * PCSIZE) + 1);
  board->pcs[i] = NULL;
}

int main(int ac, char **argv)
{
  t_board	board;
  t_cur		c;

  if (ac != 2)
    return (0);
  fillit_init(&board, &c);
  fillit_parse(&board, &c, argv);
  return (0);
}
