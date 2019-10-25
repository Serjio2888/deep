#include <stdio.h>

int main(){
	const char *work_places[2];
	work_places[0] = "bellhoper";
	work_places[1] = "cleaner";
	for (size_t i = 0; i < 10; ++i) {
		printf("%c", work_places[0][i]);
	}
	int j = 0;

	while (&work_places[1][j] != "\0") {
		printf("%c", work_places[1][j]);
		++j;
	}
	return 0;
}
