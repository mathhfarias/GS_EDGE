#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

// Configurações do WiFi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Configurações do TagoIO
const char* token_dispositivo = " // SEU TOKEN AQUI"; // Insira seu token do dispositivo TagoIO aqui
const char* servidor = "https://api.tago.io/data";

// Configurações dos pinos
#define PINO_DHT 17    // DHT22 
#define TIPO_DHT DHT22
const int pino_trig = 23;  // HC-SR04 Trig
const int pino_echo = 19;  // HC-SR04 Echo

DHT dht(PINO_DHT, TIPO_DHT);

void configurar_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando-se a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  int tentativas = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    tentativas++;
    if (tentativas > 20) { // 10 segundos de tentativas
      Serial.println("Falha ao conectar-se ao WiFi. Reiniciando...");
      ESP.restart();
    }
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(pino_trig, OUTPUT);
  pinMode(pino_echo, INPUT);
  configurar_wifi();
}

void loop() {
  // Verifica a conexão WiFi
  if (WiFi.status() != WL_CONNECTED) {
    configurar_wifi();
  }

  // Leitura do DHT22
  float temperaturaArC = dht.readTemperature();
  float umidadeAr = dht.readHumidity();

  if (isnan(temperaturaArC) || isnan(umidadeAr)) {
    Serial.println("Falha ao ler o sensor DHT!");
    return;
  }

  // Leitura do HC-SR04
  digitalWrite(pino_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(pino_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pino_trig, LOW);

  long duracao = pulseIn(pino_echo, HIGH);
  float distanciaCm = duracao * 0.0342 / 2;

  // Cria o payload JSON
  String payload = "[";
  payload += "{\"variable\":\"temperaturaArC\",\"value\":" + String(temperaturaArC) + "},";
  payload += "{\"variable\":\"umidadeAr\",\"value\":" + String(umidadeAr) + "},";
  payload += "{\"variable\":\"distanciaCm\",\"value\":" + String(distanciaCm) + "}";
  payload += "]";

  // Envia os dados para o TagoIO
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(servidor); // URL do servidor TagoIO
    http.addHeader("Content-Type", "application/json");
    http.addHeader("Device-Token", token_dispositivo);

    int codigoRespostaHTTP = http.POST(payload);

    if (codigoRespostaHTTP > 0) {
      Serial.print("Código de resposta HTTP: ");
      Serial.println(codigoRespostaHTTP);
    } else {
      Serial.print("Código de erro: ");
      Serial.println(codigoRespostaHTTP);
    }
    http.end();
  } else {
    Serial.println("Erro na conexão WiFi");
  }

  Serial.println("==================================");
  Serial.print("Temperatura do Ar: ");
  Serial.print(temperaturaArC);
  Serial.println(" ºC");

  Serial.print("Umidade do Ar: ");
  Serial.print(umidadeAr);
  Serial.println(" %");

  Serial.print("Distância: ");
  Serial.print(distanciaCm);
  Serial.println(" km");

  delay(1000); // Espera 1 segundos antes de enviar novamente
}
