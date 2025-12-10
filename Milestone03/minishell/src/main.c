/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:44:43 by drubio-s          #+#    #+#             */
/*   Updated: 2025/11/30 14:00:56 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	init_data(t_mshl *data, char **envp)
{
	data->env = env_build_from_envp(envp);
	data->pipeline = NULL;
	data->exit_status = 0;
	data->should_exit = 0;
	data->sintax_error = 0;
}

static void	run_line(t_mshl *data, char *line)
{
	data->sintax_error = 0;
	if (line[0] == '\0' || is_blank_line(line))
		return ;
	add_history(line);
	data->pipeline = parse_line(line, data);
	if (!data->sintax_error && data->pipeline)
	{
		exec_pipeline(data);
		free_pipeline(data->pipeline);
		data->pipeline = NULL;
	}
	else
	{
		free_pipeline(data->pipeline);
		data->pipeline = NULL;
		data->sintax_error = 0;
		return ;
	}
}

static void	shell_loop(t_mshl *data)
{
	char	*line;

	while (1)
	{
		handle_signals_in_loop(data);
		line = readline("minishell$ ");
		if (!line)
		{
			write(1, "exit\n", 5);
			break ;
		}
		if (line && *line)
			run_line(data, line);
		free(line);
		if (data->should_exit == 1)
			break ;
	}
}

static void	non_interactive_loop(t_mshl *data)
{
	char	*line;
	char	*trimmed_line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		trimmed_line = ft_strtrim(line, "\n");
		free(line);
		if (trimmed_line)
		{
			run_line(data, trimmed_line);
			free(trimmed_line);
		}
		if (data->should_exit == 1)
			break ;
		line = get_next_line(STDIN_FILENO);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_mshl	data;

	(void)argc;
	(void)argv;
	init_data(&data, envp);
	if (isatty(STDIN_FILENO))
	{
		data.interactive = 1;
		set_signals_interactive();
		shell_loop(&data);
	}
	else
	{
		data.interactive = 0;
		non_interactive_loop(&data);
	}
	rl_clear_history();
	list_content_free(&data.env);
	return (data.exit_status);
}
