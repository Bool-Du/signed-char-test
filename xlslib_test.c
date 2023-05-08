#include <string.h>
#include <xlslib/xlslib.h>

using namespace xlslib_core;
using namespace std;

void test() {
    
    workbook wb;
    
    font_t * _font = wb.font("Calibri");
    _font->SetBoldStyle(BOLDNESS_BOLD);  // 设置粗字体
    
    xf_t* xf = wb.xformat();
    xf->SetFont(_font);
    
    worksheet* ws;
    ws = wb.sheet("sheet1");
    
    cell_t * cell;
    cell = ws->label(1,2,"hello",xf);    // 从0开始数，第1行，第2列，即C3
    cell = ws->label(2,2,"world");
    
    //cell->fillfgcolor(CLR_RED);
    //cell->fillbgcolor(CLR_WHITE);

    
    range * _range;
    _range = ws->rangegroup(0,0,2,2);   // 设置背景为白色
    _range->cellcolor(CLR_WHITE);
    
    _range = ws->rangegroup(3,3,5,5);
    _range->cellcolor(CLR_GOLD);
    
    
    wb.Dump("workbook.xls");
}

void test1() {
    
    workbook wb;
    worksheet* ws;
    
    ws = wb.sheet("sheet1");
    ws->defaultColwidth(256*10);
    ws->colwidth(2,256*30);
    
    cell_t * cell;
    
    cell = ws->label(1,2,"hello",xf);    // 从0开始数，第1行，第2列，即C3
    cell = ws->label(2,2,"world");
    
    wb.Dump("workbook1.xls");
}


int main (int argc, char *argv[]) 
{
 
	/* Sample 0 */
	/*workbook wb;

    	xf_t* xf = wb.xformat();

    	worksheet* ws;
    	ws = wb.sheet("sheet1");
	
	string label = "Hello, World!";
	ws->label(1,2,label,xf);
	
	wb.Dump("workbook.xls");
   	*/

	/* Sample 1 */

	test();	
	
	//test1();

	return 0;
}
