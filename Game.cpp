#include"Game.h"


void Game(SDL_Window* window, SDL_Renderer* renderer) {

	SDL_Texture* mode = LoadTexture("art/mode.jpg", renderer);
	SDL_RenderClear(renderer);
	renderTexture(mode, renderer, 0, 0);
	SDL_RenderPresent(renderer);

	vector<SDL_Texture *> wheels;
	wheels.push_back(LoadTexture("wheels/1.png", renderer));
	wheels.push_back(LoadTexture("wheels/2.png", renderer));
	wheels.push_back(LoadTexture("wheels/3.png", renderer));
	wheels.push_back(LoadTexture("wheels/4.png", renderer));
	wheels.push_back(LoadTexture("wheels/5.png", renderer));
	wheels.push_back(LoadTexture("wheels/6.png", renderer));
	wheels.push_back(LoadTexture("wheels/7.png", renderer));
	wheels.push_back(LoadTexture("wheels/8.png", renderer));
	wheels.push_back(LoadTexture("wheels/9.png", renderer));
	wheels.push_back(LoadTexture("wheels/10.png", renderer));
	wheels.push_back(LoadTexture("wheels/11.png", renderer));
	wheels.push_back(LoadTexture("wheels/12.png", renderer));
	wheels.push_back(LoadTexture("wheels/13.png", renderer));
	wheels.push_back(LoadTexture("wheels/14.png", renderer));
	wheels.push_back(LoadTexture("wheels/15.png", renderer));
	bool running_game = true;
	SDL_Event e_mode;
	while (SDL_WaitEvent(&e_mode)) {
		if (e_mode.type == SDL_QUIT) { quitSDL(window, renderer); }
		if (e_mode.type == SDL_MOUSEBUTTONDOWN && e_mode.button.button == SDL_BUTTON_LEFT
			&& e_mode.motion.x >= 330 && e_mode.motion.x <= 970 && e_mode.motion.y >= 240 && e_mode.motion.y <= 320) {
			do {
				Single_play(window, renderer, wheels);
				SDL_Event again;
				while (SDL_WaitEvent(&again)) {
					if (again.type == SDL_QUIT) { quitSDL(window, renderer); }
					if (again.type == SDL_MOUSEBUTTONDOWN && again.button.button == SDL_BUTTON_LEFT
						&& again.motion.x >= 580 && again.motion.x <= 650 && again.motion.y >= 450 && again.motion.y <= 515) {
						break;
					}
					if (again.type == SDL_MOUSEBUTTONDOWN && again.button.button == SDL_BUTTON_LEFT
						&& again.motion.x >= 800 && again.motion.x <= 860 && again.motion.y >= 450 && again.motion.y <= 515) {
						running_game = false;
						quitSDL(window, renderer);
					}
				}
			} while (running_game);
		}
		if (e_mode.type == SDL_MOUSEBUTTONDOWN && e_mode.button.button == SDL_BUTTON_LEFT
			&& e_mode.motion.x >= 330 && e_mode.motion.x <= 970 && e_mode.motion.y >= 390 && e_mode.motion.y <= 470) {
			do {
				Multi_play(window, renderer, wheels);
				SDL_Event again;
				while (SDL_WaitEvent(&again)) {
					if (again.type == SDL_QUIT) { quitSDL(window, renderer); }
					if (again.type == SDL_MOUSEBUTTONDOWN && again.button.button == SDL_BUTTON_LEFT
						&& again.motion.x >= 580 && again.motion.x <= 650 && again.motion.y >= 450 && again.motion.y <= 515) {
						break;
					}
					if (again.type == SDL_MOUSEBUTTONDOWN && again.button.button == SDL_BUTTON_LEFT
						&& again.motion.x >= 800 && again.motion.x <= 860 && again.motion.y >= 450 && again.motion.y <= 515) {
						running_game = false;
						quitSDL(window, renderer);
					}
				}
			} while (running_game);
		}
	}

	SDL_DestroyTexture(mode);
	for (int i = 0; i < wheels.size(); i++){
		SDL_DestroyTexture(wheels[i]);
	}
}

void Single_play(SDL_Window* window, SDL_Renderer* renderer, vector<SDL_Texture*> wheels) {
	int bad_guess = 3;
	vector<PLAYER> player(single);
		player[0].score = 0;
	
	SDL_Texture* background_welcome = LoadTexture("art/welcome_single.jpg", renderer);
	SDL_Texture* background = LoadTexture("art/single_mode.jpg", renderer);
	SDL_Texture* guess_now = LoadTexture("art/guess_now.jpg", renderer);

	vector<SDL_Texture*> turn;
	turn.push_back(LoadTexture("art/0.jpg", renderer));
	turn.push_back(LoadTexture("art/1.jpg", renderer));
	turn.push_back(LoadTexture("art/2.jpg", renderer));

	srand(time(0));
	int randNum = randomIndex(Answer);
	string question = readFile(Question, randNum);
	string word = getUpperCaseString(readFile(Answer, randNum));
	
	if (word.length() < 1) {
		cout << "Error reading vocabulary file " << Answer;
		exit(0);
	}
	if (question.length() < 1) {
		cout << "Error reading vocabulary file " << Question;
		exit(0);
	}

	string guessedWord = string(word.length(), '*');
	guessedWord = update_space(word, guessedWord);
	vector<char> guessed;

	//Vẽ ảnh đầu vào giữa màn hình
	int iSize = 400; //Kích cỡ ảnh (và là đường kính của bánh xe)
	int x = 0;
	int y = 320;

	SDL_RenderClear(renderer);
	renderTexture(background_welcome, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);

	renderTexture(background, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	renderTexture(wheels[12], renderer, x, y, iSize, iSize);
	writeText(renderer, question, 440, 360, 255, 255, 255, 28,"VNARIS.TTF");
	SDL_RenderPresent(renderer);
	Draw(word, renderer);

	do {
		bool running = false;
		int diem_quay = 0;
		int cnt_guess = 0;
		SDL_Event k;
		int i = 0;
		while (SDL_WaitEvent(&k)) {
			if (k.type == SDL_QUIT)  quitSDL(window, renderer);
			
			if (k.type == SDL_MOUSEBUTTONDOWN && k.button.button == SDL_BUTTON_LEFT) {
				if (k.motion.x >= 925 && k.motion.x <= 1045 && k.motion.y >= 245 && k.motion.y <= 300) {
					//Đoán luôn
					renderTexture(guess_now, renderer, 0, 0);
					SDL_RenderPresent(renderer);
					do {
						char guess = readGuess(renderer, guessedWord, guessed);

						if (contains(word, guess)) {
							guessedWord = update(word, guessedWord, guess, renderer);
							continue;
						}
						else {
							bad_guess--;
							renderTexture(turn[bad_guess], renderer, 0, 0);
							SDL_RenderPresent(renderer);
						}
					} while (guessedWord != word && bad_guess>0);
					break;
				}
			}

			if (k.type == SDL_KEYDOWN && k.key.keysym.sym == SDLK_SPACE) {
				running = true;
				i = Rotation(wheels, renderer, running); break;
			}
		}
		if (guessedWord == word) break;

		if (i == 3) {
			player[0].score /= 2;	//chia đôi
			renderScore(renderer, player, 0, 1);
		}
		if (i == 13) {				//mất điểm
			player[0].score = 0;
			renderScore(renderer, player, 0, 1);
			continue;
		}

		char guess = readGuess(renderer, guessedWord, guessed);

		if (contains(word, guess)) {
			if (i == 0) diem_quay = 100000;   //cuối vòng
			else if (i == 3) {	}
			else if (i == 8) {
				player[0].score *= 2;				//nhân đôi
			}
			else if (i == 13) {	}
			else diem_quay = vong_quay[i - 1];
			cnt_guess = count_guess(word, guess);
			player[0].score += diem_quay*cnt_guess;		//Cộng điểm nếu đoán đúng
			renderScore(renderer, player, 0, 1);
			guessedWord = update(word, guessedWord, guess, renderer);
			continue;
		}
		else {
			bad_guess--;
			renderTexture(turn[bad_guess], renderer, 0, 0);
			SDL_RenderPresent(renderer);
		}
	} while (guessedWord != word && bad_guess>0);

	// Ghi điểm vào file
	scoreFile(player[0].score, "file/highScore_single.txt");

	//end game
	if (guessedWord == word) {
		SDL_Texture* tip = LoadTexture("art/tip.jpg", renderer);
		renderTexture(tip, renderer,400,319);
		SDL_RenderPresent(renderer);
		SDL_DestroyTexture(tip);
	}
	else {
		SDL_Texture* tip = LoadTexture("art/hetluot.jpg", renderer);
		renderTexture(tip, renderer, 400, 319);
		SDL_RenderPresent(renderer);
		SDL_DestroyTexture(tip);
	}
	
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(background_welcome);
	for (int i = 0; i < turn.size(); i++) {
		SDL_DestroyTexture(turn[i]);
	}
}


void Multi_play(SDL_Window* window, SDL_Renderer* renderer, vector<SDL_Texture*> wheels) {

	vector<PLAYER> player(num_of_player);
	for (size_t i = 0; i < num_of_player; i++){
		player[i].score = 0;
	}

	SDL_Texture* background_welcome = LoadTexture("art/background_welcome.jpg", renderer);
	SDL_Texture* background = LoadTexture("art/background.jpg", renderer);
	SDL_Texture* guess_now = LoadTexture("art/guess_now.jpg", renderer);

	vector<SDL_Texture*> turn;
	turn.push_back(LoadTexture("art/player1.jpg", renderer));
	turn.push_back(LoadTexture("art/player2.jpg", renderer));
	turn.push_back(LoadTexture("art/player3.jpg", renderer));

	srand(time(0));
	int flag = 0;
	int randNum = randomIndex(Answer);
	string question = readFile(Question, randNum);
	string word = getUpperCaseString(readFile(Answer, randNum));

	if (word.length() < 1) {
		cout << "Error reading vocabulary file " << Answer;
		exit(0);
	}
	if (question.length() < 1) {
		cout << "Error reading vocabulary file " << Question;
		exit(0);
	}

	string guessedWord = string(word.length(), '*');
	guessedWord = update_space(word, guessedWord);
	vector<char> guessed;

	//Vẽ ảnh đầu vào giữa màn hình
	int iSize = 400; //Kích cỡ ảnh (và là đường kính của bánh xe)
	int x = 0;
	int y = 320;

	SDL_RenderClear(renderer);
	renderTexture(background_welcome, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);

	renderTexture(background, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	renderTexture(wheels[12], renderer, x, y, iSize, iSize);
	writeText(renderer, question, 440, 360, 255, 255, 255, 28,"VNARIS.TTF");
	SDL_RenderPresent(renderer);
	Draw(word, renderer);

	do {
		bool running = false;
		flag = flag % num_of_player;
		int diem_quay = 0;
		int cnt_guess = 0;
		SDL_Event k;
		int i = 0;
		while (SDL_WaitEvent(&k)) {
			if (k.type == SDL_QUIT)  quitSDL(window, renderer);

			if (k.type == SDL_MOUSEBUTTONDOWN && k.button.button == SDL_BUTTON_LEFT) {
				if (k.motion.x >= 925 && k.motion.x <= 1045 && k.motion.y >= 245 && k.motion.y <= 300) {
					//Đoán luôn
					renderTexture(guess_now, renderer, 0, 0);
					SDL_RenderPresent(renderer);
					do {
						char guess = readGuess(renderer, guessedWord, guessed);

						if (contains(word, guess)) {
							guessedWord = update(word, guessedWord, guess, renderer);
							continue;
						}
						else {
							player[flag].score = 0;
							flag++;
							flag = flag % num_of_player;
							renderTexture(turn[flag], renderer, 0, 0);
							SDL_RenderPresent(renderer);
							break;
						}
					} while (guessedWord != word);
					if (guessedWord == word) break;
				}
			}

			if (k.type == SDL_KEYDOWN && k.key.keysym.sym == SDLK_SPACE) {
				running = true;
				i = Rotation(wheels, renderer, running); break;
			}
		}
		if (guessedWord == word) break;

		
		if (i == 3) {
			player[flag].score /= 2;	//chia đôi
			renderScore(renderer, player, flag, flag);
		}
		
		if (i == 13) {				//mất điểm
			player[flag].score = 0;
			renderScore(renderer, player, flag, flag);
			flag++;
			continue;
		}
		
		char guess = readGuess(renderer, guessedWord, guessed);

		if (contains(word, guess)) {
			if (i == 0) diem_quay = 100000;   //cuối vòng
			else if (i == 3) {}
			else if (i == 8) {
				player[flag].score *= 2;				//nhân đôi
			}
			else if (i == 13) {}
			else diem_quay = vong_quay[i - 1];
			
			cnt_guess = count_guess(word, guess);
			player[flag].score += diem_quay * cnt_guess;		//Cộng điểm nếu đoán đúng
			renderScore(renderer, player, flag, flag);
			guessedWord = update(word, guessedWord, guess, renderer);
			continue;
		}
		else {
			flag++;
			flag = flag % num_of_player;
			renderTexture(turn[flag], renderer, 0, 0);
			SDL_RenderPresent(renderer);
			continue;
		}
	} while ( guessedWord != word );

	// Ghi điểm vào file
	for (size_t i = 0; i < num_of_player; i++)
	{
		scoreFile(player[i].score, "file/highScore_multi.txt");
	}

	//end game
	if (guessedWord == word) {
		SDL_Texture* tip = LoadTexture("art/multi_endgame.jpg", renderer);
		renderTexture(tip, renderer, 400, 319);
		writeText(renderer, to_string(flag+1), 708, 361, 255, 243, 0, 50,"VNCOOP.TTF");
		SDL_RenderPresent(renderer);
		SDL_DestroyTexture(tip);
	}

	SDL_DestroyTexture(background);
	SDL_DestroyTexture(background_welcome);
	for (int i = 0; i < turn.size(); i++) {
		SDL_DestroyTexture(turn[i]);
	}

}
