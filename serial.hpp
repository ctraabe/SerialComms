
#include <cinttypes>
#include <string>

#include <termios.h>

class Serial
{
public:
  Serial() : id_(-1) {}
  Serial(const std::string &comport, const int baudrate);

  operator bool() const { return id_ != -1; }

  // Check how many bytes are available to be read.
  int BytesAvailable() const;

  // Returns the number of bytes read.
  int Read(uint8_t* const buffer, const int length) const;

  // Read one byte, if available, otherwise returns false.
  bool ReadByte(uint8_t* const buffer) const;

  // // Returns the number of bytes written.
  int SendByte(const uint8_t byte) const;

  int SendBuffer(const uint8_t* const buffer, const int length) const;

  void Close();

private:
  int id_;
  struct termios original_port_settings_;
};

#endif // SERIAL_HPP_
