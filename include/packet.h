#ifndef __PACKET__
#define __PACKET__

struct packet
{
	char channel;
	char command;
	double data[3];
	char duration;
	char nullterm;
};

#endif
