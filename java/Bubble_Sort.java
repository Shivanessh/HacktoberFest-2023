public class BubbleSort {
    public int[] sortArray(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = 0; j < nums.length - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    // Swap nums[j] and nums[j + 1]
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
        return nums;
    }

    public static void main(String[] args) {
        BubbleSort sorter = new BubbleSort();
        int[] nums = {5, 3, 8, 4, 2};
        int[] sortedArray = sorter.sortArray(nums);

        System.out.print("Sorted array: ");
        for (int num : sortedArray) {
            System.out.print(num + " ");
        }
    }
}
