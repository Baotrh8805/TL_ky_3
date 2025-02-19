#include "QLPT.h"
#include <iostream>
#include <fstream>
#include <string>

#undef byte

using namespace std;

#include <iostream>
using namespace std;

  
int main(){
    logo();
    QLPT qlpt;
    qlpt.doc_file_hd();
    qlpt.doc_file_bill();
    qlpt.doc_file_phong();
    qlpt.doc_file_chu();
    qlpt.doc_file_thue();
    qlpt.dang_nhap();
    return 0;
}