#include "putlog.h"
#include <unistd.h>
#include <fcntl.h>

void putlog(unsigned int lv, char *str)
{
  int		fd;
  char		**levels;

  fd = open(DEBUG_LOGFILE, O_WRONLY, O_CREAT, O_APPEND);
  if (fd != -1)
    {
      if (lv == DEBUG_LVL0)
	write(fd, "*INFO* ", 7);
      else if (lv == DEBUG_LVL1)
	write(fd, "*WARNING* ", 10);
      else if (lv == DEBUG_LVL2)
	write(fd, "*ERROR* ", 8);
      else
	write(fd, "*OTHER* ", 8);
      write(fd, str, ft_strlen(str));
      write(fd, "\n", 1);
      close(fd);
    }
  if (lv >= DEBUG_LEVEL)
    write(2, str, ft_strlen(str));
}
