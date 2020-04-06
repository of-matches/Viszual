SHELL = bash

cc = g++
objectFiles = Axis.o Canvas.o Color.o Cube.o main.o Position.o Scene.o

Viszual: $(objectFiles)
	$(cc) -o ./win64/Viszual $(objectFiles) -L\"C:/dev/freeglut-mingw-3.0.0/lib/x64\" -lfreeglut -lglu32 -lopengl32 $$(pkg-config --libs gtk+-3.0)

%.o: %.cpp
	$(cc) -c $< -L\"C:/dev/freeglut-mingw-3.0.0/include\" $$(pkg-config --cflags gtk+-3.0)