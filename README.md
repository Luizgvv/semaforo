# Controle de Semáforo com Temporizador - Raspberry Pi Pico W

## Descrição

Este projeto implementa um sistema de semáforo utilizando o Raspberry Pi Pico W, onde os LEDs vermelho, amarelo e verde são acionados em sequência a cada 3 segundos. O controle dos LEDs é feito através de um temporizador repetitivo, garantindo a troca automática entre os estados do semáforo.

Além disso, o sistema exibe mensagens no terminal via comunicação serial para monitoramento.

## Componentes Utilizados

- Raspberry Pi Pico W
- 3 LEDs (Vermelho, Amarelo, Verde)
- 3 Resistores (330Ω)

## Conexões (GPIOs)

| Componente     | GPIO  |
|----------------|-------|
| LED Vermelho   | 13    |
| LED Amarelo    | 12    |
| LED Verde      | 11    |

## Estrutura do Código

1. Definição dos pinos GPIO dos LEDs.
2. Inicialização do hardware, incluindo configuração de GPIOs e serial.
3. Configuração do temporizador repetitivo, que chama a função `repeating_timer_callback()` a cada 3 segundos.
4. Função de callback que alterna os LEDs entre vermelho, amarelo e verde.
5. Loop principal, onde mensagens são exibidas no terminal a cada segundo para monitoramento.

## Como Executar o Projeto

### 1. Configuração do Ambiente

Certifique-se de ter instalado:

- Raspberry Pi Pico SDK
- Compilador ARM GNU Toolchain
- Wokwi (para simulação) ou Raspberry Pi Pico físico

### 2. Clonar o Repositório

```bash
git clone https://github.com/Luizgvv/semaforo.git
cd semaforo
```
### 3. Compilar o Código

Execute os seguintes comandos no terminal:

```bash
mkdir build
cd build
cmake ..
make
```
Isso gerará um arquivo .uf2 que pode ser enviado para o Raspberry Pi Pico.

### 4. Executar a Simulação no Wokwi
Caso queira testar no Wokwi, use o seguinte link:
https://wokwi.com/projects/421825067603470337

### 5. Monitorar a Saída Serial
Para visualizar as mensagens do sistema utilize o PuTTY ou conecte a placa no PC e utilize o Serial Monitor do VSCode.

### Exemplo de Saída Serial
```bash
Sistema funcionando - Temporizador ativo
Sistema funcionando - Temporizador ativo
... (mensagem a cada segundo)
```
### Autor
Luiz Gustavo do Valle Vieira