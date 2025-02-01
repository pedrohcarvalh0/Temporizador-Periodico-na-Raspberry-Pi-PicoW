#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definições das portas GPIO dos LEDs
#define RED_LED_PIN 11
#define YELLOW_LED_PIN 12
#define GREEN_LED_PIN 13

// Estados do semáforo
typedef enum {
    RED,
    YELLOW,
    GREEN
} SemafaroState;

volatile SemafaroState state = RED; // Estado inicial

// Função de callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    switch (state) {
        case RED:
            gpio_put(RED_LED_PIN, 1);
            gpio_put(YELLOW_LED_PIN, 0);
            gpio_put(GREEN_LED_PIN, 0);
            state = YELLOW;
            break;
        case YELLOW:
            gpio_put(RED_LED_PIN, 0);
            gpio_put(YELLOW_LED_PIN, 1);
            gpio_put(GREEN_LED_PIN, 0);
            state = GREEN;
            break;
        case GREEN:
            gpio_put(RED_LED_PIN, 0);
            gpio_put(YELLOW_LED_PIN, 0);
            gpio_put(GREEN_LED_PIN, 1);
            state = RED;
            break;
    }
    return true; // Continua repetindo o temporizador
}

int main() {
    stdio_init_all(); // Inicializa a comunicação serial
    
    // Configuração dos pinos como saída
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);
    gpio_init(YELLOW_LED_PIN);
    gpio_set_dir(YELLOW_LED_PIN, GPIO_OUT);
    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);
    
    // Inicializa o semáforo desligando amarelo e verde, ligando vermelho
    gpio_put(RED_LED_PIN, 1);
    gpio_put(YELLOW_LED_PIN, 0);
    gpio_put(GREEN_LED_PIN, 0);
    
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Força a primeira execução do callback para evitar atraso inicial
    repeating_timer_callback(NULL);

    while (true) {
        tight_loop_contents();
    }
}