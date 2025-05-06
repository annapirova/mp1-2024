// 2.3 Вектор,  12.03.25

#include <iostream>
#include <cmath>
using namespace std;

class Vector {
private:
    int size;
    int* data;

public:

    Vector() {
        size = 0;
        data = nullptr;
    }

    Vector(int s) {
        size = s;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }

    Vector(const Vector& v) {
        size = v.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = v.data[i];
        }
    }

    Vector& operator=(const Vector& v) {
        if (this == &v) return *this;

        delete[] data;

        size = v.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = v.data[i];
        }
        return *this;
    }

    ~Vector() {
        delete[] data;
    }

    void setSize(int nSize) {
        if (nSize == size) return;

        delete[] data;

        size = nSize;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }

    int getSize() {
        return size;
    }

    void setComponent(int ind, int value) {
        if (ind >= 0 && ind < size) {
            data[ind] = value;
        }
        else {
            cout << "Ошибка: выход за границы вектора" << endl;
        }
    }

    int getComponent(int ind) {
        if (ind >= 0 && ind < size) {
            return data[ind];
        }
        else {
            cout << "Ошибка: выход за границы вектора" << endl;
            return 0;
        }
    }

    double len() {
        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum += pow(data[i], 2);
        }
        return sqrt(sum);
    }

    // Перегрузка + 
    Vector operator+(Vector& v) {
        Vector result(size);
        if (size != v.size) {
            cout << "Ошибка, разный размер векторов или отсутствие одного из них" << endl;
            return result;
        }
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] + v.data[i];
        }
        return result;
    }

    // Перегрузка * 
    int operator*(Vector& v) {
        if (size != v.size) {
            cout << "Ошибка, разный размер векторов или отсутствие одного из них" << endl;
            return 0;
        }
        int res = 0;
        for (int i = 0; i < size; i++) {
            res += data[i] * v.data[i];
        }
        return res;
    }

    friend ostream& operator<<(ostream& os, Vector& v);
};


ostream& operator<<(ostream& ost, Vector& v) {
    ost << "[ ";
    for (int j = 0; j < v.size; j++) {
        ost << v.data[j] << " ";
    }
    ost << "]";

    return ost;
}


void fillVector(Vector& v) {
    int n = v.getSize();
    cout << "Введите " << n << " целых чисел:" << endl;
    for (int i = 0; i < n; i++) {
        int val;
        cout << "Элемент [" << i << "]: ";
        cin >> val;
        v.setComponent(i, val);
    }
}


void showMenu() {

    cout << "\n==============================\n";
    cout << "              МЕНЮ\n";
    cout << "==============================\n";
    cout << "1. Создать вектор\n";
    cout << "2. Заполнить вектор \n";
    cout << "3. Показать текущий вектор\n";
    cout << "4. Длина вектора\n";
    cout << "5. Скалярное произведение двух векторов\n";
    cout << "6. Сложение двух векторов\n";
    cout << "7. Выход\n";
    cout << "==============================\n";
    cout << "Выберите действие: ";
}

int main() {
    setlocale(LC_ALL, "Russian");
    Vector v1, v2;
    bool exit = false;

    while (!exit) {
        showMenu();
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            int size;
            cout << "Введите размер вектора: ";
            cin >> size;
            v1.setSize(size);
            cout << "Вектор создан." << endl;
            break;
        }
        case 2: {
            if (v1.getSize() == 0) {
                cout << "Для этого создайте сначала вектор" << endl;
                break;
            }
            fillVector(v1);
            break;
        }
        case 3: {
            cout << "Текущий вектор: " << v1 << endl;
            break;
        }
        case 4: {
            cout << "Длина вектора: " << v1.len() << endl;
            break;
        }
        case 5: {
            cout << "Создайте второй вектор" << endl;
            int size;
            cout << "Размер: ";
            cin >> size;
            v2.setSize(size);
            fillVector(v2);

            cout << "Скалярное произведение: " << v1 * v2 << endl;
            break;
        }
        case 6: {
            cout << "Создайте второй вектор" << endl;
            int size;
            cout << "Размер: ";
            cin >> size;
            v2.setSize(size);
            fillVector(v2);

            Vector sum = v1 + v2;
            cout << "Сумма векторов: " << sum << endl;
            break;
        }

        case 7: {
            exit = true;
            cout << "Выход..." << endl;
            break;
        }
        default:
            cout << "Неверный выбор" << endl;
        }
    }

    return 0;
}