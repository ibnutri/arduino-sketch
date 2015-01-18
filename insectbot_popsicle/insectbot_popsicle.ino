#include <Servo.h>
// insectbot pake popsicle stick, baru bisa ke depan
Servo frontservo, backservo;
char forward[] = {
    70, 110, 110, 110, 110, 70, 70, 70
};
void setup() {
    frontservo.attach(9);
    backservo.attach(10);
    frontservo.write(90);
    backservo.write(90);
    delay(3000);
}
void loop() {
    for (int n = 0; n < 4; n++) {
        frontservo.write(forward[2 * n]);
        backservo.write(forward[(2 * n) + 1]);
        delay(300);
    }
}
