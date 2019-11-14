
#define NO_OF_BITS (sizeof(int)*8)

unsigned int MirrorBits(unsigned int _num)
{
	int i;
	unsigned int mirror=0;
	for(i=0; i<NO_OF_BITS; ++i)
	{
		mirror<<=1;
		mirror |= (_num&1);
		_num >>=1;
	}
	return mirror;
}


