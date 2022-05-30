# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:      :+:    :+:    #
#                                                      +:+                     #
#    By: saladuit <safoh@student.codam.nl>            +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/13 21:33:38 by saladuit      #+#    #+#                  #
#    Updated: 2022/05/26 19:16:54 by safoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include makerc/files.mk
include makerc/colours.mk

PROJECT				:=	Unit-Battle
NAME				:=	bowling_game

MAIN 				:= main.c
SRCS				=
UNIT_SRCS			=	unit_test.c


CC					:=	gcc
RM					:=	rm -rfv

CFLAGS				=	-Wall -Wextra -Werror $(if $(DEBUG), -g) \
					$(if $(FSAN), -fsanitize=address -g) \

SRC_DIR				:=	src/
BUILD_DIR			:=	build/
HEADERS_DIR			:=	include/
MAIN_OBJ			=	$(addprefix $(BUILD_DIR)/, $(MAIN:%.c=%.o))
OBJS				=	$(addprefix $(BUILD_DIR), $(SRCS:%.c=%.o))


UNIT_DIR			:=	unit_test/$(HEADERS_DIR)
UNIT_HEADERS		:=	$(UNIT_DIR)unit_test.h
HEADERS				:=	$(HEADERS_DIR)bowling_game.h
INCLUDE_FLAGS		:= $(addprefix -I, $(sort $(dir $(HEADERS))))


UNIT_TEST			:=	unit-test
UNIT_LFLAGS			:=	-lcriterion

UNIT_DIR			:= unit_test/
UNIT_SRCS_DIR		:=	$(UNIT_DIR)$(SRC_DIR)
UNIT_OBJS			=	$(UNIT_SRCS:.c=.o)
UNIT_INCLUDE_FLAGS	:=	$(addprefix -I, $(sort $(dir $(UNIT_HEADERS)))) $(INCLUDE_FLAGS)
COVERAGE			=	$(SRCS:.c=.gcda)	\
				$(SRCS:.c=.gcno)	\
				$(MAIN:.c=.gcda)	\
				$(MAIN:.c=.gcno)	\
				$(UNIT_SRCS:.c=.gcno)	\
				$(UNIT_SRCS:.c=.gcda)	\
################################################################################
all: $(NAME)

$(NAME): SHELL := /bin/bash

$(NAME): $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $^ $(INCLUDE_FLAGS) -o $(NAME)
	@printf "$(BLUE_FG)$(NAME)$(RESET_COLOR) created\n"

$(BUILD_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $(INCLUDES) -c $< -o $@

################################################################################

debug:
	@$(MAKE) DEBUG=1

fsan:
	@$(MAKE) FSAN=1

clean:
	$(RM) $(OBJS) $(MAIN_OBJ) $(UNIT_TEST_OBJS) $(COVERAGE)
	@$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	$(RM) $(NAME) $(UNIT_TEST)
	@$(MAKE) fclean -C $(LIB_DIR)

re: fclean
	$(MAKE)

env:
	export LIBRARY_PATH=/sgoinfre/criterion_test/.brew/lib:${LIBRARY_PATH}
	export C_INCLUDE_PATH=/sgoinfre/criterion_test/.brew/include:${C_INCLUDE_PATH}
tests_run: CFLAGS += --coverage
tests_run: $(OBJS) env
	$(CC) $(CFLAGS) $(OBJS) $(addprefix $(UNIT_SRCS_DIR), $(UNIT_SRCS)) -o $(UNIT_TEST) $(UNIT_INCLUDE_FLAGS) $(UNIT_LFLAGS)
	./$(UNIT_TEST) -j0

coverage:
	gcov $(SRCS)

re_tests: fclean
	$(MAKE) tests_run

.PHONY: all clean fclean re tests_run debug fsan coverage env
