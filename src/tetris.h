#ifndef TETRIS_H
#define TETRIS_H

#define TET_TICKS_START 30

// blocks are drawn in a square of some size
// b variable shows if block exists in this square or not
typedef struct TetBlock {
	int b;	
} TetBlock;

// Representation of the current (falling) figure
typedef struct TetFigure {
	int x; // current coordinates
	int y; // of the falling figure
	int size; // size of the square in which the figure is drawn
	TetBlock* blocks; // what blocks this figure consists of? (could be just an array of bools)
} TetFigure;

typedef struct TetFiguresT {
	int count; // number of figures in the game
	int size; // size of the square figure field
	TetBlock* blocks; // info about all blocks structure
} TetFiguresT;

// game playing field info
typedef struct TetField {
	int width;
	int height;
	TetBlock* blocks; // array of blocks
} TetField;

enum {
	TET_GAMEOVER = 0,
	TET_PLAYING,
};

enum {
	TET_PLAYER_NOP = 0,
	TET_PLAYER_UP,
	TET_PLAYER_DOWN,
	TET_PLAYER_LEFT,
	TET_PLAYER_RIGHT,
	};

	typedef struct TetPlayer {
		int action;
	} TetPlayer;

// define the structure TetGame
// and create an alias TetGame for struct TetGame
typedef struct TetGame {
	TetField* field; // playing field info (blocks)
	TetFigure* figure; // current figure (one that is falling)
	TetFiguresT* figurest; // figure types

	TetPlayer* player;

	int ticks;
	int ticks_left;
	int playing;
	int score;
} TetGame;

/** @brief Initializes main game structure **/
TetGame* createTetGame(int field_width, int field_height, int figure_size, int count, 
	TetBlock* figures_template);

/** @brief Procedure calculating one game measure (tact) **/
void calculateTet(TetGame* tetg);



TetFiguresT* createTetFiguresT(int count, int figures_size, 
TetBlock* figures_template);

void freeTetFiguresT(TetFiguresT* tetft);

TetField* createTetField(int width, int height);

void freeTetField(TetField* tetf);

TetGame* createTetGame(int field_width, int field_height, 
	int figure_size, int count, TetBlock* figures_template);

void freeTetGame(TetGame* tetg);

void moveFigureUp(TetGame* tetg);

void moveFigureDown(TetGame* tetg);

void moveFigureLeft(TetGame* tetg);

void moveFigureRight(TetGame* tetg);

int collisionTet(TetGame* tetg);

void plantFigure(TetGame* tetg);

int lineFilledTet(int i, TetField* tfl);

void dropLineTet(int i, TetField* tfl);

int eraseLinesTet(TetGame* tetg);

TetFigure* createTetFigure(TetGame* tetg);

void freeTetFigure(TetFigure* t);

void dropNewFigure(TetGame* tetg);

TetFigure* rotTetFigure(TetGame* tetg);

void calculateTet(TetGame* tetg);

#endif
