#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/24 11:05:54 by ddinaut           #+#    #+#              #
#    Updated: 2018/02/23 16:28:35 by ddinaut          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Output #
NAME		= 42sh

# compilation #
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
ADDFLAGS	= #-fsanitize=address -g3

# Directories #
OBJ_PATH	= obj
SRC_PATH	= srcs
LIB_PATH	= libft
INC_PATH	= includes/

# Sub_dirs #
SH			= shell/
EXEC		= executor/
LEXER		= lexer/
PARSER		= parser/
SOURCE		= source/
BUILTIN		= built_in/
SIGNAL		= signal/
READ_LINE	= read_line_and_edition/
	AUTOCOMP 	= $(READ_LINE)autocomplete/

# Colors #
BLACK		= \033[1;30m
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
PURPLE		= \033[1;35m
WHITE		= \033[1;37m
END_COL		= \033[0m
COUNT		= 1

# libraries #
LIBFT		= -L $(LIB_PATH)
LIBS		= $(LIBFT) -lft
ADD_LIBS	= -ltermcap
INCLUDES 	= -I./ -I $(LIB_PATH)/$(INC_PATH) -I $(INC_PATH)

# Links #
OBJ			= $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
SRC			= $(addprefix $(SRC_PATH)/,$(SRCS))

# Sources #
SRCS 	=	main.c\
\
			$(SH)allocate_shell.c\
\
			$(EXEC)allocate_executor.c \
			$(EXEC)dup_io.c \
			$(EXEC)execute.c \
			$(EXEC)execute_supplementary.c \
			$(EXEC)execute_supplementary_bis.c \
			$(EXEC)supplementary_pipe.c \
			$(EXEC)find_command.c \
			$(EXEC)here_document.c \
			$(EXEC)redirect.c \
\
			$(LEXER)append_char.c\
			$(LEXER)is_something.c\
			$(LEXER)lexer.c\
			$(LEXER)quoting_state.c\
			$(LEXER)token.c\
			$(LEXER)extract_token_routine.c\
			$(LEXER)extract_token_routine_bis.c\
			$(LEXER)extract_token_routine_ter.c\
			$(LEXER)extract_token_is.c\
			$(LEXER)extract_token_is_bis.c\
\
			$(PARSER)intermediate_code.c\
			$(PARSER)parse_complete_command.c\
			$(PARSER)parse_supplementary.c\
			$(PARSER)free_parser.c\
			$(PARSER)parse_subshell.c\
			$(PARSER)parse_error.c\
			$(PARSER)parse_supplementary_bis.c\
			$(PARSER)parser.c\
			$(PARSER)init_type_do_heredoc.c\
			$(PARSER)heredoc_supplementary.c\
\
			$(SOURCE)source.c\
			$(SOURCE)source_supplementary.c\
\
			$(BUILTIN)ft_cd.c\
			$(BUILTIN)ft_env.c\
			$(BUILTIN)env_supplementary.c\
			$(BUILTIN)built_in_error_msg.c\
			$(BUILTIN)ft_setenv.c\
			$(BUILTIN)ft_unsetenv.c\
			$(BUILTIN)ft_echo.c\
			$(BUILTIN)ft_exit.c\
\
			$(READ_LINE)quoting_several_lines.c\
			$(READ_LINE)read_line.c\
			$(READ_LINE)update_term.c\
			$(READ_LINE)update_term_supplementary.c\
			$(READ_LINE)historic.c\
			$(READ_LINE)line_edition.c\
			$(READ_LINE)term_mode_tc_init.c\
			$(READ_LINE)read_line_signal.c\
			$(READ_LINE)char_read_line.c\
			$(READ_LINE)routine_read_line.c\
			$(READ_LINE)is_key.c\
			$(READ_LINE)is_key_bis.c\
			$(READ_LINE)is_key_ter.c\
			$(READ_LINE)is_key_quater.c\
			$(READ_LINE)move.c\
			$(READ_LINE)move_bis.c\
			$(READ_LINE)copy_paste.c\
			$(READ_LINE)move_ter.c\
			$(READ_LINE)various.c\
\
			$(AUTOCOMP)autocomplete.c\
			$(AUTOCOMP)autocomplete_binary.c\
			$(AUTOCOMP)autocomplete_files.c\
			$(AUTOCOMP)autocomplete_get.c\
			$(AUTOCOMP)autocomplete_isdir.c\
			$(AUTOCOMP)autocomplete_misc.c\
\
			$(SIGNAL)main_signal.c \
			$(SIGNAL)child_signal.c

# Exceptions #
.PHONY: all clean fclean re

# Compilation rules #
all: $(NAME)

$(NAME): $(OBJ)
		@printf "                                                                              \r"
		@printf "$(BLUE)Almost done\n :$(END_COL)"
		@printf "                                                                              \r"
		@printf "$(RED)Checking libft$(END_COL)"
		@make -s -C $(LIB_PATH)
		@printf "                                                                              \r"
		@printf "$(GREEN)Checking libft: Done$(END_COL)\n"
		@$(CC) -o $@ $(FLAGS) $(ADDFLAGS) $(OBJ) $(LIBS) $(ADD_LIBS)
		@printf "								\r$(PURPLE)- 42sh ready to work -\n$(END_COL)"

$(OBJ): $(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
		@mkdir -p $(dir $@)
		@$(CC) -o $@ $(FLAGS) $(ADD_FLAGS) $(INCLUDES) -c $<
		@printf "\e[1;38;5;%dm" $(COUNT)
		@$(eval COUNT = $(shell echo $$(($(COUNT) + 1))))
		@printf "42sh: %s                                 $(END_COL)\r" $<

clean:
		@$(MAKE) clean -C libft
		@/bin/rm -rf $(OBJ_PATH)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all
