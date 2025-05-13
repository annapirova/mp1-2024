#include <stdlib.h>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector> 
#include <random> 
#include <iostream>
#include <stdexcept> 

// ANSI escape codes для цветов 3текста
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

using namespace std;



// 0 - пустое
// * - выстрел мимо
// x - попадание
// # - корабль


class Field{
    protected:
        int n, m;
        
    public:
        vector<vector<string> >pole;
        Field(){
            for (int i = 0; i < 10; i++){
                vector <string> notes;
                for (int j = 0; j < 10; j++){
                    notes.push_back(" ");
                }
                pole.push_back(notes);
            }
        }

        void PrintField(){
            cout << "----------------------" << endl;
            for (int i = 0; i < 10; i++){
                cout << "|";
                for (int j = 0; j < 10; j++){
                    cout << pole[i][j] << " ";
                }
                cout << "|" << endl;
            }
            cout << "----------------------" << endl;
        }

        vector<vector<string> > getPole(){
            return pole;
        }

        
};

class User{
    protected:
        
    public:
        Field my_pole, enemy_pole, fighting;
        vector <int> current_ship = {4, 3, 2, 1};
        int auto_pole = 0;
        virtual void setField()=0;
        virtual int Fire()=0;
        Field getMyPole(){
            return my_pole;
        }
        Field getEnemyPole(){
            return enemy_pole;
        }
        bool check_set_ship(vector<vector<string>> pole, int x, int y, int plane, int size){
            x -= 1;
            y -= 1;
            int count = 0;
            if (plane == 1){
                int left_border = x - 1;
                int rigth_border = x + 1;
                if (x - 1 < 0){
                    left_border = x;
                }
                if (x + 1 > 9){
                    rigth_border = x;
                }
                for(int i = y - 1; i < y + size + 1; i++){
                    if (i < -1 || i > 10){
                        cout << "За пределы поля ушел" << endl;
                        return false;
                    }
                    if (i == -1 || i == 10){
                        continue;
                    }
                    if ((i == y - 1) || (i == y + size)){
                        cout << "Проверка места по x" << i << " " << x << endl;
                        if (!((my_pole.pole[i][left_border] == " ") &&  my_pole.pole[i][x] == " " &&  (my_pole.pole[i][rigth_border] == " "))){
                            return false;
                        }
                    }else if (!((my_pole.pole[i][left_border] == " ") && my_pole.pole[i][x] == " " && (my_pole.pole[i][rigth_border] == " "))){
                            return false;
                        }
                    }
            }
            else{
                int top_border = y-1;
                int botton_border = y+1;
                if (y - 1 < 0){
                    top_border = y+1;
                }
                if (y + 1 > 9){
                    botton_border = y;
                }
                for(int i = x - 1; i < x + size + 1; i++){
                    if (i < -1 || i > 10){
                        cout << "За пределы поля ушел" << endl;
                        return false;
                    }
                    if (i == -1 || i == 10){
                        continue;
                    }
                    if ((i == x - 1) || (i == x + size)){
                        cout << "Проверка места по y" << i << " " << y << endl;
                        if (!((my_pole.pole[top_border][i] == " ") &&  my_pole.pole[y][i] == " " &&  (my_pole.pole[botton_border][i] == " "))){
                            return false;
                        }
                    }else if (!((my_pole.pole[top_border][i] == " ") &&  (my_pole.pole[botton_border][i] == " "))){
                            return false;
                        }
                    }
                
            }
            return true;
        }
        void copy_enemy_pole(vector<vector<string>> e_pole){
            for (int i = 0; i < e_pole.size(); i++){
                for (int j = 0 ; j < e_pole[i].size(); j++){
                    enemy_pole.pole[i][j] = e_pole[i][j];
                }
            }
        }
        void print_game_poles(){
            cout << "----------------------\t \t----------------------" << endl;
            for (int i = 0; i < 10; i++){
                cout << "|";
                for (int j = 0; j < 10; j++){ // печать моего поля
                    cout << my_pole.pole[i][j] << " ";
                }
                cout << "|\t \t";
                cout << "|";
                for (int j = 0; j < 10; j++){ // печать куда стрелял поля
                    cout << fighting.pole[i][j] << " ";
                }
                cout << "|" << endl;
            }
            cout << "----------------------\t \t----------------------" << endl;
        }
        int check_shoot(int x, int y){
            x-=1;
            y-=1;
            if (fighting.pole[y][x] != " "){
                cout << "Стреляешь уже проверенную клетку" << endl;
                return -1;
            }
            else if (enemy_pole.pole[y][x] == "#"){
                fighting.pole[y][x] = "X";
                return 1;
            }else{
                fighting.pole[y][x] = "*";
                return 0;
            }
        }
        void generanePole(){
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> distrib(1, 10);
            uniform_int_distribution<> distrib_plane(1, 2);
            int rand_x, rand_y, rand_plane;
            bool flag = true;
            vector <int> all_ship = {4, 3, 2, 1};
            int index = 3;
            while (index > -1)
            {
                if (all_ship[index] > 0){
                    rand_x = distrib(gen);
                    rand_y = distrib(gen);
                    rand_plane = distrib_plane(gen);
                    if (rand_plane == 1){
                        if (check_set_ship(my_pole.pole, rand_x, rand_y, rand_plane, index + 1)){
                            for (int i = rand_y - 1; i < rand_y - 1 + index + 1; i++){
                                my_pole.pole[i][rand_x - 1] = "#";
                            }
                        }else{
                            //cout << "Неправильное место размещение!!!" << endl;
                            continue;
                        }
                        }else{
                            if (check_set_ship(my_pole.pole, rand_x, rand_y, rand_plane, index + 1)){
                                for (int i = rand_x - 1; i < rand_x - 1 + index + 1; i++){
                                my_pole.pole[rand_y-1][i] = "#";
                            }
                            }else{
                                //cout << "Неправильное место размещение!!!" << endl;
                                continue;
                            }  
                        }
                        all_ship[index] -=1;
                        my_pole.PrintField();
                        //cout << "Бот ставит " << all_ship[0] << all_ship[1] << all_ship[2] << all_ship[3] << endl;
                        if (check_set_field(all_ship)){
                            flag = false;
                            cout << "Поле сгенереровано!"<< endl;
                        }
                }else{
                    index -= 1;
                }
            }
    }
        bool check_set_field(vector <int>pole){
            int count = 0;
            for (int x:pole){
                count += x;
            }
            return count == 0;
    }  
        int check_kill_ship(int x, int y){
            x -= 1;
            y -= 1;
            bool left_border = false;
            bool rigth_border = false;
            bool top_border = false;
            bool botton_border = false;
            if (x - 1 < 0){
                left_border = true;
            }
            if (x + 1 > 9){
                rigth_border = true;
            }
            if (y - 1 < 0){
                top_border = true;
            }
            if (y + 1 > 9){
                botton_border = true;
            }
            // проверка на однопалубный
            // cout << "Перед ошибкой!!!" << endl;
            // cout << x << " " << y << "коорданты перед падением" << endl;
            // cout << left_border << rigth_border << top_border << botton_border << "Значение флагов" << endl;
            try {
            if ((enemy_pole.pole[y][x] == "#") && (left_border || enemy_pole.pole[y][x - 1] == " ") && 
                (rigth_border || enemy_pole.pole[y][x + 1] == " ") && (top_border || enemy_pole.pole[y - 1][x] == " ") && 
                (botton_border || enemy_pole.pole[y + 1][x] == " ")){
                cout << "Проверка на маленький корабль" << endl;
                if (!left_border){
                    fighting.pole[y][x - 1] = '*';
                    if(!top_border)
                        fighting.pole[y - 1][x - 1] = '*';
                    if(!botton_border)
                        fighting.pole[y + 1][x - 1] = '*';
                }
                if (!rigth_border){
                    fighting.pole[y][x + 1] = '*';
                    if (!top_border)
                        fighting.pole[y - 1][x + 1] = '*';
                    if (!botton_border)
                        fighting.pole[y + 1][x + 1] = '*';
                }
                if(!top_border){
                    fighting.pole[y - 1][x] = '*';
                }
                if(!botton_border){
                    fighting.pole[y + 1][x] = '*';
                }
                current_ship[0] -= 1;
                return 1;
            }else if (enemy_pole.pole[y][x] == "#"){ // проверка большого
                // определение направления
                int directions = -1;
                if(!left_border){
                    if(enemy_pole.pole[y][x - 1] == "#"){
                        directions = 0;
                    }
                }
                if(!rigth_border){
                    if(enemy_pole.pole[y][x + 1] == "#"){
                        directions = 0;
                    }
                }
                if(!top_border){
                    if(enemy_pole.pole[y - 1][x] == "#"){
                        directions = 1;
                    }
                }
                if(!botton_border){
                    if(enemy_pole.pole[y + 1][x] == "#"){
                        directions = 1;
                    }
                }
                if (directions == -1){
                    cout << "Неопределил позицию" << endl;
                    return 0;
                }
                // найти стартовую позицию коробля
                int current_x = x, current_y = y;
                int start_x, start_y;
                bool flag = true;

                if (directions == 0){
                    while (current_x > -1 && enemy_pole.pole[y][current_x] == "#")
                    {
                        current_x -= 1;
                    }
                    
                    start_x = current_x;
                    start_y = current_y;
                    int size = 0;
                    for (int i = start_x + 1; i < start_x + 1 + 4; i++){
                        if(i >= 10) continue;
                        if (enemy_pole.pole[start_y][i] == "#" && fighting.pole[start_y][i] == " "){
                            flag = false;
                            break;
                        }else if (enemy_pole.pole[start_y][i] == " "){
                            break;
                        }
                        else{
                            size++;
                        }
                    }
                    if(flag){
                        for (int i = start_x; i < start_x + size + 2; i++){
                            if(i >= 10 || i < 0) continue;
                            if (i == start_x || i == start_x + size + 1){
                                if(!top_border) fighting.pole[start_y - 1][i] = "*";
                                if(!botton_border) fighting.pole[start_y + 1][i] = "*";
                                fighting.pole[start_y][i] = "*";
                                continue;
                            }
                            if(!top_border){
                                fighting.pole[start_y - 1][i] = "*";
                            }
                            if(!botton_border){
                                fighting.pole[start_y + 1][i] = "*";
                            }
                        }
                        cout << "Убил большого!!!" << endl; 
                        cout << "Размер " <<  size << endl;
                        cout << "нашед начальные кооринаты: " <<  current_x << " " << current_y << endl;
                        current_ship[size-1]-=1;
                        return 1;
                    }else{
                        if(directions == 1){
                            cout << "Вертикаль" << endl;
                        }else if (directions == 0){
                            cout << "Горизованталь" << endl;
                        }
                        cout << "Размер " <<  size << endl;
                        cout << "нашед начальные кооринаты: " <<  current_x << " " << current_y << endl;
                        cout << "НЕ УБИЛ!!!" << endl;
                    }  
                }else if(directions == 1){
                    while (current_y > -1 && enemy_pole.pole[current_y][x] == "#")
                    {
                        current_y -= 1;
                    }
                    
                    start_x = current_x;
                    start_y = current_y;
                    int size = 0;
                    for (int i = start_y + 1; i < start_y + 1 + 4; i++){
                        if(i >= 10) continue;
                        if (enemy_pole.pole[i][start_x] == "#" && fighting.pole[i][start_x] == " "){
                            flag = false;
                            break;
                        }if (enemy_pole.pole[i][start_x] == " "){
                            break;
                        }
                        else{
                            size++;
                        }
                    }
                    if(flag){
                        for (int i = start_y; i < start_y + size + 2; i++){
                            if(i >= 10 || i < 0) continue;
                            if (i == start_y || i == start_y + size + 1){
                                if(!left_border) fighting.pole[i][start_x - 1] = "*";
                                if(!rigth_border) fighting.pole[i][start_x + 1] = "*";
                                fighting.pole[i][start_x] = "*";
                                continue;
                            }
                            if(!left_border){
                                fighting.pole[i][start_x - 1] = "*";
                            }
                            if(!rigth_border){
                                fighting.pole[i][start_x + 1] = "*";
                            }
                        }
                        current_ship[size-1]-=1;
                        cout << "Убил большого!!!" << endl; 
                        cout << "Размер " <<  size << endl;
                        cout << "нашед начальные кооринаты: " <<  current_x << " " << current_y << endl;
                        return 1;
                }


            }
            else{
                cout << "просто зашел" << endl;
                return 0;
            }
            }
            }catch (const std::exception& e) { // Ловим все стандартные исключения
                std::cerr << "❗ Ошибка: " << e.what() << std::endl;
                std::cerr << "Тип ошибки: " << typeid(e).name() << std::endl;
            }catch (...) { // Ловим любые другие исключения (нестандартные)
                std::cerr << "❌ Неизвестная ошибка!" << std::endl;
            }
            cout << "После ошибки!!!" << endl;
            return 0;
        }
        bool check_win_game(){
            for (int x:current_ship){
                if (x != 0){
                    return false;
                }
            }
            return true;
        }
        void update_my_find(vector<vector<string>> e_pole){
            for (int i = 0; i < e_pole.size(); i++){
                for (int j = 0 ; j < e_pole[i].size(); j++){
                    if (e_pole[i][j] == "X"){
                        my_pole.pole[i][j] = "X";
                    }
                }
            }
        }
};

class Bot: public User{
    public:
    bool flag_fire = false;
    int direction = -1;
    bool search_posihion = false;
    int current_x, current_y, start_x, start_y;
    void setField(){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1, 10);
        uniform_int_distribution<> distrib_plane(1, 2);
        int rand_x, rand_y, rand_plane;
        bool flag = true;
        vector <int> all_ship = {4, 3, 2, 1};
        int foor = 1;
        int three = 2;
        int two = 3;
        int one = 4;
        int index = 3;
        while (index > -1)
        {
            if (all_ship[index] > 0){
                rand_x = distrib(gen);
                rand_y = distrib(gen);
                rand_plane = distrib_plane(gen);
                if (rand_plane == 1){
                    if (check_set_ship(my_pole.pole, rand_x, rand_y, rand_plane, index + 1)){
                        for (int i = rand_y - 1; i < rand_y - 1 + index + 1; i++){
                            my_pole.pole[i][rand_x - 1] = "#";
                        }
                    }else{
                        cout << "Неправильное место размещение!!!" << endl;
                        continue;
                    }
                    }else{
                        if (check_set_ship(my_pole.pole, rand_x, rand_y, rand_plane, index + 1)){
                            for (int i = rand_x - 1; i < rand_x - 1 + index + 1; i++){
                            my_pole.pole[rand_y-1][i] = "#";
                        }
                        }else{
                            cout << "Неправильное место размещение!!!" << endl;
                            continue;
                        }  
                    }
                    all_ship[index] -=1;
                    my_pole.PrintField();
                    cout << "Бот ставит " << all_ship[0] << all_ship[1] << all_ship[2] << all_ship[3] << endl;
                    if (check_set_field(all_ship)){
                        flag = false;
                        cout << "Расстановка закончена!"<< endl;
                    }
            }else{
                index -= 1;
            }
        }
    }

    int Fire(){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1, 10);
        int x = distrib(gen);
        int y = distrib(gen);
        int res;
        // cout << "Кординаты для бота " << endl;
        // cin >> x >> y;

        bool left_border = false;
        bool rigth_border = false;
        bool top_border = false;
        bool botton_border = false;
        if (x - 1 - 1  < 0){
            left_border = true;
        }
        if (x + 1 - 1 > 9){
            rigth_border = true;
        }
        if (y - 1 - 1< 0){
            top_border = true;
        }
        if (y + 1 - 1> 9){
            botton_border = true;
        }

        if (flag_fire && !search_posihion){ // поиск коробля вокруг
            // проверка справа
            res = -1;
            int repiat = 0;
            while (res == -1){ // стреляет в проверенную клетку
            if (((start_x + 1) < 10) && direction <= 0){
                res = check_shoot(start_x + 1, start_y);
                direction = 0;
            // проверка снизу
            }else if (((start_y + 1) < 10) && direction <= 1){
                res = check_shoot(start_x, start_y + 1);
                direction = 1;
            // проверка слева
            }else if (((start_x - 1) >= 0) && direction <= 2){
                res = check_shoot(start_x - 1, start_y);
                direction = 2;
            // провелка сверху
            }else if (((start_y - 1) >= 0) && direction <= 3){
                res = check_shoot(start_x, start_y - 1);
                direction = 3;
            }else{
                break;
            } 
            if (repiat > 4){
                cout  << "Бесконечный цикл" << endl;
                break;
            }
            if (res == -1){
                direction++;
            }
            if (direction >= 4){
                direction = 0;
                repiat++;
            }
            }
            
        }else{ // просто выстрел
            res = check_shoot(x, y);
            while (res == -1)
            {   
                x = distrib(gen);
                y = distrib(gen);
                res = check_shoot(x, y);
            }
        }
        
        
        
        if (res == 1 && flag_fire){
            if(!search_posihion){ // нашел положение
                search_posihion = true;
                if (check_kill_ship(current_x, current_y) == 1){
                    return res;
                }

                if (direction == 0){ // чтобы не стрелять в проверенную клетку
                    current_x += 1;
                } else if (direction == 1){
                    current_y += 1;
                } else if (direction == 2){
                    current_x -= 1;
                } else if (direction == 3){
                    current_y -= 1;
                }
            }if(search_posihion){
                if (direction == 0){
                    res = check_shoot(current_x + 1, current_y);
                    while (current_x <= 9 && res == 1)
                    {
                        current_x++;
                        res = check_shoot(current_x + 1, current_y);
                    }
                    if (check_kill_ship(current_x - 1, current_y) == 1){
                        cout << "Убил!! "<< direction << endl;
                        flag_fire = false;
                        search_posihion = false;
                        direction = -1;
                    }else{
                        direction =  (direction + 2)%4;
                        search_posihion = false;
                        current_x = start_x;
                        current_y = start_y;
                        cout << "БОТ не убил " << current_x << " " << current_y << endl;
                    }
                } else if (direction == 1){
                    res = check_shoot(current_x, current_y + 1);
                    while (current_y <= 9 && res == 1)
                    {   
                        current_y++;
                        res = check_shoot(current_x, current_y + 1);
                    }
                    if (check_kill_ship(current_x, current_y - 1) == 1){
                        cout << "Убил!! "<< direction << endl;
                        flag_fire = false;
                        search_posihion = false;
                        direction = -1;
                    }else{
                        direction =  (direction + 2)%4;
                        search_posihion = false;
                        current_x = start_x;
                        current_y = start_y;
                        cout << "БОТ не убил " << current_x << " " << current_y << endl;
                    }
                } else if (direction == 2){
                    res = check_shoot(current_x - 1, current_y);
                    while (current_x >= 0 && res == 1)
                    {
                        current_x--;
                        res = check_shoot(current_x - 1, current_y);
                    }
                    if (check_kill_ship(current_x + 1, current_y) == 1){
                        cout << "Убил!! "<< direction << endl;
                        flag_fire = false;
                        search_posihion = false;
                        direction = -1;
                    }else{
                        direction =  (direction + 2)%4;
                        search_posihion = false;
                        current_x = start_x;
                        current_y = start_y;
                        cout << "БОТ не убил " << current_x << " " << current_y << endl;
                    }
                } else if (direction == 3){
                    res = check_shoot(current_x, current_y - 1);
                    while (current_y >= 0 && res == 1)
                    {
                        current_y--;
                        res = check_shoot(current_x, current_y - 1);
                    }
                    if (check_kill_ship(current_x, current_y + 1) == 1){
                        cout << "Убил!! "<< direction << endl;
                        flag_fire = false;
                        search_posihion = false;
                        direction = -1;
                    }else{
                        direction =  (direction + 2)%4;
                        search_posihion = false;
                        current_x = start_x;
                        current_y = start_y;
                        cout << "БОТ не убил " << current_x << " " << current_y << endl;
                    }
                }
                
            }
        }else if(res == 1 && !flag_fire){ // попадание первый раз
            if (!flag_fire && !search_posihion && res != -1 && check_kill_ship(x,y) == 1){
                flag_fire = false;
                search_posihion = false;
                direction = -1;
                cout << "Убил!!" << endl;
                return res;
            }
            flag_fire = true;
            start_x = x;
            start_y = y;
            current_x = x;
            current_y = y;
            direction = 0;
        }else if (flag_fire){
            direction += 1;
        }
        if (!flag_fire && !search_posihion && res != -1 && check_kill_ship(x,y) == 1){
            flag_fire = false;
            search_posihion = false;
            direction = -1;
            cout << "Убил!!" << endl;
        }
        return res;
    }

};

class Player: public User{
    public:
        void setField(){
            if (auto_pole){
                generanePole();
                return ;
            }
            bool flag = true;
            vector <int> all_ship = {4, 3, 2, 1};
            int choice, plane, x, y;
            while (flag)
            {
                cout << "Выбирите корабль: " << endl;
                cout << "1) 1-парубы: " << all_ship[0] << endl;
                cout << "2) 2-парубы: " << all_ship[1] << endl;
                cout << "3) 3-парубы: " << all_ship[2] << endl;
                cout << "4) 4-парубы: " << all_ship[3] << endl;
                cin >> choice;
                cout << "Напишите координаты" << endl;
                cin >> x >> y;
                if (choice == 1){
                    plane = 1;
                }else{
                    cout << "Выберите плоскость" << endl;
                    cout << "1) Вертикаль" << endl;
                    cout << "2) Горизонталь" << endl;
                    cin >> plane;
                }
                if (plane == 1){
                    if (check_set_ship(my_pole.pole, x, y, plane, choice)){
                        for (int i = y - 1; i < y - 1 + choice; i++){
                            my_pole.pole[i][x - 1] = "#";
                        }
                    }else{
                        cout << "Неправильное место размещение!!!" << endl;
                        continue;
                    }
                }else{
                    if (check_set_ship(my_pole.pole, x, y, plane, choice)){
                        for (int i = x - 1; i < x - 1 + choice; i++){
                        my_pole.pole[y-1][i] = "#";
                    }
                    }else{
                        cout << "Неправильное место размещение!!!" << endl;
                        continue;
                    }  
                }
                all_ship[choice - 1] -=1;
                my_pole.PrintField();
                if (check_set_field(all_ship)){
                    flag = false;
                    cout << "Расстановка закончена!"<< endl;
                }
            }
        }

        int Fire(){
            int x, y;
            cout << "выберите координаты куда будете стрелять" << endl;
            cin >> x >> y;
            int res = check_shoot(x, y);
            while (res == -1)
            {   
                cin >> x >> y;
                res = check_shoot(x, y);
            }
            if (check_kill_ship(x,y) == 1){
                cout << "Убил!!" << endl;
            }
            
            return res;
        }

};


class Game{
    private:
        Player player;
        Bot bot;
    public:
        Game(){
            player.auto_pole = 1;
            player.setField();
            bot.setField();
            player.copy_enemy_pole(bot.my_pole.pole);
            bot.copy_enemy_pole(player.my_pole.pole);            
        }

        void start_game(){
            int queue = 1;
            int running = true;
            int result;
            while (running)
            {
                if (queue == 1){
                    cout << GREEN << "Поле Ваше" << WHITE  << endl;
                    player.print_game_poles();
                    result = player.Fire();
                    //cin >> running;
                    if (result == 0){
                        queue *= -1;
                        bot.update_my_find(player.fighting.pole);
                    }
                    if (result == 1){
                        cout << RED << "Попадание!!!" << WHITE <<  endl;
                        if (player.check_win_game()){
                            cout << GREEN << "Игрок победил!!!";
                            running = false;
                            break;
                        }
                    }
                }else{               
                    result = bot.Fire();
                    if (result == 0){
                        cout << GREEN  << "Поле Бота" << WHITE  << endl;
                        queue *= -1;
                        player.update_my_find(bot.fighting.pole);
                        bot.print_game_poles();
                    }else{
                        cout << "Бот попал !!" << endl;
                        if (bot.check_win_game()){
                            cout << GREEN << "Игрок победил!!!";
                            running = false;
                            break;
                        }
                    }
                }
                
                
            }
            
        }

        

};

int main(){
    Game game;
    game.start_game();
    return 0;
}