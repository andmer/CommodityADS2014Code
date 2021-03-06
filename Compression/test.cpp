#include "Compression.h"
#include <iostream>
using namespace igmdk;

Vector<unsigned char> compress(Vector<unsigned char> const& byteArray)
{
    BitStream result;
    GammaEncode(7, result);
    result.bitset.output();
    DEBUG(GammaDecode(result));
    byteEncode(128, result);
    result.bitset.output();
    DEBUG(byteDecode(result));
    FibonacciEncode(2342, result);
    result.bitset.output();
    DEBUG(FibonacciDecode(result));

    //return BWTCompress(byteArray);

    BitStream in(byteArray);
    BitStream out;
    LZWCompress(in, 10, out);
    return ExtraBitsCompress(out.bitset);
}

Vector<unsigned char> uncompress(Vector<unsigned char> const& byteArray)
{
    //return BWTUncompress(byteArray);

    BitStream in(ExtraBitsUncompress(byteArray));
    BitStream out;
    LZWUncompress(in, 10, out);
    return out.bitset.getStorage();
}

void timeRT()
{
    char text[] = //"abbabab";
    "sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    sdjkhlsdfjhsdfajdsfjkhljkhlsdfhjklsdfhjlkdasfjhklsdf\
    ";
    Vector<unsigned char> uncompressed0;
    for(int i = 0; i < sizeof(text)-1; ++i) uncompressed0.append(text[i]);
    Vector<unsigned char> uncompressed(uncompressed0);

    cout << "uncompressed.size" << uncompressed.getSize() << endl;
    Vector<unsigned char> compressed(compress(uncompressed));
    cout << "compressed.size" << compressed.getSize() << endl;
    Vector<unsigned char> uncompressed2(uncompress(compressed));
    cout << "uncompressed2.size" << uncompressed2.getSize() << endl;
    assert(uncompressed.getSize() ==  uncompressed2.getSize());
    for(int i = 0; i < uncompressed2.getSize(); ++i) assert(uncompressed2[i] == uncompressed[i]);
}

int main()
{
	clock_t start = clock();
	    timeRT();
	int tFL = (clock() - start);
    cout << "FL: "<<tFL << endl;
	return 0;
}
