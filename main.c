#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b) {
	int t=*a;
	*a = *b;
	*b = t;
}
void sort_array(int* arr, int len) {
	int i, r;
	for (i = 0; i < len - 1; i++)
		for (r = i + 1; r < len; r++)
			if (arr[i] > arr[r])
				swap(arr + i, arr + r);
}
void sort_array_bubble(int* arr, int len) {
	int i, r;
	for (i = 1; i < len; i++)
		for (r = 0; r < len - i; r++)
			if (arr[r] > arr[r + 1])
				swap(arr + r, arr + r + 1);
}
void sort_matrix(int** arr, int rows, int cols) {
	int i, r, j, k;
	for (i = 0; i < rows; i++)
		for (r = 0; r < cols; r++) {
			for (j = r + 1; j < cols; j++)
				if (arr[i][r] > arr[i][j])
					swap(arr[i] + r, arr[i] + j);
			for (k = i + 1; k < rows; k++)
				for (j = 0; j < cols; j++)
					if (arr[i][r] > arr[k][j])
						swap(arr[i] + r, arr[k] + j);
		}
}
void sort_matrix_bubble(int** arr, int rows, int cols) {
	int i, r, j, k, *p;
	for (i = 0; i < rows; i++)
		for (r = 0; r < cols; r++) {
			p = arr[0];
			for (j = 0; j < rows - i - 1; j++)
				for (k = 0; k < cols; k++) {
					if (*p > arr[j][k])
						swap(p, arr[j] + k);
					p = arr[j] + k;
				}
			for (j = 0; j < cols - r; j++) {
				if (*p > arr[rows - i - 1][j])
					swap(p, arr[rows - i - 1] + j);
				p = arr[rows - i - 1] + j;
			}
		}
}
void sort_3d_array(int*** arr, int height, int rows, int cols) {
	int i, r, j, k, m, x;
		for (i = 0; i < height; i++)
			for (r = 0; r < rows; r++)
				for (j = 0; j < cols; j++) {
					for (k = j + 1; k < cols; k++)
						if (arr[i][r][j] > arr[i][r][k])
							swap(arr[i][r] + j, arr[i][r] + k);
					for (k = r + 1; k < rows; k++)
						for (m = 0; m < cols; m++)
							if (arr[i][r][j] > arr[i][k][m])
								swap(arr[i][r] + j, arr[i][k] + m);
					for (k = i + 1; k < height; k++)
						for (m = 0; m < rows; m++)
							for (x = 0; x < cols; x++)
								if (arr[i][r][j] > arr[k][m][x])
									swap(arr[i][r] + j, arr[k][m] + x);
				}
}
void sort_3d_array_bubble(int*** arr, int height, int rows, int cols) {
	int i, r, j, k, m, x, *p;
	for (i = 0; i < height; i++)
		for (r = 0; r < rows; r++)
			for (j = 0; j < cols; j++) {
				p = arr[0][0];
				for (k = 0; k < height - i - 1; k++)
					for (m = 0; m < rows; m++)
						for (x = 0; x < cols; x++) {
							if (*p > arr[k][m][x])
								swap(p, arr[k][m] + x);
							p = arr[k][m] + x;
						}
				for (k = 0; k < rows - r - 1; k++)
					for (m = 0; m < cols; m++) {
						if (*p > arr[height - i - 1][k][m])
							swap(p, arr[height - i - 1][k] + m);
						p = arr[height - i - 1][k] + m;
					}
				for (k = 0; k < cols - j; k++) {
					if (*p > arr[height - i - 1][rows - r - 1][k])
						swap(p, arr[height - i - 1][rows - r - 1] + k);
					p = arr[height - i - 1][rows - r - 1] + k;
				}
			}
}
int* get_array(int len) {
	int* p = malloc(sizeof(int) * len);
	int i;
	for (i = 0; i < len; i++) {
		printf("Enter array %d element: ",i+1);
		scanf("%d", p + i);
	}
	return p;
}
int** get_matrix(int rows,int cols) {
	int** p = malloc(sizeof(int*) * rows);
	int i,r;
	for (i = 0; i < rows; i++)
		p[i] = malloc(sizeof(int) * cols);
	for(i=0;i<rows;i++)
		for (r = 0; r < cols; r++) {
			printf("Enter row: %d, col: %d,element: ", i + 1, r + 1);
			scanf("%d", p[i]+r);
		}
	return p;
}
int*** get_3d_arr(int height, int rows, int cols) {
	int*** p = malloc(sizeof(int**) * height);
	int i;
	for (i = 0; i < height; i++) {
		printf("Enter matrix %d\n", i + 1);
		p[i] = get_matrix(rows, cols);
	}
	return p;
}
void print_arr(int* arr, int len) {
	int i;
	for (i = 0; i < len; i++)
		printf("%d,", arr[i]);
	putchar('\n');
}
void print_matrix(int **arr, int rows, int cols) {
	int i, r;
	for (i = 0; i < rows; i++)
		print_arr(arr[i], cols);
}
void print_3d_arr(int*** arr, int height, int rows, int cols) {
	int i;
	for (i = 0; i < height; i++) {
		print_matrix(arr[i], rows, cols);
		printf("\n");
	}
}
void free_matrix(int **arr,int rows) {
	int i;
	for (i = 0; i < rows; i++)
		free(arr[i]);
	free(arr);
}
void free_3d_array(int*** arr, int height, int rows) {
	int i;
	for (i = 0; i < height; i++)
		free_matrix(arr[i], rows);
	free(arr);
}
void main() {
	int height, rows, cols, choose,*p,**p2,***p3,type_sort;
	while(1){
		puts("1 = array");
		puts("2 = 2d array");
		puts("3 = 3d array");
		puts("other number exit");
		scanf("%d", &choose);
		if (choose > 3 || choose < 1)
			break;
		puts("Enter type of sorting 1 = regular, 2 = bubble");
		scanf("%d", &type_sort);
		switch (choose) {
			case 1:
				printf("Enter array length: ");
				scanf("%d", &cols);
				p = get_array(cols);
				puts("The array:");
				print_arr(p, cols);
				puts("The sorted array:");
				if (type_sort == 1)
					sort_array(p, cols);
				else
					sort_array_bubble(p, cols);
				print_arr(p, cols);
				free(p);
				break;
			case 2:
				printf("Enter array rows: ");
				scanf("%d", &rows);
				printf("Enter array cols: ");
				scanf("%d", &cols);
				p2 = get_matrix(rows,cols);
				puts("The 2d array:");
				print_matrix(p2,rows,cols);
				puts("The sorted 2d array:");
				if (type_sort == 1)
					sort_matrix(p2, rows, cols);
				else
					sort_matrix_bubble(p2, rows, cols);
				print_matrix(p2, rows,cols);
				free_matrix(p2,rows);
				break;
			case 3:
				printf("Enter array height: ");
				scanf("%d", &height);
				printf("Enter array rows: ");
				scanf("%d", &rows);
				printf("Enter array cols: ");
				scanf("%d", &cols);
				p3 = get_3d_arr(height, rows, cols);
				puts("The 3d array:");
				print_3d_arr(p3, height, rows, cols);
				puts("The sorted 3d array:");
				if (type_sort == 1)
					sort_3d_array(p3, height, rows, cols);
				else
					sort_3d_array_bubble(p3, height, rows, cols);
				print_3d_arr(p3, height, rows, cols);
				free_3d_array(p3,height,rows);
				break;
		}
		printf("\n\n");
	}
	puts("GOOD BYE");
	system("pause>0");
}