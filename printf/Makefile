# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 12:42:28 by aidgomez          #+#    #+#              #
#    Updated: 2022/12/07 12:42:28 by aidgomez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Declaración de variables:
# \---------------------------------------------------/
# Nombre del programa y header
NAME = ft_printf.a
HDRS = ft_printf.h

# Archivos de código fuente
SRC =  ft_printchar.c \
	ft_printdec.c \
	ft_printstr.c \
	ft_printf.c \
	ft_printhex.c \
	ft_printptr.c \

# Archivos de código objeto
OBJS = $(SRC:.c=.o)

# Flags de compilación
CFLAGS = -Wall -Werror -Wextra

# Comando de compilación
CC = gcc

# Remove si existen
RM = rm -f
# \----------------------------------------------------/

# Reglas:
# \---------------------------------------------------/
# ar: Herramienta que crea, manipula y administra archivos de una biblioteca
# -crs:
# c: Crea archivo si no existe
# r: Reemplaza o agrega archivos
# s: Actualiza el índice de símbolos

# Regla que genera los OBJS de SRC.
.c.o:
	@echo "Compilando..."
	$(CC) -c $(CFLAGS) $< -o $(<:.c=.o)

# Regla que compila el programa principal.
$(NAME):$(OBJS) $(HDRS)
	ar -crs $(NAME) $(OBJS)
	@echo "$(NAME) se ha generado!"

# Se ejecuta con el comando make y compila el archivo principal
all: $(NAME)

# Borra todos los archivos .o si los hubiese (-f)
clean:
	$(RM) *.o
	@echo "Archivos borrados"

# Borra todos los archivos y el programa
fclean: clean
	$(RM) $(NAME)
	@echo "$(NAME) borrado"

# Realiza un re-make (borra y hace make)
re: fclean all

# Indica que estos nombres no son archivos sino acciones
.PHONY: all clean fclean re
# \----------------------------------------------------/