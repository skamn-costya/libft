NAME = libft.a
CC = cc
PATH_C = ./
PATH_H = ./
PATH_GNL = ./gnl/
PATH_FT_PRINTF = ./ft_printf/

FUNCTIONS = \
ft_isalpha \
ft_isdigit \
ft_isalnum \
ft_isascii \
ft_isprint \
ft_strlen \
ft_memset \
ft_bzero \
ft_memcpy \
ft_memmove \
ft_strlcpy \
ft_strlcat \
ft_toupper \
ft_tolower \
ft_strchr \
ft_strrchr \
ft_strncmp \
ft_memchr \
ft_memcmp \
ft_strnstr \
ft_atoi \
ft_calloc \
ft_strdup \
\
ft_substr \
ft_strjoin \
ft_strtrim \
ft_split \
ft_itoa \
ft_strmapi \
ft_striteri \
ft_putchar_fd \
ft_putstr_fd \
ft_putendl_fd \
ft_putnbr_fd \
\
ft_lstnew \
ft_lstadd_front \
ft_lstsize \
ft_lstlast \
ft_lstadd_back \
ft_lstdelone \
ft_lstgetidx \
ft_lstclear \
ft_lstiter \
ft_lstmap \
\
ft_uitoa \
ft_checkbase \
ft_uitoa_base \
ft_ultoa_base \
ft_nbrlen \
ft_lstgetidx \
ft_abs \
ft_strcmp \
ft_strncat \
ft_strcat \
ft_isnumber \
ft_isxdigit \
ft_isxnumber \
ft_atol \
ft_pow \
ft_atof \
ft_strreplace \
\
ft_parrnew \
ft_parradd_front \
ft_parrsize \
ft_parrlast \
ft_parradd_back \
ft_parrdelone \
ft_parrgetidx \
ft_parrclear \
ft_parriter \
ft_parrmap \
\
ft_new_strcmp

FUNCTION_GNL = \
get_next_line \
get_next_line_utils

FUNCTION_FT_PRINTF = \
ft_printf \
ft_printf_c \
ft_printf_cnvspc \
ft_printf_di \
ft_printf_di_size \
ft_printf_p \
ft_printf_p_size \
ft_printf_s \
ft_printf_u \
ft_printf_u_size \
ft_printf_xxx

SOURCES = $(addprefix $(PATH_C), $(addsuffix .c, $(FUNCTIONS)))
OBJECTS = $(SOURCES:.c=.o)
SOURCES_GNL = $(addprefix $(PATH_GNL), $(addsuffix .c, $(FUNCTION_GNL)))
OBJECTS_GNL = $(SOURCES_GNL:.c=.o)
SOURCES_FT_PRINTF = $(addprefix $(PATH_FT_PRINTF), $(addsuffix .c, $(FUNCTION_FT_PRINTF)))
OBJECTS_FT_PRINTF = $(SOURCES_FT_PRINTF:.c=.o)

CCFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJECTS) $(OBJECTS_GNL) $(OBJECTS_FT_PRINTF)
	ar rcs $@ $^

all: $(NAME)

%.o: %.c
	$(CC) -g $(CCFLAGS) -I$(PATH_H) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(OBJECTS_GNL) $(OBJECTS_FT_PRINTF)

fclean: clean
	rm -f $(NAME)

re: fclean all
