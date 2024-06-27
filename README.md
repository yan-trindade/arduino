# Projeto light clap arduino

## Integrantes do grupo:
* Yan Trindade Meireles - 13680035
* Lucas Dúckur Nunes Andreolli - 15471518
* Pedro Henrique Barbosa Oliveira - 15483776

## O projeto:
No projeto 2, nós decidimos implementar um sistema de iluminação inteligente controlado pelo usuário através de palmas. Uma palma desliga a lâmpada, outra palma a apaga.

## Esquemático de ligação dos componentes:
![tinker](https://github.com/yan-trindade/arduino/assets/67748194/73490605-b5de-4d10-aaa4-0424c2d7166a)

## Código utilizado:
```cpp
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
```
## Vídeo do projeto em funcionamento:


https://github.com/yan-trindade/arduino/assets/67748194/ed350b5b-9454-4013-88ae-1d558da04974

## Os componentes:
| Quantidade    | Componente    | Valor unitário  | Valor total |
| :-------------:|:-------------:| :-----:|:----:|
| 1            | Sensor de som KY-037| R$17,60 |R$17,60 |
| 1          | Protoboard      |   R$21,70 |R$21,70  |
| 3           | Resistor 100R 2W   |    R$1,20 |R$3,60 |
| 10            | Jumpers macho-macho |   R$0,70 |R$7,00 |
| 1            | LED 5mm vermelho |   R$0,50 |R$0,50 |
| 2            | Arduino UNO |    Membro do grupo possuía | ----- |
|             | Valor total:  |    |R$50,40 |

