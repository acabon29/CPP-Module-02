###############    variables    ###############

CXX = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98 -I./includes -I./libs -Ofast

SRC_DIR = ./srcs
OBJS_DIR = ./objs
OUTPUT_DIR ?= .
NAME ?= NowWeCanTalk

###############    Files    ###############

SRC_GENERAL =	main \
				Fixed \

SRC	= $(addprefix $(SRC_DIR)/, $(addsuffix .cpp,	$(SRC_GENERAL) \
))

OBJS	:= $(patsubst $(SRC_DIR)/%.cpp, $(OBJS_DIR)/%.o, $(SRC))

###############    Compilation    ###############
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) -o $(OUTPUT_DIR)/$(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CFLAGS) -o $@ -c $<



###############    Cleaning    ###############
clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)

###############    Re    ###############
re: fclean all