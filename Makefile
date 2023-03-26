# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME			=	fdf

# ---- Directories ---- #

DIR_OBJS		=	bin/

DIR_SRCS		=	srcs/

DIR_HEADERS		=	includes/

DIR_HEADERS_NLX	=	lib/new_libx/includes/

# ---- Libs variables ---- #

LIBFT			=	lib/libft/libft.a

NLX				=	lib/new_libx/libnlx.a

# ---- Files ---- #

HEADERS_LIST	=	nlx.h fdf.h parsing.h


SRCS_LIST		=	main.c				\
					init.c				\
					parsing/parsing.c	\
					matrix/matrix_creation.c

HEADERS			=	${HEADERS_LIST:%.h=${DIR_HEADERS}%.h} \

OBJS			=	${SRCS_LIST:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC				=	cc

CFLAGS			=	 -Wall -Werror -Wextra -g3

FRAMEWORKS		=	-Llib/libft -Llib/mlx -lft -lmlx -lXext -lX11


# ---- Commands ---- #

RM				=	rm -rf

MKDIR			=	mkdir -p

# ********* RULES ******** #

all				:	${NAME}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} ${HEADERS}
					make -C lib/libft
					make -C lib/new_libx
					${CC} ${CFLAGS} -I ${DIR_HEADERS} ${OBJS} ${FRAMEWORKS} -o ${NAME}

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEADERS}
					${CC} ${CFLAGS} -I ${DIR_HEADERS} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}
					${MKDIR} ${DIR_OBJS}/parsing
					${MKDIR} ${DIR_OBJS}/matrix

# ---- Usual Rules ---- #

clean			:
					${RM} ${OBJS}

fclean			:	clean
					${RM} ${NAME}
					make -C lib/libft fclean

re				:	fclean all


.PHONY:	all clean fclean re
