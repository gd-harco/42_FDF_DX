# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 15:42:45 by gd-harco          #+#    #+#              #
#    Updated: 2022/12/17 16:39:02 by gd-harco         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ******** VARIABLES ******** #

# ---- Final Executable --- #
NAME			=	libft.a

NAME_DEBUG		=	libft_debug.a

# ---- Directories ---- #
INCLUDES		=	includes/

DIR_OBJS		=	./.objs/

SRCS			=	${addprefix srcs/, ${C_FILES}}

# ---- FILES ---- #
C_FILES 		=	char/ft_isalnum.c	\
					char/ft_isalpha.c	\
					char/ft_isascii.c	\
					char/ft_isdigit.c	\
					char/ft_isprint.c	\
					char/ft_toupper.c	\
					char/ft_tolower.c	\
\
					io/ft_putchar_fd.c						\
					io/ft_putendl_fd.c						\
					io/ft_putnbr_fd.c						\
					io/ft_putstr_fd.c						\
					io/ft_printf.c							\
					io/ft_GetNextLine/get_next_line.c		\
					io/ft_GetNextLine/get_next_line_utils.c	\
\
					list/ft_lstadd_back_bonus.c		\
					list/ft_lstadd_front_bonus.c	\
					list/ft_lstclear_bonus.c		\
					list/ft_lstdelone_bonus.c		\
					list/ft_lstiter_bonus.c			\
					list/ft_lstlast_bonus.c			\
					list/ft_lstmap_bonus.c			\
					list/ft_lstnew_bonus.c			\
					list/ft_lstsize_bonus.c			\
\
					memory/ft_bzero.c		\
					memory/ft_calloc.c		\
					memory/ft_memchr.c		\
					memory/ft_memcmp.c		\
					memory/ft_memcpy.c		\
					memory/ft_memmove.c		\
					memory/ft_memset.c		\
					memory/ft_free_array.c	\
\
					numbers/ft_atoi.c	\
					numbers/ft_itoa.c	\
\
				str/ft_split.c		\
				str/ft_free_split.c	\
				str/ft_strchr.c		\
				str/ft_strdup.c		\
				str/ft_strpdup.c	\
				str/ft_striteri.c	\
				str/ft_strjoin.c	\
				str/ft_strlcat.c	\
				str/ft_strlcpy.c	\
				str/ft_strlen.c		\
				str/ft_strmapi.c	\
				str/ft_strncmp.c	\
				str/ft_strnstr.c	\
				str/ft_strrchr.c	\
				str/ft_strtrim.c	\
				str/ft_substr.c		\
\
					array/ft_array_length.c

HEADERS 		=	${INCLUDES}char.h				\
					${INCLUDES}io.h					\
					${INCLUDES}libft.h				\
					${INCLUDES}list.h				\
					${INCLUDES}memory.h				\
					${INCLUDES}numbers.h			\
					${INCLUDES}str.h				\
					${INCLUDES}get_next_line.h		\
					${INCLUDES}array.h

OBJS			=	${addprefix ${DIR_OBJS},${SRCS:.c=.o}}

OBJS_DEBUG		=	${addprefix ${DIR_OBJS},${SRCS:.c=_debug.o}}

# ---- Compilation ---- #

CC				= cc

FLAGS 			= -Wall -Wextra -Werror

DEBUG_FLAGS		=-g3 -fsanitize=address


# ---- Commands ---- #
RMF				=	rm -rf

MKDIR			= 	mkdir -p

# ********* RULES ******** #

all:			${DIR_OBJS}
				@${MAKE} ${NAME}

debug:			${DIR_OBJS}
				@${MAKE} ${NAME_DEBUG} FLAGS="${FLAGS} ${DEBUG_FLAGS}"

# ---- Variables Rules ---- #

$(NAME):		${OBJS}
				ar rcs ${NAME} ${OBJS}

${NAME_DEBUG}: ${OBJS_DEBUG}
				ar rcs ${NAME_DEBUG} ${OBJS_DEBUG}

# ---- Compiled Rules ---- #

${DIR_OBJS}:
			@echo ${OBJS} | tr ' ' '\n'\
				| sed 's|\(.*\)/.*|\1|'\
				| sed 's/^/${MKDIR} /'\
				| sh -s
			@# Prints all OBJS. 1 per line
				@# Removes the .o file names
				@# Adds mkdir -p at start of each lines
				@# Executes the script (Creates all folders)

${DIR_OBJS}%.o: %.c ${HEADERS}
				cc ${FLAGS} -I ${INCLUDES} -c $< -o $@

${DIR_OBJS}%_debug.o: %.c ${HEADERS}
				cc ${FLAGS} -I ${INCLUDES} -c $< -o $@

# ---- Usual Rules ---- #

clean:
				${RMF} ${OBJS} ${OBJS_DEBUG}

fclean:			clean
				${RMF} ${NAME} ${NAME_DEBUG}

re:				fclean
				${MAKE} all

re_debug:		fclean
				${MAKE} debug

echo_objs:
				@echo ${OBJS}

.PHONY:			all clean fclean re re_debug echo_objs debug
