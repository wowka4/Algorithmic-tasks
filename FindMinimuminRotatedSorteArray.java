import java.util.Arrays;
import java.util.List;

public class FindMinimuminRotatedSorteArray {
    public static void main(String[] args) {
        List<Integer> arr = Arrays.asList(30, 40, 15, 10, 20);
        System.out.println(findMinRotated(arr));
    }

    public static int findMinRotated(List<Integer> arr) {
        // WRITE YOUR BRILLIANT CODE HERE
        int l = 0;
        int r = arr.size() - 1;
        int indexMin = 0;
        while (l < r) {
            if (arr.get(l) <= arr.get(r)) {
                indexMin = l;
                r--;
            } else {
                indexMin = r;
                l++;
            }
        }
        return indexMin;
    }
}
