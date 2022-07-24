#include <stdio.h>
#include <stdlib.h>

int cnt0, cnt1;
int* tree;
int N,back;
int idx = 0;

void tree_func() {
	while (1) {
		for (int i = 0; i <= back; i++) {
			printf("%d ", tree[i]);
		}
		if (tree[back] == 2) {
			cnt0++;
			cnt1++;
			printf(" [0 : %d, 1 : %d] \n", cnt0, cnt1);
			if (back == 0) return;
			if (tree[back - 1] - 1 == tree[back])
				tree[back] = tree[back - 1] - 2;
			else if (tree[back - 1] - 2 == tree[back]) {
				while (tree[back - 1] - 2 == tree[back]) {
					if (back == 1) return;
					back--;
				}
				tree[back]--;
				for (int i = tree[back]; i >= 2; i--) {
					tree[back++] = i;
				}
				back--;
			}
		}
		else if (tree[back] == 1) {
			if (back == 1) {
				printf(" [0 : %d, 1 : %d] \n", cnt0, cnt1);
				break;
			}
			cnt1++;
			printf(" [0 : %d, 1 : %d] \n", cnt0, cnt1);
			back--;
			if (tree[back - 1] - 1 == tree[back]) {
				tree[back] = tree[back - 1] - 2;
			}
			else if (tree[back - 1] - 2 == tree[back]) {
				while (tree[back - 1] - 2 == tree[back]) {
					if (back == 1) return;
					back--;
				}
				tree[back]--;
				for (int i = tree[back]; i >= 2; i--) {
					tree[back++] = i;
				}
				back--;
			}
		}

	}
}


int main(void) {
	int Tc;
	scanf("%d", &Tc);
	while (Tc--) {
		idx = 0;
		cnt0 = 0;
		cnt1 = 0;
		scanf("%d", &N);
		if (N == 0) printf("1 0\n");
		else if (N == 1) printf("0 1\n");
		else {
			tree = (int*)malloc(4 * N + 4);
			back = N - 2;
			for (int i = N; i >= 2; i--)
				tree[idx++] = i;
			tree_func();
			printf("%d %d\n", cnt0, cnt1);
		}
	}
	free(tree);
	return 0;
}
