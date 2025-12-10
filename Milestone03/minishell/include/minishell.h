/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:18:21 by adeestev          #+#    #+#             */
/*   Updated: 2025/11/30 23:46:36 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ========================================================================== */
/*                              libraries                                     */
/* ========================================================================== */

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

/* ========================================================================== */
/*                            enums and structures                            */
/* ========================================================================== */

typedef enum e_redir_type
{
	R_IN,
	R_OUT,
	R_APPEND,
	R_HEREDOC
}	t_redir_type;

/* environment */

typedef struct s_env
{
	char	*key;
	char	*value;
}	t_env;

/* redirections */

typedef struct s_redir
{
	t_redir_type	type;
	char			*target;
	int				hd_fd;
}	t_redir;

/* commands */

typedef struct s_cmd
{
	char	**argv;
	t_redir	*redirs;
	int		n_redirs;
	int		is_builtin;
}	t_cmd;

/* pipeline */

typedef struct s_pipeline
{
	t_cmd	*cmds;
	int		n_cmds;
}	t_pipeline;

/* main */

typedef struct s_mshl
{
	t_pipeline	*pipeline;
	t_list		*env;
	int			exit_status;
	int			should_exit;
	int			interactive;
	int			sintax_error;
}	t_mshl;

/* expansion context */

typedef struct s_exp_ctx
{
	t_list	*env;
	int		last_status;
}	t_exp_ctx;

typedef struct s_expand_state
{
	int		i;
	int		in_single;
	int		in_double;
	char	*result;
}	t_expand_state;

/* command filling helpers */

typedef struct s_args_fill
{
	int	i;
	int	a_i;
	int	r_i;
	int	ok;
}	t_args_fill;

typedef struct s_args_ctx
{
	t_cmd		*cmd;
	char		**tokens;
	t_args_fill	*args;
	t_exp_ctx	*exp;
}	t_args_ctx;

typedef struct s_fill_ctx
{
	t_cmd		*cmd;
	char		**tokens;
	int			argc;
	int			n_redirs;
	t_exp_ctx	*exp;
}	t_fill_ctx;

/* ========================================================================== */
/*                              prototypes                                    */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/*                               signals                                      */
/* -------------------------------------------------------------------------- */

extern volatile sig_atomic_t	g_signal_received;

void		set_signals_interactive(void);
void		set_signals_child(void);
void		set_signals_parent_execution(void);
void		handle_signals_in_loop(t_mshl *data);

/* -------------------------------------------------------------------------- */
/*                           parsing - tokenizer                              */
/* -------------------------------------------------------------------------- */

char		**tokenize(char *str);
int			count_tokens(const char *str);
void		free_tokens(char **tokens);
char		*dup_quoted(const char *str, int len);
int			token_len(const char *str);
int			quote_len(const char *str);
int			word_len(const char *str);
int			is_redir(const char *str);
int			is_quote(char c);
int			is_space(char c);

/* tokenizer utils */

int			has_forbidden_chars(char *s);
char		*str_append(char *str, char c);
int			append_single_quoted(char *str, int i, char **buf);
int			append_double_quoted(char *str, int i, char **buf);

/* -------------------------------------------------------------------------- */
/*                             parsing - parser                               */
/* -------------------------------------------------------------------------- */

t_pipeline	*parse_line(char *line, t_mshl *data);
t_cmd		parse_cmd(char *cmd_str, t_mshl *data);
t_pipeline	*alloc_pipeline(int n_cmds);
void		fill_pipeline_cmds(t_pipeline *pipeline, char **cmds, t_mshl *data);
char		**split_pipes_outside_quotes(const char *line);

/* parser utils */

void		free_strings(char **arr);
int			count_strings(char **arr);
int			has_empty_pipe_cmds(char **cmds, int n_cmds);

/* -------------------------------------------------------------------------- */
/*                         parsing - syntax validation                        */
/* -------------------------------------------------------------------------- */

int			is_valid_redir_sequence(char **tokens, t_mshl *data);

/* -------------------------------------------------------------------------- */
/*                          parsing - command building                        */
/* -------------------------------------------------------------------------- */

void		init_cmd(t_cmd *cmd);
int			fill_a_and_r(t_fill_ctx *ctx);
int			handle_a_r_token(t_args_ctx *ctx);
int			count_argv(char **tokens);
int			count_redirs(char **tokens);
int			get_redir_type(const char *token);
char		*get_redir_target(char *target_token, int redir_type,
				t_exp_ctx *exp);
int			check_if_builtin(char *cmd_name);

/* command parsing context */

int			malloc_exp_ctx(t_exp_ctx **exp_ctx, t_list *env, int last_status);
int			init_tokens_ctx(char *cmd_str, char ***tokens);
int			validate_and_free_tokens(char **tokens, t_mshl *data);
void		free_if_error(t_cmd *cmd, char **tokens);

/* -------------------------------------------------------------------------- */
/*                            parsing - expansion                             */
/* -------------------------------------------------------------------------- */

char		*expand_token(const char *token, t_exp_ctx *ctx, int quoted_type);
char		*expand_var(const char *token, int *i, t_exp_ctx *ctx);
char		*expand_exit_status(int *i, t_exp_ctx *ctx);
char		*expand_named_var(const char *token, int *i, t_exp_ctx *ctx);
int			expand_dollar_in_dquote(const char *token, t_exp_ctx *ctx,
				t_expand_state *st);

/* expansion utils */

char		*expand_append_char(char *result, char c);
int			get_varname_len(const char *token, int start);
char		*get_env_value(const char *var, t_list *env);

/* -------------------------------------------------------------------------- */
/*                                environment                                 */
/* -------------------------------------------------------------------------- */

/* build */

t_list		*env_build_from_envp(char **envp);

/* get */

const char	*env_get(t_list *env, const char *key);
t_env		*env_get_pair(t_list *env, const char *key);

/* set */

t_env		*env_pair_from_key(const char *key, const char *value);
int			env_update_value(t_env *node, const char *new_val);

/* utils */

int			keys_equal(const char *key_a, const char *key_b);
int			env_equal_index(const char *line);
void		env_list_push_back(t_list **env_head, t_list *node);

/* conversion */

char		**env_to_envp(t_list *envp);

/* free */

void		env_content_free(void *content);
void		list_content_free(t_list **head);
void		envp_free(char **copy_envp);

/* -------------------------------------------------------------------------- */
/*                            execution - pipeline                            */
/* -------------------------------------------------------------------------- */

int			exec_pipeline(t_mshl *data);
int			run_pipeline(t_mshl *data);

/* child process */

void		launch_child(t_mshl *data, int index,
				int prev_pipe[2], int next_pipe[2]);

/* wait */

void		wait_for_children(pid_t *pid, int n_cmds, t_mshl *data);
void		update_exit_status_from_status(int status, t_mshl *data);

/* cleanup */

int			cleanup_on_pipe_error(pid_t *pid, int last_index,
				int prev_pipe[2]);
int			clean_on_fork_error(pid_t *pid, int last_index,
				int prev_pipe[2], int next_pipe[2]);
void		switch_pipes_to_next(int prev_pipe[2], int next_pipe[2]);
void		close_pipe_if_open(int pipefd[2]);

/* -------------------------------------------------------------------------- */
/*                           execution - commands                             */
/* -------------------------------------------------------------------------- */

void		run_command(t_mshl *data, t_cmd *cmd);
int			exec_external(t_mshl *data, t_cmd *cmd);

/* path resolution */

char		*resolve_path(const char *cmd, t_list *env);
char		*path_join(const char *path, const char *cmd);
char		*copy_path(const char *path, size_t start, const size_t end);
int			find_delimiter(char character, char delimiter);
int			not_exec_in_path(const char *path, const char *cmd);
int			handle_no_path(t_mshl *data, t_cmd *cmd);

/* external command errors */

void		print_no_such(char *name);
void		print_is_dir(char *name);
void		print_perm_denied(char *name);

/* -------------------------------------------------------------------------- */
/*                           execution - redirections                         */
/* -------------------------------------------------------------------------- */

int			apply_redirs(t_cmd *cmd);
int			redir_in(t_redir *redir);
int			redir_out(t_redir *redir);
int			redir_append(t_redir *redir);
int			redir_heredoc(t_redir *redir);

/* heredoc */

int			create_heredoc_fd(t_redir *redir, t_mshl *data);
int			prepare_all_heredocs(t_mshl *data);
void		close_all_heredocs(t_mshl *data);
int			is_heredoc_delim(const char *line, const char *delim);
void		normalize_heredoc_line(char *line);
void		print_heredoc_prompt(void);

/* redirection errors */

int			print_redir_error(char *prefix, char *target);
int			print_dup2_error(char *msg);

/* -------------------------------------------------------------------------- */
/*                                builtins                                    */
/* -------------------------------------------------------------------------- */

int			builtin_dispatch(t_mshl *data, t_cmd *cmd);
int			exec_builtin_in_parent(t_mshl *data, t_cmd *cmd);

/* individual builtins */

int			builtin_echo(char **argv);
int			builtin_cd(char **argv, t_list *env);
int			builtin_pwd(void);
int			builtin_export(char **argv, t_list **env);
int			builtin_unset(char **argv, t_list **env);
int			env_builtin(char **argv, t_list *env_list);
int			builtin_exit(t_mshl *data, char **argv);

/* export utils */

int			check_args_export(char *argv);
void		export_print_list(t_list *env);
int			export_split_kv(char *arg, char **key_text, const char **val,
				int eq_pos);
int			export_create_var(t_list **env, char *key_text,
				const char *value_text);
int			export_update_var(t_env *pair, int eq_pos, const char *value_text);

/* -------------------------------------------------------------------------- */
/*                                utilities                                   */
/* -------------------------------------------------------------------------- */

void		put_error(char *a, char *b, char *c);
int			is_blank_line(const char *line);

/* memory cleanup */

void		free_cmd(t_cmd *cmd);
void		free_pipeline(t_pipeline *pipeline);

#endif
