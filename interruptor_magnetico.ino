


//Reed Switch y Arduino



const int pinSensor = 2;
const int pinLED = 13;
void setup() {
//configurar pin como entrada con resistencia pull-up interna
pinMode(pinSensor, INPUT_PULLUP);
pinMode(pinLED, OUTPUT);
}
void loop() {
int value = digitalRead(pinSensor);
if (value == LOW) {
digitalWrite(pinLED, HIGH);
} else {
digitalWrite(pinLED, LOW);
}
delay(1000);
}
