# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tobeshota <tobeshota@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 09:34:52 by tobeshota         #+#    #+#              #
#    Updated: 2024/09/23 20:25:26 by tobeshota        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	a.out
CC				=	c++
FLAGS			=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors
RM				=	rm -rf

SRCS_DIR		=	srcs/
INCS_DIR		=	includes/
OBJS_DIR		=	objs/
DOCS_DIR		=	docs/
HTML_DIR		=	$(DOCS_DIR)html/
LATEX_DIR		=	$(DOCS_DIR)latex/

SRCS			=	$(wildcard $(SRCS_DIR)*.cpp)
HEADERS			=	$(wildcard $(INCS_DIR)*.hpp)
SHS				=	$(wildcard *.sh)
OBJS			=	$(patsubst %.cpp, $(OBJS_DIR)%.o, $(SRCS))
DOXYFILE_PATH	= $(DOCS_DIR)Doxyfile
INDEX_HTML_PATH	= $(HTML_DIR)index.html

ifeq ($(MAKECMDGOALS), debug)
	FLAGS += -DDEBUG
endif

ifeq ($(MAKECMDGOALS), address)
	FLAGS += -g3 -fsanitize=address
endif

ifeq ($(MAKECMDGOALS), test)
	FLAGS += -DTEST
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -I $(INCS_DIR) $(OBJS) -o $@

$(OBJS_DIR)%.o : %.cpp
	mkdir -p $(@D)
	$(CC) $(FLAGS) -I $(INCS_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR) $(HTML_DIR) $(LATEX_DIR)

fclean: clean
	make fclean -C test/
	$(RM) $(NAME)

re:		fclean all

fmt:
	make fmt -C test/
	$(if $(SRCS), clang-format --style=Google -i $(SRCS))
	$(if $(HEADERS), clang-format --style=Google -i $(HEADERS))
	$(if $(SHS), shfmt -w $(SHS))

debug: re

address: re

test:
	@ make test -C test/

doc:
	@ if [ ! -f $(DOXYFILE_PATH) ]; then doxygen -g $(DOXYFILE_PATH); fi
	@ doxygen $(DOXYFILE_PATH)
	@ open $(INDEX_HTML_PATH)

.PHONY:	all clean fclean re fmt debug address test doc
