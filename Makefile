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

HEADERS_LIST	=	fdf.h		\
					init.h		\
					map.h		\
					nlx.h		\
					projections.h

SRCS_LIST		=	main.c				\
					init.c				\
					projections.c		\
					parsing/parsing.c

HEADERS			=	${HEADERS_LIST:%.h=${DIR_HEADERS}%.h} \

OBJS			=	${SRCS_LIST:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC				=	cc

CFLAGS			=	 -Wall -Werror -Wextra -g3

FRAMEWORKS		=	-Llib/libft -Llib/new_libx -lft -lnlx -lXext -lX11 -lm


# ---- Commands ---- #

RM				=	rm -rf

MKDIR			=	mkdir -p

# ********* RULES ******** #

all				:	${NAME}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} ${HEADERS}
					make -C lib/libft
					make -C lib/new_libx
					${CC} ${CFLAGS} -I ${DIR_HEADERS} -I ${DIR_HEADERS_NLX} ${OBJS} ${FRAMEWORKS} -o ${NAME}

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
					make -C lib/new_libx fclean

re				:	fclean all


.PHONY:	all clean fclean re
