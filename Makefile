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

HEADERS_LIST	=	drawing.h		\
					exit.h			\
					fdf.h			\
					init.h			\
					key_handler.h	\
					map.h			\
					nlx.h			\
					projections.h	\
					ui.h			\
					update.h

SRCS_LIST		=	main.c				\
					camera.c			\
					drawing.c			\
					exit.c				\
					init.c				\
					key_handler.c		\
					mouvement.c			\
					parsing_util.c		\
					parsing.c			\
					projections.c		\
					tracker.c			\
					ui.c				\
					update_camera.c		\
					update_world.c

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

init			:
					git submodule update --init --recursive
					make all

all				:	${OBJS} ${HEADERS}
					make -C lib/libft
					make -C l${MLX_A}ib/new_libx
					make ${NAME}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} ${HEADERS} ${LIBFT} ${NLX}
					${CC} ${CFLAGS} -I ${DIR_HEADERS} -I ${DIR_HEADERS_NLX} ${OBJS} ${FRAMEWORKS} -o ${NAME}

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEADERS}
					${CC} ${CFLAGS} -I ${DIR_HEADERS} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

# ---- Usual Rules ---- #

clean			:
					make -C lib/libft clean
					make -C lib/new_libx clean
					${RM} ${OBJS}

fclean			:
					make clean
					${RM} ${NAME}
					make -C lib/libft fclean
					make -C lib/new_libx fclean

re				:
					make fclean
					make all

.PHONY:	all clean fclean re
