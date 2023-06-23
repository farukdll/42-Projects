#include "minishell.h"

void	dup_files(int *fd)
{
	if (dup2(fd[1], 1) == -1)
		perror("Error on pipe dup2");
	if (close(fd[1]) == -1)
		perror("Error on closing file");
	if (close(fd[0]) == -1)
		perror("Error on closing file");
}

void	dup_infile(int fd_in)
{
	if (dup2(g_data.infiles[fd_in], 0) == -1)
		perror("Error on dup2");
	if (close(g_data.infiles[fd_in]))
		perror("Error on closing infile");
}

void	dup_outfile(int fd_out)
{
	if (dup2(g_data.outfiles[fd_out], 1) == -1)
		perror("Error on dup2");
	if (close(g_data.outfiles[fd_out]) == -1)
		perror("Error on closing file");
}

void	main_process(int *fd)
{
	if (dup2(fd[0], 0) == -1)
		perror("Error on dup2");
	if (close(fd[0]) == -1)
		perror("Error on closing file");
	if (close(fd[1]) == -1)
		perror("Error on closing file");
}
