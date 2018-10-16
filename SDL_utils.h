#pragma once
#ifndef SDL_UTILS_H
#define SDL_UTILS_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>
#include <conio.h>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
using namespace std;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const char WINDOW_TITLE[] = "Chiec Non Ki Dieu";

//Khởi tạo SDL
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer,
	int screenWidth, int screenHeight, const char* windowTitle);

//Thoát 
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

// Load ảnh lên texture
SDL_Texture* LoadTexture(const std::string &str, SDL_Renderer *ren);

// Vẽ texture tại toạ độ (x,y), giữ nguyên kích cỡ 
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);

// Vẽ texture tại toạ độ (x,y), với kích cỡ w,h mới 
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);

// Dùng SDL_ttf viết chữ lên renderer tại toạ độ _x, _y, màu R G B và cỡ chữ
void writeText(SDL_Renderer* renderer, string text,int _x, int _y, Uint8 R, Uint8 G, Uint8 B, int size, const char* _font);

#endif // SDL_UTILS_H