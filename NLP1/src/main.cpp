#include "preprocesor.h"
#include <iostream>
using namespace std;

int main() {
	string read_ULR = "C:/Users/luisn/source/repos/NLP1/text_files/Resume.txt";
	string create_ULR = "C:/Users/luisn/source/repos/NLP1/text_files/Preproseser_Resume.txt";
	preproscesor p;
	p.senteces_separetor(read_ULR, create_ULR);
}