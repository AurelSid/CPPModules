# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roko <roko@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 14:51:00 by roko              #+#    #+#              #
#    Updated: 2025/03/16 20:09:04 by roko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = my_program

SRCS = src/main.cpp  src/AForm.cpp src/Bureaucrat.cpp src/PresidentialPardonForm.cpp \
		src/RobotomyRequestForm.cpp src/ShrubberyCreationForm.cpp  src/Intern.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) && rm example.txt

re: clean all

.PHONY: all clean re