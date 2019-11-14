#include <stdio.h>
#include "CDR.h"
#include "subAgr.h"

int main()
{
	CDR* cdr1;
	CDR* cdr2;
	SubAgr* subAgr;
	char line1[256] = "1|cellcome|42502|MOC|100";
	char line2[256] = "1|cellcome|42503|MTC|150";
	cdr1 = CreateCDR(line1);
	if (cdr1 == NULL)
	{
		perror ("CreateCDR1");
		return 0;
	}
	cdr2 = CreateCDR(line2);
	if (cdr2 == NULL)
	{
		perror ("CreateCDR2");
		return 0;
	}
	subAgr = CreateSubAgr(100, 10);
	if (subAgr == NULL)
	{
		perror ("CreateSubAgr");
		return 0;
	}
	UpdateSubAgr(cdr1, subAgr);
	UpdateSubAgr(cdr2, subAgr);
	return 0;
}
