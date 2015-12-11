#include "fillit.h"

void fillit_parse(t_board *board, char **av)
{
  int	fd;
  char	*line;
  int	i;
  t_cur c;

  line = NULL;
  fd = open(av[1], O_RDONLY);
  while (get_next_line(fd, &line) > 0)
  {
    printf("line get is %s\n", line);
    i = 0;
    c.i = 0;
    while (line[i] != '\n' && line[i] != '\0')
    {
      if (line[i] == '.' || line[i] == '#')
      {
	c.w++;
	if (c.w > PCSIZE)
	  fillit_error("Invalid map");
	board->pcs[board->nb][c.i] = line[i];
	c.i++;
      }
      else if (line[i] == ' ')
      {
	if (c.w < PCSIZE && c.w > 0)
	  fillit_error("Invalid map");
	c.i -= (c.w == 0) ? 0 : PCSIZE; 
	c.w = 0;
	board->nb += (line[i+1] == '.' || line[i + 1] == '#') ? 1 : 0;
	c.nb += (line[i+1] == '.' || line[i + 1] == '#') ? 1 : 0;
      }
      else
	fillit_error("Invalid map");
      i++;
    }
	if (line[i] == '\n')
	{
		if (c.nl && c.h < PCSIZE)
			fillit_error("Invalid map");
		board->nb -= (c.h == PCSIZE) ? -1 : c.nb;
		c.h = (c.nl) ? 0 : c.h + 1;
		if (c.h > PCSIZE)
	  		fillit_error("Invalid map");
		c.i = (c.nl) ? 0 : c.i + 1;
		c.nl = 1;
      }
  }
}
