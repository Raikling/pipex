#include "pipex.h"

void ft_init_pipex(t_pipex *pipex)
{
    pipex->fd_in = -1;
    pipex->fd_out = -1;
    pipex->pipefds[0] = -1;
    pipex->pipefds[1] = -1;
    pipex->pid1 = -1;
    pipex->pid2 = -1;
    pipex->cmd_paths = NULL;
    pipex->cmd_args = NULL;
}
void ft_cleanup(t_pipex *pipex)
{
   if (pipex->fd_in >= 0)
      close(pipex->fd_in);
   if (pipex->fd_out >= 0)
      close(pipex->fd_out);
   if (pipex->pipefds[0] >= 0)
      close(pipex->pipefds[0]);
    if (pipex->pipefds[1] >= 0)
      close(pipex->pipefds[1]);
   free_string_array(pipex->cmd_paths);
   free_2d_array(pipex->cmd_args, 2);

   ft_init_pipex(pipex);
}

int ft_check_args(t_pipex *pipex, char *file1, char *file2)
{
    pipex->fd_in = open(file1, O_RDONLY);
    if (pipex->fd_in == -1)
    {
        perror("open infile");
        return (-1);
    }
    pipex->fd_out = open(file2, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (pipex->fd_out == -1)
    {
        perror("open outfile");
        close(pipex->fd_in);
        pipex->fd_in = -1;
        return (-1);
    }
    return (0);
}


