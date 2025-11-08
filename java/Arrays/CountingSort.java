public class CountingSort {
    public static void main(String[] args) {
        int[] arr = {2, 8, 3, 4, 5, 11, 7};
        int n = arr.length;
        int max = 0;

        // Find the maximum value
        for (int i = 0; i < n; i++) {
            if (max < arr[i]) {
                max = arr[i];
            }
        }

        // Create count array
        int[] count = new int[max + 1];

        // Count frequency of each element
        for (int i : arr) {
            count[i]++;
        }

        // Build sorted array
        int index = 0;
        for (int i = 0; i <= max; i++) {
            while (count[i] > 0) {
                arr[index] = i;
                index++;       // ✅ increment index here
                count[i]--;
            }
        }

        // Print result
        System.out.println("Sorted Array :- ");
        for (int j = 0; j < n; j++) {
            System.out.println(arr[j]);
        }
    }
}
