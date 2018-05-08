#include <Servo.h>

const short START_ROTATE = 0;
const short FULL_ROTATE = 175;

const short DELAY_MS = 50;

const short ECHO_PIN = 10;
const short TRIG_PIN = 11;
const short SERVO_PIN = 12;

long duration = 0; 
short distance = 0;

Servo usingServo;

void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, OUTPUT);
    
    Serial.begin(9600);

    usingServo.attach(SERVO_PIN);
}

void loop() {
    for (int angle = START_ROTATE; angle <= FULL_ROTATE; ++angle) {
        usingServo.write(angle);
        
        delay(DELAY_MS);

        distance = calculateDistance();

        Serial.print(angle + ',' + distance + '.');
    }
}

short calculateDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Get travel time of wave
    duration = pulseIn(ECHO_PIN, HIGH);

    // calculate distance
    distance *= 0.017;

    return distance; 
}
