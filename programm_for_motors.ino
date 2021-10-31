int BUTTON2 = 2;
int BUTTON3 = 3; 
int val = 0; 
int val1 = 0;
int val2 = 0;


void setup()  {
  pinMode(M1, OUTPUT); // устанавливаем режим работы для пинов моторов
  pinMode(M2, OUTPUT);
  pinMode(DIRECTION1, OUTPUT);
  pinMode(DIRECTION2, OUTPUT);
  pinMode(BUTTON1, INPUT_PULLUP);// устанавливаем режим работы для пинов кнопок
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  digitalWrite(M1, LOW); // задаем начальное состояние моторов
  digitalWrite(DIRECTION1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(DIRECTION2, LOW);
}


void loop() {
  val = !digitalRead(BUTTON1); // переменная val считывает состояние кнопки 1
  val1 = !digitalRead(BUTTON2); // переменная val1 считывает состояние кнопки 2
  val2 = !digitalRead(BUTTON3); //переменная val2 считывает состояние кнопки 3

  
  if (val == HIGH && val1 == LOW && val2 == LOW) { // создаем условие: если кнопка1 нажата, то моторы 1 и 2 едут в одном направлении - например - назад
    analogWrite(M1, 200);  // указываем мощность моторов. это значение отвечает за скорость перемещения платформы. мы можем менять его в зависимости от того какая скорость нам нужна.
    digitalWrite(M1, HIGH);
    digitalWrite(DIRECTION1, LOW);
    analogWrite(M2, 200); // указываем мощность моторов. это значение отвечает за скорость перемещения платформы. мы можем менять его в зависимости от того какая скорость нам нужна.
    digitalWrite(M2, HIGH);
    digitalWrite(DIRECTION2, LOW);
  }

  
  if (val1 == HIGH && val == LOW && val2 == LOW) { // создаем условие : если кнопка2 нажата, кнопка1 и кнопка3 не нажаты, то моторы 1 и 2 останавливаются
    analogWrite(M1, 200);
  digitalWrite(M1, LOW);
  digitalWrite(DIRECTION1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(DIRECTION2, LOW);  
   } 

   
   if (val2 == HIGH && val == LOW && val1 == LOW) { // создаем условие: если кнопка3 нажата, то моторы 1 и 2 едут в обратном направлении, т.е. - вперед
    analogWrite(M1, 200); 
    digitalWrite(M1,LOW);
    digitalWrite(DIRECTION1, HIGH);
    analogWrite(M2, 200);
    digitalWrite(M2, LOW);
    digitalWrite(DIRECTION2, HIGH);
   }
}
