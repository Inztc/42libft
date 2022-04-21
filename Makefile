# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btiewcha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 03:25:41 by btiewcha          #+#    #+#              #
#    Updated: 2022/04/21 00:57:33 by btiewcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS                          = -Wall -Wextra -Werror

NAME                            = libft.a

SRCS                            = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
				  ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				  ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
				  ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_striteri.c ft_substr.c

OBJS                            = $(SRCS:.c=.o)

BONUS                           = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
				  ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJS                      = $(BONUS:.c=.o)

all:				$(NAME)

$(NAME):			$(OBJS)
				@gcc $(CFLAGS) -c $(SRCS)
				ar -rcs $(NAME) $(OBJS)

bonus:				$(OBJS) $(BONUS_OBJS)
				@gcc $(CFLAGS) -c $(BONUS)
				ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	        
clean:                          
				@rm -f $(OBJS) $(BONUS_OBJS)

fclean:                         clean
				@rm -f $(NAME)

re:				fclean all

.PHONY: NAME all clean fclean re bonus
