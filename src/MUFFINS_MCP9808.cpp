#include <MUFFINS_MCP9808.h>

MCP9808::MCP9808(String component_name, void (*info_function)(String), void (*error_function)(String)) : Component_Base(component_name, info_function, error_function)
{
  return;
}

MCP9808::~MCP9808()
{
  return;
}

bool MCP9808::begin(const Config &config)
{
  _config = config;
  if (!_mcp9808.begin(_config.i2c_address, _config.wire))
  {
    error("Failed to initialize!");
    return false;
  }

  _mcp9808.setResolution(_config.resolution);
  delay(100);
  _mcp9808.wake();

  info("Initialized successfully!");
  set_initialized(true);

  return true;
}

bool MCP9808::read()
{
  if (!initialized())
  {
    return false;
  }

  data.temperature = _mcp9808.readTempC();

  return true;
}
