# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 17:43:31 by aidgomez          #+#    #+#              #
#    Updated: 2023/08/08 17:43:31 by aidgomez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# Declaración de variables:
# \---------------------------------------------------/
# Nombre del programa
NAME_C = client
NAME_S = server
NAME_CBONUS = client_bonus
NAME_SBONUS = server_bonus

# Archivos de código fuente
SRC_C = client.c
SRC_S = server.c

# Archivos de código fuente BONUS
SRC_CBONUS = client_bonus.c
SRC_SBONUS = server_bonus.c

# Archivos de código objeto
OBJS_C = $(SRC_C:.c=.o)
OBJS_S = $(SRC_S:.c=.o)

# Archivos de código objeto BONUS
OBJS_CBONUS = $(SRC_CBONUS:.c=.o)
OBJS_SBONUS = $(SRC_SBONUS:.c=.o)

# Ruta librería PRINTF
PRINTF_PATH = printf/ft_printf.a

# Flags de compilación
CFLAGS = -Wall -Werror -Wextra

# Comando de compilación
CC = gcc

# Remove si existen
RM = rm -f
# \----------------------------------------------------/

# Reglas:
# \---------------------------------------------------/
# $@: Representa el objeto (NAME)
# $^: Representa todas las dependencias (archivos objeto)
# $<: Representa la primera dependencia en la regla (archivo fuente .c que se está compliando)
# -o $(<:.c=.o): Nombre del archivo objeto después de la compilación
# -C: Cambiar el directorio
# -c: Compila el archivo fuente y generar el objeto, sin realizar la etapa de enlace.

# Se ejecuta con el comando make y compila el archivo principal
all: $(NAME_C) $(NAME_S)

# Regla que genera los OBJS de SRC.
.c.o:
	@echo "Compilando..."
	$(CC) -c $(CFLAGS) $< -o $@

# Regla que compila el programa principal y genera el objeto binario (ejecutable).
$(NAME_C): $(PRINTF_PATH) $(OBJS_C)
	$(CC) $(CFLAGS) $(OBJS_C) $(PRINTF_PATH) -o $@
	@echo "$@ se ha generado!"

$(NAME_S): $(PRINTF_PATH) $(OBJS_S)
	$(CC) $(CFLAGS) $(OBJS_S) $(PRINTF_PATH) -o $@
	@echo "$@ se ha generado!"

$(NAME_CBONUS): $(PRINTF_PATH) $(OBJS_CBONUS)
	$(CC) $(CFLAGS) $(OBJS_CBONUS) $(PRINTF_PATH) -o $@
	@echo "$@ se ha generado!"

$(NAME_SBONUS): $(PRINTF_PATH) $(OBJS_SBONUS)
	$(CC) $(CFLAGS) $(OBJS_SBONUS) $(PRINTF_PATH) -o $@
	@echo "$@ se ha generado!"

# Borra todos los archivos .o si los hubiese (-f)
clean:
	$(RM) *.o
	make -C printf clean

# Borra todos los archivos y el programa
fclean: clean
	$(RM) $(PRINTF_PATH) $(NAME_C) $(NAME_S) $(NAME_CBONUS) $(NAME_SBONUS)
	@echo "Archivos borrados"

# Realiza un re-make (borra y hace make)
re: fclean all

bonus: $(NAME_CBONUS) $(NAME_SBONUS)

$(PRINTF_PATH):
	make -C printf all

# Indica que estos nombres no son archivos sino acciones
.PHONY: all clean fclean re bonus
# \----------------------------------------------------/
