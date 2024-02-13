# NAME
# **************************************************************************** #
BINARY				= btc

# FILES
# **************************************************************************** #
SRCS				= main.cpp \
					BitcoinExchange.cpp

OBJS				=${addprefix ${OBJS_DIR}, ${SRCS:.cpp=.o}}
DEPS				=${addprefix ${OBJS_DIR}, ${SRCS:.cpp=.d}}

# DIRECTORY
# **************************************************************************** #
OBJS_DIR			= objs/
SRCS_DIR			= 

# COMPILATION
# **************************************************************************** #
LINK				= c++
CC					= c++ -c
DEPFLAGS			= -MMD -MP
CFLAGS				= -Wall -Wextra -Werror -std=c++98
RM					= rm -rf

# RULES
# **************************************************************************** #
all:	$(BINARY)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.cpp
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) $< -o $@

$(BINARY): $(OBJS)
					$(LINK) $(CFLAGS) $(INCLUDE) -o $@ $^ $(LIBS)

clean:
					@$(RM) $(OBJS_DIR)

fclean: clean
					@$(RM) $(BINARY)

re: fclean all

-include ${DEPS}

.PHONY: all bonus clean fclean re