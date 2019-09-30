import java.util.PriorityQueue;

public class FindElement {

    public int findKthLargestElement(int[] nums, int k) {
        if (k > nums.length || k < 1) {
            return Integer.MIN_VALUE;
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>(k);
        for (int i = 0; i < k; i++) {
            pq.add(nums[i]);
        }
        for (int i = k; i < nums.length; i++) {
            if (nums[i] > pq.peek()) {
                pq.poll();
                pq.add(nums[i]);
            }
        }
        return pq.peek();
    }

}