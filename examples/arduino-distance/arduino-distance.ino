#include <SonicSensor.h>

SonicSensor uss = SonicSensor(5, 6);

void setup() {
  Serial.begin(9600);
  uss.setDebounce(250);
}

int last = 0;
void loop() {
 int cur = uss.getDistance();
 if (last!=cur){
   Serial.print("Distance = ");
   Serial.print(cur);
   Serial.println(" cm");
   last = cur;
 }

}
