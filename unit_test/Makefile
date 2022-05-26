# **************************************************************************** #
#                                                                              #
#                                                     .--.  _                  #
#    Makefile                                           :+:    :+:             #
#                                                    |:_/ || |_ _   ___  __    #
#    By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    #
#                                                  (|     | )|_| |_| |>  <     #
#    Created: 2022/03/21 10:11:56 by safoh        /'\_   _/`\__|\__,_/_/\_\    #
#    Updated: 2022/04/11 16:05:58 by safoh        \___)=(___/                  #
#                                                                              #
# **************************************************************************** #

include	../makerc/utils.mk
include ../makerc/colours.mk
include ../makerc/srcs.mk
include	src/usrcs.mk

PROJECT		=	Unit-Test
NAME		:=	pushtest
PSWAP		=	push_swap

CC			=	gcc
RM			=	rm -rfv
CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
CRITERION	=	-lcriterion

OBJS		=	$(addprefix $(BUILD_DIR)/, $(USRCS:%.c= %.o))
POBJS		=	$(addprefix $(PBUILD_DIR)/, $(SRCS:%.c= %.o))
SRC_DIR		=	./src
PSRC_DIR	=	../src
BUILD_DIR	=	./build
PBUILD_DIR	=	../build

LIB_DIR		:=	../libs/libft
LIBFT		:=	$(LIB_DIR)/libft.a
HEADERS		=	$(LIB_DIR)/include/libft.h \
			../include/push_swap.h \
			./include/

INCLUDE_FLAGS	+= $(addprefix -I, $(sort $(dir $(HEADERS))))
LIB_FLAGS += $(addprefix -L, $(sort $(dir $(USER_LIBS))))

ifndef PROJECT_SPACING
	export PROJECT_SPACING := 11
endif
################################################################################
all: $(NAME)

$(NAME): SHELL := /bin/bash

$(NAME): $(OBJS) | $(PSWAP) $(LIBFT)
	@$(call print_prefix,"$(PROJECT)","make")
	$(CC) $(CFLAGS) $(CRITERION) $(POBJS) $(LIBFT) $^ $(INCLUDE_FLAGS) $(LIB_FLAGS) -o $(NAME)
	@$(call print_prefix,"$(PROJECT)","make")
	@printf "$(BLUE_FG)$(NAME)$(RESET_COLOR) created\n"

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(HEADERS)
	@mkdir -p $(dir $@)
	@$(call print_prefix,"$(PROJECT)","make")
	@$(call exec_no_nl,$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $(INCLUDES) -c $< -o $@)
	@printf "$(CLEAR_REST_OF_LINE)\r"

$(PSWAP):
	@$(MAKE) -C ..

clean:
	@$(call print_prefix,"$(PROJECT)","$@")
	$(RM) $(OBJS)
	@$(MAKE) clean -C ..

fclean: clean
	@$(call print_prefix,"$(PROJECT)","$@")
	$(RM) $(NAME)
	@$(MAKE) fclean -C ..

fsan:
	$(MAKE) FSAN=1

re: fclean all

.PHONY: all clean fclean re
################################################################################
