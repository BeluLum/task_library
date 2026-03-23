

#include <map>
#include <iostream>
#include <iomanip>
#include <fstream> 
#include <string> 
#include <algorithm> 
using namespace std;

class Train
{

public:

    string destination_point;
    string train_number;
    string departure_time;
    int all_seats;
    int coupe_seats;
    int open_sleeper_seats;

    Train(string point, string  number, string time, int seats, int coupe, int sleeper) {
    destination_point = point;
    departure_time = time;
    train_number = number;
    all_seats = seats;
    coupe_seats = coupe;
    open_sleeper_seats = sleeper;
    }


    void SetDestination_point(string point) {
        destination_point = point;
    }

    void SetTrain_number(string number) {
        train_number = number;

    }

    void SetDeparture_time(string point) {
        departure_time = point;

    }

    void SetAll_seats(int seats) {
        all_seats = seats;

    }

    void SetCoupe_seats(int seatss) {
        coupe_seats = seatss;
    }

    void SetOpen_sleeper_seats(int seatsss) {
        open_sleeper_seats = seatsss;

    }

    void show() const {
        cout << "Точка назначения: " << destination_point << " Номер поезда: " << train_number << " Время пребытия: " << departure_time << " Все места: " << all_seats << " Купе места:" << coupe_seats << "Плацкарт места" << open_sleeper_seats;
    }



    string GetDestination_point() {
        return  destination_point;

    }

    string GetTrain_number() {
        return train_number;

    }

    string GetDeparture_time() {
        return departure_time;

    }

    int GetAll_seats() {
        return all_seats;

    }

    int GetCoupe_seats() {
        return coupe_seats;
    }

    int GetOpen_sleeper_seats() {
        return open_sleeper_seats;

    }





};


string remove_colons(string str) {
    string result;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ':') {
            result += str[i];
        }
    }
    return result;
}

int main()
{
    setlocale(LC_ALL, "Russian");


    Train first_train( "Prague", "12:22","11A", 100, 80, 40);
    Train second_train("Lisbon", "14:00", "24A", 120, 50, 70);
    Train third_train("Hamburg", "6:00", "03B", 200, 100, 100);
  

    Train trains[3] = { first_train, second_train, third_train };

    string required_info;
    bool seccusec_flag = false;

    cout << "Введите нужный пункт назначения" << endl;
    cin >> required_info;
    cout << "Подходящие поезда:" << endl;

        for (int i = 0; i < 3; i++) {
            if (required_info == trains[i].destination_point) {
                cout << trains[i].train_number << endl;
                seccusec_flag = true;
            }
        }
    if (seccusec_flag == false) {
    cout << "В текущий момент соответствующих рейсов нет" << endl;
    }


    string required_info1;
    string required_time;

    cout << "Введите нужный пункт назначения" << endl;
        cin >> required_info;
        cout << "Введите время:" << endl;
        cin >> required_time;
    cout << "Подходящие поезда:" << endl;

        for (int i = 0; i < 3; i++) {
            if (required_info == trains[i].destination_point) {
                string d_remove_colons = remove_colons(required_time);
                string k_remove_colons = remove_colons(trains[i].departure_time);
                int int_required_time = stoi(d_remove_colons);
                int int_departure_time = stoi(k_remove_colons);
                    if (int_departure_time > int_required_time) {
                        cout << trains[i].train_number << endl;
                        seccusec_flag = true;
                    }
            }

               
        }\
    if (seccusec_flag == false) {
        cout << "В текущий момент соответствующих рейсов нет" << endl;
    }

    string required_info2;

    cout << "Введите нужный пункт назначения" << endl;
    cin >> required_info;

    cout << "Подходящие поезда со свободными местами:" << endl;
        for (int i = 0; i < 3; i++) {
            if ((required_info == trains[i].destination_point) && (trains[i].all_seats > 0)) {
                cout << trains[i].train_number << endl;
                seccusec_flag = true;
            }
        }
    if (seccusec_flag == false) {
        cout << "В текущий момент соответствующих рейсов нет" << endl;
    }
}
