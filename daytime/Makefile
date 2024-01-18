.PHONY: all clean
# Имя компилятора
CXX = g++

# Флаги компилятора
CXXFLAGS = -Wall 

# Имя исполняемого файла
TARGET = daytime

# Исходные файлы
SOURCES = main.cpp

# Объектные файлы
OBJECTS = $(SOURCES:.cpp=.o)

# Зависимости на заголовочные файлы
DEPS = base.h ui.h communicator.h logger.h

# Цель по умолчанию
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(CXXFLAGS) -o $(TARGET) 

clean:
	rm -f $(OBJECTS) $(TARGET)