INCLUDE = ./include
SRC = ./src
BIN = ./bin
OBJ = ./obj
 
CXX = g++ -std=c++11
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

OBJS =  main.o \
	    $(OBJ)/UGSfunctions.o \
	    $(OBJ)/UGSGameMajor.o \
		$(OBJ)/UGSLeftButtonsMenuMain.o \
		$(OBJ)/UGSMat.o \
		$(OBJ)/UGSMenuMain.o \
		$(OBJ)/UGSMenuMainCards.o \
		$(OBJ)/UGSMenuMainDetails.o \
		$(OBJ)/UGSMenuMainNovoJogo.o \
		$(OBJ)/UGSMenuMainNovoJogoStep2.o \
		$(OBJ)/UGSMusicPlayer.o \
		$(OBJ)/UGSNotasConsecutivas.o \
		$(OBJ)/UGSRock.o \
		$(OBJ)/UGSScoreMajor.o \
		$(OBJ)/UGSScoreMinor.o \
		$(OBJ)/UGSScreenGame.o \
		$(OBJ)/UGSTile.o

all: $(OBJS) 
	$(CXX) -o $(BIN)/ugs2 -I $(INCLUDE) $(OBJS) $(SFML)
	@$(BIN)/ugs2

main.o: main.cpp
	$(CXX) -c main.cpp -I $(INCLUDE) -o main.o $(SFML)

$(OBJ)/UGSfunctions.o: $(SRC)/UGSfunctions.cpp
	$(CXX) -c $(SRC)/UGSfunctions.cpp -I $(INCLUDE) -o $(OBJ)/UGSfunctions.o $(SFML)

$(OBJ)/UGSGameMajor.o: $(SRC)/UGSGameMajor.cpp
	$(CXX) -c $(SRC)/UGSGameMajor.cpp -I $(INCLUDE) -o $(OBJ)/UGSGameMajor.o $(SFML)

$(OBJ)/UGSLeftButtonsMenuMain.o: $(SRC)/UGSLeftButtonsMenuMain.cpp
	$(CXX) -c $(SRC)/UGSLeftButtonsMenuMain.cpp -I $(INCLUDE) -o $(OBJ)/UGSLeftButtonsMenuMain.o $(SFML)

$(OBJ)/UGSMat.o: $(SRC)/UGSMat.cpp
	$(CXX) -c $(SRC)/UGSMat.cpp -I $(INCLUDE) -o $(OBJ)/UGSMat.o $(SFML)

$(OBJ)/UGSMenuMain.o: $(SRC)/UGSMenuMain.cpp
	$(CXX) -c $(SRC)/UGSMenuMain.cpp -I $(INCLUDE) -o $(OBJ)/UGSMenuMain.o $(SFML)

$(OBJ)/UGSMenuMainCards.o: $(SRC)/UGSMenuMainCards.cpp
	$(CXX) -c $(SRC)/UGSMenuMainCards.cpp -I $(INCLUDE) -o $(OBJ)/UGSMenuMainCards.o $(SFML)

$(OBJ)/UGSMenuMainDetails.o: $(SRC)/UGSMenuMainDetails.cpp
	$(CXX) -c $(SRC)/UGSMenuMainDetails.cpp -I $(INCLUDE) -o $(OBJ)/UGSMenuMainDetails.o $(SFML)

$(OBJ)/UGSMenuMainNovoJogo.o: $(SRC)/UGSMenuMainNovoJogo.cpp
	$(CXX) -c $(SRC)/UGSMenuMainNovoJogo.cpp -I $(INCLUDE) -o $(OBJ)/UGSMenuMainNovoJogo.o $(SFML)

$(OBJ)/UGSMenuMainNovoJogoStep2.o: $(SRC)/UGSMenuMainNovoJogoStep2.cpp
	$(CXX) -c $(SRC)/UGSMenuMainNovoJogoStep2.cpp -I $(INCLUDE) -o $(OBJ)/UGSMenuMainNovoJogoStep2.o $(SFML)

$(OBJ)/UGSMusicPlayer.o: $(SRC)/UGSMusicPlayer.cpp
	$(CXX) -c $(SRC)/UGSMusicPlayer.cpp -I $(INCLUDE) -o $(OBJ)/UGSMusicPlayer.o $(SFML)

$(OBJ)/UGSNotasConsecutivas.o: $(SRC)/UGSNotasConsecutivas.cpp
	$(CXX) -c $(SRC)/UGSNotasConsecutivas.cpp -I $(INCLUDE) -o $(OBJ)/UGSNotasConsecutivas.o $(SFML)

$(OBJ)/UGSRock.o: $(SRC)/UGSRock.cpp
	$(CXX) -c $(SRC)/UGSRock.cpp -I $(INCLUDE) -o $(OBJ)/UGSRock.o $(SFML)

$(OBJ)/UGSScoreMajor.o: $(SRC)/UGSScoreMajor.cpp
	$(CXX) -c $(SRC)/UGSScoreMajor.cpp -I $(INCLUDE) -o $(OBJ)/UGSScoreMajor.o $(SFML)

$(OBJ)/UGSScoreMinor.o: $(SRC)/UGSScoreMinor.cpp
	$(CXX) -c $(SRC)/UGSScoreMinor.cpp -I $(INCLUDE) -o $(OBJ)/UGSScoreMinor.o $(SFML)

$(OBJ)/UGSScreenGame.o: $(SRC)/UGSScreenGame.cpp
	$(CXX) -c $(SRC)/UGSScreenGame.cpp -I $(INCLUDE) -o $(OBJ)/UGSScreenGame.o $(SFML)

$(OBJ)/UGSTile.o: $(SRC)/UGSTile.cpp
	$(CXX) -c $(SRC)/UGSTile.cpp -I $(INCLUDE) -o $(OBJ)/UGSTile.o $(SFML)

clean:
	rm -rf ./obj/*.o

run:
	./bin/ugs2



