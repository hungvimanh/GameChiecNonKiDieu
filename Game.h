#pragma once
#ifndef _GAME_H
#define _GAME_H
#include "File.h"

const char Answer[] = "file/answer.txt";
const char Question[] = "file/question.txt";

const int vong_quay[15] = { 5000,20000,0,100,500000,50000,1000,0,2000,10000,200,200000,0,500,100000 };
const int num_of_player = 3;
const int single = 1;

//Hàm game
void Game(SDL_Window* window, SDL_Renderer* renderer);

//Chế độ 1 người chơi
void Single_play(SDL_Window* window, SDL_Renderer* renderer, vector<SDL_Texture*> wheels);

//Chế độ 3 người chơi
void Multi_play(SDL_Window* window, SDL_Renderer* renderer, vector<SDL_Texture*> wheels);

#endif // !_GAME_H