#include <stdlib.h>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector> 

using namespace std;

vector <string> type_weaher = {"Солнечно", "Пасмурно", "Дождливо", "Ветренно"};

typedef struct discover
{
    int day;
    int mount;
    int year;
    int hour;
    int minute;
    string specification;
    double temperature;
} discover;

bool operator==(const discover &a, const discover &b)
{   
    return (a.year == b.year && a.mount== b.mount && a.day == b.day && a.hour == b.hour && a.minute == b.minute);
}


bool check_time(string& str){
    return (count(str.begin(), str.end(), ':') == 1) && (str.find("id:") == -1);
}

bool check_date(string& str){
    return count(str.begin(), str.end(), '/') == 2;
}

bool check_temp(string& str){
    return count(str.begin(), str.end(), '.') > 0;
}

bool check_command(string& str){
    vector <string> type_command = {"get", "set"};
    for (int i = 0; i < type_command.size(); i++){
        if (type_command[i] == str){
            return true;
        }
    }
    return false;
}


int levenshteinDistance(const string &s1, const string &s2) {
    const size_t len1 = s1.size(), len2 = s2.size();
    vector<vector<int>> d(len1 + 1, vector<int>(len2 + 1));

    for (size_t i = 0; i <= len1; ++i){
        d[i][0] = i;
    }
    for (size_t j = 0; j <= len2; ++j){ 
        d[0][j] = j;
    }
    for (size_t i = 1; i <= len1; ++i) {
        for (size_t j = 1; j <= len2; ++j) {
            int cost = (s1[i-1] == s2[j-1]) ? 0 : 1;
            d[i][j] = min({ d[i-1][j] + 1,      // удаление
                                 d[i][j-1] + 1,      // вставка
                                 d[i-1][j-1] + cost  // замена
                               });
        }
    }
    return d[len1][len2];
}


int check_weaher(string& str){
    for (int i = 0; i < type_weaher.size(); i++){
        if (levenshteinDistance(type_weaher[i], str) <= 2){
            return i;
        }
    }
    return -1;
}

bool check_id(string& str){
    return str.find("id:") != -1;
}


class Thermometer{
    private:
        discover *all_info;
        int fullness;
        int size;

        void AddMemory(){
            discover *tmp = new discover[fullness+10];
                for(int i = 0; i < size; i++){
                    tmp[i] = all_info[i];
                }
                delete[] all_info;
                all_info = tmp;
                size = fullness+10;
        }

        void WorkCommand(vector <string> arr){
            if (arr[0] == "set"){
                int id = -1;
                double temp = -1000000;
                string weaher = "";
                for (int i = 1; i < arr.size(); i++){
                    if (check_id(arr[i])){
                        //cout << arr[i].substr(arr[i].find("id:")+3) << " str" << endl;
                        id = stoi(arr[i].substr(arr[i].find("id:")+3));
                    }else if(check_temp(arr[i])){
                        temp = stod(arr[i]);
                    } else if (check_weaher(arr[i]) != -1){
                        weaher = type_weaher[check_weaher(arr[i])];
                    }
                }
                if (id != -1){
                    if (weaher != "")
                        all_info[id - 1].specification = weaher;
                    if (temp != -1000000)
                        all_info[id - 1].temperature = temp;
                }
            }
            else if (arr[0] == "get"){
                if (arr[1] == "min"){
                    this->SearchMin();
                }else if(arr[1] == "max"){
                    this->SearchMax();
                }else if (arr[1] == "average"){
                    this->SearchAverage();
                }
                else{
                    discover start, end;
                    for (int i = 1; i<arr.size();i++){
                        vector <string> date;
                        string token;
                        istringstream tokenStream(arr[i]);
                        while (getline(tokenStream, token, '/')) {
                            date.push_back(token);
                        }
                        if (i == 1){
                            start.year = stoi(date[0]);
                            start.mount = stoi(date[1]);
                            start.day = stoi(date[2]);
                        }else{
                            end.year = stoi(date[0]);
                            end.mount = stoi(date[1]);
                            end.day = stoi(date[2]);
                        }
                    }
                    cout << "События в выбранном периоде" << endl;
                    for (int i = 0; i < fullness; i++){
                        if(start.year <= all_info[i].year <= end.year && start.mount<= all_info[i].mount <= end.mount && 
                        start.day <= all_info[i].day <= end.day){
                            cout << "Год: " << all_info[i].year << " Месяц: " << all_info[i].mount << " День: " << 
                            all_info[i].day  << " Часы: " << all_info[i].hour << " Минуты: " << all_info[i].minute << endl;
                            cout << "Описание: " << all_info[i].specification << endl; 
                            cout << "Температура: " << all_info[i].temperature << endl; 
                        }
                    }
                    cout << "---------------" << endl;
                }
            }
        }

    public:
        Thermometer(int s=0){size = s; all_info = new discover[s]; fullness = 0;};
        void SetData(int year=0, int mount=0, int day=0, int series=1){
            int hour, minute;
            bool flag = true;
            if (year == 0 && mount == 0 && day==0 && series==1){
                cout << "Введите год: ";
                cin >> year;
                cout << "Введите месяц: ";
                cin >> mount;
                cout << "Введите день: ";
                cin >> day;
            }
            for (int i = 0; i < series; i++){
                cout << "Введите час: ";
                cin >> hour;
                cout << "Введите минуты: ";
                cin >> minute;
                discover notes;
                notes.year = year; notes.mount = mount; notes.day = day; notes.hour = hour; notes.minute = minute;
            
                for (int i = 0; i < fullness; i++){
                    if(notes == all_info[i]){
                        all_info[i].year = notes.year; all_info[i].mount = notes.mount; all_info[i].day = notes.day; 
                        all_info[i].hour = notes.hour; all_info[i].minute = notes.minute;
                        flag=false;
                        break;
                    }
                }
                if (flag){
                    if (size == fullness){
                        this->AddMemory();
                    }
                    all_info[fullness] = notes;
                    fullness++;
                    cout << size << " " << fullness << endl;
                }
            }
            
        }
        void GetData(){
            for (int i = 0; i < fullness; i++){
                cout << "Год: " << all_info[i].year << " Месяц: " << all_info[i].mount << " День: " << 
                all_info[i].day  << " Часы: " << all_info[i].hour << " Минуты: " << all_info[i].minute << endl;
            }
        }
        void SetObservation(){
            for (int i = 0; i < fullness; i++){
                cout << "ID:" << i+1 << "| Год: " << all_info[i].year << " Месяц: " << all_info[i].mount << " День: " << 
                all_info[i].day  << " Часы: " << all_info[i].hour << " Минуты: " << all_info[i].minute << endl;
            }
            cout << "Выбирете ID наблюдения, чтобы задать его"<<endl;
            int tmp;
            double temp;
            string notes;
            cin >> tmp;
            cout << "Добавьте описание для наблюдения" << endl;
            cin >> notes;
            cout << "Добавьте температуру для наблюдения" << endl;
            cin >> temp;
            all_info[tmp - 1].specification = notes;
            all_info[tmp - 1].temperature = temp;
            cout << "Описание добавлено!!"<<endl;

        }
        void GetTemperature(){
            for (int i = 0; i < fullness; i++){
                cout << "ID:" << i+1 << "| Год: " << all_info[i].year << " Месяц: " << all_info[i].mount << " День: " << 
                all_info[i].day  << " Часы: " << all_info[i].hour << " Минуты: " << all_info[i].minute << endl;
            }
            cout << "Выбирете ID наблюдения, чтобы узнать температуру"<<endl;
            int tmp;
            cin >> tmp;
            cout << "Температура равна: " << all_info[tmp - 1].temperature << endl;
        }
        void SetSeriesObservation(int year=2015, int mount=1, int day=1){
            int series;
            cout << "Сколько задать наблюдений: ";
            cin >> series;
            SetData(year, mount, day, series);
        }
        void SearchMiddleTemperature(){
            int a;
            cout << "Выберите как хотите узнать среднюю температуру"<<endl;
            cout << "1) Своя дата" << endl;
            cout << "2) Определенный месяц" << endl;
            cout << "3) За всю история" << endl;
            cin >>a;
            int hour, minute, year, mount, day;
            double temp = 0;
            double count = 0;
            if (a == 1){
                cout << "Введите год: ";
                cin >> year;
                cout << "Введите месяц: ";
                cin >> mount;
                cout << "Введите день: ";
                cin >> day;
                for (int i = 0; i < fullness; i++)
                    if (all_info[i].year == year && all_info[i].mount == mount && all_info[i].day == day){
                        temp += all_info[i].temperature;
                        count++;
                    }
            }else if (a == 2){
                cout << "Введите месяц: ";
                    cin >> mount;
                for (int i = 0; i < fullness; i++)
                    if (all_info[i].mount == mount){
                        temp += all_info[i].temperature;
                        count++;
                    }  
            }else{
                for (int i = 0; i < fullness; i++){
                    temp += all_info[i].temperature;
                    count++;
                }
            }
            if (count > 0){
                cout << "Средняя температура: " << temp/count << endl; 
            }else{
                cout << "Нет наблюдений в этом периоде" << endl;
            }

        
        } //выбранной даты, выбранного месяца, за всю историю наблюдений
        void SearchDayNightTemp(int m = 1){
            cout << "Выбирите для какую найти температуру:" << endl;
            cout << "1) Дневную" << endl;
            cout << "2) Ночную" << endl;
            int tmp;
            double temp = 0;
            double count = 0;
            cin >> tmp;
            for (int i = 0; i < fullness; i++){
                if(tmp == 1){
                    if(all_info[i].mount == m && all_info[i].hour >= 6 && all_info[i].hour <= 21){
                        temp += all_info[i].temperature;
                        count+=1;
                    }
                }else{
                    if(all_info[i].mount == m && (all_info[i].hour < 6 || all_info[i].hour > 21)){
                        temp += all_info[i].temperature;
                        count+=1;
                    }
                }
            }
            if (count > 0){
                if(tmp == 1){
                    cout << "Средняя дневная температура равна: " << temp/count <<endl;
                }else{
                    cout << "Средняя ночная температура равна: " << temp/count <<endl;
                }
            }else{
                cout << "Нет наблюдений в этом периоде" << endl;
            }
        }
        void SaveHistory(){
            ofstream outFile("output.txt");
            if (!outFile.is_open()) {
                cout << "Не удалось открыть файл для записи: " << "output.txt" << endl;
            }
            for (int i = 0; i < fullness; i++) {
                outFile << all_info[i].year << " " << all_info[i].mount << " " << all_info[i].day << " " << 
                all_info[i].hour << " " << all_info[i].minute << " " << all_info[i].specification << " " << 
                all_info[i].temperature << endl; 
            }
            outFile.close();
        }
        void LoadHistory(){
            
            ifstream inFile("input.txt");
            string line;
            if (!inFile.is_open()) {
                cout << "Не удалось открыть файл: " << "input.txt" << endl;
              
            }
            int count = 0;
            
            while (std::getline(inFile, line)) {
                if (line.empty()) continue;
                // Используем stringstream для разбиения строки по пробелам
                istringstream iss(line);
                string word;
                bool flag_command = false;

                // Разбиваем строку на слова
                vector <string> split_space;
                discover notes;
                notes.year = 0;  notes.mount = 0;  notes.day = 0; notes.hour = 0; notes.minute = 0;
                while (iss >> word) {
                    split_space.push_back(word);
                }
                if (size == fullness){
                    this->AddMemory();
                }
                for (int i = 0; i < split_space.size(); i++){
                    if (check_command(split_space[i])){
                        flag_command = true;
                        break;
                    }else if (check_time(split_space[i])){
                        vector <string> time;
                        string token;
                        istringstream tokenStream(split_space[i]);
                        while (getline(tokenStream, token, ':')) {
                            time.push_back(token);
                        }
                        // all_info[fullness].hour = stoi(time[0]);
                        // all_info[fullness].minute = stoi(time[1]);
                        notes.hour = stoi(time[0]);
                        notes.minute = stoi(time[1]);

                    }
                    else if (check_date(split_space[i])){
                        vector <string> date;
                        string token;
                        istringstream tokenStream(split_space[i]);
                        while (getline(tokenStream, token, '/')) {
                            date.push_back(token);
                        }
                        // all_info[fullness].year = stoi(date[0]);
                        // all_info[fullness].mount = stoi(date[1]);
                        // all_info[fullness].day = stoi(date[2]);
                        notes.year = stoi(date[0]);
                        notes.mount = stoi(date[1]);
                        notes.day = stoi(date[2]);
                    }else if (check_temp(split_space[i])){
                        // all_info[fullness].temperature = stod(split_space[i]);
                        notes.temperature = stod(split_space[i]);
                    }else if (check_weaher(split_space[i]) != -1){
                        // all_info[fullness].specification = split_space[i];
                        notes.specification = type_weaher[check_weaher(split_space[i])];
                    }
                }
                if (flag_command){
                    this->WorkCommand(split_space);
                }else if (notes.year != 0 && notes.mount != 0 && notes.day != 0 && notes.hour != 0 && notes.minute != 0){
                    all_info[fullness].hour = notes.hour;
                    all_info[fullness].minute = notes.minute;
                    all_info[fullness].year =  notes.year;
                    all_info[fullness].mount = notes.mount;
                    all_info[fullness].day =  notes.day;
                    all_info[fullness].temperature = notes.temperature;
                    all_info[fullness].specification=  notes.specification;
                    fullness++;
                    count++;
                    
                }
            }
            inFile.close(); 
        }

        void PrintInfo(){
            for (int i = 0; i < fullness; i++){
                cout << "Год: " << all_info[i].year << " Месяц: " << all_info[i].mount << " День: " << 
                all_info[i].day  << " Часы: " << all_info[i].hour << " Минуты: " << all_info[i].minute << endl;
                cout << "Описание: " << all_info[i].specification << endl; 
                cout << "Температура: " << all_info[i].temperature << endl; 
            }
        }

        void SearchMin(){
            double minumym = 10000000;
            for (int i = 0; i < fullness; i++){
                minumym = min(all_info[i].temperature, minumym);    
            }
            cout << "Минимальная температура" << endl;
            cout << minumym << endl;
        }

        void SearchMax(){
            double maximym = -10000000;
            for (int i = 0; i < fullness; i++){
                maximym = max(all_info[i].temperature, maximym);    
            }
            cout << "Максимальная температура" << endl;
            cout << maximym << endl;
        }

        void SearchAverage(){
            double temp = 0, count = 0;
            for (int i = 0; i < fullness; i++){
                temp += all_info[i].temperature;
                count++;
            }
            cout << "Средняя температура" << endl;
            cout << temp/count << endl;
        }
 
        ~Thermometer(){delete[] all_info;};
};



int main(){
    Thermometer a1;
    //a1.SetData(2024, 12, 12);
    a1.LoadHistory();
    a1.PrintInfo();
    
    return 0;
}