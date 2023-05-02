/*There was a test in your class and you passed it. Congratulations!
But you're an ambitious person. You want to know if you're better than the average student in your class.

You receive an array with your peers' test scores. Now calculate the average and compare your score!

Return True if you're better, else False!

Note:
Your points are not included in the array of your class's points. For calculating the average point you may add your point to the given array!*/

int better_than_average(int arr[], int len, int my_point)
{
  int i = 0;
  int avr = 0;
  int sum = 0;
  while (i < len)
    sum += arr[i++];
  avr = sum / len;
  if (avr < my_point)
    return 1;
  return 0;
}