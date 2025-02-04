# 🚦 Semáforo com Raspberry Pi Pico usando Temporizador 🚦

Este projeto implementa um **semáforo simples** utilizando a **Raspberry Pi Pico** e a ferramenta educacional **BitDogLab**. O código utiliza a função `add_repeating_timer_ms()` do **Pico SDK** para alternar os LEDs com um atraso de 3 segundos entre cada estado.

---

##  Funcionalidades

1. **Alternância entre os LEDs** 🚥:
   - O semáforo segue a sequência: **Vermelho → Amarelo → Verde → Vermelho**.
   - Cada estado dura **3 segundos**.
   - A alternância é controlada por um **temporizador repetitivo**.

2. **Impressão na Porta Serial** 🖥️:
   - A cada **1 segundo**, uma mensagem é impressa na **porta serial** para monitoramento.

3. **Uso da BitDogLab** 💡:
   - O semáforo é implementado utilizando os LEDs RGB da **placa BitDogLab**, conectados às GPIOs **11, 12 e 13**.

---

##  Requisitos

```plaintext
🔧 Hardware:
- Raspberry Pi Pico.
- Placa BitDogLab (Para Teste Real)
- LEDs RGB conectados às GPIOs 11, 12 e 13.

💻 Software:
- SDK do Raspberry Pi Pico configurado.
- Compilador C compatível (como GCC).
- Ferramentas para upload do código para o Pico (como `picotool`).
```

---

## Configuração do Hardware

```plaintext
1. Conecte os LEDs RGB:
   - LED Vermelho na GPIO 11.
   - LED Amarelo na GPIO 12.
   - LED Verde na GPIO 13.
```

---

## 🚀 Compilação e Upload

```plaintext
1. Clone o repositório do código:
   git clone <URL_DO_REPOSITORIO>

2. Compile o programa usando CMake:
   mkdir build
   cd build
   cmake ..
   make

   Também é possível compilar diretamente na  extensão do Raspberry Pi Pico Project no VS Code clicando em "Compile Project"

3. Envie o arquivo `.uf2` gerado para o Raspberry Pi Pico:
   - Mantenha o botão `BOOTSEL` pressionado enquanto conecta o Pico ao computador.
   - Através da extensão do Raspberry Pi Pico Project no VS Code, é possível enviar o código para a placa clicando em "Run Project (USB)".
   - Caso não consiga enviar diretamente, copie o arquivo `.uf2` gerado para a unidade montada.

4. Caso não tenha a placa, é possível simular o sistema:
   - Compile o código.
   - Clique no arquivo `diagram.json` e inicie a simulação.
```


