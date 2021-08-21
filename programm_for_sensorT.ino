#include <TroykaDHT.h> // подключаем библиотеку для датчика
DHT dht(7, DHT11); //создаем объект для работы с датчиком
void setup() {
  Serial.begin(9600); // открываем монитор порта
  dht.begin();  // инициализируем датчик

}

void loop() {
  dht.read();
  // проверяем состояние данных
  switch(dht.getState()) {
    // если всё OK
    case DHT_OK:
      // выводим показания влажности и температуры
      Serial.print("Temperature = ");
      Serial.print(dht.getTemperatureC());
      Serial.println(" C \t");
      Serial.print("Temperature = ");
      Serial.print(dht.getTemperatureK());
      Serial.println(" K \t");
      Serial.print("Temperature = ");
      Serial.print(dht.getTemperatureF());
      Serial.println(" F \t");
      Serial.print("Humidity = ");
      Serial.print(dht.getHumidity());
      Serial.println(" %");
      break;
    // если произошла ошибка контрольной суммы
    case DHT_ERROR_CHECKSUM:
      Serial.println("Checksum error");
      break;
    // если превышено время ожидания, то выводим в монитор порта это:
    case DHT_ERROR_TIMEOUT:
      Serial.println("Time out error");
      break;
    // если данных нет, датчик не реагирует или отсутствует
    case DHT_ERROR_NO_REPLY:
      Serial.println("Sensor not connected");
      break;
  }
 
  // ждём две секунды и повторяем цикл
  delay(2000);

}
