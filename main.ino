#include <Esplora.h>

void setup() {
  // Configuración inicial
  Serial.begin(9600);  // Inicializa la comunicación serial a 9600 baudios
  screen.begin();      // Inicializa la pantalla TFT

  // Limpia la pantalla con un color de fondo inicial (negro)
  screen.background(0, 0, 0);
}

void loop() {
  // Lee los valores del acelerómetro en los ejes X, Y, y Z
  int x = Esplora.readAccelerometer(X_AXIS);
  int y = Esplora.readAccelerometer(Y_AXIS);
  int z = Esplora.readAccelerometer(Z_AXIS);

  // Calcula los valores de color basados en el movimiento del acelerómetro
  int red = map(x, -512, 512, 0, 255);   // Mapea el valor del eje X a un rango de color
  int green = map(y, -512, 512, 0, 255); // Mapea el valor del eje Y a un rango de color
  int blue = map(z, -512, 512, 0, 255);  // Mapea el valor del eje Z a un rango de color

  // Limita los valores de color entre 0 y 255
  red = constrain(red, 0, 255);
  green = constrain(green, 0, 255);
  blue = constrain(blue, 0, 255);

  // Cambia el color de fondo de la pantalla
  screen.background(red, green, blue);
  
  // Muestra los valores en el monitor serial
  Serial.print("X: ");
  Serial.print(x);
  Serial.print("\tY: ");
  Serial.print(y);
  Serial.print("\tZ: ");
  Serial.println(z);

  // Agrega un pequeño retraso para evitar saturar la comunicación serial
  delay(100);
}
