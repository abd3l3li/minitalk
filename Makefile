# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 11:40:25 by abel-baz          #+#    #+#              #
#    Updated: 2024/01/25 13:18:18 by abel-baz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CNAME = client
SNAME = server
CNAME_BONUS = client_bonus
SNAME_BONUS = server_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

CSRC = client.c
SSRC = server.c
BCSRC = client_bonus.c
BSSRC = server_bonus.c

OBJS_CSRC = ${CSRC:.c=.o}
OBJS_SSRC = ${SSRC:.c=.o}
OBJS_BCSRC = ${BCSRC:.c=.o}
OBJS_BSSRC = ${BSSRC:.c=.o}

all: ${CNAME} ${SNAME}

${CNAME}: ${OBJS_CSRC}
	${CC} ${CFLAGS} ${OBJS_CSRC} -o ${CNAME}

${SNAME}: ${OBJS_SSRC}
	${CC} ${CFLAGS} ${OBJS_SSRC} -o ${SNAME}

bonus: ${CNAME_BONUS} ${SNAME_BONUS}

${CNAME_BONUS}: ${OBJS_BCSRC}
	${CC} ${CFLAGS} ${OBJS_BCSRC} -o ${CNAME_BONUS}

${SNAME_BONUS}: ${OBJS_BSSRC}
	${CC} ${CFLAGS} ${OBJS_BSSRC} -o ${SNAME_BONUS}

clean:
	${RM} ${OBJS_CSRC} ${OBJS_SSRC} ${OBJS_BCSRC} ${OBJS_BSSRC}

fclean: clean
	${RM} ${CNAME} ${SNAME} ${CNAME_BONUS} ${SNAME_BONUS}

re: fclean all

.PHONY : all bonus clean fclean re
