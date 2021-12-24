const int numReadings = 10;
const int filterSize = 4;
const int outputSize = numReadings + filterSize; // We will use padding

int readings[numReadings];      // the readings from the analog input
float freadings[outputSize];      // the filtered readings from the analog input (with padding)
int readIndex = 0;              // the index of the current reading
int inputPin = A0;

// the filter
int filter[filterSize] = {1, 1, 1, 1};        

float* convolution (int _filter[], int _rbuffer[]) {

    static float results[outputSize];

    // Fill it up with zeroes
    for (int index = 0; index<outputSize;index++){
        results[index] = 0;
        if (filterSize <= index< numReadings+filterSize){

          results[index] = (float)_rbuffer[index-filterSize];

        }
    }

    // Convolution
    for (int index = 0; index<outputSize-filterSize;index ++){
        int value = 0;

        for (int filterindex = 0; filterindex<filterSize; filterindex ++) {

            value += results[index+filterindex]* _filter[filterindex];
        }

        results[index] = value / filterSize;
    }

    return results;
}

void setup() {
  // initialize serial communication with computer:
  Serial.begin(9600);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  readings[readIndex] = analogRead(inputPin);
  readIndex = readIndex + 1;

  if (readIndex >= numReadings) {
    readIndex = 0;
    float *freadings = convolution (filter, readings);
  }

  // Print the arrays
  for (int i=0; i<numReadings; i++){
    Serial.print(readings[i]);
    Serial.print(",");
    Serial.println(freadings[i]);    
  }

  delay(1);        // delay in between reads for stability
}
