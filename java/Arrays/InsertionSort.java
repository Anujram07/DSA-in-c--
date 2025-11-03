public class InsertionSort {
    public static void main(String[] args) {
        int[] array = {14, 52, 75, 11, 75, 25};
        int n = array.length;

        for (int i = 1; i < n; i++) {
            int currentValue = array[i];
            int j = i - 1;

            // Shift elements greater than currentValue one position ahead
            while (j >= 0 && array[j] > currentValue) {
                array[j + 1] = array[j];
                j--;
            }

            // Place the currentValue in its correct position
            array[j + 1] = currentValue;
        }

        System.out.print("Sorted array: ");
        for (int value : array) {
            System.out.print(value + " ");
        }
    }
}

