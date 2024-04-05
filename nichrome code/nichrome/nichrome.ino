#define RF_PIN 2
#define TD_PIN 7
#define NC_PIN 8
#define BUZZ_PIN 6

const int NC_DELAY = 500;
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
  pinMode(BUZZ_PIN, OUTPUT);

  digitalWrite(TD_PIN, LOW);
  digitalWrite(NC_PIN, LOW);

  Serial.begin(9600);

  buzz();
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

void buzz() {
  digitalWrite(BUZZ_PIN, HIGH);
  delay(1000);
  digitalWrite(BUZZ_PIN, LOW);
  delay(1000);
  digitalWrite(BUZZ_PIN, HIGH);
  delay(1000);
  digitalWrite(BUZZ_PIN, LOW);
}
