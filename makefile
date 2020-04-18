cc = g++
objectFiles = Axis.o Canvas.o Color.o Controls.o Cube.o main.o Position.o Scene.o

Viszual: $(objectFiles)
	$(cc) -o ./win64/Viszual $(objectFiles) -L\"C:/dev/freeglut-mingw-3.0.0/lib/x64\" -lfreeglut -lglu32 $$(pkg-config --libs gtkmm-3.0 | sed 's/ -I/ -isystem /g')

%.o: %.cpp
	$(cc) -c $< -L\"C:/dev/freeglut-mingw-3.0.0/include\" $$(pkg-config --cflags gtkmm-3.0) -Wall -std=c++2a