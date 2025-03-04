#include "pipex.h"

void check_param(int ac)
{
   if ( ac != 5)
   {
      ft_putstr_fd("Wrong number of Args\n", 1);
      exit(EXIT_FAILURE);
   }

}
void free_string_array(char **arr)
{
   if (arr)
   {
      int i;

      i = 0;
      while (arr[i])
      {
         free(arr[i]);
         i++;
      }
      free(arr);
   }
}
void free_2d_array(char ***arr, int size)
{
   if (arr)
   {
      int i;

      i = 0;
      while (i < size)
      {
         free_string_array(arr[i]);
         i++;
      }
      free(arr);
   }
}



int main(int ac, char **av, char **env) {
    t_pipex pipex;

    ft_init_pipex(&pipex);
    check_param(ac);
    if (ft_check_args(&pipex, av[1], av[4]) == -1) {
        ft_cleanup(&pipex);
        exit(EXIT_FAILURE);
    }
    pipex.cmd_paths = ft_parse_cmds(av[2], av[3], env);
    if (!pipex.cmd_paths) {
        ft_cleanup(&pipex);
        exit(EXIT_FAILURE);
    }
    pipex.cmd_args = ft_parse_args(av[2], av[3]);
    if (!pipex.cmd_args) {
        ft_cleanup(&pipex);
        exit(EXIT_FAILURE);
    }
    if (pipe(pipex.pipefds) == -1) {
        perror("pipe");
        ft_cleanup(&pipex);
        exit(EXIT_FAILURE);
    }

    pipex.pid1 = fork();
    if (pipex.pid1 == -1) {
        perror("fork 1");
        ft_cleanup(&pipex);
        exit(EXIT_FAILURE);
    }
    if (pipex.pid1 == 0) {
        close(pipex.pipefds[0]);
        dup2(pipex.fd_in, STDIN_FILENO);
        dup2(pipex.pipefds[1], STDOUT_FILENO);
        close(pipex.fd_in);
        close(pipex.pipefds[1]);
        execve(pipex.cmd_paths[0], pipex.cmd_args[0], env);
        perror("execve cmd 1");
        exit(EXIT_FAILURE);
    }

    pipex.pid2 = fork();
    if (pipex.pid2 == -1) {
        perror("fork 2");
        ft_cleanup(&pipex);
        exit(EXIT_FAILURE);
    }
    if (pipex.pid2 == 0) {
        close(pipex.pipefds[1]);
        dup2(pipex.pipefds[0], STDIN_FILENO);
        dup2(pipex.fd_out, STDOUT_FILENO);
        close(pipex.fd_out);
        close(pipex.pipefds[0]);
        execve(pipex.cmd_paths[1], pipex.cmd_args[1], env);
        perror("execve cmd 2");
        exit(EXIT_FAILURE);
    }

    ft_cleanup(&pipex); 
    waitpid(pipex.pid1, NULL, 0);
    waitpid(pipex.pid2, NULL, 0);
    return (EXIT_SUCCESS);
}

