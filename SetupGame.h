#pragma once
#ifndef _SETUPGAME_H
#define _SETUPGAME_H
#include "SDL_utils.h"

const struct Toado {
	int x;
	int y;
};

typedef struct Player {
	int score;
}PLAYER;

//Vẽ ô chữ
void Draw(const string& word, SDL_Renderer* renderer);

//Upper case
string getUpperCaseString(const string& s);

//Đoán chữ cái
char readGuess(SDL_Renderer* renderer, string guessedWord, vector<char> &guessed);

//Kiểm tra chữ cái được đoán có trong đáp án hay không
bool contains(const string& word, char guess);

//Kiểm tra chữ cái được đoán đã được đoán trước đó hay không
bool check(char guess, vector<char> guessed);

//Đếm chữ cái được đoán có trong đáp án
int count_guess(string word, char guess);

//Bù khoảng trắng vào đáp án
string update_space(const string& word, string guessedWord);

//Cập nhật đáp án
string update(const string& word, string guessedWord, char guess, SDL_Renderer* renderer);

//Vòng quay
int Rotation(vector<SDL_Texture*> wheels, SDL_Renderer* renderer, bool running);

//In điểm
void renderScore(SDL_Renderer* renderer, vector<PLAYER> &player, int flag, int pos);

#endif // !_SETUPGAME_H