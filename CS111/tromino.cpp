/* Talen Phillips
 * CS111-01
 * 02MAR2014
 * "Tromino"
 *
 * This program prompts the user to specify a matrix of size n^2 x n^2
 * and the coordinates of an element. The trom function will fill the
 * rest of the elements in the matrix with "trominos" (3 elements in
 * the shape of an L).
 */

#include<iostream>
#include<iomanip>

using namespace std;

int trom(int **a, int d, int x, int y, int i)
{
    /* base case is one element */
    if (d <= 1)
        return i;

    /* find the element that has already been filled (can only be one) */
	int hole_x = x;
	int hole_y = y;
	for (int k = y; k <= y+d-1; ++k)
        for (int j = x; j <= x+d-1; ++j)
            if (a[j][k] != -1){
                hole_x = j;
                hole_y = k;
            }

    /* place tromino pointed away from the filled element (and increment i) */
	if (hole_x > x+(d/2)-1) {
		if (hole_y > y+(d/2)-1)
			a[x+(d/2)-1][y+(d/2)] = a[x+(d/2)-1][y+(d/2)-1] = a[x+(d/2)][y+(d/2)-1] = i++;
		else
			a[x+(d/2)-1][y+(d/2)] = a[x+(d/2)][y+(d/2)] = a[x+(d/2)-1][y+(d/2)-1] = i++;
	} else {
		if (hole_y > y+(d/2)-1)
			a[x+(d/2)][y+(d/2)] = a[x+(d/2)-1][y+(d/2)-1] = a[x+(d/2)][y+(d/2)-1] = i++;
		else
			a[x+(d/2)-1][y+(d/2)] = a[x+(d/2)][y+(d/2)] = a[x+(d/2)][y+(d/2)-1] = i++;
	}

	/* nested function call that splits the array into 4 sub-arrays. Each call returns the value for the new i. */
	return trom(a, d/2, x+(d/2), y, trom(a, d/2, x, y, trom(a, d/2, x+(d/2), y+(d/2), trom(a, d/2, x, y+(d/2), i))));
}

int getUserInput(string prompt, int low, int high)
{
    int n;
    do {
    cout << prompt << endl;
    cin >> n;
    } while (n < low || n > high);
    cout << endl;
    return n;
}

int main(void)
{
    /* get size of the matrix (size can be larger, but formatting is messy) */
    int n = getUserInput("enter size 2^n (1 to 5)", 1, 5);
    int diameter = 1;
    for (int i = 0; i < n; ++i)
        diameter *= 2;
    cout << "diameter = " << diameter << "." << '\n' << endl;

    /* get (valid) coordinates for the "hole" */
    int a = getUserInput("Enter x coordinate of 1x1 tile", 0, diameter-1);
    int b = getUserInput("Enter y coordinate of 1x1 tile", 0, diameter-1);

    /* declare array */
    int **arr = NULL;
    arr = new int* [diameter];
    for(int x = 0; x < diameter; x++)
       arr[x] = new int[diameter];

    /* initialize array to -1 */
    for(int x = 0; x < diameter ; x++)
       for(int y = 0; y < diameter ; y++)
          arr[x][y] = -1;

    /* place 1x1 tile (hole) */
    arr[a][b]=0;

    /* fill array */
    trom(arr, diameter, 0, 0, 1);

    /* print array */
    for (int j = diameter-1; j >= 0; --j) {
       for (int k = 0; k < diameter; ++k)
           cout << setw(4) << left << arr[k][j];
       cout << endl << endl;
    }
    return 0;
}
