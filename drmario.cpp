/*
 * drmario.cpp
 *
 *  Created on: Nov 7, 2012
 *      Author: mikmister02
 */

#include <zmq.hpp>
//#include <zmq.h>
#include <iostream>
#include <string>

using namespace std;

int main(void){

	zmq::context_t context(1);
	zmq::socket_t socket(context, ZMQ_REQ);

	socket.connect("tcp://ec2-50-19-179-117.compute-1.amazonaws.com:5557");

	zmq::message_t request (6);
	memcpy ((void *) request.data (), "Hello", 5);
	std::cout << "Sending Hello " << endl;
	socket.send (request);

	//  Get the reply.
	zmq::message_t reply;
	int size = socket.recv(&reply);
	char* string = (char*) reply.data();
	cout << "Received World " << string << endl;

	return 0;

}
