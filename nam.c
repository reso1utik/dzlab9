#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

#define M_PI 3.14159265358979323846

int main() {
    setlocale(LC_ALL, "rus");

    double alpha_g, b;
    char sym;

    printf("Введите символ для рисования фигуры: ");
    scanf(" %c", &sym);

    printf("Введите длину прилежащего катета b: ");
    if (scanf("%lf", &b) <= 0) {
        printf("Ошибка: длина должна быть положительным числом.\n");
    
    }

    printf("Введите угол alpha в градусах (от 1 до 89): ");
    if (scanf("%lf", &alpha_g) <= 0 || alpha_g >= 90) {
        printf("Ошибка: угол должен быть в диапазоне от 0 до 90 градусов.\n");
    
    }

    double alpha_rad = alpha_g * M_PI / 180.0;
    double a = b * tan(alpha_rad);

    int height = (int)(a);
    int width = (int)(b);

    if (height < 1) height = 1;
    if (width < 1) width = 1;

    printf("\n--- Результат отрисовки (Высота = %d, Ширина = %d) ---\n\n", height, width);

    for (int y = 0; y < height; y++) {
        double precise_current_width = ((double)(y + 1) / height) * width;
        int current_width = (int)(precise_current_width);

        for (int x = 0; x < current_width; x++) {
            printf("%c", sym);
        }
        printf("\n");
    }

    return 0;
}