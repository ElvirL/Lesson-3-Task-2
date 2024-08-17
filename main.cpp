/*
2. ������ ������ ��� ������
��� ����� �������
��������� ��������� ������, �������� ��������� ������ ������.
��� ��������
� ������ ������� �� ��������, � � ������� ������� ���� ���� �����.
� �� ����� ������� ����� ������ ����� ���, � ����� ����� ���� � ������ ����������:
� �����,
� ����� (�������),
� ����.
� � ������� ������ ���� ���������� � �������, ������� ��� �������� �� �������.
� � ���� ����� ���� 1�3 �����, �� ����� � 2�4 �������:
� �������,
� �����,
� ������,
� �������,
� ��������.
� � ������� ����� ���� ���������� � ���������� ������ � ������ ������� �� �����.
� � ������ ������� ���� ���������� � ���������� �������.
� � ���� � ���� ����� ���� ���� � ������.
��� ���� ���������� ��������� ����� �������� ��������� ������.

����������� ��� ���������� �������
������� ��������� ������ ��� �������� ������ ������. ��������� ������ ����:
� �������� � ����� ������������,
� ��� ����������� �����������.

�������������
���������� ���������� �������� ������.
������������ ��������� ������ � ������: ������ ����� ���������� ��������, � ����� ������������ ������.
������� ����������� ���������� �������� �� �������, � ����� � ����������, ����� ��� ���������, ������� ������ � ����, 
����� ������� �� ������.
����� ����� ������ ����� ���������� ��������� ��������, �������� ������� �����, ���������� �����������, �� ����� ������� ������. 
������� � ���� ������ �� �������� ��������, � ��������� ������.

������ � ������������
� ����������� ���� ������ � ����� ������ � C++.
� ����� ��������� ������������ � �������, ��������� ��������� ������ �������� � ��� �����.
� ����������� ������� � ���� ������ ����� ��������� �������:

enum room_type
{
living,
children,
�

� ����� ����� ������������ ���������� ��� ������ ���������. �������� ���������� ������� ������� ����������:
� ������� ������ ������� ����,
� ������ � ���������� ��������,
� �������� ������ � ������ ��� ������ push_back.
*/

#include <iostream>
#include <vector>

using namespace std;

enum construction_type{
    garage,
    barn
};

enum room_type {
    bedroom,
    kitchen,
    bathroom,
    children,
    living
};

struct construction{
    construction_type type;
    int square = 0;
};

struct room{
    room_type type;
    int square =0;
};

struct floor_house{
    int number=0;
    int count_room = 0;
    int ceiling_height = 0;
    vector<room> rooms;
};

struct bathouse{
    int square = 0;
    bool have_stove = false;
};

struct house{
    int square = 0;
    int number_floors = 0;
    vector<floor_house> floors;
    bool have_stove = false;
};

struct area{    
    int number = 0;
    int count_construction_in_area = 0;
    vector<construction> construction_in_area;
    house house_in_area;
    bathouse bathouse_in_area;
};

int main(){
    setlocale(LC_ALL, "Russian");
    cout << "������� ���������� ��������: ";
    int count_area;
    cin >> count_area;
    vector<area> village;

    for (int i=0; i<count_area; ++i){
        area area_on_village;

        cout << "������� ����� �������: ";
        int number_area;
        cin >> number_area;
        area_on_village.number = number_area;

        cout << "������� ���������� �������� �� �������: ";
        int count_construction;
        cin >> count_construction;
        area_on_village.count_construction_in_area = count_construction;

        cout << "������� ������� ����, (������� 0 ���� �� ������� ��� ����): ";
        int square_house;
        cin >> square_house;
        if (square_house != 0){
            area_on_village.house_in_area.square= square_house;
            cout << "������� ���������� ������ � ����: ";
            int count_floors;
            cin >> count_floors;
            area_on_village.house_in_area.number_floors = count_floors;
            for (int i=1; i<=count_floors; ++i){
                floor_house f;
                f.number = i;
                cout << "������� ������ ������� �� ����� " << i << " �����" << endl; 
                int ceiling_height;
                cin >> ceiling_height;
                f.ceiling_height = ceiling_height;
                cout << "������� ���������� ������ �� " << i << " �����: ";
                int count_room;
                cin >> count_room;
                f.count_room = count_room;

                cout << "��������������� ������� ��� � ������� �������:" << endl;
                for (int i=1; i<=count_room; ++i){
                    room r;
                    cout << "������� ����� ��������������� ���� �������:" << endl;
                    cout << "1. C������;" << endl;
                    cout << "2. �����;" << endl;
                    cout << "3. ������;" << endl;
                    cout << "4. �������;" << endl;
                    cout << "5. ��������." << endl;
                    cout << "�����: ";
                    int number_room;
                    cin >> number_room;
                    while (number_room<1 || number_room >5){
                        cout << "������� ����� �� 1 �� 5: ";
                        cin >> number_room;
                    }
                    if (number_room == 1)
                        r.type = bedroom;
                    else if (number_room == 2)
                        r.type = kitchen;
                    else if (number_room == 3)
                        r.type = bathroom;
                    else if (number_room == 4)
                        r.type = children;
                    else if (number_room == 5)
                        r.type = living;

                    cout << "������� ������� �������: ";
                    int square_room;
                    cin >> square_room;
                    r.square = square_room;

                    f.rooms.push_back(r);
                }
                area_on_village.house_in_area.floors.push_back(f);
            }
            cout << "������� �� � ���� ����? (������� 1, ���� �������, ������� 0, ���� �� �������): ";
            int have_stove;
            cin >> have_stove;
            while (have_stove != 0 && have_stove != 1){
                cout << "������� 0 ��� 1: ";
                cin >> have_stove;
            }
            if (have_stove == 1)
                area_on_village.house_in_area.have_stove == true;
        }
        cout << "������� ������� ���� �� ����������. ���� ���� ���������� ������� 0: ";
        int square_bathouse;
        cin >> square_bathouse;
        if (square_bathouse > 0){
            area_on_village.bathouse_in_area.have_stove = true;
            area_on_village.bathouse_in_area.square = square_bathouse;
            ++area_on_village.count_construction_in_area;
        }

        cout << "������� ������� ������ �� ����������. ���� ����� ����������� ������� 0: ";
        int square_garage;
        cin >> square_garage;
        if (square_garage > 0){
            construction garage_in_area;
            garage_in_area.square = square_garage;
            garage_in_area.type = garage;
            ++area_on_village.count_construction_in_area;
            area_on_village.construction_in_area.push_back(garage_in_area);
        }

        cout << "������� ������� ����� (�������). ���� ����� (�������) ����������� ������� 0: ";
        int square_barn;
        cin >> square_barn;
        if (square_barn > 0){
            construction barn_in_area;
            barn_in_area.square = square_barn;
            barn_in_area.type = barn;
            ++area_on_village.count_construction_in_area;
            area_on_village.construction_in_area.push_back(barn_in_area);
        }
       cout << "������� � " << number_area << " ��������." << endl;
       village.push_back(area_on_village); 
    }
    
}