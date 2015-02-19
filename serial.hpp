#ifndef SERIAL_H_
#define SERIAL_H_

#include <cinttypes>
#include <string>

#include <termios.h>

class Serial
{
public:
  Serial() : id_(-1) {}
  Serial(const std::string &comport, const int baudrate);

  operator bool() const { return id_ != -1; }

  int Read(uint8_t* const buffer, const int length) const;
  int SendByte(const uint8_t byte) const;
  int SendBuffer(const uint8_t* const buffer, const int length) const;
  void Close();

private:
  int id_;
  struct termios original_port_settings_;
};

#endif // SERIAL_H_