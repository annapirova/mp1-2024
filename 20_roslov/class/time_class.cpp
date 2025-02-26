#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <map>

using namespace std;

class Datetime{
    private:
        int hour;
        int minutes;
        int seconds;
    public:
       
        void setTime(int h=0, int m=0, int s=0){
            hour = (h > 0) ? (h % 24) : 0;
            minutes = (m > 0) ? (m % 60 ): 0;
            seconds = (s > 0) ? (s % 60) : 0;
            cout << "Время установленно" << endl;
        }
        string getTime(){
            cout << "Текущее время" << endl;
            return to_string(hour) + ":" + to_string(minutes) + ":" + to_string(seconds);
        }
        void differenceTime(int h=0, int m=0, int s=0){
            cout << "Разница во времени" << endl;
            cout << abs(hour - h) << ":" << abs(minutes - m) << ":" << abs(seconds - s) << endl; 
        }

        void deltaTime(int h=0, int m=0, int s=0, string side="+"){
            int flag = 1;
            if (side == "-"){
                flag = -1;
            }
            hour += h * flag;
            minutes += m * flag;
            seconds += s * flag;
            checkTime();
            cout << "Время успешно преведено" << endl;
        }

        void checkTime(){
            hour = (hour > 0) ? (hour % 24) : 0;
            minutes = (minutes > 0) ? (minutes % 60 ): 0;
            seconds = (seconds > 0) ? (seconds % 60) : 0;
        }

        Datetime(int h=0, int m=0, int s=0){
            hour = (h > 0) ? (h % 24) : 0;
            minutes = (m > 0) ? (m % 60 ): 0;
            seconds = (s > 0) ? (s % 60) : 0;
        };
        ~Datetime(){};
};


int main(){
    Datetime test(100,100,100);
    cout << test.getTime() << endl;
    test.setTime(10,10,10);
    cout << test.getTime() << endl;
    test.deltaTime(5, 0, 5, "-");
    cout << test.getTime() << endl;
    test.differenceTime(5, 5, 5);
    return 0;
}