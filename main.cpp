#include "Game.h"
int main(int argc, char* argv[])
{
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
	
	SDL_Texture *background = LoadTexture("art/menu.jpg", renderer);
	
	//Xoá màn hình
	SDL_RenderClear(renderer);
	renderTexture(background, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_RenderPresent(renderer);
	
	SDL_Event e;
	while (SDL_WaitEvent(&e)) {
		if (e.type == SDL_QUIT) {
			quitSDL(window, renderer);
		}
		if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
			if (e.motion.x >= 400 && e.motion.x <= 900 && e.motion.y >= 350 && e.motion.y <= 410) {	//Bắt đầu
				Game(window, renderer);	
			}

			if (e.motion.x >= 400 && e.motion.x <= 900 && e.motion.y >= 450 && e.motion.y <= 505) {  //Điểm cao
				SDL_Texture* highscore = LoadTexture("art/highscore.jpg", renderer);
				renderTexture(highscore, renderer, 0, 0);
				highScore(renderer, "file/highScore_single.txt", 345);
				highScore(renderer,"file/highScore_multi.txt",790);
				SDL_RenderPresent(renderer);
				SDL_Event temp;
				while (SDL_WaitEvent(&temp)) {
					if (temp.type == SDL_QUIT) {
						quitSDL(window, renderer);
					}
					if (temp.type == SDL_MOUSEBUTTONDOWN && temp.button.button == SDL_BUTTON_LEFT) {
						if (temp.motion.x >= 50 && temp.motion.x <= 190 && temp.motion.y >= 600 && temp.motion.y <= 650) {
							renderTexture(background, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
							SDL_RenderPresent(renderer);
							break;
						}
					}
				}
				SDL_DestroyTexture(highscore);
			}

			if (e.motion.x >= 400 && e.motion.x <= 900 && e.motion.y >= 545 && e.motion.y <= 600) {  //Hướng dẫn
				SDL_Texture* info = LoadTexture("art/info.jpg", renderer);
				renderTexture(info, renderer, 0, 0);
				SDL_RenderPresent(renderer);
				printf("Huong dan\n");
				SDL_Event temp;
				while (SDL_WaitEvent(&temp)) {
					if (temp.type == SDL_QUIT) {
						quitSDL(window, renderer);
					}
					if (temp.type == SDL_MOUSEBUTTONDOWN && temp.button.button == SDL_BUTTON_LEFT) {
						if (temp.motion.x >= 50 && temp.motion.x <= 190 && temp.motion.y >= 600 && temp.motion.y <= 650) {
							renderTexture(background, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
							SDL_RenderPresent(renderer);
							break;
						}
						if (temp.motion.x >= 1090 && temp.motion.x <= 1230 && temp.motion.y >= 600 && temp.motion.y <= 650) {
							printf("Bat dau\n");
							Game(window, renderer);
						}
					}
				}
				SDL_DestroyTexture(info);
			}

			if (e.motion.x >= 400 && e.motion.x <= 900 && e.motion.y >= 640 && e.motion.y <= 685) {  //Thoát
				quitSDL(window, renderer);
				printf("Thoat\n");
			}
		}
	}
	SDL_DestroyTexture(background);
	quitSDL(window, renderer);
	return 0;
}

