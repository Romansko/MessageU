/**
 * MessageU Client
 * @file CSocketHandler.h
 * @brief Handle sending and receiving from a socket.
 * @author Roman Koifman
 */

#pragma once
#include <boost/asio/ip/tcp.hpp>
using boost::asio::ip::tcp;

constexpr size_t PACKET_SIZE = 1024;
constexpr INT VALID_ADDRESS  = 1;
constexpr auto LOCALHOST     = "localhost";

class CSocketHandler
{
public:
	CSocketHandler();
	bool isValidIp(std::string& ip);
	bool isValidPort(std::string& port);
	bool receive(tcp::socket& sock, uint8_t (&buffer)[PACKET_SIZE]);
	bool send(tcp::socket& sock, const uint8_t(&buffer)[PACKET_SIZE]);

	
	// todo remove
	static std::string testSocket(std::string& address, std::string& port, const char* msg);

private:
	bool _bigEndian;
	void convertEndian(uint8_t* const buffer, const size_t size) const;
	
};
