#define STROBE 4
#define RESET 5
#define DC_One A0
#define DC_Two A1

int fanPulse = 3;

int freq_amp;
int Frequencies_One[7];
int Frequencies_Two[7];
int i;

void setup() {
  Serial.begin(9600);

  pinMode(fanPulse, INPUT);
  digitalWrite(fanPulse, HIGH);


  //Set Spectrum Shield pin configurations
  pinMode(STROBE, OUTPUT);
  pinMode(RESET, OUTPUT);
  pinMode(DC_One, INPUT);
  pinMode(DC_Two, INPUT);
  digitalWrite(STROBE, HIGH);
  digitalWrite(RESET, HIGH);

  //Initialize Spectrum Analyzers
  digitalWrite(STROBE, LOW);
  delay(1);
  digitalWrite(RESET, HIGH);
  delay(1);
  digitalWrite(STROBE, HIGH);
  delay(1);
  digitalWrite(STROBE, LOW);
  delay(1);
  digitalWrite(RESET, LOW);

}

void loop() {

  Read_Frequencies();
  Graph_Frequencies();
  delay(50);

}

void Read_Frequencies() {
  //Read frequencies for each band
  for (freq_amp = 0; freq_amp < 7; freq_amp++)
  {
    Frequencies_One[freq_amp] = analogRead(DC_One);
    Frequencies_Two[freq_amp] = analogRead(DC_Two);
    digitalWrite(STROBE, HIGH);
    digitalWrite(STROBE, LOW);
  }

  Serial.print(Frequencies_One[0]);
  Serial.print(" ,");
  Serial.print(Frequencies_One[1]);
  Serial.print(" ,");
  Serial.print(Frequencies_One[2]);
  Serial.print(" ,");
  Serial.print(Frequencies_One[3]);
  Serial.print(" ,");
  Serial.print(Frequencies_One[4]);
  Serial.print(" ,");
  Serial.println(Frequencies_One[5]);
  Serial.print(" ,");
  Serial.println(Frequencies_One[6]);
  Serial.print(" ,");
  Serial.println(Frequencies_One[6]);

}
void Graph_Frequencies() {
  for (i = 0; i < 7; i++)
  {
    if (Frequencies_One[1] >= 90) {
      analogWrite(3, 255);

    }
    else {
      analogWrite(3, 0);

    }
  }
}
