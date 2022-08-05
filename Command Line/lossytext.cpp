/*	********************************************
	Lossy Text Compression - BitSqueeze Method
	Written by Tomas "Frooxius" Mariancik September 4 2011
	This is done simply for fun as proof of concept that
	I can write seven letter word with six characters x3
	Don't take this too seriously :3
	Website: https://patreon.com/frooxius
	E-mail: tomas.mariancik@gmail.com
  ********************************************* */

#include <iostream>
using namespace std;

// For x86 abd some others
typedef unsigned short int UINT16;
#define CHECK_PLATFORM

/* ****** Method BitSqueeze ****** */
struct BitBuffer;
void LossyTextCompressBS(char *input, char *outbuf, unsigned int outbuf_size);
bool BitBufferWrite(UINT16 value, unsigned int bits, BitBuffer &bitbuf, char *&outbuf);
void LossyTextDecompressBS(char *input, char *outbuf, unsigned int outbuf_size);
UINT16 BitBufferRead(unsigned int bits, BitBuffer &bitbuf, char *&input);
UINT16 ReverseBits(UINT16 value, unsigned int bits);
const char *BITSQUEEZETABLE = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()*+/<>";
template<class X> inline X Min(X a, X b) { return (a<b)?a:b; }

int main()
{
	char *reference = "This is a testing message 1337 hax0r! LOLOL. OMG >.< Are you sure this will work? Some information will be lost.";
	//char *reference = "abcdefghi";
	char cBitSqueeze[255], dBitSqueeze[255];
	LossyTextCompressBS(reference, cBitSqueeze, 255);
	LossyTextDecompressBS(cBitSqueeze, dBitSqueeze, 255);
	cout << reference << endl << "Length: " << strlen(reference) << "\n\n";
	cout << cBitSqueeze << endl << "Length: " << strlen(cBitSqueeze) << "\n\n";
	cout << dBitSqueeze << endl << "Length: " << strlen(dBitSqueeze) << "\n\n";
	cin.get();
}

struct BitBuffer
{
	UINT16 bitbuf;
	unsigned short bitnum;
	BitBuffer() { bitbuf = bitnum = 0; }
};

void LossyTextCompressBS(char *input, char *outbuf, unsigned int outbuf_size)
{
#ifdef CHECK_PLATFORM
	// Can't check this with the preprocessor -_-, throws a simple expression, feel free to alter the error reporting the way you want
	if(sizeof(UINT16) < 2)	// well not strictly UINT16, but meh >.>
		throw "UINT16 HAS WRONG SIZE";
#endif
	BitBuffer bitbuf;
	bool wasspace, skipspace = false;

	while(*input && outbuf_size)
	{
		wasspace = false;
		// encode only certain characters using 5 bits and insert them into the bitbuffer
		if(*input >= 'a' && *input <= 'z')
			outbuf_size -= BitBufferWrite(*input - 'a', 5, bitbuf, outbuf);
		else if (*input >= 'A' && *input <= 'Z')
			outbuf_size -= BitBufferWrite(*input - 'A', 5, bitbuf, outbuf);
		else if (*input >= '0' && *input <= '3')
			outbuf_size -= BitBufferWrite(*input - '0' + 'z' - 'a' + 2, 5, bitbuf, outbuf);
		else if (*input >= '4' && *input <= '9')
			outbuf_size -= BitBufferWrite(31, 5, bitbuf, outbuf) | BitBufferWrite(*input - '4', 3, bitbuf, outbuf);
		else if(*input == '.' || *input == '!' || *input == '?')
			outbuf_size -= BitBufferWrite(31, 5, bitbuf, outbuf) | BitBufferWrite('9'-'4'+1, 3, bitbuf, outbuf);
		else if(*input == '\n' || *input == '\r')
			outbuf_size -= BitBufferWrite(31, 5, bitbuf, outbuf) | BitBufferWrite('9'-'4'+2, 3, bitbuf, outbuf);
		else
		{
			wasspace = true; // indicate that 
			if(!skipspace)
				outbuf_size -= BitBufferWrite('z'+1 - 'a', 5, bitbuf, outbuf); // anythig else is converted to space
		}
		skipspace = wasspace;
		input++;
	}
	// finalize it - insert null character at the end
	if(outbuf_size)
	{
		BitBufferWrite('z'+1 - 'a', 6-bitbuf.bitnum, bitbuf, outbuf);
		*outbuf = 0;
	}
	else
		*(outbuf-1) = 0;
}

// bit buffer takes bits and once there's enough of them to print a character from the squeeze table it stores it in the output
bool BitBufferWrite(UINT16 value, unsigned int bits, BitBuffer &bitbuf, char *&outbuf)
{
	// the value sanitization isn't strictly needed for this example, but in case you wanted to use this elsewhere, it's there ;)
	bitbuf.bitbuf |= (value & ~(0xFFFFU << bits)) << bitbuf.bitnum; // add the new value to the buffer
	// if there's enough to generate a character
	if((bitbuf.bitnum += bits) >= 6)
	{
		*(outbuf++) = *(BITSQUEEZETABLE + ( bitbuf.bitbuf & 0x3FU)) ;
		bitbuf.bitbuf >>= 6;
		bitbuf.bitnum -= 6;
		return true;
	}
	return false;
}

void LossyTextDecompressBS(char *input, char *outbuf, unsigned int outbuf_size)
{
#ifdef CHECK_PLATFORM
	// Can't check this with the preprocessor -_-, throws a simple expression, feel free to alter the error reporting the way you want
	if(sizeof(UINT16) < 2)	// well not strictly UINT16, but meh >.>
		throw "UINT16 HAS WRONG SIZE";
#endif

	BitBuffer bitbuf;
	UINT16 temp;
	while((temp = BitBufferRead(5, bitbuf, input)) != 0xFFFFU && outbuf_size--)
	{
		if(temp <= ('z'-'a'))
			*(outbuf++) = 'a'+temp;
		else if(temp == ('z'-'a'+1))
			*(outbuf++) = ' ';
		else if(temp == 31U)
			*(outbuf++) = "456789.\n"[Min((int)BitBufferRead(3, bitbuf, input), 7)];
		else *(outbuf++) = '0'-('z'-'a'+2)+temp;
	}
	// finish it
	if(outbuf_size)
		*outbuf = 0;
	else
		*(outbuf-1) = 0;
}

UINT16 BitBufferRead(unsigned int bits, BitBuffer &bitbuf, char *&input)
{
	if(bitbuf.bitnum < bits)
	{
		if(*input == 0)
		return 0xFFFFU;

		UINT16 newvalue;
		for(newvalue = 0; (*input != *(BITSQUEEZETABLE+newvalue)) && newvalue < 64; ++newvalue); // not most efficient, can be replaced with generated conversion table
		bitbuf.bitbuf |= newvalue << bitbuf.bitnum;
		bitbuf.bitnum += 6;
		input++;
	}
	UINT16 ret = bitbuf.bitbuf & ~(0xFFFFU << bits);
	bitbuf.bitnum -= bits;
	bitbuf.bitbuf >>= bits;
	return ret;
}

UINT16 ReverseBits(UINT16 value, unsigned int bits)
{
	UINT16 reversed = 0;
	for(unsigned int i = 0; i < bits; ++i)
		reversed |= ((bool)(value & (1<<i))) << (bits-i-1);
	return reversed;
}