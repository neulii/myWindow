OBJS = MainWindow.o cApp.o

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

clean:

	rm $(OBJS)
	rm window
