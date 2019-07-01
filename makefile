all : final

final: main.o Hallway.o Elevator.o Bar.o HotelRoom.o inputVal.o Kitchen.o Lobby.o Player.o Space.o startGame.o
	g++ -std=c++11 main.o Hallway.o Elevator.o Bar.o HotelRoom.o inputVal.o Kitchen.o Lobby.o Player.o Space.o startGame.o -o final

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Hallway.o: Hallway.hpp Hallway.cpp
	g++ -std=c++11 -c Hallway.cpp

Elevator.o: Elevator.hpp Elevator.cpp
	g++ -std=c++11 -c Elevator.cpp

Bar.o: Bar.hpp Bar.cpp
	g++ -std=c++11 -c Bar.cpp

HotelRoom.o: HotelRoom.hpp HotelRoom.cpp
	g++ -std=c++11 -c HotelRoom.cpp

inputVal.o: inputVal.hpp inputVal.cpp
	g++ -std=c++11 -c inputVal.cpp

Kitchen.o: Kitchen.hpp Kitchen.cpp
	g++ -std=c++11 -c Kitchen.cpp

Lobby.o: Lobby.hpp Lobby.cpp
	g++ -std=c++11 -c Lobby.cpp

Player.o: Player.hpp Player.cpp
	g++ -std=c++11 -c Player.cpp

Space.o: Space.hpp Space.cpp
	g++ -std=c++11 -c Space.cpp

startGame.o: startGame.hpp startGame.cpp
	g++ -std=c++11 -c startGame.cpp

clean:
	rm *o final
