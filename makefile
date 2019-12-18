OBJS = MainWindow.o cApp.o Window.o MainWindowToView.o Player.o Game.o

CXXFLAGS = -Wall -std=c++11 `wx-config --cxxflags`
LDLIBS   = `wx-config --libs`

window: $(OBJS)
	g++ -o window  $(OBJS) $(CXXFLAGS) $(LDLIBS)  

MainWindow.o: MainWindow.cpp MainWindow.h 
	g++ -c MainWindow.cpp $(CXXFLAGS)

cApp.o: cApp.cpp cApp.h
	g++ -c cApp.cpp $(CXXFLAGS)

Window.o: Window.cpp Window.h
	g++ -c Window.cpp $(CXXFLAGS)

MainWindowToView.o: MainWindowToView.cpp MainWindowToView.h
	g++ -c MainWindowToView.cpp $(CXXFLAGS)

Player.o: Player.cpp Player.h
	g++ -c Player.cpp $(CXXFLAGS)

Game.o: Game.cpp Game.h
	g++ -c Game.cpp $(CXXFLAGS)


clean:

	rm $(OBJS)
	rm window
