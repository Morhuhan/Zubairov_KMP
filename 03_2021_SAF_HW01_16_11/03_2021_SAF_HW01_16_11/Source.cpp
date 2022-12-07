#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void create_pi(int* pi, char* p, int  size_p) {

    // Индексы для перемещения по образу
    int j = 0;
    int i = 1;

    // Пока не закончится образ
    while (i != size_p) {

        // Проверяем равенство i-го и j-того элемента

        // i-ый и j-ый элементы РАВНЫ
        if (p[i] == p[j]) {
            pi[i] = j + 1;
            i++;
            j++;
        }

        // i-ый и j-ый элементы НЕ РАВНЫ
        else {

            // Слечай если j еще не сдвинулось
            if (j == 0) {
                pi[i] = 0;
                i++;
            }

            // Случай если j уже сдвинулось
            else {
                j = pi[j - 1];
            }
        }
    }
}

int KMP(int size_p, char* p, char* text) {
    
    // Индекс для перемещения по тексту
    int k = 0;

    // Индекс для перемещения по образцу
    int l = 0;

    // Создание массива pi с кол-вом элементов size_p
    int* pi = (int*)calloc(size_p, sizeof(int));

    // Заполнение массива pi
    create_pi(pi, p, size_p);

    // Пока не дойдем до конца строки текста
    while (text[k] != '\0') {

        // Проверяем элементы образца и текста посимвольно
        if (text[k] == p[l]) {
            k++;
            l++;
        }

        // Пробуем воспользоваться помощью массива pi
        else {

            if (l == 0) {
                k++;
            }

            else {
                l = pi[l-1];
            }

        }

        // Если колличество сходств = размеру образца - возвращаем номер элемента с которого началось сходство
        if (l == size_p) {
            return k - size_p + 1;
        }

    }

    // если за цикл сходств найти не удлаось - возвращаем 0
    return 0;
}



int main() {

    system("chcp 1251");
    system("cls");

    // Создание указателя на первый символ образца и выделение памяти под size_p элементов
    int size_p;
    printf("Введите размер образца: ");
    scanf("%d", &size_p);
    char* p = (char*)calloc(size_p, sizeof(char));

    char text[255];

    printf("Введите образец: ");
    scanf("%s", p);

    printf("Введите текст: ");
    scanf("%s", text);

    printf("\nKMP = %d\n", KMP(size_p, p, text));

}