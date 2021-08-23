// вводим константы
#define M1 4 // первый мотор (1-ое направление движения)
#define M2 6 // второй мотор (1-ое направление движения)
#define DIRECTION1 9 //первый мотор (2-ое направление движения)
#define DIRECTION2 12 // второй мотор (2-ое направление движения)
int BUTTON1 = 1; // вводим переменные для кнопок
int BUTTON2 = 2;
int BUTTON3 = 3;
int val = 0;
int val1 = 0;
int val2 = 0;
void setup() {
pinMode(M1, OUTPUT); // устанавливаем режим работы для пинов моторов
pinMode(M2, OUTPUT);
pinMode(DIRECTION1, OUTPUT);
pinMode(DIRECTION2, OUTPUT);
pinMode(BUTTON1, INPUT); // устанавливаем режим работы для пинов кнопок
pinMode(BUTTON2, INPUT);
pinMode(BUTTON3, INPUT);
digitalWrite(M1, LOW); // задаем начальное состояние моторов
digitalWrite(DIRECTION1, LOW);
digitalWrite(M2, LOW);
digitalWrite(DIRECTION2, LOW);
}
void loop() {
val = digitalRead(BUTTON1); // переменная val считывает состояние кнопки 1
val1 = digitalRead(BUTTON2); // переменная val1 считывает состояние кнопки 2
val2 = digitalRead(BUTTON3); //переменная val2 считывает состояние кнопки 3
if (val == HIGH) { // создаем условие: если кнопка1 нажата, то моторы 1 и 2 едут в одном направлении - например - назад
analogWrite(M1, 200); // указываем мощность моторов. это значение отвечает за скорость перемещения платформы. мы можем менять его в зависимости от того какая скорость нам нужна.
digitalWrite(M1, HIGH);
digitalWrite(DIRECTION1, LOW);
analogWrite(M2, 200); // указываем мощность моторов. это значение отвечает за скорость перемещения платформы. мы можем менять его в зависимости от того какая скорость нам нужна.
digitalWrite(M2, HIGH);
digitalWrite(DIRECTION2, LOW);
}
if (val1 == HIGH) { // создаем условие : если кнопка2 нажата, то моторы 1 и 2 останавливаются

digitalWrite(M1, LOW);
digitalWrite(DIRECTION1, LOW);
digitalWrite(M2, LOW);
digitalWrite(DIRECTION2, LOW);
}
if (val2 == HIGH) { // создаем условие: если кнопка3 нажата, то моторы 1 и 2 едут в обратном направлении, т.е. - вперед
analogWrite(M1, 200);
digitalWrite(M1,LOW);
digitalWrite(DIRECTION1, HIGH);
analogWrite(M2, 200);
digitalWrite(M2, LOW);
digitalWrite(DIRECTION2, HIGH);
} // создаем условия, чтобы кнопки не приходилось зажимать для выполнения их программы.
if (val == HIGH) { // например: если пин при кнопке1 получил ток, то пины при двух других кнопок не могут получать ток, до тех пор пока не будут нажаты.
val1 == LOW;
val2 == LOW;
}
if (val1 == HIGH) {
val == LOW;
val2 == LOW;
}
if (val2 == HIGH) {
val == LOW;
val1 == LOW;
}
}
