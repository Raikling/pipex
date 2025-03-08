#include "pipex.h"

char ***ft_parse_args(char *cmd1, char *cmd2)
{
    char ***args;
    
    args = malloc(3 * sizeof(char **));
    if (!args)
        return (NULL);

    args[0] = ft_split(cmd1, ' ');
    if (!args[0])
    {
        free(args);
        return (NULL);
    }
    args[1] = ft_split(cmd2, ' ');
    if (!args[1])
    {
        free_string_array(args[0]);
        free(args);
        return (NULL);
    }
    args[2] = NULL;
    return (args);
}

char *get_command_base(char *cmd)
{
    char *space;

    space = ft_strchr(cmd, ' ');
    if (space)
        return (ft_substr(cmd, 0, space - cmd));
    else
        return (ft_strdup(cmd));
}

// char *get_exe_path(char **dirs, char *cmd_base)
// {
//     int i;
//     char *path;
//     char *tmp;

//     i = 0;
//     path = NULL;
//     while (dirs[i] && !path)
//     {
//         tmp = ft_strjoin(dirs[i++], "/");
//         path = ft_strjoin(tmp, cmd_base);
//         free(tmp);
//         if (path && access(path, X_OK) == 0)
//             return (path);
//         free(path);
//         path = NULL;
//     }
//     if (cmd_base[0] == '/' && access(cmd_base, X_OK) == 0)
//         return (printf("get_exe_path: '%s' -> NULL\n", cmd_base), ft_strdup(cmd_base));
    
//     return (NULL);
// }
char *get_exe_path(char **dirs, char *cmd_base)
{
    int i;
    char *path;
    char *tmp;

    // If absolute path, check it directly
    if (cmd_base[0] == '/')
    {
        if (access(cmd_base, X_OK) == 0)
            return (ft_strdup(cmd_base));
        return (NULL);
    }
    // Otherwise, search PATH
    i = 0;
    path = NULL;
    while (dirs[i] && !path)
    {
        tmp = ft_strjoin(dirs[i++], "/");
        path = ft_strjoin(tmp, cmd_base);
        free(tmp);
        if (path && access(path, X_OK) == 0)
            return (path);
        free(path);
        path = NULL;
    }
    return (NULL);
}

void set_command_paths(char **paths, char *cmd1, char *cmd2, char **env)
{
    int i;
    char **dirs;
    char *cmd1_base;
    char *cmd2_base;
    
    i = 0;
    while (env[i] && ft_strncmp(env[i], "PATH=", 5))
        i++;
    if (!env[i])
        return ;
    dirs = ft_split(env[i] + 5, ':');
    cmd1_base = get_command_base(cmd1);
    cmd2_base = get_command_base(cmd2);
    paths[0] = get_exe_path(dirs, cmd1_base);
    paths[1] = get_exe_path(dirs, cmd2_base);
    free_string_array(dirs);
    free(cmd1_base);
    free(cmd2_base);
}

char **ft_parse_cmds(char *cmd1, char *cmd2, char **env) 
{
    char **paths;

    paths= malloc(3 * sizeof(char *));
    if (!paths || !env) 
    {
        free(paths);
        return (NULL);
    }
    paths[2] = NULL;
    set_command_paths(paths, cmd1, cmd2, env);
    if (!paths[0] || !paths[1])
    { 
        free_string_array(paths);
        return (NULL);
    }
    return (paths);
}