# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lvan-bus <lvan-bus@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/24 13:17:24 by lvan-bus      #+#    #+#                  #
#    Updated: 2023/05/24 13:17:26 by lvan-bus      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include makerc/colors.mk

################################################################################

NAME			:= first
UNIT_OUT		:= test.out
BUILD_DIR		:= build
INCLUDE_DIR		:= include
RM				:= rm -rvf

HEADERS			= $(INCLUDE_DIR)/Fixed.hpp
CC				= c++

################################################################################

CFLAGS			= -Wall -Wextra -Werror -Wpedantic -std=c++98 -std=c++11
INCLUDE_FLAGS	:= $(addprefix -I, $(sort $(dir $(HEADERS))))
CRIT_FLAG		= -lcriterion

ifdef	DEBUG
	CFLAGS		+=-g
endif

ifdef	FSAN
	CFLAGS		+=-fsanitize=address,undefined
endif

################################################################################

# Source files
SRC = \
  src/main.cpp \
  src/Fixed.cpp

TEST_SRC =

UNIT_SRC =

################################################################################

# Object files
OBJS       = $(addprefix $(BUILD_DIR)/, $(SRC:%.cpp=%.o))
#MAIN_OBJ   = $(addprefix $(BUILD_DIR)/, $(MAIN:%.c=%.o))

################################################################################

# Include directories
INC_UNIT = -I/Users/lucienvanbussel/.brew/cellar/criterion/2.4.1_2/include

# Criterion library
LIB_UNIT = -L/Users/lucienvanbussel/.brew/cellar/criterion/2.4.1_2/lib

################################################################################

all: $(NAME)

unit_test: $(UNIT_OUT) all
.PHONY: unit_test

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ $(INCLUDE_FLAGS) -o $(NAME)
	@printf "$(BLUE_FG)$(NAME)$(RESET_COLOR) created\n"

$(OBJS): $(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

################################################################################

$(UNIT_OUT):
	$(CC) $(CFLAGS) $(CRIT_FLAG) $(INCLUDE_FLAGS) $(INC_UNIT) $(LIB_UNIT) $(TEST_SRC) $(UNIT_SRC) -o $(UNIT_OUT)
	@printf "$(BLUE_FG)$(UNIT_OUT)$(RESET_COLOR) created\n"

test:
	@$(MAKE) DEBUG=1 FSAN=1 unit_test
	@./$(UNIT_OUT)
.PHONY: test

retest: fclean test
.PHONY: retest

uclean:
	@$(RM) test.* unit_test/include/*.gch

clean:
	@$(RM) $(OBJS) $(MAIN_OBJ)

debug:
	$(MAKE) DEBUG=1
.PHONY: debug

rebug: fclean debug
.PHONY: rebug

fsan:
	$(MAKE) DEBUG=1 FSAN=1
.PHONY: debug

resan: fclean fsan
.PHONY: resan

fclean: clean

re: fclean all

.PHONY: all clean fclean re