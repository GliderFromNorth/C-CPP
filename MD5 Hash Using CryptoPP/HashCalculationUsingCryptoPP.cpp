// HashCalculationUsingCryptoPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include "cryptlib.h"
#include "md5.h"
#include <md5.h>
#include "filters.h"
#include "hex.h"
#include "files.h"
using namespace std;




int main(int argc, char* argv[])
{
	using namespace CryptoPP;

	string digest;
	FileSource file("filename.txt", true, new StringSink(digest));

	HexEncoder encoder(new FileSink(std::cout));

	Weak::MD5 hash;
	hash.Update((const byte*)&digest[0], digest.size());
	digest.resize(hash.DigestSize());
	hash.Final((byte*)&digest[0]);

	std::cout << "Message: " << digest << std::endl;

	std::cout << "Digest: ";
	StringSource(digest, true, new Redirector(encoder));
	std::cout << std::endl;
	system("pause");
	return 0;
}