/**
 * MessageU Client
 * @file CSocketHandler.h
 * @brief Handle sending and receiving from a socket.
 * @author Roman Koifman
 */
#pragma once
#include <string>
#include <cstdint>
#include <ostream>
#include <boost/asio/ip/tcp.hpp>

constexpr size_t PACKET_SIZE = 1024;
constexpr auto LOCALHOST     = "localhost";
constexpr auto CLOCALHOST    = "LOCALHOST";

class CSocketHandler
{
public:
	CSocketHandler();
	~CSocketHandler();
	
	friend std::ostream& operator<<(std::ostream& os, const CSocketHandler& socket);
	bool setSocketInfo(const std::string& address, const std::string& port);

	// do not allow
	CSocketHandler(const CSocketHandler& other) = delete;
	CSocketHandler(CSocketHandler&& other) noexcept = delete;
	CSocketHandler& operator=(const CSocketHandler& other) = delete;
	CSocketHandler& operator=(CSocketHandler&& other) noexcept = delete;

	// validations
	static bool isValidAddress(const std::string& address);
	static bool isValidPort(const std::string& port);

	// logic
	bool connect();
	void close();
	bool receive(uint8_t(&buffer)[PACKET_SIZE]) const;
	bool receive(uint8_t* const buffer, const size_t size) const;
	bool send(uint8_t(&buffer)[PACKET_SIZE]) const;
	bool send(const uint8_t* const buffer, const size_t size) const;
	
	// todo remove
	std::string testSocket(const char* msg) const;

private:
	std::string                     _address;
	std::string                     _port;
	boost::asio::io_context*        _ioContext;
	boost::asio::ip::tcp::resolver* _resolver;
	boost::asio::ip::tcp::socket*   _socket;
	bool _bigEndian;

	void clear();
	void convertEndianness(uint8_t* const buffer, const size_t size) const;

	
};
