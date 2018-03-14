int led = 3; //Porta do LED

//porta da interrupção:
//O Arduino Uno só aceita as portas 2 e 3
int interruptPort = 2;

//Variáveis modificadas por interrupções devem ser volatile
volatile int state = LOW;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(interruptPort, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPort), toggle, CHANGE);
}

void loop() {
  // Qualquer processamento mais longo...
}

void toggle() {
  state = !state;
  digitalWrite(led,state);
}

