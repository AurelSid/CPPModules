# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roko <roko@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 14:51:00 by roko              #+#    #+#              #
#    Updated: 2024/11/11 17:30:51 by roko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17

# Executable name
TARGET = my_program

# Source files and object files
SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets to avoid conflicts
.PHONY: all clean



