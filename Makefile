all: compile link run

compile: 
	g++ -c main.cpp -I"C:\Users\Kristo\Documents\libraries\SFML-3.0.0-windows-gcc-14.2.0-mingw-64-bit\SFML-3.0.0\include" -DSFML_STATIC 

link:
	g++ main.o -o main -L"C:\Users\Kristo\Documents\libraries\SFML-3.0.0-windows-gcc-14.2.0-mingw-64-bit\SFML-3.0.0\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows

run: 
	./main

clean: 
	rm -f main.exe *.o

# tutorial: https://youtu.be/rZE700aaT5I?si=yLV3sfS8Y2Zy7RzE