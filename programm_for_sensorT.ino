#include <NewPing.h>
#include <Wire.h>  // подключение библиотеки Wire

#define TRIG1 11
#define ECHO1 12
#define TRIG2 8
#define ECHO2 9
#define TRIG3 6
#define ECHO3 7
#define MAX_DISTANCE 200 // Константа для определения максимального расстояния, которое мы будем считать корректным.

NewPing sonar (TRIG1,ECHO1, MAX_DISTANCE);
NewPing sonar2(TRIG2,ECHO2, MAX_DISTANCE);
NewPing sonar3(TRIG3,ECHO3, MAX_DISTANCE);

int ADXL345 = 0x53; // Адрес I2C датчика ADXL345
float X_out, Y_out, Z_out;  // Выходы


void setup() {
  // Инициализируем взаимодействие по последовательному порту на скорости 9600
  Serial.begin(9600);
  Wire.begin(); // Инициализация библиотеки Wire 
  // Установите ADXL345 в режим измерения
  Wire.beginTransmission(ADXL345); // Начать общение с устройством 
  Wire.write(0x2D); // работа с регистром  POWER_CTL  - 0x2D
  // Включить измерение
  Wire.write(8); // (8dec -> 0000 1000 двоичный) Бит D3 High для разрешения измерения
  Wire.endTransmission();
  delay(10);
}


void loop() {

  // Стартовая задержка, необходимая для корректной работы.
  delay(1000);

  // Получаем значение от датчика расстояния и сохраняем его в переменную
  unsigned int distance1 = sonar.ping_cm();
  unsigned int distance2 = sonar2.ping_cm();
  unsigned int distance3 = sonar3.ping_cm();
  // Печатаем расстояние в мониторе порта
  Serial.print("$");
  Serial.print(distance1);
  Serial.print(" ");
  Serial.print(distance2);
  Serial.print(" ");
  Serial.print(distance3);
  Serial.println(";");

  // === Считать данные акселерометра === //
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32); // Начать с регистра 0x32 (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true); // Чтение всех 6 регистров, значение каждой оси сохраняется в 2 регистрах
  X_out = ( Wire.read()| Wire.read() << 8); // Значение по оси X
  X_out = X_out; //Для диапазона + -2g нам нужно разделить необработанные значения на 256 в соответствии с datasheet
  Y_out = ( Wire.read()| Wire.read() << 8); // Значение по оси Y
  Y_out = Y_out;
  Z_out = ( Wire.read()| Wire.read() << 8); // Значение по оси Z
  Z_out = Z_out;
  Serial.print("Xa= ");
  Serial.print(X_out/256);
  Serial.print("   Ya= ");
  Serial.print(Y_out/256);
  Serial.print("   Za= ");
  Serial.println(Z_out/256);
  delay(1000);

}
