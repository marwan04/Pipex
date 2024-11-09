NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

SRCDIR = srcs
SRCDIR_BONUS = srcs_bonus
INCDIR = includes
OBJDIR = obj
LIBPATH	= libft/

LIB = -L./libft -lft

RM = rm -rf

SRC_FILES = pipex.c utils.c
# SRC_FILES_BONUS = 

SRC = $(addprefix $(SRCDIR)/, $(SRC_FILES))
#SRC_BONUS = $(addprefix $(SRCDIR_BONUS)/, $(SRC_FILES_BONUS))
OBJ = $(addprefix $(OBJDIR)/, $(SRC_FILES:.c=.o))
#OBJ_BONUS = $(addprefix $(OBJDIR)/, $(SRC_FILES_BONUS:.c=.o))

all: $(NAME)

${NAME}: ${OBJ}
	 make -C ${LIBPATH}
	 ${CC} ${CFLAGS} $^ ${LIB} -o $@
	 
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)
	 
#bonus : clean
#	make -C ${LIBPATH}
#	${CC} ${CFLAGS} ${SRCS_BONUS} -o $(NAME)
	 
clean:
	make clean -C ${LIBPATH}
	${RM} $(OBJDIR)

fclean: clean
	make fclean -C ${LIBPATH}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
