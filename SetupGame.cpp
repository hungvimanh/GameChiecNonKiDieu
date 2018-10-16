#include "SetupGame.h"

Toado oChu[42] = { 
	{ 125,117 },{ 181,117 },{ 237,117 },{ 293,117 },{ 349,117 },{ 405,117 },{ 461,117 },{ 517,117 },{ 573,117 },{ 629,117 },
	{ 685,117 },{ 741,117 },{ 797,117 },{ 853,117 },{ 125,181 },{ 181,181 },{ 237,181 },{ 293,181 },{ 349,181 },{ 405,181 },
	{ 461,181 },{ 517,181 },{ 573,181 },{ 629,181 },{ 685,181 },{ 741,181 },{ 797,181 },{ 853,181 },{ 125,245 },{ 181,245 },
	{ 237,245 },{ 293,245 },{ 349,245 },{ 405,245 },{ 461,245 },{ 517,245 },{ 573,245 },{ 629,245 },{ 685,245 },{ 741,245 },
	{ 797,245 },{ 853,245 }
};
Toado key1[22] = { {415,575},{ 470,575 },{ 526,575 },{ 585,575 },{ 640,575 },{ 695,575 },{ 750,575 },{ 805,575 },{ 863,575 },{ 920,575 },
					{ 975,575 },{ 415,640 },{ 470,640 },{ 526,640 },{ 585,640 },{ 640,640 },{ 695,640 },{ 750,640 },{ 805,640 },{ 863,640 },
					{ 920,640 },{ 975,640 } };
Toado key2[22] = { {455,610},{ 510,610 },{ 570,610 },{ 625,610 },{ 680,610 },{ 735,610 },{ 790,610 },{ 850,610 },{ 905,610 },{ 960,610 },{ 1005,610 },
{ 455,675 },{ 510,675 },{ 570,675 },{ 625,675 },{ 680,675 },{ 735,675 },{ 790,675 },{ 850,675 },{ 905,675 },{ 960,675 },{ 1005,675 } };


void Draw(const string& word, SDL_Renderer* renderer) {
	SDL_Texture* space = LoadTexture("key/HIDEN.jpg", renderer);
	for (int i = 0; i < word.length(); i++) {
		if (word[i] != ' ') {
			renderTexture(space, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
	}
}

string getUpperCaseString(const string& s)
{
	string res = s;
	transform(s.begin(), s.end(), res.begin(), ::toupper);
	return res;
}

char readGuess(SDL_Renderer* renderer, string guessedWord, vector<char> &guessed) {
	char ch=NULL;
	SDL_Texture *A = LoadTexture("under/uA.jpg", renderer);
	SDL_Texture *B = LoadTexture("under/uB.jpg", renderer);
	SDL_Texture *C = LoadTexture("under/uC.jpg", renderer);
	SDL_Texture *D = LoadTexture("under/uD.jpg", renderer);
	SDL_Texture *E = LoadTexture("under/uE.jpg", renderer);
	SDL_Texture *G = LoadTexture("under/uG.jpg", renderer);
	SDL_Texture *H = LoadTexture("under/uH.jpg", renderer);
	SDL_Texture *I = LoadTexture("under/uI.jpg", renderer);
	SDL_Texture *K = LoadTexture("under/uK.jpg", renderer);
	SDL_Texture *L = LoadTexture("under/uL.jpg", renderer);
	SDL_Texture *M = LoadTexture("under/uM.jpg", renderer);
	SDL_Texture *N = LoadTexture("under/uN.jpg", renderer);
	SDL_Texture *O = LoadTexture("under/uO.jpg", renderer);
	SDL_Texture *P = LoadTexture("under/uP.jpg", renderer);
	SDL_Texture *Q = LoadTexture("under/uQ.jpg", renderer);
	SDL_Texture *R = LoadTexture("under/uR.jpg", renderer);
	SDL_Texture *S = LoadTexture("under/uS.jpg", renderer);
	SDL_Texture *T = LoadTexture("under/uT.jpg", renderer);
	SDL_Texture *U = LoadTexture("under/uU.jpg", renderer);
	SDL_Texture *V = LoadTexture("under/uV.jpg", renderer);
	SDL_Texture *X = LoadTexture("under/uX.jpg", renderer);
	SDL_Texture *Y = LoadTexture("under/uY.jpg", renderer);
	SDL_Event e;
	do {
		while (SDL_WaitEvent(&e)) {
			if (e.type == SDL_QUIT)		SDL_Quit();
			if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
				if (e.motion.x >= key1[0].x && e.motion.x <= key2[0].x && e.motion.y >= key1[0].y && e.motion.y <= key2[0].y) {
					ch = 'A';
					renderTexture(A, renderer, 414, 572);
					SDL_RenderPresent(renderer);
					break;
				}
				if (e.motion.x >= key1[1].x && e.motion.x <= key2[1].x && e.motion.y >= key1[1].y && e.motion.y <= key2[1].y) {
					ch = 'B';
					renderTexture(B, renderer, 470, 572);
					SDL_RenderPresent(renderer);
					break;
				}
				if (e.motion.x >= key1[2].x && e.motion.x <= key2[2].x && e.motion.y >= key1[2].y && e.motion.y <= key2[2].y) {
					ch = 'C';
					renderTexture(C, renderer, 526, 572);
					SDL_RenderPresent(renderer);
					break;
				}
				if (e.motion.x >= key1[3].x && e.motion.x <= key2[3].x && e.motion.y >= key1[3].y && e.motion.y <= key2[3].y) {
					ch = 'D';
					renderTexture(D, renderer, 582, 572);
					SDL_RenderPresent(renderer);
					break;
				}
				if (e.motion.x >= key1[4].x && e.motion.x <= key2[4].x && e.motion.y >= key1[4].y && e.motion.y <= key2[4].y) {
					ch = 'E';
					renderTexture(E, renderer, 638, 572);
					SDL_RenderPresent(renderer);
					break;
				}
				if (e.motion.x >= key1[5].x && e.motion.x <= key2[5].x && e.motion.y >= key1[5].y && e.motion.y <= key2[5].y) {
					ch = 'G';
					renderTexture(G, renderer, 694, 572);
					SDL_RenderPresent(renderer);
					break;
				}
				if (e.motion.x >= key1[6].x && e.motion.x <= key2[6].x && e.motion.y >= key1[6].y && e.motion.y <= key2[6].y) {
					ch = 'H';
					renderTexture(H, renderer, 750, 572);
					SDL_RenderPresent(renderer);
					break;
				}
				if (e.motion.x >= key1[7].x && e.motion.x <= key2[7].x && e.motion.y >= key1[7].y && e.motion.y <= key2[7].y) {
					ch = 'I';
					renderTexture(I, renderer, 806, 572);
					SDL_RenderPresent(renderer);
					break;
				}
				if (e.motion.x >= key1[8].x && e.motion.x <= key2[8].x && e.motion.y >= key1[8].y && e.motion.y <= key2[8].y) {
					ch = 'K';
					renderTexture(K, renderer, 862, 572);
					SDL_RenderPresent(renderer);
					break;
				}
				if (e.motion.x >= key1[9].x && e.motion.x <= key2[9].x && e.motion.y >= key1[9].y && e.motion.y <= key2[9].y) {
					ch = 'L';
					renderTexture(L, renderer, 918, 572);
					SDL_RenderPresent(renderer);
					break;
				}
				if (e.motion.x >= key1[10].x && e.motion.x <= key2[10].x && e.motion.y >= key1[10].y && e.motion.y <= key2[10].y) {
					ch = 'M';
					renderTexture(M, renderer, 974, 572);
					SDL_RenderPresent(renderer);
					break;
				}
				if (e.motion.x >= key1[11].x && e.motion.x <= key2[11].x && e.motion.y >= key1[11].y && e.motion.y <= key2[11].y) {
					ch = 'N';
					renderTexture(N, renderer, 414, 636);
					SDL_RenderPresent(renderer);
					break;
				}
				if (e.motion.x >= key1[12].x && e.motion.x <= key2[12].x && e.motion.y >= key1[12].y && e.motion.y <= key2[12].y) {
					ch = 'O';
					renderTexture(O, renderer, 470, 636);
					SDL_RenderPresent(renderer);
					break;

				}
				if (e.motion.x >= key1[13].x && e.motion.x <= key2[13].x && e.motion.y >= key1[13].y && e.motion.y <= key2[13].y) {
					ch = 'P';
					renderTexture(P, renderer, 526, 636);
					SDL_RenderPresent(renderer);
					break;
				}
				if (e.motion.x >= key1[14].x && e.motion.x <= key2[14].x && e.motion.y >= key1[14].y && e.motion.y <= key2[14].y) {
					ch = 'Q';
					renderTexture(Q, renderer, 582, 636);
					SDL_RenderPresent(renderer);
					break;
				}
				if (e.motion.x >= key1[15].x && e.motion.x <= key2[15].x && e.motion.y >= key1[15].y && e.motion.y <= key2[15].y) {
					ch = 'R';
					renderTexture(R, renderer, 638, 636);
					SDL_RenderPresent(renderer);
					break;
				}
				if (e.motion.x >= key1[16].x && e.motion.x <= key2[16].x && e.motion.y >= key1[16].y && e.motion.y <= key2[16].y) {
					ch = 'S';
					renderTexture(S, renderer, 694, 636);
					SDL_RenderPresent(renderer);
					break;
				}
				if (e.motion.x >= key1[17].x && e.motion.x <= key2[17].x && e.motion.y >= key1[17].y && e.motion.y <= key2[17].y) {
					ch = 'T';
					renderTexture(T, renderer, 750, 636);
					SDL_RenderPresent(renderer);
					break;
				}
				if (e.motion.x >= key1[18].x && e.motion.x <= key2[18].x && e.motion.y >= key1[18].y && e.motion.y <= key2[18].y) {
					ch = 'U';
					renderTexture(U, renderer, 806, 636);
					SDL_RenderPresent(renderer);
					break;
				}
				if (e.motion.x >= key1[19].x && e.motion.x <= key2[19].x && e.motion.y >= key1[19].y && e.motion.y <= key2[19].y) {
					ch = 'V';
					renderTexture(V, renderer, 862, 636);
					SDL_RenderPresent(renderer);
					break;
				}
				if (e.motion.x >= key1[20].x && e.motion.x <= key2[20].x && e.motion.y >= key1[20].y && e.motion.y <= key2[20].y) {
					ch = 'X';
					renderTexture(X, renderer, 918, 636);
					SDL_RenderPresent(renderer);
					break;
				}
				if (e.motion.x >= key1[21].x && e.motion.x <= key2[21].x && e.motion.y >= key1[21].y && e.motion.y <= key2[21].y) {
					ch = 'Y';
					renderTexture(Y, renderer, 974, 636);
					SDL_RenderPresent(renderer);
					break;
				}
			}
		}
		guessed.push_back(ch);
		if (!check(ch, guessed)) continue;
		else break;
	}while (1);
	return toupper(ch);
}

bool contains(const string& word, char guess) {
	return (word.find_first_of(guess) != string::npos);
}

bool check(char guess, vector<char> guessed) {
	if (guessed.size() < 2) return true;
	for (int i = 0; i < guessed.size()-1; i++){
		if (guess == guessed[i]) return false;
	}
	return true;
}

int count_guess(string word, char guess) {
	int count = 0;
	for (int i = 0; i < word.length(); i++) {
		if (guess == word[i]) count++;
	}
	return count;
}

string update_space(const string& word, string guessedWord) {
	int n = word.length();
	for (int i = 0; i < n; i++) {
		if (word[i] == ' ') {
			guessedWord[i] = ' ';
		}
	}
	return guessedWord;
}

string update(const string& word, string guessedWord, char guess, SDL_Renderer* renderer) {
	int n = word.length();
	SDL_Texture *A = LoadTexture("key/A.bmp", renderer);
	SDL_Texture *B = LoadTexture("key/B.bmp", renderer);
	SDL_Texture *C = LoadTexture("key/C.bmp", renderer);
	SDL_Texture *D = LoadTexture("key/D.bmp", renderer);
	SDL_Texture *E = LoadTexture("key/E.bmp", renderer);
	SDL_Texture *G = LoadTexture("key/G.bmp", renderer);
	SDL_Texture *H = LoadTexture("key/H.bmp", renderer);
	SDL_Texture *I = LoadTexture("key/I.bmp", renderer);
	SDL_Texture *K = LoadTexture("key/K.bmp", renderer);
	SDL_Texture *L = LoadTexture("key/L.bmp", renderer);
	SDL_Texture *M = LoadTexture("key/M.bmp", renderer);
	SDL_Texture *N = LoadTexture("key/N.bmp", renderer);
	SDL_Texture *O = LoadTexture("key/O.bmp", renderer);
	SDL_Texture *P = LoadTexture("key/P.bmp", renderer);
	SDL_Texture *Q = LoadTexture("key/Q.bmp", renderer);
	SDL_Texture *R = LoadTexture("key/R.bmp", renderer);
	SDL_Texture *S = LoadTexture("key/S.bmp", renderer);
	SDL_Texture *T = LoadTexture("key/T.bmp", renderer);
	SDL_Texture *U = LoadTexture("key/U.bmp", renderer);
	SDL_Texture *V = LoadTexture("key/V.bmp", renderer);
	SDL_Texture *X = LoadTexture("key/X.bmp", renderer);
	SDL_Texture *Y = LoadTexture("key/Y.bmp", renderer);
	for (int i = 0; i < n; i++) {
		if (guess == 'A' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(A, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'B' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(B, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'C' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(C, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'D' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(D, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'E' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(E, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'G' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(G, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'H' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(H, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'I' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(I, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'K' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(K, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'L' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(L, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'M' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(M, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'N' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(N, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'O' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(O, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'P' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(P, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'Q' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(Q, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'R' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(R, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'S' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(S, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'T' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(T, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'U' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(U, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'V' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(V, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'X' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(X, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		if (guess == 'Y' && word[i] == guess)
		{
			guessedWord[i] = guess;
			renderTexture(Y, renderer, oChu[i].x, oChu[i].y, 50, 53);
			SDL_RenderPresent(renderer);
		}
		
	}
	return guessedWord;
}

int Rotation(vector<SDL_Texture*> wheels, SDL_Renderer* renderer, bool running) {
	int iSize = 400; //đường kính của vòng quay
	int x = 0;
	int y = 320;

	int curImage = 0;
	int imageNum = wheels.size();
	SDL_Event k;
	while ( running ) {
		//Tốc độ vòng quay
		SDL_Delay(30);
		//Vẽ vòng quay
		renderTexture(wheels[curImage], renderer, x, y, iSize, iSize);
		SDL_RenderPresent(renderer);
		curImage = (curImage + 1) % imageNum;
		while (SDL_PollEvent(&k)){
			if (k.type == SDL_QUIT) SDL_Quit();
			//Nếu bấm phím SPACE thì dừng vòng quay
			if (k.type == SDL_KEYDOWN && k.key.keysym.sym == SDLK_SPACE) running = false;
		}
	}
	return curImage;
}

void renderScore(SDL_Renderer* renderer, vector<PLAYER> &player, int flag, int pos) {
	SDL_Color White = { 255, 255, 255 };
	
	TTF_Font* font = TTF_OpenFont((char*)"VNTIME.ttf", 1000);
	SDL_Texture *clear = LoadTexture("art/clear.jpg", renderer);
	SDL_Surface* score = TTF_RenderText_Solid(font, to_string(player[flag].score).c_str(), White);
	SDL_Texture* scoreMessage = SDL_CreateTextureFromSurface(renderer, score);
	SDL_Rect scoreRect;
	switch (pos) {
		case 0: {
			renderTexture(clear, renderer, 1065, 154);
			scoreRect.w = 100;
			scoreRect.h = 40;
			scoreRect.x = 1080;
			scoreRect.y = 170;
			break;
		}
		case 1: {
			renderTexture(clear, renderer, 1065, 364);
			scoreRect.w = 100;
			scoreRect.h = 40;
			scoreRect.x = 1080;
			scoreRect.y = 377;
			break;
		}
		case 2: {
			renderTexture(clear, renderer, 1065, 576);
			scoreRect.w = 100;
			scoreRect.h = 40;
			scoreRect.x = 1080;
			scoreRect.y = 590;
			break;
		}
	}
	SDL_RenderCopy(renderer, scoreMessage, NULL, &scoreRect);
	SDL_RenderPresent(renderer);
	TTF_CloseFont(font);
	SDL_FreeSurface(score);
}
