import java.util.Scanner;

public class HeapSort {

    // Function to heapify a subtree rooted at index i
    static void heapify(int[] arr, int size, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check if left child is larger than root
        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }

        // Check if right child is larger than largest so far
        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        // Swap and continue heapifying if root is not largest
        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            // Recursively heapify the affected subtree
            heapify(arr, size, largest);
        }
    }

    // Function to build a max-heap
    static void makeHeap(int[] arr, int size) {
        for (int i = (size / 2) - 1; i >= 0; i--) {
            heapify(arr, size, i);
        }
    }

    // Main heap sort function
    static void heapSort(int[] arr, int size) {
        makeHeap(arr, size);

        // One by one extract elements from heap
        for (int i = size - 1; i > 0; i--) {
            // Move current root to end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of array: ");
        int n = scanner.nextInt();

        int[] arr = new int[n];

        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        heapSort(arr, n);

        System.out.print("Sorted array is: ");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }

        scanner.close();
    }
}
