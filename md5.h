#pragma once
#include <string>
typedef unsigned char byte;
class cmd5
{
public:
	cmd5();
	std::string calcMD5(const char* data, size_t len);
private:
	typedef struct
	{
		unsigned int count[2];
		unsigned int state[4];
		unsigned char buffer[64];   
	} MD5_CTX;
private:
	void MD5Init(MD5_CTX *context);
	void MD5Update(MD5_CTX *context, unsigned char *input, unsigned int inputlen);
	void MD5Final(MD5_CTX *context, unsigned char digest[16]);
	void MD5Transform(unsigned int state[4], unsigned char block[64]);
	void MD5Encode(unsigned char *output, unsigned int *input, unsigned int len);
	void MD5Decode(unsigned int *output, unsigned char *input, unsigned int len);
private:
	byte PADDING[16 * 4];
};

