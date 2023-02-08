#include <iostream>
#include <map>
using namespace std;

typedef map<int, int>::iterator iter;

/*
 * В следующих заданиях поработаем с методами контейнера map (именно их надо использовать в функциях)
 *
 * В заданиях надо маписать функцию или несколько функций для взаимодействия с контейнером
 * Для удобства везде используем шаблонные параметры int, int
 *
 * Никаких баллов нет - делаем смелее, со всеми проблемами разберёмся
 */

/*
 * Задание №1
 * Напишите 3+ функции для вставки нового элемента в map
 * (в этом задании написано объявление 1 функции, остальные надо придумать)
 */

/*
 * Вспомогательные вопросы:
 * 1) Какие ещё варианты для возвращаемых значений?
 * 2) Какие ещё варианты для аргументов?
 */
void insert_element_1(map<int, int>& m, int key, int value) {
    m.insert(pair<int, int>(key, value));
}

void insert_element_2(map<int, int>& m, int key, int value) {
    m.emplace(key, value);
}

pair<iter, bool> insert_element_3(map<int, int>& m, int key, int value) {
    return m.emplace(key, value);
}

pair<iter, bool> insert_element_4(map<int, int>& m, int key, int value) {
    return m.insert_or_assign(key, value);
}



/*
 * Задание №2
 * Напишите функцию (можно и несколько функций) для вывода содержимого контейнера map в консоль (обычный вывод)
 */
void print_1(map<int, int>& m) {
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << "[" << it->first << "] = " << it->second << "\n";
    }
}

void print_2(map<int, int>& m) {
    for (auto item : m) {
        cout << "[" << item.first << "] = " << item.second << "\n";
    }
}

void print_3(map<int, int>& m) {
    for (auto [key, value] : m) {
        cout << "[" << key << "] = " << value << "\n";
    }
}


/*
 * Задание №3
 * Напишите функцию для проверки наличия ключа в контейнере map
 * Подсказка: вспомнить возвращаемый тип метода find у map
 */
bool check_1(map<int, int>& m, int key) {
    if (m.find(key) != m.end()) {
        return true;
    }
    return false;
}




/*
 * Задание №4
 * Напишите функцию для получения итератора, указывающего на искомый ключ (если он есть)
 * Подсказка: необязательно (может даже и желательно) возвращать только итератор, взгляните на первую функцию в задании №1
 * но хотя можно и ничего не возвращать...
 */
iter find_1(map<int, int>& m, int key) {
    return m.find(key);
}


/*
 * Задание №5
 * Напишите функцию для удаления элемента из контейнера map
 */
void erase_1(map<int, int>& m, int key) {
    m.erase(key);
}

size_t erase_2(map<int, int>& m, int key) {
    return m.erase(key);
}


int main() {
    /*
     * Задание №0
     * Создайте контейнер map с шаблонными параметрами int, int
     */
    map<int, int> m1;

    pair<int, int> p1(1, 1);

    m1.insert(p1);

    m1.insert(pair<int, int>(2, 2));

    m1.insert(make_pair(0, 3));

    m1.emplace(-1, 4);

    insert_element_1(m1, 6, 3);

    auto p2 = insert_element_3(m1, 9, 2);

    cout << p2.first->first << " " << p2.first->second << " " << boolalpha << p2.second << "\n";

    auto p3 = insert_element_3(m1, 9, 32);

    print_3(m1);

    cout << p2.first->first << " " << p2.first->second << " " << boolalpha << p2.second << "\n";
    cout << p3.first->first << " " << p3.first->second << " " << boolalpha << p3.second << "\n";

    auto p4 = insert_element_4(m1, 9, 32);

    cout << p4.first->first << " " << p4.first->second << " " << boolalpha << p4.second << "\n";

    cout << "\n";

    cout << m1[0] << "\n";

    cout << m1.at(0) << "\n";

    m1[3] = 5;

    cout << m1[3] << "\n";

    cout << "\n" << boolalpha << check_1(m1, 78976) << " " << check_1(m1, 1) << "\n";

    cout << m1.lower_bound(3)->first << " " << m1.lower_bound(3)->second << "\n";

    cout << m1.upper_bound(1)->first << " " << m1.upper_bound(1)->second << "\n";

    cout << erase_2(m1, 1) << "\n";

    print_3(m1);

    /*
     * Задание №6
     * Примените некоторые функции (как написанные, так и встроенные)
     */
    // YOUR CODE HERE



    return 0;
}
