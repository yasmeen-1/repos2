

#include<iostream>

#include <string>
#include <algorithm>   
using namespace std;

struct SEMBOLS {
	char SEMBO;
	float FREQ;
	

};
char ORIGNOL[500];

// get the position of a character in the array of structre
int getposition(const SEMBOLS* AR, size_t size, char c)
{
	for (int i = 0; i < size; i++) {
		if (AR[i].SEMBO == c) {
			return i;
		}
	}
	return -1;
}

int getposition(const char* array, size_t size, char c)
{
	for (int i = 0; i < size; i++) {
		if (array[i] == c) {
			return i;
		}
	}
	return -1;
}

int main()
{
	
	char Frequncy[500];

	while (true) {
		int number = 0, t = 0, max_count_number = 0, u;
		SEMBOLS te_mx;
		SEMBOLS frequncy_rr[26];
		cout	<< "\t 2. Least-Simple  Substitution Algorithm" << endl;
	
	
		char frequncy_slie[26] = { 'E','T','A','I','O','N','S','R','H','D','L','U','C','M','F','Y','W','G','P','B','V','K','X','Q','J','Z' };
		cout << "The letter frequency in slide" << endl<< "++++++++++++++++++\t++++++++++++++++++\t++++++++++++++++++";
		
		cout << "   letter => ";
		for (int j = 0; j <= 25; j++) {
			cout << (char)frequncy_slie[j] << "   \t";
		}
		cout << endl << "Frequency : ";
		float Freq_count[26] = { 12.02,9.10,8.12,7.68,7.31,6.95,6.28,6.02,5.92,4.32,4.98,2.88,2.71,2.61,2.30,2.11,2.09,2.03,1.82,1.49,1.11,0.69,0.17,0.11,0.10,0.07 };
		for (int i = 0; i <= 25; i++) {
			cout << Freq_count[i] << "\t";
		}
		cout << endl;
		cout << " replace the letter  to Frequency array" << endl;
		char incrypt[26] = { 'J','I','C','A','X','S','E','Y','V','D','K','W','B','Q','T','Z','R','H','F','M','P','N','U','L','G','O' };
		for (int x = 0; x <= 25; x++) {
			cout << incrypt[x] << "\t";
		}
		cout << "Please Enter the Plaintext  " << endl;
				cin >> Frequncy;
			
				cout << endl << " \t \t++++++++++++++++++++++++++++++++++++++++ t\ " << endl;
				
				for (int j = 65; j <= 90; j++) {
					number = 0;
					cout << "Letter " << (char)(j) << " Counts: ";
					for (u = 0; u < strlen(Frequncy); u++) {
						if (Frequncy[u] == ((char)j)) {
							number++;
						}
					}
					frequncy_rr[t].FREQ = (float)number / strlen(Frequncy);
					frequncy_rr[t].SEMBO = (char)(j); 
					cout << number << "\t freq =" << frequncy_rr[t].FREQ << endl;
					t++;
				}
				cout << " sort the letters according to the frequecy" << endl;

				
				for (int i = 1; i <= 25; i++) {
					if (frequncy_rr[i].FREQ < frequncy_rr[i - 1].FREQ) {
						for (int k = i; (k >= 1) && (frequncy_rr[k].FREQ < frequncy_rr[k - 1].FREQ); k--) {

							te_mx.FREQ = frequncy_rr[k - 1].FREQ;
							te_mx.SEMBO = frequncy_rr[k - 1].SEMBO;
							frequncy_rr[k - 1].FREQ = frequncy_rr[k].FREQ;
							frequncy_rr[k - 1].SEMBO = frequncy_rr[k].SEMBO;
							frequncy_rr[k].FREQ = te_mx.FREQ;
							frequncy_rr[k].SEMBO = te_mx.SEMBO;

						}
					}
				}
			

			
				int uo = 25;  
				int freqp = 0;   
				while (freqp < uo) 
				{
					te_mx.FREQ = frequncy_rr[freqp].FREQ;
					te_mx.SEMBO = frequncy_rr[freqp].SEMBO;
					frequncy_rr[freqp].FREQ = frequncy_rr[uo].FREQ;
					frequncy_rr[freqp].SEMBO = frequncy_rr[uo].SEMBO;
					frequncy_rr[uo].FREQ = te_mx.FREQ;
					frequncy_rr[uo].SEMBO = te_mx.SEMBO;
					freqp++;
					uo--;
				}
				
				for (int i = 0; i <=25; i++) {
					cout << "Letter at index " << i << "is :" << frequncy_rr[i].SEMBO << endl;
				}
				strncpy(ORIGNOL, Frequncy, 500);
				string ciphertext = ""; 
				
				for (int i = 0; i < strlen(ORIGNOL); i++) {
					char chrcter = ORIGNOL[i];
					cout << "Letter : " << chrcter;
					int position_ = getposition(frequncy_rr, 26, chrcter);
					cout << ", position  is " << position_;
					//cout << mostfreq[pos];
					cout << " ,replace with " << incrypt[position_] << endl;
					ciphertext += incrypt[position_];
				}
				
				cout << "The Encrypted  is : \n " << ciphertext << endl;

			
		


		
}
