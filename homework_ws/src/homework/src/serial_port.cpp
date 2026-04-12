//
// Created by arcyfields on 2026/3/21.
//

#include "serial_port.h"

#include <iostream>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdexcept>

void SerialPort::open_port(const std::string & device, int baud_rate) {
    _fd = open(device.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
    if (_fd < 0) {
        throw std::runtime_error("Failed to open " + device);
    }

    struct termios tty;
    memset(&tty, 0, sizeof tty);
    if (tcgetattr(_fd, &tty) != 0) {
        close(_fd);
        throw std::runtime_error("tcgetattr failed.");
    }

    cfsetispeed(&tty, baud_rate);
    cfsetospeed(&tty, baud_rate);

    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
    tty.c_iflag &= ~IGNBRK;                         // disable break processing
    tty.c_lflag = 0;                                // no signaling, echo, etc.
    tty.c_oflag = 0;
    tty.c_cc[VMIN]  = 0;                            // read doesn't block
    tty.c_cc[VTIME] = 5;                            // 0.5 seconds read timeout

    tty.c_iflag &= ~(IXON | IXOFF | IXANY);         // shut off flow control
    tty.c_cflag |= (CLOCAL | CREAD);                // ignore modem controls
    tty.c_cflag &= ~(PARENB | PARODD);              // no parity
    tty.c_cflag &= ~CSTOPB;                         // 1 stop bit
    tty.c_cflag &= ~CRTSCTS;                        // no hardware flow control

    if (tcsetattr(_fd, TCSANOW, &tty) != 0) {
        close(_fd);
        throw std::runtime_error("tcsetattr failed.");
    }
}

void SerialPort::close_port() {
    std::cerr << "close_port called, fd = " << _fd << std::endl;
    if (_fd >= 0) {
        ::close(_fd);
        _fd = -1;
    }
}

SerialPort::SerialPort() : _fd(-1) {
    close_port();
}

SerialPort::SerialPort(const std::string & device, int baud_rate) : _fd(-1) {
    open_port(device, baud_rate);
}

SerialPort::~SerialPort() {
    close_port();
}

void SerialPort::write(const uint8_t * date, size_t size) {
    if (_fd < 0) {
        return;
    }

    ssize_t written = ::write(_fd, date, size);
    if (written != static_cast<ssize_t>(size)) {
        throw std::runtime_error("Failed to write.");
    }

    usleep(size * 500);
}