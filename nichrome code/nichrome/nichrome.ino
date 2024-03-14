const int RF_PIN = 2;
const int TD_PIN = 7;
const int NC_PIN = 8;
const int LED = PIN_LED2; 

const int NC_DELAY = 2000;
const int NC_BURN_TIME = 3000;
const int RF_THRESHOLD = 1740;
// const float RF_Time = 100;

int rfVal = 0;
bool dropped;
// bool rfTrue;
// float triggerTime;
// float holdTime;

void setup() {
  pinMode(RF_PIN, INPUT);
  pinMode(TD_PIN, OUTPUT);
  pinMode(NC_PIN, OUTPUT);
  pinMode(LED, OUTPUT);

  digitalWrite(TD_PIN, LOW);
  digitalWrite(NC_PIN, LOW);

  Serial.begin(9600);
}

void loop() {
  if (dropped) return;
  rfVal = pulseIn(RF_PIN, HIGH);
  if (rfVal > RF_THRESHOLD) drop();

  Serial.print("RF: ");
  Serial.println(rfVal);
  delay(100);
}

void drop() {
  digitalWrite(TD_PIN, HIGH);
  delay(NC_DELAY);

  digitalWrite(NC_PIN, HIGH);
  delay(NC_BURN_TIME);
  digitalWrite(TD_PIN, LOW);
  digitalWrite(NC_PIN, LOW);

  dropped = true;
}
