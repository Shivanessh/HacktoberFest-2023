import java.util.ArrayList;
import java.util.Collections;

public class BucketSort {
    
    public void sort(float[] arr) {
        // Create buckets
        int n = arr.length;
        if (n <= 0) return;

        @SuppressWarnings("unchecked")
        ArrayList<Float>[] buckets = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            buckets[i] = new ArrayList<>();
        }

        // Distributing the elements into buckets
        for (float num : arr) {
            int bucketIndex = (int) (num * n); // Determine the bucket index
            if (bucketIndex >= n) {
                bucketIndex = n - 1; // Handle edge case
            }
            buckets[bucketIndex].add(num);
        }

        // Sort individual buckets and gather the results
        int index = 0;
        for (ArrayList<Float> bucket : buckets) {
            Collections.sort(bucket); // Sort the individual bucket
            for (float num : bucket) {
                arr[index++] = num; // Put back the sorted numbers
            }
        }
    }

    public static void main(String[] args) {
        BucketSort sorter = new BucketSort();
        float[] arr = {0.42f, 0.32f, 0.56f, 0.21f, 0.75f, 0.62f, 0.98f, 0.34f};

        System.out.println("Original array:");
        for (float num : arr) {
            System.out.print(num + " ");
        }

        sorter.sort(arr);

        System.out.println("\nSorted array:");
        for (float num : arr) {
            System.out.print(num + " ");
        }
    }
}
