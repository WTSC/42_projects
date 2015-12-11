#include "fillit.h"

void fillit_error(char *msg)
{
  ft_putstr_fd(msg, 2);
  exit(0);
}
