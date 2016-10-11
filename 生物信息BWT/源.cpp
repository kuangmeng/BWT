#include<string>
#include<algorithm>
#include<iostream>
#include<fstream>
#define MAX 1000
using namespace std;

void BWT(char L[],string str) {
	int strlen = str.length();
	str+= '$';
	strlen += 1;
	string matrix[MAX];
	for (int i = 0; i < strlen; i++){
		matrix[i] = str.substr(i);
	}
	sort(matrix, matrix + strlen);
	for (int i = 0; i < strlen; i++){
		L[i] = str[(2 * strlen - matrix[i].length() - 1) % strlen];
	}
}
int main(int argc, char* argv[])
{
	char fasta[1000], result[MAX] = { 0 };
	string fastas;
	ifstream input("input.fasta");
	if (!input.is_open()){
		cout << "无法打开文件!";
		return 0;
	}
	input.getline(fasta, 1000);
	input.close();
	fastas = fasta;
	BWT(result, fastas);
	ofstream output("bwt.txt", ios::app);
	for (int i = 0; i < MAX; i++){
		if (result[i] != 0){
			output << result[i];
		}
		if ((i + 1) % 100 == 0) {
			output << endl;
		}
	}
	output.close();
	return 0;
}

