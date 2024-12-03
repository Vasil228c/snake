

#include <iostream>
#include <C:/My Lib C++/field28.h>
#include <string>
#include <vector>
#include <Windows.h>
#include <conio.h>
struct ConrtrolPoint {
	Vector2 position;
	Vector2 rotation;
	ConrtrolPoint(Vector2 positionC,Vector2 rotationC) {
		position = positionC;
		rotation = rotationC;
	}
};
struct Apple {
	Vector2 position;
};
ConsoleField field;

void AddApple() {
	field.CreatePixel("Apple");
	field.SetPosPixel("Apple", rand() % 20 + 1, rand() % 20 + 1);
	
}
struct snake {
	std::vector <ConrtrolPoint> Conrtrols_Points;
	int size = 0;
	bool IsHeadTouchPoint(Vector2 Position) {
		for (int f = 0; f < Conrtrols_Points.size(); f++) {
			if (Conrtrols_Points[f].position == Position) {
				return true;
			}
		}
		return false;
	}

	void RightMove() {
		if (IsHeadTouchPoint(field.GetPixel("cletka1").position) != true && field.GetPixel("cletka1").rotation != Vector2(-1, 0)) {
			Conrtrols_Points.push_back(ConrtrolPoint(field.GetPixel("cletka1").rotation + field.GetPixel("cletka1").position, Vector2(1, 0)));
		}
	}
	void LeftMove() {
		if (IsHeadTouchPoint(field.GetPixel("cletka1").position) != true && field.GetPixel("cletka1").rotation != Vector2(1, 0)) {
			Conrtrols_Points.push_back(ConrtrolPoint(field.GetPixel("cletka1").rotation + field.GetPixel("cletka1").position, Vector2(-1, 0)));
		}
	}
	void DownMove() {
		if (IsHeadTouchPoint(field.GetPixel("cletka1").position) != true && field.GetPixel("cletka1").rotation != Vector2(0, -1)) {
			Conrtrols_Points.push_back(ConrtrolPoint(field.GetPixel("cletka1").rotation + field.GetPixel("cletka1").position, Vector2(0, 1)));
		}
	}
	void UpMove() {
		if (IsHeadTouchPoint(field.GetPixel("cletka1").position) != true && field.GetPixel("cletka1").rotation != Vector2(0, 1)) {
			Conrtrols_Points.push_back(ConrtrolPoint(field.GetPixel("cletka1").rotation + field.GetPixel("cletka1").position, Vector2(0, -1)));
		}
	}

	void add_cleltka() {
		if (size != 0) {
			Vector2 pos = field.GetPixel("cletka" + std::to_string(size)).position;
		}

		size += 1;
		field.CreatePixel("cletka" + std::to_string(size));
		if (size != 1) {
			field.SetRotationPixel("cletka" + std::to_string(size), field.GetPixel("cletka" + std::to_string(size - 1)).rotation.x, field.GetPixel("cletka" + std::to_string(size - 1)).rotation.y);
		}

		if (size == 1) {
			field.MovePosPixel("cletka" + std::to_string(size), 4, 4);
			field.SetRotationPixel("cletka" + std::to_string(size), 1, 0);
		}
		else {
			field.MovePosPixel("cletka" + std::to_string(size), field.GetPixel("cletka" + std::to_string(size - 1)).position.x + field.GetPixel("cletka" + std::to_string(size)).rotation.x * -1, field.GetPixel("cletka" + std::to_string(size - 1)).position.y + field.GetPixel("cletka" + std::to_string(size)).rotation.y * -1);

		}
	}
	void move() {
		for (int i = 1; i < size + 1; i++) {

			field.MovePosPixel("cletka" + std::to_string(i), field.GetPixel("cletka" + std::to_string(i)).rotation.x, field.GetPixel("cletka" + std::to_string(i)).rotation.y);
			for (int f = 0; f < Conrtrols_Points.size(); f++) {
				if (field.GetPixel("cletka" + std::to_string(i)).position == Conrtrols_Points[f].position) {
					field.SetRotationPixel("cletka" + std::to_string(i), Conrtrols_Points[f].rotation.x, Conrtrols_Points[f].rotation.y);
					if (i == size) {
						Conrtrols_Points.erase(std::next(Conrtrols_Points.begin(), f));
					}
				}
			}


		}

	}
};
int main()
{
	SetConsoleOutputCP(CP_UTF8);
	std::cout << u8"░██████╗███╗░░██╗░█████╗░██╗░░██╗███████╗\n██╔════╝████╗░██║██╔══██╗██║░██╔╝██╔════╝\n╚█████╗░██╔██╗██║███████║█████═╝░█████╗░░\n░╚═══██╗██║╚████║██╔══██║██╔═██╗░██╔══╝░░\n██████╔╝██║░╚███║██║░░██║██║░╚██╗███████╗\n╚═════╝░╚═╝░░╚══╝╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝░\n\n\n\n\n";
	std::cout << u8"█▀█ █▀█ █▀▀ █▀ █▀   ▄▀█ █▄░█ █▄█   █▄▀ █▀▀ █▄█   ▀█▀ █▀█   █▀ ▀█▀ ▄▀█ █▀█ ▀█▀\n█▀▀ █▀▄ ██▄ ▄█ ▄█   █▀█ █░▀█ ░█░   █░█ ██▄ ░█░   ░█░ █▄█   ▄█ ░█░ █▀█ █▀▄ ░█░\n";
	int key = _getch();
	system("cls");
	snake TestSnake;
	TestSnake.add_cleltka();
	TestSnake.add_cleltka();
	TestSnake.add_cleltka();
	AddApple();
	while (true)
	{
		
		if (GetKeyState('D') & 0x8000) {
			TestSnake.RightMove();
		}
		if (GetKeyState('A') & 0x8000) {
			TestSnake.LeftMove();

		}
		if (GetKeyState('S') & 0x8000) {
			TestSnake.DownMove();

		}
		if (GetKeyState('W') & 0x8000) {
			TestSnake.UpMove();

		}
		TestSnake.move();
		if (field.GetPixel("Apple").position == field.GetPixel("cletka1").position) {
			TestSnake.add_cleltka();
			field.DestroyPixel("Apple");
			AddApple();
		}
		bool GameOver = false;
		if (field.GetPixel("cletka1").position.x < 0 or field.GetPixel("cletka1").position.x > field.wight) {
			GameOver = true;
			break;
		}
		if (field.GetPixel("cletka1").position.y < 0 or field.GetPixel("cletka1").position.y > field.height) {
			GameOver = true;
			break;
		}
		for (int i = 1; i < TestSnake.size + 1; i++) {
			if (field.GetPixel("cletka" + std::to_string(i)).position == field.GetPixel("cletka1").position) {
				if (i != 1) {
					GameOver = true;
					break;
				}
				

			}
		}
		
		if (GameOver) {
			break;
		}
		field.Render();
		
		Sleep(1000);
	}
	system("cls");
	
	std::cout << u8"░█▀▀█ █▀▀█ █▀▄▀█ █▀▀ 　 ░█▀▀▀█ ▀█─█▀ █▀▀ █▀▀█\n░█─▄▄ █▄▄█ █─▀─█ █▀▀ 　 ░█──░█ ─█▄█─ █▀▀ █▄▄▀\n░█▄▄█ ▀──▀ ▀───▀ ▀▀▀ 　 ░█▄▄▄█ ──▀── ▀▀▀ ▀─▀▀\nyou score:" << TestSnake.size;
}

