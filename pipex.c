#include "pipex.h"



int main(int ac, char **av, char **env)
{
    t_pipex pipex;
    ft_init_pipex(&pipex);
    check_param(ac);
    if (ft_check_args(&pipex, av[1], av[4]) == -1)
    {
        ft_cleanup(&pipex);
        exit(EXIT_FAILURE);
    }
    pipex.cmd_paths = ft_parse_cmds(av[2], av[3], env);
    pipex.cmd_args = ft_parse_args(av[2], av[3]);
    if (!pipex.cmd_paths || !pipex.cmd_args || pipe(pipex.pipefds) == -1)
    {
        write(2, "ERROR\n", 6);
        ft_cleanup(&pipex);
        exit(EXIT_FAILURE);
    }
    pipex.pid1 = fork();
    if (pipex.pid1 == 0)
        exe_child1(&pipex, env);
    pipex.pid2 = fork();
    if (pipex.pid2 == 0)
        exe_child2(&pipex, env);
    ft_cleanup(&pipex);
    waitpid(pipex.pid1, NULL, 0);
    waitpid(pipex.pid2, NULL, 0);
    return (EXIT_SUCCESS);
}



