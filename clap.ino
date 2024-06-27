const int ledPin = 8;        // Pin do LED
const int sensorPin = 13;     // Pin do sensor de som
int sensorValue = 0;         // Valor lido do sensor
bool ledState = false;       // Estado atual do LED

void setup() {
  pinMode(ledPin, OUTPUT);   // Define o pino do LED como saída
  pinMode(sensorPin, INPUT); // Define o pino do sensor como entrada
  digitalWrite(ledPin, LOW); // Inicializa o LED como desligado
}

void loop() {
  sensorValue = digitalRead(sensorPin); // Lê o valor do sensor de som
  
  if (sensorValue == HIGH) {            // Verifica se o som foi detectado (uma palma)
    delay(50);                          // Debounce para evitar leituras múltiplas
    if (digitalRead(sensorPin) == HIGH) { // Verifica novamente para confirmar a palma
      ledState = !ledState;             // Alterna o estado do LED
      digitalWrite(ledPin, ledState);   // Atualiza o LED de acordo com o novo estado
      while (digitalRead(sensorPin) == HIGH) {
        // Espera o som terminar para evitar múltiplas detecções
      }
    }
  }
}
