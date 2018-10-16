#include"File.h"

int randomIndex(const char* fileName) {
	int count = 0;
	fstream file(fileName);
	if (file.is_open()) {
		file >> count;
		file.close();
	}
	return (rand() % count);
}

string readFile(const char* fileName, int randNum) {
	vector<string> List;
	fstream file(fileName);
	if (file.is_open()) {
		string temp;
		getline(file, temp);

		string word;
		while (!file.eof()) {
			getline(file, word);
			List.push_back(word);
		}
		file.close();
	}
	if (List.size()>0) {

		return List[randNum];
	}
	else return "";
}

void swap_score(PLAYER &A, PLAYER &B)
{
	PLAYER temp = A;
	A = B;
	B = temp;
}

void arrange(vector<PLAYER> &s)
{
	int size = s.size();
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (s[i].score < s[j].score)
				swap_score(s[i], s[j]);
		}
	}
}

void scoreFile(int hightScore, string fileName)
{
	vector<Player> topScore;

	ifstream FileIn(fileName, ios::in); //Mở file hight score
	if (FileIn.fail()){ // Thất bại => lần đầu play
		PLAYER s;
		ofstream FileOut(fileName, ios::out); // Tạo mới file hight socre

		for (int i = 0; i < 5; i++){ //Add vào file
			if (i == 0)
				FileOut << hightScore << endl;
			else
				FileOut << "0" << endl; // Cho có đủ 5 hight score
		}
		FileOut.close();
		return;
	}
	else{
		//Đọc file vào vector topScore
		while (!FileIn.eof()){
			PLAYER s;
			FileIn >> s.score;
			topScore.push_back(s);
		}
	}
	FileIn.close();

	// k phải play lần đầu;
	PLAYER s;
	s.score = hightScore;
	topScore.push_back(s);
	arrange(topScore);

	//Ghi lại vào file sau khi sắp xếp;
	ofstream FileOut(fileName, ios::out);
	FileOut.clear();

	int maxLength;			//Xét top điểm của topScore.size() lượt chơi
	if (topScore.size() < 5)
		maxLength = topScore.size();
	else
		maxLength = 5; // Top 5 hight score;
	for (int i = 0; i < maxLength; i++)
	{
		FileOut << topScore[i].score << endl;
	}
	FileOut.close();
}


void highScore(SDL_Renderer* renderer, const std::string &file, int pos)
{
	int score;

	ifstream FileIn(file, ios::in);
	int rank = 0;
	int post = 255;
	while (rank < 5)
	{
		FileIn >> score;
		writeText(renderer, to_string(score), pos, post, 0, 0, 0, 30, "VNTIME.TTF");
		post += 82;
		rank++;
	}
}