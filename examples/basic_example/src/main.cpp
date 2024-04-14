#include <Arduino.h>
#include <Wire.h>
#include <MUFFINS_MCP9808.h>

const int SENSOR_POWER_ENABLE_PIN = 17;
const int WIRE0_SCL = 1;
const int WIRE0_SDA = 0;

MCP9808 mcp9808;

MCP9808::Config mcp9808_config = {
    .wire = &Wire,
    .i2c_address = 0x1F,
    .resolution = 3};

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
    delay(1000);
  }

  pinMode(SENSOR_POWER_ENABLE_PIN, OUTPUT_12MA);
  digitalWrite(SENSOR_POWER_ENABLE_PIN, HIGH);

  if (Wire.setSCL(WIRE0_SCL) && Wire.setSDA(WIRE0_SDA))
  {
    Wire.begin();
  }

  if (!mcp9808.begin(mcp9808_config))
  {
    while (1)
      ;
  }
}

void loop()
{
  mcp9808.read();

  Serial.print("Temperature: ");
  Serial.print(mcp9808.data.temperature);
  Serial.println(" C");

  delay(100);
}