# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:      :+:    :+:    #
#                                                      +:+                     #
#    By: saladuit <safoh@student.codam.nl>            +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/13 21:33:38 by saladuit      #+#    #+#                  #
#    Updated: 2022/05/26 15:37:42 by safoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include makerc/main.mk
include makerc/srcs.mk
include makerc/colours.mk
include makerc/unit_test.mk
include makerc/headers.mk

PROJECT			:=	Unit-Battle
NAME			:=	bowling_game

CC				:=	gcc
RM				:=	rm -rfv
CFLAGS			=	-Wall -Wextra -Werror $(if $(DEBUG), -g) \
					$(if $(FSAN), -fsanitize=address -g) \
					$(if $(COV), -g --coverage)

SRC_DIR			:=	./src
BUILD_DIR		:=	./build
OBJS			=	$(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))
MAIN_OBJ		=	$(addprefix $(BUILD_DIR)/, $(MAIN:%.c=%.o))


INCLUDE_FLAGS	:= $(addprefix -I, $(sort $(dir $(HEADERS))))

UNIT_TEST		:=	unit-test
UNIT_DIR		:= ./unit_test
UNIT_SRCS_DIR	:=	$(UNIT_DIR)/src/

UNIT_LFLAGS		:=	-lcriterion
UNIT_OBJS		=	$(UNIT_SRCS:.c=.o)
UNIT_INCLUDE_FLAGS	:= $(addprefix -I, $(sort $(dir $(UNIT_HEADERS)))) $(INCLUDE_FLAGS)
 COVERAGE	=	$(SRCS:.c=.gcda)	\
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

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
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

tests_run:
	export LIBRARY_PATH="${PWD}/criterion:${LIBRARY_PATH}"
	$(MAKE) COV=1
	$(CC) $(CFLAGS) $(OBJS) $(addprefix $(UNIT_SRCS_DIR)/, $(UNIT_SRCS)) -o $(UNIT_TEST) $(UNIT_INCLUDE_FLAGS) $(UNIT_LFLAGS)
	./$(UNIT_TEST) -j0

coverage:
	gcov $(SRCS)

re_tests: fclean
	$(MAKE) tests_run

.PHONY: all clean fclean re tests_run debug fsan coverage
