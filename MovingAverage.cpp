#include <iostream>

using namespace std;


int main() {
    int size;
    cin >> size;
    int a[size];
    int i = 0;
    while (i < size) {
        int item;
        cin >> item;
        a[i++] = item;
    }
    int k;
    cin >> k;


    int start = k - 1; // инициализация индекса от которого начинается рассчет МА(Moving Average)
    double res[size - start]; // инициализация результирующего массива
    int index = start - k + 1; // переменная, хранящая индекс начала рассчета МА. Будет увеличиваться на каждой итерации в последнем цикле
    double result = 0; // переменная, будет хранить сумму чисел для послед рассчета среднего
    for (int i = index; i <= start; i++) { // рассчитываем результат МА для первого индекса(start)
        result += a[i];
    }
    double item = result / k; // высчитвываем среднее арифметическое, поделив на переменную, хранящуюю кол-во окон сглаживания
    res[0] = item;
    start += 1; // Увеличиваем индекс для которого нужно рассчитывать МА
    // result = 10 После высчитывания первого МА
    for (int i = start; i < size; i++) {
        result += a[start] - a[++index - 1]; // Теперь result будет равен своему предыдущему значению + текущее значение -
        double item = result / k;// индекса для которого надо рассчитать МА ;минус; индекс, который уже не должен попасть
        res[index] = item;
        start += 1;
    }

    for (double temp : res) { // вывод МА
        cout << temp << " ";
    }
}
