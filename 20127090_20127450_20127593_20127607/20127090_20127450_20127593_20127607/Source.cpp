#include<iostream>
#include<string>
using namespace std;

string vigenere_cipher_enc(string key, string message) {
	size_t m = key.length();

	string encrypted_message = "";
	int index_key = 0;
	for (char ch : message) {

		encrypted_message += (char)(((int)tolower(ch) + (int)key[index_key] - 97 * 2) % 26 + 97);
		if (index_key == m - 1) {
			index_key = 0;
		}
		else index_key++;
	}
	return encrypted_message;
}

string vigenere_cipher_dec(string key, string encrypted_message) {
	int m = key.length();

	string message = "";

	int index_key = 0;
	for (char ch : encrypted_message) {
		message += (char)((int(ch) - (int)tolower(key[index_key]) + 26) % 26 + 97);
		if (index_key == m - 1) {
			index_key = 0;
		}
		else index_key++;
	}
	cout << endl;
	return message;
}

int main() {

	string m = "thiscryptosystemisnotsecure", k = "cipher", c = "";

	cout << "original message: " << m << endl;

	c = vigenere_cipher_enc(k, m);

	cout << "encrypted message: " << c << endl;

	m = vigenere_cipher_dec(k, c);

	cout << "decrypted message: " << m << endl;

	return 0;
}