#include "pico/stdlib.h"
#include <stdio.h>

// Definição dos pinos para os LEDs
#define LED_VERMELHO 13
#define LED_AMARELO 12
#define LED_VERDE 11

// Função de call-back do temporizador (repeating timer)
bool repeating_timer_callback(struct repeating_timer *t) {
    static int estado = 0;


    switch (estado) {
        case 0:
            // Vermelho aceso, outros apagados
            gpio_put(LED_VERMELHO, 1);
            gpio_put(LED_AMARELO, 0);
            gpio_put(LED_VERDE, 0);
            break;
        case 1:
            // Amarelo aceso, outros apagados
            gpio_put(LED_VERMELHO, 0);
            gpio_put(LED_AMARELO, 1);
            gpio_put(LED_VERDE, 0);
            break;
        case 2:
            // Verde aceso, outros apagados
            gpio_put(LED_VERMELHO, 0);
            gpio_put(LED_AMARELO, 0);
            gpio_put(LED_VERDE, 1);
            break;
    }

    // Incrementa o estado para a próxima cor
    estado = (estado + 1) % 3; // Ciclo entre 0, 1, 2

    return true;  // Retorna 'true' para continuar chamando a função a cada 3 segundos
}

int main() {
    // Inicializa os pinos GPIO para os LEDs
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    // Inicializa a serial
    stdio_init_all();

    // Cria o temporizador repetido
    struct repeating_timer timer;
    if (!add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer)) {
        return 1; // Erro ao configurar o temporizador
    }

    // Loop principal
    int tempo_segundos = 0;
    while (true) {
        // Imprime o tempo em segundos no console a cada segundo
        printf("Temporizador ativo - %d segundos\n", tempo_segundos);

        // Incrementa o contador de segundos
        tempo_segundos++;
        
        // Espera 1 segundo
        sleep_ms(1000);
    }

    return 0;
}
