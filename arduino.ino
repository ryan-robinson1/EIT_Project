int counter = 0;
const int numReadings = 10; // number of readings to take per second

void setup() {
  Serial.begin(115200);
}

void loop() {
  long sumForce1 = 0;
  long sumForce2 = 0;
  long sumForce3 = 0;
  long sumForce4 = 0;

  // take a number of readings in quick succession
  for (int i = 0; i < numReadings; i++) {
    sumForce1 += analogRead(0);
    sumForce2 += analogRead(2);
    sumForce3 += analogRead(3);
    sumForce4 += analogRead(1);
    delay(100); // wait for a little bit between readings
  }

  // calculate averages
  int avgForce1 = sumForce1 / numReadings;
  int avgForce2 = sumForce2 / numReadings;
  int avgForce3 = sumForce3 / numReadings;
  int avgForce4 = sumForce4 / numReadings;

  int totalForce = avgForce1 + avgForce2 + avgForce3 + avgForce4;

  // round to the nearest multiple of 10
  totalForce = round(totalForce / 10.0) * 10;

  Serial.println(totalForce);

  delay(1000 - (numReadings * 100)); // wait for the remainder of the second
}
