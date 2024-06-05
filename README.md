Claro, aqui está tudo consolidado em um único bloco de markdown:

```markdown
# Ocean Health Tracker 🌊🐟

O projeto **Ocean Health Tracker** foi criado para ajudar a proteger os oceanos, monitorando a temperatura da água, a umidade do ar, a distância da terra mais próxima (a partir da localização do sensor) e a temperatura do ar.

## Descrição 📝

O objetivo deste projeto é criar um sistema de monitoramento ambiental utilizando o ESP32 e sensores DHT22 e HC-SR04. Os dados coletados são enviados para a plataforma TagoIO para visualização e análise em tempo real, contribuindo para a proteção e conservação dos oceanos.

## Funcionalidades 🌟

- 🌡️ Medição da temperatura do ar
- 💧 Medição da umidade do ar
- 📏 Medição da distância
- 📡 Envio de dados para a plataforma TagoIO

## Instalação 🛠️

### Pré-requisitos

- Placa ESP32
- Sensores DHT22 e HC-SR04
- Biblioteca DHT para Arduino
- Biblioteca WiFi para ESP32
- Biblioteca HTTPClient para ESP32

### Passos

1. Clone este repositório:
   ```sh
   git clone https://github.com/seuusuario/seuprojeto.git
   ```

2. Abra o projeto na sua IDE de preferência (por exemplo, Arduino IDE).

3. Instale as bibliotecas necessárias:
   - DHT Sensor Library
   - Adafruit Unified Sensor
   - WiFi
   - HTTPClient

4. Conecte o hardware conforme descrito na seção "Configuração do Hardware".

## Uso 🚀

1. Abra o arquivo `main.ino` na sua IDE.
2. Configure seu SSID e senha do WiFi no código:
   ```cpp
   const char* ssid = "SEU_SSID";
   const char* password = "SUA_SENHA";
   ```
3. Configure o token do dispositivo TagoIO no código:
   ```cpp
   const char* token_dispositivo = "SEU_TOKEN_DO_TAGOIO";
   ```
4. Carregue o código na placa ESP32.
5. Abra o monitor serial para verificar a saída dos dados.

## Configuração do Hardware 🔧

### DHT22

- VCC → 3.3V
- GND → GND
- Data → GPIO 17

### HC-SR04

- VCC → 5V
- GND → GND
- Trig → GPIO 23
- Echo → GPIO 19

### Diagrama de Conexão

Aqui está um diagrama básico de como os sensores são conectados ao ESP32:

```
ESP32            DHT22            HC-SR04
  3.3V  --------- VCC
  GND   --------- GND
  GPIO 17 ------- Data

  5V    ---------------- VCC
  GND   --------------- GND
  GPIO 23 -------------- Trig
  GPIO 19 -------------- Echo
```

## Configuração do Software 💻

1. Baixe e instale a [Arduino IDE](https://www.arduino.cc/en/software).
2. Adicione a placa ESP32 na Arduino IDE:
   - Vá para `File -> Preferences`.
   - Em "Additional Boards Manager URLs", adicione `https://dl.espressif.com/dl/package_esp32_index.json`.
   - Vá para `Tools -> Board -> Boards Manager`, procure por `ESP32` e instale.
3. Instale as bibliotecas necessárias:
   - Vá para `Sketch -> Include Library -> Manage Libraries`.
   - Procure e instale `DHT sensor library`.
   - Procure e instale `Adafruit Unified Sensor`.

## Contribuições 🤝

Contribuições são bem-vindas! Por favor, abra um problema ou envie um pull request.

## Licença 📄

Distribuído sob a licença MIT. Veja `LICENSE` para mais informações.

## Contato 📧

**Matheus Farias de Lima** - [@seutwitter](https://twitter.com/seutwitter) - seuemail@example.com

**Miguel Mauricio Parrado Patarroyo** - [@seutwitter](https://twitter.com/seutwitter) - seuemail@example.com

Link do Projeto: [https://github.com/seuusuario/seuprojeto](https://github.com/seuusuario/seuprojeto)
```

Este README.md fornece uma visão geral clara e amigável do projeto, incluindo todas as informações necessárias para instalação, configuração e uso, com a adição de emojis para tornar o documento mais visualmente atraente.
