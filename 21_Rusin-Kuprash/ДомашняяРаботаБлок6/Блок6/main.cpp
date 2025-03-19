#include <iostream>
#include "Windows.h"


using namespace std;


class Block {
public:
    static HANDLE handle;
    bool solid = false;
    int id; // 0 = air, 1 = head, 2 = body, 3 = tail 4 = fruit;
    int dir; // 1 - right, 2 - down, 3 - left, 4 - up
    Block(bool _solid = false, int _id = 0,  int _dir = 0): solid(_solid), id(_id), dir(_dir){}
};


class Map {
public:
    int size;
    Block* map;
    Map(int _size = 7) : size(_size) {
        map = new Block[size, size];
    }
    ~Map() {
        delete[] map;
    }
    void print() {
        Block bl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                bl = map[i, j];
                if (bl.solid) {
                    cout << "##";
                }
                else {
                    switch (bl.id) {

                    }
                }
            }
            cout << endl;
        }
    }
};


int main() {
    const int deltaTime = 450;
    int dir = 4;
    int* headPos = new int[2];
    int lenght = 5;
    Map map = Map();
    while (!(GetKeyState(VK_ESCAPE) & 0x8000)) {
        if (GetKeyState(VK_LEFT) & 0x8000) {
            cout << "left" << endl;
            dir = 3;
        }
        else if (GetKeyState(VK_RIGHT) & 0x8000) {
            cout << "right" << endl;
            dir = 1;
        }
        else if (GetKeyState(VK_UP) & 0x8000) {
            cout << "up" << endl;
            dir = 4;
        }
        else if (GetKeyState(VK_DOWN) & 0x8000) {
            cout << "left" << endl;
            dir = 2;
        }

        Sleep(deltaTime);
        system("cls");
    }
    
    


	return 1;
}