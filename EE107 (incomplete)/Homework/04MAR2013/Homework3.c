/* Talen Phillips
 * EE107-01
 * 04MAR2013
 * "Min/Max identifier"
 */
#include <stdio.h>
int main (void)
{
	int w, x, y, z, min, max, min1, max1, min2, max2;
	printf("Enter four integers:\n");
	scanf ("%d %d %d %d", &w, &x, &y, &z);
	max1 = w>x?w:x;
	min1 = w>x?x:w;
	max2 = y>z?y:z;
	min2 = y>z?z:y;
	max = max1>max2?max1:max2;
	min = min1>min2?min2:min1;
	/*if (w > x){ 	  //compare the first pair of variables.
		max1 = w;
		min1 = x;
	}
	else{
		max1 = x;
		min1 = w;
	}
	if (y > z){		//compare the second pair of variables.
		max2 = y;
		min2 = z;
	}
	else{
		max2 = z;
		min2 = y;
	}
	if (min1 < min2) min = min1;	// Compare the results of
	else min = min2;				// the earlier comparisons
	if (max1 > max2) max = max1;	// to set an absolute max
	else max = max2;				// and min.*/
	printf ("Largest: %d\nSmallest: %d", max, min);
	return 0;
}

