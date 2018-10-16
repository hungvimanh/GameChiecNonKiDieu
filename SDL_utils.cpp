#include "SDL_utils.h"

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer,
	int screenWidth, int screenHeight, const char* windowTitle){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//Initialize renderer color
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	//Initialize SDL_ttf
	TTF_Init();

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(renderer, screenWidth, screenHeight);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	exit(0);
}

SDL_Texture* LoadTexture(const std::string &str, SDL_Renderer *ren)
{
	SDL_Surface* surface = IMG_Load(str.c_str());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(ren, surface);
	SDL_FreeSurface(surface);
	return texture;
}
/**
* Vẽ một SDL_Texture lên một SDL_Renderer tại toạ độ (x, y), trong khi
* giữ nguyên chiều rộng và cao của ảnh
*  - tex: texture nguồn chúng ta muốn vẽ ra
*  - ren: thiết bị renderer chúng ta muốn vẽ vào
*  - x: hoành độ
*  - y: tung độ
*/
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y)
{
	//Thiết lập hình chữ nhật đích mà chúng ta muốn vẽ ảnh vào trong
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//Truy vẫn texture để lấy chiều rộng và cao (vào chiều rộng và cao tương ứng của hình chữ nhật đích)
	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	//Đưa toàn bộ ảnh trong texture vào hình chữ nhật đích
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

/**
* Vẽ một SDL_Texture lên một SDL_Renderer tại toạ độ (x, y), với
* chiều rộng và cao mới
* - tex: texture nguồn chúng ta muốn vẽ ra
* - ren: thiết bị renderer chúng ta muốn vẽ vào
* - x: hoành độ
* - y: tung độ
* - w: chiều rộng (mới)
* - h: độ cao (mới)
*/
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h)
{
	//Thiết lập hình chữ nhật đích mà chúng ta muốn vẽ ảnh vào trong
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	//Đưa toàn bộ ảnh trong texture vào hình chữ nhật đích
	//(ảnh sẽ co dãn cho khớp với kích cỡ mới)
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

/**
* Viết chữ lên renderer
* - _x: hoành độ
* - _y: tung độ
* - R G B: màu
* - size: cỡ chữ
* - _font: font chữ
*/
void writeText(SDL_Renderer* renderer, string text,int _x, int _y, Uint8 R, Uint8 G, Uint8 B, int size, const char* _font ) {
	SDL_Color color = { R, G, B };
	
	TTF_Font* font = TTF_OpenFont(_font, size);

	SDL_Surface* Text = TTF_RenderText_Solid(font, text.c_str(), color);
	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, Text);
	SDL_Rect Scr;	
	SDL_QueryTexture(Message, NULL, NULL, &Scr.w, &Scr.h);
	Scr.x = _x;
	Scr.y = _y;

	SDL_RenderCopy(renderer, Message, NULL, &Scr);
	TTF_CloseFont(font);
	SDL_FreeSurface(Text);
}
