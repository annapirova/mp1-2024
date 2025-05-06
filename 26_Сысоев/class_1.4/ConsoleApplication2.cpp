// простой класс / 26.02.25 / 1.4. Конвертер длин /

#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <locale>

using namespace std;

class Conv {
private:
    double m;
    unordered_map<string, pair<string, double>> kf = {
        {"ft", {"футы", 3.28}},
        {"yd", {"ярды", 1.09}},
        {"arsh", {"аршины", 1.41}},
        {"sazh", {"сажени", 0.4686}},
    };

public:
    Conv() : m(0) {}
    Conv(double x) : m(x) {}

    void set(double x) {
        m = x;
    }

    void add(double x) {
        m += x;
    }

    void sub(double x) {
        m -= x;
        if (m < 0) m = 0;
    }

    double get() const {
        return m;
    }

    double conv(const string& u) const {
        if (kf.find(u) != kf.end()) {
            return m * kf.at(u).second;
        }
        else {
            cerr << "Ошибка, неизвестная единица измерения!" << endl;
            return 0;
        }
    }

    void out(const string& unit = "") const {
        cout.imbue(locale("")); 
        cout << "Длина: " << m << " метров" << endl;

        if (unit.empty()) {
            for (const auto& p : kf) {
                cout << " - " << p.second.first << ": " << fixed << setprecision(2) << conv(p.first) << endl;
            }
        }
        else {
            if (kf.find(unit) != kf.end()) {
                cout << " - " << kf.at(unit).first << ": " << fixed << setprecision(2) << conv(unit) << endl;
            }
            else {
                cout << "Ошибка: неизвестная единица измерения!" << endl;
            }
        }
    }
};

int main() {

    setlocale(LC_ALL, "Russian");
    Conv l;
    double val;
    int choice;
    string unit;

    while (true) {
        cout << "\n1. установить длину (м)\n2. увеличить длину (м)\n3. уменьшить длину (м)\n4. показать длину (всех единицах)\n5. Показать длину (в выбранной единице)\n6. выйти\nВыберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите длину (м): ";
            cin >> val;
            l.set(val);
            break;
        case 2:
            cout << "На сколько увеличить (м): ";
            cin >> val;
            l.add(val);
            break;
        case 3:
            cout << "На сколько уменьшить (м): ";
            cin >> val;
            l.sub(val);
            break;
        case 4:
            l.out();
            break;
        case 5:
            cout << "Введите код единицы измерения (ft, yd, arsh, sazh): ";
            cin >> unit;
            l.out(unit);
            break;
        case 6:
            return 0;
        default:
            cout << "неизвестная команда!" << endl;
        }
    }
}
