/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line_and_edition.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:43:00 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/07/18 14:03:08 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_LINE_AND_EDITION_H
# define READ_LINE_AND_EDITION_H
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include "struct_read_line.h"
# define BUF_SIZE 32
# define MAX_KEY_LEN 7
# define QUOTES 2
# define NULL_CTRLD 4
# define HISTORIC 8
# define TERMCAP 16
# define CHAR_WINCH (char)-61
# define CHAR_REPRINT (char)-62
# define CTRLD_ASCII (char)4
# define ADD 1
# define INIT 0
# define ON 1
# define OFF 0
# define START 0
# define STOP 1
# define CLEAR_NEEDED 2
# define ABS(val) ((val < 0) ? -(val) : val)

typedef int		(*t_routine_read_line)(t_line *, char **, int);
typedef int		(*t_do_edition)(t_line *, int);
typedef int		(*t_is_key)(char *buf);

void	tc_init(void);
void	raw_terminal_mode(void);
void	default_terminal_mode(void);
char	*ft_read_line(char *prompt, int flags);
void	init_line(t_line *line_struct, char *prompt, int flags);
void	add_char(t_line *line_struct, char c);
int		line_edition(t_line *line_struct, char *buf, int flags);
void	ft_historic(t_line *l, int flags);
void	quoting_several_lines(t_line *line_struct);

void	no_return_read_line(t_line *line_struct, char *buf, int flags);
void	ctrl_d_read_line(t_line *line_struct, char **l, int flags);
void	backslash_read_line(t_line *line_struct, char **l, int flags);
void	print_prompt(t_line *line_struct, int flags);

int		is_right_key(char *buf);
int		is_left_key(char *buf);
int		is_delete_key(char *buf);
int		is_up_key(char *buf);
int		is_down_key(char *buf);
int		is_shift_right(char *buf);
int		is_shift_left(char *buf);
int		is_shift_up(char *buf);
int		is_shift_down(char *buf);
int		is_ctrl_a(char *buf);
int		is_ctrl_w(char *buf);
int		is_ctrl_b(char *buf);
int		is_ctrl_d(char *buf);
int		is_home(char *buf);
int		is_end(char *buf);
int		is_control_code(char *buf);
int		is_tab(char *buf);
int		is_return_one(char *buf);

int		move_right(t_line *line_struct, int flags);
int		move_left(t_line *line_struct, int flags);
int		move_right_word(t_line *line_struct, int flags);
int		move_left_word(t_line *line_struct, int flags);
int		down_line(t_line *line, int flags);
int		up_line(t_line *line, int flags);
int		ft_delete_character(t_line *line_struct, int flags);
int		ft_delete_current_character(t_line *line_struct, int flags);
int		up_historic(t_line *line_struct, int flags);
int		down_historic(t_line *line_struct, int flags);
int		select_mode(t_line *line_struct, int flags);
int		copy_selected(t_line *line_struct, int flags);
int		paste_selected(t_line *line_struct, int flags);
int		move_home(t_line *line_struct, int flags);
int		move_end(t_line *line_struct, int flags);
int		return_one(t_line *line_struct, int flags);
int		return_zero(t_line *line_struct, int flags);

void	update_term(t_line *line_struct, int flags);
void	compute_lines(t_line *line_struct);
int		get_nb_col_term(void);
int		get_nb_line_term(void);
int		get_term_line(t_line *line_struct, t_term_line *term_line, int index);
void	add_line(t_line *line, int start_index, int nb_char);
void	free_term_line(t_line *line_struct);

void	signal_read_line(int on_off);
void	exit_routine(void);
int		ft_putc(int c);

char	**realloc_tab(char **tab_str, int size);
int		ft_autocomplete(t_line *line_struct, int flags);
void	ft_autocomplete_propose(t_list *files, int col);
void	ft_autocomplete_append(t_line *line_struct, char *new, char *start);
char	*ft_get_last_word(char *str, int cursor_pos);
char	*ft_get_path(char *str);
char	*ft_get_start(char *str);
void	ft_autocomplete_binary_get_path(t_line *line_struct, char *start,\
										char **binary_path, int i);
t_list	*ft_autocomplete_binary_fill(t_list **files, char *binary_path,\
										char *filename, char *start);
void	ft_autocomplete_binary_display(t_line *line_struct, t_list **files,\
										char *start, char *path);
void	ft_autocomplete_binary_isdir(t_list **files, char *path);
void	ft_autocomplete_isdir(t_list **files, char *path);
int		ft_isvalid(char c);
char	*ft_isvalidchr(char *str);
char	ft_last_char(char *str);
int		ft_first_word(char *str, int i, int d);
int		ft_isnot_dot(char *str);
int		get_maxlen(t_list *files);
void	ft_autocomplete_files(t_line *line_struct, char *last_word);
void	ft_autocomplete_binary(t_line *line_struct, char *last_word);
char	**loop_path(char **env);
#endif
