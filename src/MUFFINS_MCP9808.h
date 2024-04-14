#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <MUFFINS_Component_Base.h>
#include <Adafruit_MCP9808.h>

class MCP9808 : public Component_Base
{
public:
  struct Config
  {
    TwoWire *wire;
    int i2c_address;
    int resolution; // 0-3
  };

  struct Data
  {
    float temperature;
  } data;

private:
  Adafruit_MCP9808 _mcp9808;
  Config _config;

public:  
  /**
   * @brief Construct a new MCP9808 sensor instance
   */
  MCP9808(String component_name = "MCP9808", void (*info_function)(String) = nullptr, void (*error_function)(String) = nullptr);

  /**
   * @brief Destroys the MCP9808 sensor instance.
   */
  ~MCP9808();

  /**
   * @brief Initializes the MCP9808 sensor with the specified configuration.
   *
   * @param config The configuration settings for the sensor.
   * @return True if the initialization is successful, false otherwise.
   */
  bool begin(const Config &config);

  /**
   * @brief Reads data from the MCP9808 sensor.
   *
   * This function reads data from the MCP9808 sensor and stores it in the provided data structure.
   *
   * @return true if the read operation was successful, false otherwise.
   */
  bool read();
};
