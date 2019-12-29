OBJS = obj/MainWindow.o obj/cApp.o obj/Window.o obj/MainWindowToView.o obj/Player.o obj/Game.o 

CXXFLAGS = -Wall -std=c++11 `wx-config --cxxflags` -I "neulib/include" -I "include/"
LDLIBS   = `wx-config --libs` -L . "neulib/lib/main_lib.lib"

window: $(OBJS)
	g++ -o window  $(OBJS) $(CXXFLAGS) $(LDLIBS)  

obj/MainWindow.o: src/MainWindow.cpp include/MainWindow.h 
	g++ -c -o obj/MainWindow.o src/MainWindow.cpp $(CXXFLAGS)

obj/cApp.o: src/cApp.cpp include/cApp.h
	g++ -c -o obj/cApp.o src/cApp.cpp $(CXXFLAGS)

obj/Window.o: src/Window.cpp include/Window.h
	g++ -c -o obj/Window.o src/Window.cpp $(CXXFLAGS)

obj/MainWindowToView.o: src/MainWindowToView.cpp include/MainWindowToView.h
	g++ -c -o obj/MainWindowToView.o src/MainWindowToView.cpp $(CXXFLAGS)

obj/Player.o: src/Player.cpp include/Player.h
	g++ -c -o obj/Player.o src/Player.cpp $(CXXFLAGS)

obj/Game.o: src/Game.cpp include/Game.h
	g++ -c -o obj/Game.o src/Game.cpp $(CXXFLAGS)


clean:

	rm $(OBJS)
	rm window
