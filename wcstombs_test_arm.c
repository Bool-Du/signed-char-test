#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <errno.h>

int xls_is_bigendian()
{
#if defined (__BIG_ENDIAN__)
    return 1;
#elif defined (__LITTLE_ENDIAN__)
    return 0;
#else
    static int n = 1;

    return (*(char *)&n == 0);
#endif
}

uint32_t xlsIntVal (uint32_t i)
{
    unsigned char c1, c2, c3, c4;

    if (xls_is_bigendian()) {
        c1 = i & 255;
        c2 = (i >> 8) & 255;
        c3 = (i >> 16) & 255;
        c4 = (i >> 24) & 255;

        return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
    } else {
        return i;
    }
}

void main()
{
	printf("Hello World - 22222!\n");
	printf("size of wchar_t:%d\n",sizeof(wchar_t));

	// 87 00 67 00 06 82 123 124 - decimal
	// 57 00 43 00 06 52 7b 7c

	wchar_t src1[64[ = {0};
	const wchar_t src[] = L"WC分类";
	//const wchar_t src[] = {0x0057, 0x0043, 0x5206, 0x7c7b, 0x0000};

	char dst[64] = {0};
	
	printf("wide-character string: '%s'\n",src);

   	for (size_t ndx=0; ndx < sizeof src/sizeof src[0]; ++ndx)
        {
		src1[ndx] = xlsIntVal(src[ndx]);

		printf("   src[%d] = 0x%04x - src1[%d] = 0x%04x\n", ndx, src[ndx], ndx, src1[ndx]);
	}
	//setlocale(LC_ALL, "Chinese-simplified");
	//char* pLoc = setlocale(LC_CTYPE, "chs"); 
	
	//setlocale(LC_CTYPE,setlocale(LC_ALL,""));
	//char* p = setlocale(LC_CTYPE, "en-US.utf8");
	   
	char* p = setlocale(LC_ALL, "");
	
	/* Display some of the locale settings */
	//printf("Thousands Separator: %s\n", loc->thousands_sep);
	//printf("Currency Symbol: %s\n", loc->currency_symbol);

	int j = errno;

	//int rtn_val = wcstombs(dst, src, sizeof(dst));
	int rtn_val = wcstombs(dst, src1, sizeof(dst));

	//int rtn_val = wcstombs(dst, src, 20);
	//char* p1 = setlocale(LC_ALL, "C");

	int i = errno;
	printf("rtn_val = %d, errno:%d\n", rtn_val, i);
	
	if (rtn_val > 0)
        	printf("multibyte string:  '%s'\n",dst);

	for(size_t ndx=0; ndx < sizeof dst/sizeof dst[0]; ++ndx)
		printf("  dst[%d] = 0x%02x\n", ndx, dst[ndx]);
}
