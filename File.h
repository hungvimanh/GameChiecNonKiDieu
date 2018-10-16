#pragma once
#include "SetupGame.h"

//Đổi chỗ
void swap_score(PLAYER &, PLAYER &);

//Sắp xếp
void arrange(vector<PLAYER> &);

//Ghi điểm vào file
void scoreFile(int hightScore, string fileName);

//In điểm từ file vào renderer
void highScore(SDL_Renderer* renderer, const std::string &file, int pos);

//Sinh số ngẫu nhiên từ số lượng câu hỏi
int randomIndex(const char* fileName1);

//Đọc câu hỏi/đáp án từ file
string readFile(const char* fileName, int randNum);