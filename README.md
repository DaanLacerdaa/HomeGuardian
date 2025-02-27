# Sistema de Monitoramento Ambiental com Alertas e Interface Gráfica

## **Descrição do Projeto**

Este projeto implementa um sistema embarcado na placa BitDogLab para monitoramento de temperatura e nível de som, com interface gráfica no OLED, alertas visuais/sonoros e controle por joystick.

## **Funcionalidades**

- **Monitoramento em tempo real** de temperatura e nível de som.
- Exibição de dados no **display OLED** com barras de progresso dinâmicas.
- **Feedback visual** avançado por meio de uma matriz de LEDs **WS2812B** (5x5).
- **Alertas sonoros** (via buzzer) e visuais (via LEDs) ativados quando limiares configuráveis são excedidos.
- **Configuração de limiares** diretamente no dispositivo utilizando o joystick.
- Controle de modos e cancelamento de alertas por meio de botões e joystick.

---

## **Requisitos de Hardware**

- **Placa BitDogLab** (baseada no RP2040).
- **Display OLED SSD1306** (conexão via I2C).
- **Matriz de LEDs WS2812B** (5x5).
- **Joystick analógico** e **botões**.
- **Buzzer** e **LEDs RGB**.

---

## **Relevância do Projeto**

Este projeto ilustra a aplicação de **sistemas embarcados** em uma solução de monitoramento ambiental eficiente e de baixo custo. Ele combina o uso de periféricos como ADC, I2C, PWM e PIO, além de técnicas avançadas de programação (interrupções, leituras analógicas e controle de LEDs endereçáveis), alinhando-se aos princípios da **Internet das Coisas (IoT)**. Sua relevância pode ser destacada pelos seguintes pontos:

- **Prevenção de riscos**: Ideal para ambientes sensíveis, como laboratórios ou salas de servidores, onde temperaturas extremas ou ruídos excessivos podem indicar problemas.
- **Conforto e segurança residencial**: Permite detectar condições adversas, como calor excessivo ou barulhos anormais, contribuindo para o bem-estar.
- **Educação e inovação**: Serve como base para aprendizado e prototipagem em projetos de automação, sendo acessível e escalável graças ao uso da BitDogLab e componentes de custo reduzido.

Assim, o sistema é uma ferramenta prática tanto para entusiastas quanto para aplicações reais, oferecendo flexibilidade e funcionalidade em um design compacto.

---

## **Pinagem e Portas GPIO**

A tabela abaixo apresenta as conexões dos componentes às portas GPIO da placa BitDogLab:

| **Componente**            | **Função**                     | **GPIO Utilizadas**            |
|---------------------------|--------------------------------|--------------------------------|
| **Display OLED**          | Interface gráfica (I2C)        | GPIO 14 (SDA), GPIO 15 (SCL)   |
| **Matriz de LEDs WS2812B**| Feedback visual (PIO)          | GPIO 7                         |
| **Joystick**              | Controle de navegação          | GPIO 26 (Eixo X, ADC0), GPIO 27 (Eixo Y, ADC1), GPIO 22 (Botão) |
| **Botões**                | Cancelamento de alertas        | GPIO 5 (Botão A), GPIO 6 (Botão B) |
| **Buzzer**                | Alertas sonoros (PWM)          | GPIO 21                        |
| **LEDs RGB**              | Indicadores adicionais         | GPIO 11 (Verde), GPIO 12 (Azul), GPIO 13 (Vermelho) |
| **Sensor de Temperatura** | Leitura de temperatura (ADC)   | GPIO 4 (ADC4)                  |
| **Microfone**             | Leitura de nível de som (ADC)  | GPIO 26 (ADC0)                 |

**Nota**: O GPIO 26 é compartilhado entre o microfone e o eixo X do joystick, utilizando o ADC0 em momentos distintos.

---

## **Instruções de Instalação**

1. Clone o repositório:

   ```bash
   git clone https://github.com/DaanLacerdaa/HomeGuardian.git

2. Configure o Pico SDK no ambiente de desenvolvimento.
3. Compile e carregue o código na BitDogLab usando CMake e um cabo USB.

## **Uso**

**Modo Normal**: Exibe temperatura e som no OLED.
**Modo Alerta**: Ativado quando limiares são excedidos (vermelho piscante nos LEDs).
**Modo Configuração:** Mova o joystick para cima para entrar; ajuste limiares com o eixo X.
**Botão A**: Cancela alertas.

## **Demonstração**

[[Link para o vídeo de demonstração no YouTube]] (<https://www.youtube.com/watch?v=v0>)

## **Simulação**

[[Link para a simulação no Wokwi]](https://wokwi.com/projects/424001269230968833)

## **Licença**

**MIT License** - Veja o arquivo LICENSE para detalhes.

## 👨‍💻 **Autor**

| [<img src="https://avatars.githubusercontent.com/DaanLacerdaa" width=115><br><sub>Daan Lacerda</sub>](https://github.com/DaanLacerdaa) |
Nome: [Danilo P. Lacerda]
Email: [danilolacerdadpl@gmail.com]
