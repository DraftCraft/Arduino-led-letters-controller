const int letterPins[] = {A0, A1, A2, A3, A4};  // Пины для букв
const int numLetters = 5;                        // Количество букв
const int fadeDuration = 1000;                   // Время плавного перехода (мс)

void setup() {
  for (int i = 0; i < numLetters; i++) {
    pinMode(letterPins[i], OUTPUT);
    analogWrite(letterPins[i], 0);  // Начинаем с выключенного состояния
  }
}

void loop() {
  for (int i = 0; i < numLetters; i++) {
    // Плавное включение текущей буквы
    for (int brightness = 0; brightness <= 255; brightness++) {
      analogWrite(letterPins[i], brightness);
      delay(fadeDuration / 255);
    }
    
    delay(500);  // Задержка перед выключением
    
    // Плавное выключение текущей буквы (если нужно)
    for (int brightness = 255; brightness >= 0; brightness--) {
      analogWrite(letterPins[i], brightness);
      delay(fadeDuration / 255);
    }
    
    delay(200);  // Пауза перед следующей буквой
  }
}