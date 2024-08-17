/*
2. Модель данных для посёлка
Что нужно сделать
Используя структуры данных, создайте подробную модель посёлка.
Что известно
• Посёлок состоит из участков, и у каждого участка есть свой номер.
• На любом участке может стоять жилой дом, а также могут быть и другие сооружения:
— гараж,
— сарай (бытовка),
— баня.
• У каждого здания есть информация о площади, которую оно занимает на участке.
• В доме может быть 1–3 этажа, на этаже — 2–4 комнаты:
— спальня,
— кухня,
— ванная,
— детская,
— гостиная.
• У каждого этажа есть информация о количестве комнат и высоте потолка на этаже.
• У каждой комнаты есть информация о занимаемой площади.
• В доме и бане может быть печь с трубой.
Для всех упомянутых сущностей нужно объявить структуры данных.

Обязательно для выполнения задания
Опишите структуры данных для создания модели посёлка. Структуры должны быть:
• связными и легко расширяемыми,
• без дублирующих конструкций.

Дополнительно
Реализуйте заполнение структур данных.
Пользователь заполняет данные о посёлке: вводит общее количество участков, а потом детализирует каждый.
Сначала указывается количество построек на участке, а затем — информация, какие это постройки, сколько этажей в доме, 
какие комнаты на этажах.
После ввода данных можно рассчитать суммарный параметр, например процент земли, занимаемой постройками, от общей площади посёлка. 
Главное в этой задаче не операция подсчёта, а структуры данных.

Советы и рекомендации
• Используйте свои знания о типах данных в C++.
• Можно применять перечисления и векторы, создавать структуры внутри структур и так далее.
• Перечислять комнаты и типы зданий нужно следующим образом:

enum room_type
{
living,
children,
…

• Затем нужно использовать полученный тип внутри структуры. Алгоритм заполнения каждого объекта одинаковый:
— создать объект нужного типа,
— ввести с клавиатуры значения,
— добавить объект в вектор при помощи push_back.
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
    cout << "Введите количество участков: ";
    int count_area;
    cin >> count_area;
    vector<area> village;

    for (int i=0; i<count_area; ++i){
        area area_on_village;

        cout << "Введите номер участка: ";
        int number_area;
        cin >> number_area;
        area_on_village.number = number_area;

        cout << "Введите количество построек на участке: ";
        int count_construction;
        cin >> count_construction;
        area_on_village.count_construction_in_area = count_construction;

        cout << "Введите площадь дома, (введите 0 если на участке нет дома): ";
        int square_house;
        cin >> square_house;
        if (square_house != 0){
            area_on_village.house_in_area.square= square_house;
            cout << "Введите количество этажей в доме: ";
            int count_floors;
            cin >> count_floors;
            area_on_village.house_in_area.number_floors = count_floors;
            for (int i=1; i<=count_floors; ++i){
                floor_house f;
                f.number = i;
                cout << "Введите высоту потолка на этаже " << i << " этаже" << endl; 
                int ceiling_height;
                cin >> ceiling_height;
                f.ceiling_height = ceiling_height;
                cout << "Введите количество комнат на " << i << " этаже: ";
                int count_room;
                cin >> count_room;
                f.count_room = count_room;

                cout << "Последовательно введите тип и площадь комнаты:" << endl;
                for (int i=1; i<=count_room; ++i){
                    room r;
                    cout << "Введите номер соответствующий типу комнаты:" << endl;
                    cout << "1. Cпальня;" << endl;
                    cout << "2. Кухня;" << endl;
                    cout << "3. Ванная;" << endl;
                    cout << "4. Детская;" << endl;
                    cout << "5. Гостиная." << endl;
                    cout << "Номер: ";
                    int number_room;
                    cin >> number_room;
                    while (number_room<1 || number_room >5){
                        cout << "Введите номер от 1 до 5: ";
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

                    cout << "Введите площадь комнаты: ";
                    int square_room;
                    cin >> square_room;
                    r.square = square_room;

                    f.rooms.push_back(r);
                }
                area_on_village.house_in_area.floors.push_back(f);
            }
            cout << "Имеется ли в доме печь? (введите 1, если имеется, введите 0, если не имеется): ";
            int have_stove;
            cin >> have_stove;
            while (have_stove != 0 && have_stove != 1){
                cout << "Введите 0 или 1: ";
                cin >> have_stove;
            }
            if (have_stove == 1)
                area_on_village.house_in_area.have_stove == true;
        }
        cout << "Введите площадь бани на территории. Если баня отсутсвует введите 0: ";
        int square_bathouse;
        cin >> square_bathouse;
        if (square_bathouse > 0){
            area_on_village.bathouse_in_area.have_stove = true;
            area_on_village.bathouse_in_area.square = square_bathouse;
            ++area_on_village.count_construction_in_area;
        }

        cout << "Введите площадь гаража на территории. Если гараж отсутствует введите 0: ";
        int square_garage;
        cin >> square_garage;
        if (square_garage > 0){
            construction garage_in_area;
            garage_in_area.square = square_garage;
            garage_in_area.type = garage;
            ++area_on_village.count_construction_in_area;
            area_on_village.construction_in_area.push_back(garage_in_area);
        }

        cout << "Введите площадь сарая (бытовки). Если сарай (бытовка) отсутствует введите 0: ";
        int square_barn;
        cin >> square_barn;
        if (square_barn > 0){
            construction barn_in_area;
            barn_in_area.square = square_barn;
            barn_in_area.type = barn;
            ++area_on_village.count_construction_in_area;
            area_on_village.construction_in_area.push_back(barn_in_area);
        }
       cout << "Участок № " << number_area << " сохранен." << endl;
       village.push_back(area_on_village); 
    }
    
}