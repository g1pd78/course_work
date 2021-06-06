#include <iostream>
#include "crypto++/blowfish.h"
#include "crypto++/osrng.h"
#include "crypto++/modes.h"
#include <fstream>
#include "crypto++/rsa.h"

using namespace CryptoPP;
using namespace std;




class _rsa
{
private:
	Integer m, r;

public:

	Integer encrypt(string openText){
		Integer n("0xbeaadb3d839f3b5f"), e("0x11"), d("0x21a5ae37b9959db9"), c;

		RSA::PublicKey pubKey;
		pubKey.Initialize(n, e);
		m = Integer((const byte *)openText.data(), openText.size());
		c = pubKey.ApplyFunction(m);

		return c;
	}

	string decrypt(Integer c){
		Integer n("0xbeaadb3d839f3b5f"), e("0x11"), d("0x21a5ae37b9959db9");
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