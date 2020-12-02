#include <stdio.h>

int main(void) {

	int count[5] = { 0,0,0,0,0 };
	int data[10] = { 5,3,4,5,3,4,1,5,4,1 };

	for (int i = 0; i < 20; i++) {
		count[data[i] - 1]++;
	}

	for (int i = 0; i < 5; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++) {
				printf("%d ", i + 1);
			}
		}
	}

	return 0;
}