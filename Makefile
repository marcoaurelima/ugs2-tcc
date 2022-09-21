INCLUDE = ./include
SRC = ./src
LIB = ./lib
OBJ = ./obj
 
CXX = g++ -Wall -fexceptions -O2 -DSFML_STATIC
SFML = -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-network-s -lsfml-system-s 
DEPEND = -lgdi32 -lopengl32 -lfreetype -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg -lws2_32 -lwinmm 

OBJS =  $(OBJ)/main.o \
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
	g++.exe -L $(LIB) -o ugs2-tcc.exe $(OBJS) -s $(SFML) $(DEPEND)
	ugs2-tcc.exe

$(OBJ)/main.o: main.cpp
	$(CXX) -I $(INCLUDE) -c main.cpp -o $(OBJ)/main.o 

$(OBJ)/UGSfunctions.o: $(SRC)/UGSfunctions.cpp
	$(CXX) -I $(INCLUDE) -c $(SRC)/UGSfunctions.cpp -o $(OBJ)/UGSfunctions.o

$(OBJ)/UGSGameMajor.o: $(SRC)/UGSGameMajor.cpp
	$(CXX) -I $(INCLUDE) -c $(SRC)/UGSGameMajor.cpp -o $(OBJ)/UGSGameMajor.o

$(OBJ)/UGSLeftButtonsMenuMain.o: $(SRC)/UGSLeftButtonsMenuMain.cpp
	$(CXX) -I $(INCLUDE) -c $(SRC)/UGSLeftButtonsMenuMain.cpp -o $(OBJ)/UGSLeftButtonsMenuMain.o

$(OBJ)/UGSMat.o: $(SRC)/UGSMat.cpp
	$(CXX) -I $(INCLUDE) -c $(SRC)/UGSMat.cpp -o $(OBJ)/UGSMat.o

$(OBJ)/UGSMenuMain.o: $(SRC)/UGSMenuMain.cpp
	$(CXX) -I $(INCLUDE) -c $(SRC)/UGSMenuMain.cpp -o $(OBJ)/UGSMenuMain.o

$(OBJ)/UGSMenuMainCards.o: $(SRC)/UGSMenuMainCards.cpp
	$(CXX) -I $(INCLUDE) -c $(SRC)/UGSMenuMainCards.cpp -o $(OBJ)/UGSMenuMainCards.o

$(OBJ)/UGSMenuMainDetails.o: $(SRC)/UGSMenuMainDetails.cpp
	$(CXX) -I $(INCLUDE) -c $(SRC)/UGSMenuMainDetails.cpp -o $(OBJ)/UGSMenuMainDetails.o

$(OBJ)/UGSMenuMainNovoJogo.o: $(SRC)/UGSMenuMainNovoJogo.cpp
	$(CXX) -I $(INCLUDE) -c $(SRC)/UGSMenuMainNovoJogo.cpp -o $(OBJ)/UGSMenuMainNovoJogo.o

$(OBJ)/UGSMenuMainNovoJogoStep2.o: $(SRC)/UGSMenuMainNovoJogoStep2.cpp
	$(CXX) -I $(INCLUDE) -c $(SRC)/UGSMenuMainNovoJogoStep2.cpp -o $(OBJ)/UGSMenuMainNovoJogoStep2.o

$(OBJ)/UGSMusicPlayer.o: $(SRC)/UGSMusicPlayer.cpp
	$(CXX) -I $(INCLUDE) -c $(SRC)/UGSMusicPlayer.cpp -o $(OBJ)/UGSMusicPlayer.o

$(OBJ)/UGSNotasConsecutivas.o: $(SRC)/UGSNotasConsecutivas.cpp
	$(CXX) -I $(INCLUDE) -c $(SRC)/UGSNotasConsecutivas.cpp -o $(OBJ)/UGSNotasConsecutivas.o

$(OBJ)/UGSRock.o: $(SRC)/UGSRock.cpp
	$(CXX) -I $(INCLUDE) -c $(SRC)/UGSRock.cpp -o $(OBJ)/UGSRock.o

$(OBJ)/UGSScoreMajor.o: $(SRC)/UGSScoreMajor.cpp
	$(CXX) -I $(INCLUDE) -c $(SRC)/UGSScoreMajor.cpp -o $(OBJ)/UGSScoreMajor.o

$(OBJ)/UGSScoreMinor.o: $(SRC)/UGSScoreMinor.cpp
	$(CXX) -I $(INCLUDE) -c $(SRC)/UGSScoreMinor.cpp -o $(OBJ)/UGSScoreMinor.o

$(OBJ)/UGSScreenGame.o: $(SRC)/UGSScreenGame.cpp
	$(CXX) -I $(INCLUDE) -c $(SRC)/UGSScreenGame.cpp -o $(OBJ)/UGSScreenGame.o

$(OBJ)/UGSTile.o: $(SRC)/UGSTile.cpp
	$(CXX) -I $(INCLUDE) -c $(SRC)/UGSTile.cpp -o $(OBJ)/UGSTile.o

clean:
	rmdir /s obj 
	mkdir obj

run:
	ugs2-tcc.exe



