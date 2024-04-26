#include <iostream>
#include "SpreadSheet.h"

int main() {
    SpreadSheet sheet(3, 3);
    
    sheet.add_row(0, 0, "1");
    sheet.add_row(0, 1, "2");
    sheet.add_row(0, 2, "3");
    
    std::cout << sheet << std::endl;
    
    return 0;
}

