//
// Created by arcyfields on 2026/3/21.
//

#ifndef _SERIAL_PORT_H_
#define _SERIAL_PORT_H_

#include <string>
#include <cstdint>

class SerialPort {
private:
    int _fd;

    void open_port(const std::string & device, int baud_rate);
    void close_port();
public:
    SerialPort();
    SerialPort(const std::string & device, int baud_rate);
    ~SerialPort();

    void write(const uint8_t * data, size_t size);
};

#endif //_SERIAL_PORT_H_