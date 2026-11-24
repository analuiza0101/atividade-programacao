#include <stdio.h>

float celsiusParaFahrenheit(float celsius) {
    return (9.0 * celsius) / 5.0 + 32.0;
}

int main() {
    float c, f;

    printf("Digite a temperatura em graus Celsius: ");
    scanf("%f", &c);

    f = celsiusParaFahrenheit(c);
    printf("Temperatura em Fahrenheit: %.2f\n", f);

    return 0;
}