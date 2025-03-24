#include "firstpenguin.hpp"
#include "mbed.h"
CAN can1(PA_11, PA_12, 1e6);
FirstPenguin penguin(35, can1);
BufferedSerial pc(USBTX, USBRX, 250000);
uint8_t DATA[8] = {};

DigitalIn Userbutton(BUTTON1);
bool Userbutton_f = false;

int main() {
    Userbutton.mode(PullUp);
    while (1) {
        Userbutton_f = Userbutton.read();

        if (Userbutton_f == 0) {
            penguin.pwm[0] = 5000;
            penguin.pwm[1] = 5000;
            penguin.pwm[2] = 5000;
            penguin.pwm[3] = 5000;
        } else {
            penguin.pwm[0] = 0;
            penguin.pwm[1] = 0;
            penguin.pwm[2] = 0;
            penguin.pwm[3] = 0;
        }
        penguin.send();
    }
}
