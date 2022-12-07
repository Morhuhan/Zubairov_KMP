#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void create_pi(int* pi, char* p, int  size_p) {

    // ������� ��� ����������� �� ������
    int j = 0;
    int i = 1;

    // ���� �� ���������� �����
    while (i != size_p) {

        // ��������� ��������� i-�� � j-���� ��������

        // i-�� � j-�� �������� �����
        if (p[i] == p[j]) {
            pi[i] = j + 1;
            i++;
            j++;
        }

        // i-�� � j-�� �������� �� �����
        else {

            // ������ ���� j ��� �� ����������
            if (j == 0) {
                pi[i] = 0;
                i++;
            }

            // ������ ���� j ��� ����������
            else {
                j = pi[j - 1];
            }
        }
    }
}

int KMP(int size_p, char* p, char* text) {
    
    // ������ ��� ����������� �� ������
    int k = 0;

    // ������ ��� ����������� �� �������
    int l = 0;

    // �������� ������� pi � ���-��� ��������� size_p
    int* pi = (int*)calloc(size_p, sizeof(int));

    // ���������� ������� pi
    create_pi(pi, p, size_p);

    // ���� �� ������ �� ����� ������ ������
    while (text[k] != '\0') {

        // ��������� �������� ������� � ������ �����������
        if (text[k] == p[l]) {
            k++;
            l++;
        }

        // ������� ��������������� ������� ������� pi
        else {

            if (l == 0) {
                k++;
            }

            else {
                l = pi[l-1];
            }

        }

        // ���� ����������� ������� = ������� ������� - ���������� ����� �������� � �������� �������� ��������
        if (l == size_p) {
            return k - size_p + 1;
        }

    }

    // ���� �� ���� ������� ����� �� ������� - ���������� 0
    return 0;
}



int main() {

    system("chcp 1251");
    system("cls");

    // �������� ��������� �� ������ ������ ������� � ��������� ������ ��� size_p ���������
    int size_p;
    printf("������� ������ �������: ");
    scanf("%d", &size_p);
    char* p = (char*)calloc(size_p, sizeof(char));

    char text[255];

    printf("������� �������: ");
    scanf("%s", p);

    printf("������� �����: ");
    scanf("%s", text);

    printf("\nKMP = %d\n", KMP(size_p, p, text));

}