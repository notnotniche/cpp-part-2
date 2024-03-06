NAME		=	main

OBJ_DIR		=	objs
SRC_DIR		=	$(shell find . -type d)

vpath %.cpp $(foreach dir, $(SRC_DIR), $(dir):)

SRCS		 =	main.cpp
				

OBJS		=	$(SRCS:%.cpp=${OBJ_DIR}/%.o)

RM			=	rm -rf

CC			=	c++

CFLAGS		=	-Werror -Wall -Wextra -std=c++98

all:	${NAME}

$(NAME): ${OBJS}
		@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) :
		@mkdir -p $@

clean:
		@${RM} $(OBJ_DIR)

fclean:		clean
		@${RM} ${NAME}

re:			fclean
		@$(MAKE) all -j

.PHONY:		all clean fclean re