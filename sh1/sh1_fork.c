#include <unistd.h>
#include <sys/types.h>

pid_t	sh_fork(void)
{
	pid_t	father;
	father = fork();
	return (father);
}

