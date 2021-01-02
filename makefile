cCompiler = g++
compilerFlags = -std=c++20 -Wpedantic -Wall -Wextra -fanalyzer -Wanalyzer-too-complex
objectFiles = Axis.o Canvas.o Color.o Controls.o Cube.o main.o Position.o Scene.o

Viszual: $(objectFiles)
	$(cCompiler) -o ./linux/Viszual $(objectFiles) `pkg-config gtkmm-3.0 --libs` -lGL -lGLU -lglut -lpthread

%.o: %.cpp
	$(cCompiler) -c $< -g3 `pkg-config gtkmm-3.0 --cflags` -I/usr/include/GL $(compilerFlags)