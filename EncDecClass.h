#include <iostream>
#include "crypto++/blowfish.h"
#include "crypto++/osrng.h"
#include "crypto++/modes.h"
#include <fstream>
#include "crypto++/rsa.h"
#include <cryptopp/hex.h> 
#include <cryptopp/files.h> 

#include <sstream>

using namespace CryptoPP;
using namespace std;


class _rsa
{
private:
	Integer m, r;

public:

	string encrypt(string openText){
		Integer n("0xbeaadb3d839f3b5f"), e("0x11"), d("0x21a5ae37b9959db9"), c;
		RSA::PublicKey pubKey;
		pubKey.Initialize(n, e);

		m = Integer((const byte *)openText.data(), openText.size());
		c = pubKey.ApplyFunction(m);

		stringstream ss;
		ss << std::hex << c;
		string res(ss.str());

		return res;
	}

	string decrypt(string encryptedText){
		string res = "0x" + encryptedText;

		char as[res.size()];
		strcpy(as, res.c_str());

		Integer n("0xbeaadb3d839f3b5f"), e("0x11"), d("0x21a5ae37b9959db9"), c(as);

		string recovered;
		AutoSeededRandomPool prng;
		RSA::PrivateKey privKey;
		privKey.Initialize(n, e, d);

		r = privKey.CalculateInverse(prng, c);
		size_t req = r.MinEncodedSize();
		recovered.resize(req);
		r.Encode((byte *)recovered.data(), recovered.size());

		return recovered;
	}
};