#include <iostream>
#include <C:/My Lib C++/neto28.h>
#include <vector>
#include <Windows.h>

struct ConsoleField {

	struct cletka {
		bool active = false;
	};
	struct pixel {
		std::string name;
		Vector2 position;
		Vector2 rotation;
		pixel(std::string Name) {
			name = Name;
		}
	};
	static constexpr size_t wight = 20;
	static constexpr size_t height = 20;
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	cletka Field[height][wight];


	std::vector <pixel> pixels;
	void CreatePixel(std::string name) {
		pixels.push_back(pixel(name));
		for (int i = 0; i < pixels.size(); i++) {
			if (pixels[i].name == name) {
				Field[pixels[i].position.y][pixels[i].position.x].active = true;
			}
		}
	}
	pixel GetPixel(std::string name) {
		for (int i = 0; i < pixels.size(); i++) {
			if (pixels[i].name == name) {
				return pixels[i];
			}
		}
	}
	void SetRotationPixel(std::string name, int addX, int addY) {
		for (int i = 0; i < pixels.size(); i++) {
			if (pixels[i].name == name) {
				pixels[i].rotation.y = addY;
				pixels[i].rotation.x = addX;
			}
		}
	}
	void SetPosPixel(std::string name, int addX, int addY) {
		for (int i = 0; i < pixels.size(); i++) {
			if (pixels[i].name == name) {
				Field[pixels[i].position.y][pixels[i].position.x].active = false;
				pixels[i].position.y = addY;
				pixels[i].position.x = addX;
				Field[pixels[i].position.y][pixels[i].position.x].active = true;
			}
		}
	}
	void DestroyPixel(std::string name) {
		for (int i = 0; i < pixels.size(); i++) {
			if (pixels[i].name == name) {
				pixels.erase(std::next(pixels.begin(), i));
				break ;
			}
		}
	}
	void MovePosPixel(std::string name,int addX,int addY) {
		for (int i = 0; i < pixels.size(); i++) {
			if (pixels[i].name == name) {
				Field[pixels[i].position.y][pixels[i].position.x].active = false;
				pixels[i].position.y += addY;
				pixels[i].position.x += addX;
				Field[pixels[i].position.y][pixels[i].position.x].active = true;
			}
		}
	}


	int Render() {

		SetConsoleCursorPosition(Handle, { 0,0 });
		for (int i = 0; i < height; i++) {
			std::cout << std::endl;
			for (int f = 0; f < wight; f++) {
				if (Field[i][f].active == false) {
					std::cout << u8"\u25FB ";
				}
				else {
					std::cout << u8"\u25FC ";
				}
			}
		}
		return 1;
	}

};

