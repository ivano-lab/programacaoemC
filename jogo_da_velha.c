# include <stdio.h>

int main() {

	char palsecr[20];

	palsecr[0] = 'M';
	palsecr[1] = 'E';
	palsecr[2] = 'L';

	for(int i = 0; i < 8; i++){
		printf("%c", palsecr[i]);
	}	
}
