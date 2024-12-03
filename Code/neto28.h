#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <Windows.h>

struct Vector2 {
    int x = 0;
    int y = 0;
    Vector2(int xvector = 0, int yvector = 0) {
        x = xvector;
        y = yvector;
    }
   
    Vector2& operator=(Vector2 pos) {
        x = pos.x;
        y = pos.y;
        return *this;
    }
    Vector2& operator+=(Vector2 pos) {
        x += pos.x;
        y += pos.y;
        return *this;
    }
    Vector2 operator+(Vector2 pos) {
        
        
        return Vector2(x + pos.x, y + pos.y);
    }
    bool operator==(Vector2 pos) {
        if (pos.x == x && pos.y == y) {
            return true;
        }
        return false;
    }
    bool operator!=(Vector2 pos) {
        if (pos.x == x && pos.y == y) {
            return false;
        }
        return true;
    }
};
struct CharKeycode {
    char chr = 'a';
    WORD byt = 0xA0;
    std::string lan = "en";
    CharKeycode(char letter, WORD keycode, std::string language = "en") {
        chr = letter;
        byt = keycode;
        lan = language;
    }
};

void keyPress(WORD keyCode)
{
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = keyCode;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;

    SendInput(1, &input, sizeof(INPUT));
}

void keyRelease(WORD keyCode)
{
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = keyCode;
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;

    SendInput(1, &input, sizeof(INPUT));
}

std::vector<std::string > split(std::string text, char charsplit = ' ') {
    std::vector< std::string > result;

    std::string word = "";
    for (int i = 0; i < text.length(); i++) {

        if (text[i] == charsplit) {
            result.push_back(word);
            word = "";
        }
        else {
            word += text[i];
        }
    }
    result.push_back(word);
    word = "";

    return result;
}


std::vector<CharKeycode> chars;


WORD CharToKeycode(char letter = ' ') {
    WORD Byte = 0;
    for (int f = 0; f < chars.size(); f++) {

        if (letter == chars[f].chr) {
            Byte = chars[f].byt;
        }
        else if (letter == std::tolower(chars[f].chr)) {
            Byte = chars[f].byt;
        }

    }
    return Byte;
}

void ChooseKBlang(DWORD langId) {
    HWND hCon = GetConsoleWindow();
    PostMessage(hCon, WM_INPUTLANGCHANGEREQUEST, 0, (LPARAM)langId);
    PostMessage(hCon, WM_INPUTLANGCHANGE, 0, (LPARAM)langId);

}

std::string GetCharLeng(char letter) {
    std::string g = "nil";
    for (int f = 0; f < chars.size(); f++) {
        if (letter == chars[f].chr) {

            g = chars[f].lan;
        }
        else if (letter == std::tolower(chars[f].chr)) {
            g = chars[f].lan;
        }

    }
    return g;
}
std::string ToUpper(std::string TText) {
    std::string result = "";
    for (int i = 0; i < TText.size(); i++) {
        result += std::toupper(TText[i]);
    }
    return result;
}
void KeyboardWrite(std::string Text) {

    std::string backleng = GetCharLeng(Text[0]);
    for (int i = 0; i < Text.size() + 1; i++) {

        if (GetCharLeng(Text[i]) != backleng) {
            backleng = GetCharLeng(Text[i]);
            if (backleng == "ru") {

                ChooseKBlang(0x00000419);


            }
            else {
                ChooseKBlang(0x00000409);
            }
        }

        WORD Key = CharToKeycode(Text[i]);
        keyRelease(Key);

        keyPress(Key);
        Sleep(10);
        if (Text[i] == '/') {
            Sleep(100);
        }
        keyRelease(Key);
    }
}


void tableinit() {
    chars.push_back(CharKeycode('A', 0x1E, "en"));
    chars.push_back(CharKeycode('B', 0x30, "en"));
    chars.push_back(CharKeycode('C', 0x2E, "en"));
    chars.push_back(CharKeycode('D', 0x20, "en"));
    chars.push_back(CharKeycode('E', 0x12, "en"));
    chars.push_back(CharKeycode('F', 0x21, "en"));
    chars.push_back(CharKeycode('G', 0x22, "en"));
    chars.push_back(CharKeycode('H', 0x23, "en"));
    chars.push_back(CharKeycode('I', 0x17, "en"));
    chars.push_back(CharKeycode('J', 0x24, "en"));
    chars.push_back(CharKeycode('K', 0x25, "en"));
    chars.push_back(CharKeycode('L', 0x26, "en"));
    chars.push_back(CharKeycode('M', 0x32, "en"));
    chars.push_back(CharKeycode('N', 0x31, "en"));
    chars.push_back(CharKeycode('O', 0x18, "en"));
    chars.push_back(CharKeycode('P', 0x19, "en"));
    chars.push_back(CharKeycode('Q', 0x10, "en"));
    chars.push_back(CharKeycode('R', 0x13, "en"));
    chars.push_back(CharKeycode('S', 0x1F, "en"));
    chars.push_back(CharKeycode('T', 0x14, "en"));
    chars.push_back(CharKeycode('U', 0x16, "en"));
    chars.push_back(CharKeycode('V', 0x2F, "en"));
    chars.push_back(CharKeycode('W', 0x11, "en"));
    chars.push_back(CharKeycode('X', 0x2D, "en"));
    chars.push_back(CharKeycode('Y', 0x15, "en"));
    chars.push_back(CharKeycode('Z', 0x2C, "en"));
    chars.push_back(CharKeycode('/', 0x35, "en"));

    chars.push_back(CharKeycode(' ', 0x39));

    chars.push_back(CharKeycode('Ђ', 0x21, "ru"));
    chars.push_back(CharKeycode('Ѓ', 0x33, "ru"));
    chars.push_back(CharKeycode('‚', 0x20, "ru"));
    chars.push_back(CharKeycode('ѓ', 0x16, "ru"));
    chars.push_back(CharKeycode('„', 0x26, "ru"));
    chars.push_back(CharKeycode('…', 0x14, "ru"));
    chars.push_back(CharKeycode('р', 0x29, "ru"));
    chars.push_back(CharKeycode('†', 0x27, "ru"));
    chars.push_back(CharKeycode('‡', 0x19, "ru"));
    chars.push_back(CharKeycode('€', 0x30, "ru"));
    chars.push_back(CharKeycode('‰', 0x10, "ru"));
    chars.push_back(CharKeycode('Љ', 0x13, "ru"));
    chars.push_back(CharKeycode('‹', 0x25, "ru"));
    chars.push_back(CharKeycode('Њ', 0x2F, "ru"));
    chars.push_back(CharKeycode('Ќ', 0x15, "ru"));
    chars.push_back(CharKeycode('Ћ', 0x24, "ru"));
    chars.push_back(CharKeycode('Џ', 0x22, "ru"));
    chars.push_back(CharKeycode('ђ', 0x23, "ru"));
    chars.push_back(CharKeycode('‘', 0x2E, "ru"));
    chars.push_back(CharKeycode('’', 0x31, "ru"));
    chars.push_back(CharKeycode('“', 0x12, "ru"));
    chars.push_back(CharKeycode('”', 0x1E, "ru"));
    chars.push_back(CharKeycode('•', 0x1A, "ru"));
    chars.push_back(CharKeycode('–', 0x11, "ru"));
    chars.push_back(CharKeycode('—', 0x2D, "ru"));
    chars.push_back(CharKeycode('™', 0x17, "ru"));
    chars.push_back(CharKeycode('љ', 0x18, "ru"));
    chars.push_back(CharKeycode('›', 0x1B, "ru"));
    chars.push_back(CharKeycode('њ', 0x1F, "ru"));
    chars.push_back(CharKeycode('ќ', 0x32, "ru"));
    chars.push_back(CharKeycode('ћ', 0x34, "ru"));
    chars.push_back(CharKeycode('џ', 0x2C, "ru"));

    chars.push_back(CharKeycode('Ў', 0x21, "ru")); // а = f
    chars.push_back(CharKeycode('ў', 0xBC, "ru")); // б = ,
    chars.push_back(CharKeycode('Ј', 0x20, "ru")); // в = d
    chars.push_back(CharKeycode('¤', 0x16, "ru")); // г = u
    chars.push_back(CharKeycode('Ґ', 0x26, "ru")); // д = l
    chars.push_back(CharKeycode('с', 0x24, "ru")); // е = t
    chars.push_back(CharKeycode('¦', 0x29, "ru")); // ё = `
    chars.push_back(CharKeycode('§', 0x25, "ru")); // ж = ;
    chars.push_back(CharKeycode('Ё', 0x19, "ru")); // з = p
    chars.push_back(CharKeycode('©', 0x2B, "ru")); // и = b
    chars.push_back(CharKeycode('Є', 0x10, "ru")); // й = q
    chars.push_back(CharKeycode('«', 0x13, "ru")); // к = r
    chars.push_back(CharKeycode('¬', 0x23, "ru")); // л = k
    chars.push_back(CharKeycode('®', 0x2A, "ru")); // м = v
    chars.push_back(CharKeycode('Ї', 0x15, "ru")); // н = y
    chars.push_back(CharKeycode('а', 0x22, "ru")); // о = j
    chars.push_back(CharKeycode('б', 0x20, "ru")); // п = g
    chars.push_back(CharKeycode('в', 0x12, "ru")); // р = e
    chars.push_back(CharKeycode('г', 0x29, "ru")); // с = c
    chars.push_back(CharKeycode('д', 0x35, "ru")); // т = t
    chars.push_back(CharKeycode('е', 0x14, "ru")); // у = h
    chars.push_back(CharKeycode('ж', 0x1C, "ru")); // ф = a
    chars.push_back(CharKeycode('з', 0x1A, "ru")); // х = [
    chars.push_back(CharKeycode('и', 0x11, "ru")); // ц = w
    chars.push_back(CharKeycode('й', 0x28, "ru")); // ч = x
    chars.push_back(CharKeycode('к', 0x17, "ru")); // ш = i
    chars.push_back(CharKeycode('л', 0x18, "ru")); // щ = o
    chars.push_back(CharKeycode('м', 0x1B, "ru")); // ъ = ]
    chars.push_back(CharKeycode('н', 0x1D, "ru")); // ы = s
    chars.push_back(CharKeycode('о', 0x2D, "ru")); // ь = m
    chars.push_back(CharKeycode('п', 0x26, "ru")); // э = '
    chars.push_back(CharKeycode('ю', 0x2E, "ru")); // ю = ,
    chars.push_back(CharKeycode('я', 0x2F, "ru")); // я = .



}